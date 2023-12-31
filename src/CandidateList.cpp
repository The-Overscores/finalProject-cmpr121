#include"CandidateList.h"
#include<iostream>

CandidateList::CandidateList()
{
	count = 0;
	first = nullptr;
	last = nullptr;
}

void CandidateList::addCandidate(CandidateType newCandidate)
{
	if (count == 0)
	{
		first = new Node(newCandidate, nullptr);
		last = first;
	}
	else
	{
		Node* newNode = new Node(newCandidate, nullptr);
		last->setLink(newNode);
		last = newNode;
	}
	count++;
}

bool CandidateList::searchCandidate(int ssn) const
{
	if (count == 0)
	{
		std::cout << "=> List is Empty" << std::endl;
		return 0;
	}

	Node* checkNode = first;

	while (checkNode != nullptr && ssn != checkNode->getCandidate().getSSN())
		checkNode = checkNode->getLink();
	
	bool success = checkNode != nullptr;

	if(!success)
	{
		std::cout << "=> SSN is not in the list" << std::endl;
	}

	return success; //Returns whether the iterator reached the end of the list.
}

CandidateType CandidateList::getWinner() const
{
	CandidateType winner = first->getCandidate();
	
	for (Node* checkNode = first; checkNode != nullptr; checkNode = checkNode->getLink()) //Scan the whole linklist
	{
		if (checkNode->getCandidate().getTotalVotes() > winner.getTotalVotes())
		{
			winner = checkNode->getCandidate(); //Finds the highest number.
		}
	}

	return winner;
}

void CandidateList::printCandidateName(int ssn) const
{
	if (count == 0)
	{
		std::cout << "=> List is Empty" << std::endl;
	}
	else
	{
		Node* nodePtr = first;

		while (nodePtr != nullptr && nodePtr->getCandidate().getSSN() != ssn)
			nodePtr = nodePtr->getLink();

		if (nodePtr == nullptr)
		{
			std::cout << "=> SSN is not in the list" << std::endl;
		}
		else
		{
			nodePtr->getCandidate().printName();
		}
	}
}

void CandidateList::printAllCandidates() const
{
	if (count == 0) {
		std::cout << "=> List is empty." << std::endl;
	}
	else {
		Node* currentNode = first;
		while (currentNode != last) { //might not print last
			currentNode->getCandidate().printCandidateInfo();
			currentNode = currentNode->getLink();
		}
		
	}
}

void CandidateList::printCandidateCampusVotes(int ssn, int division) const
{
	if (count == 0)
	{
		std::cout << "=> List is Empty" << std::endl;
	}
	else
	{
		Node* currentNode = first;

		while (currentNode != nullptr && currentNode->getCandidate().getSSN() != ssn)
			currentNode = currentNode->getLink();

		if (currentNode == nullptr)
		{
			std::cout << "=> SSN is not in the list" << std::endl;
		}
		else
		{
			currentNode->getCandidate().printCandidateCampusVotes(division);
			std::cout << std::endl << std::endl;
		}
	}
}

void CandidateList::printCandidateTotalVotes(int ssn) const
{
	if (count == 0)
	{
		std::cout << "=> List is Empty" << std::endl;
	}
	else
	{
		Node* currentNode = first;

		while (currentNode != nullptr && currentNode->getCandidate().getSSN() != ssn)
			currentNode = currentNode->getLink();

		if (currentNode == nullptr)
		{
			std::cout << "=> SSN is not in the list" << std::endl;
		}
		else
		{
			currentNode->getCandidate().printCandidateTotalVotes();
			std::cout << std::endl << std::endl;
		}
	}
}

void CandidateList::destroyList()
{
	Node* currentNode = first;

	for (int i = 1; i < count; ++i) {
		delete currentNode;
		currentNode = currentNode->getLink();
	}

	delete currentNode;
	//very elegant, i like this a lot -j
}

CandidateList::~CandidateList()
{
	destroyList();
}
