
// Node.h
// Jordan Pierson & Todd Muller
// COSC 2030, Fall 2018
// Project 2, Tracking Tree:
//  -Prototype for the Node class
//

#pragma once

#ifndef _Node_H_
#define _Node_H_

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using namespace std;

// -----------------------------------------------------------------------------
// Node Class:
// Will represent nodes int the binary tree
// There are no pointers as the tree will be represented in an Array(type Node)
// and use (whatever its called) math to find children, parent, etc. 
// possibly through recursion?? if necessary??
// -----------------------------------------------------------------------------

class Node
{
private:

	Node * left_;
	Node * right_;

	// String variables for nodes.
	// All should be of fixed size (8)
	// except rawE which can be up to 1024 characters long. 
	string iD,
		parentID,
		rawE,
		lHash,
		rHash;

	// Vectors of history of the lHash and rHash,
	// to be updated at the same time as lHash and rHash.
	vector<string> lHist;
	vector<string> rHist;

public:

	// Node class constructor
	/*
	Node() :
		left_(NULL),
		right_(NULL),
		iD(NULL), // Make sure to initialize based on hash of rawE and parentID
		parentID(NULL), // Should initialize with randomly generated string
		rawE(NULL), // Should also be randomly generated at first
		lHash(NULL),
		rHash(NULL),
		lHist(NULL),
		rHist(NULL)
	{
		// initialization, do we need to do something here??
	}
	*/

	// Accessor Functions
	string returnID(void);
	string returnParentID(void);
	string returnRawE(void);
	Node * returnLeft_(void);
	Node * returnRight_(void);
	string returnLHash(void);
	void printRecord(void);
	//Node * returnParent_(void);
	// Replacement functions

	// newLHash and newRHash both change the respective variable
	// as well as add the same input to the vectors 
	// lHist and rHist
	void newLHash(string input);
	void newRHash(string input);

	//set methods

	void setParentID(string input);
	void setID(string input);
	void setRawE(string input);

	// change pointers
	//void newChildLeft_(Node child);
	//void newChildRight_(Node child);

};

#endif