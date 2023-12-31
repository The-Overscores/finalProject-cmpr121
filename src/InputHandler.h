
#include <fstream>
#include <string>
#include "CandidateList.h"


void createCandidateList(std::ifstream& infile, CandidateList& candidateList)
{
	int ssn = 0;
	int allVotes[NUM_OF_CAMPUSES];
  std::string  fName, lName;

	infile >> ssn;

	while (ssn != -999)
	{
		CandidateType newCandidate;

		infile >> fName;
		infile >> lName;
		newCandidate.setPerfonInfo(fName, lName, ssn);

		for (int i = 0; i < NUM_OF_CAMPUSES; ++i)
		{
			infile >> allVotes[i];
			newCandidate.updateVotesByCampus(i, allVotes[i]);
		}

		candidateList.addCandidate(newCandidate);


		infile >> ssn;
	}
}

void readCandidateData(CandidateList& candidateList)
{
  std::ifstream infile;

  std::string fileName;

  std::cout << "Please enter the name of an input file: ";

  std::getline(std::cin, fileName);

  //this is hacky and temporary please fix
	infile.open(fileName);

	if (!infile)
	{
    std::cerr << "Input file does not exist." << std::endl;
		exit(1);
	}

	createCandidateList(infile, candidateList);

	infile.close();
}
