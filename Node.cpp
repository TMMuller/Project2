
// Node.cpp
// Jordan Pierson & Todd Muller
// COSC 2030, Fall 2018
// Project 2, Tracking Tree:
//  -Function definitions for the Node class
//

#include "Node.h"



// Accessor Functions
string Node::returnID(void)
{
	return iD;
}

string Node::returnParentID(void)
{
	return parentID;
}
string Node::returnRawE(void)
{
	return rawE;
}
Node * Node::returnLeft_(void)
{
	return left_;
}
Node * Node::returnRight_(void)
{
	return right_;
}

string Node::returnLHash(void)
{
	return string();
}

void Node::printRecord(void)
{
	cout << "Left History (Earliest record to current Left Hash):" << endl;
	for (int i = 0; i < lHist.size(); i++)
	{
	cout <<	lHist[i] << endl;
	}
	cout << "Right History (Earliest record to current Right Hash):" << endl;
	for (int i = 0; i < rHist.size(); i++)
	{
		cout << rHist[i] << endl;
	}
}

void Node::newLHash(string input)
{
	lHash = input;
	lHist.push_back(input);
}

void Node::newRHash(string input)
{
	rHash = input;
	rHist.push_back(input);
}

void Node::setParentID(string input)
{
	parentID = input;
}
void Node::setID(string input)
{
	iD = input;
}
void Node::setRawE(string input)
{
	rawE = input;
}
//string returnLHash(void)
//{
//	return lHash;
//}

// Replacement functions

// newLHash and newRHash both change the respective variable
// as well as add the same input to the vectors 
// lHist and rHist
//void newLHash(string input)
//{
//	lHash = input;
//	lHist.push_back(input);
//}


// change pointers
//void newChildLeft_(Node child);
//void newChildRight_(Node child);