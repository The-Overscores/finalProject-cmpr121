#include "PersonType.h"
#include<string>

const int NUM_OF_CAMPUSES = 4;

class CandidateType : public PersonType 
{
private:
	int totalVotes;
	int votesByCampus[NUM_OF_CAMPUSES];

	std::string formatCandidateInfo(int socialSecurityNumber, std::string firstName, std::string lastName) const;
	std::string formatCandidateTotalVotes(int tVotes) const;
	std::string formatCandidateCampusVotes(int campusNum, int* votesPerCampus) const;

public:
	CandidateType();
	CandidateType(std::string firstName, std::string lastName, int socialSecurityNumber, int allVotes, int* voteByCampusPointer);
	void updateVotesByCampus(int campusNum, int votes);
	int getTotalVotes() const;
	int getVotesByCampus(int campusNum) const;
	void printCandidateInfo();
	void printCandidateTotalVotes();
	void printCandidateCampusVotes(int campusNum);
	~CandidateType();
};
