
// Driver.cpp
// Jordan Pierson & Todd Muller
// COSC 2030, Fall 2018
// Project 2, Tracking Tree:
//  -Driver file
//
#include <cstdlib>
#include "Node.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using std::setw;

// Function Prototypes
string getRand(void);
string hashFunc(string);


int main()
{
	Node tree[6];

	//tree[0].setParentID("Hi");
	//cout << getRand();
	tree[0].setParentID(getRand());
	//cout << tree[0].returnParentID();
	string input;
	bool exit = false;
	int level = 1;
	int index = 0;
	int sizeArray = 1;

	// Tell the user how to use the program
	cout << "---------------------------------" << endl
		<< "Tracking Tree" << endl
		<< "Commands are:" << endl
		<< "'E'/'Exit' To Exit the Program"
		<< "\n'V'/'Visualize' to see all of the ID values of the nodes"
		<< "\n'S'/'Search' to search for a node using it's ID"
		<< "\n'U'/'Update' to search for, and update contents of a node"
		<< "\nIf anything else is entered, it will be taken as a "
		<< "\nnew raw event and create a new node in the tree." << endl;
	cout << "-------------------------------- - " << endl << endl;

	while (exit == false)		//		runs until the user exits
	{
		cin >> input; //take in input from user
		if (input== "E" || input == "Exit")
		{
			exit = true; // exits the program
		}
		if (input == "V" || input == "Visualize") // Print id values of nodes
		{
			cout << "Printing Contents of the Tree:" << endl
				<< "-------------------------------" << endl 
				<< "Node	RawE	ID" << endl;
			for (int i = 0; i < sizeArray && i <= index; i++)
			{
					cout << i << setw(4) << tree[i].returnRawE()
						<< setw(4) << tree[i].returnID()	<< endl;
			}
		}
		if (input == "S" || input == "Search")
		{
			cout << "Type in and ID value to search for:" << endl;
				string sID;
				cin >> sID;
				for (int i = 0; i < sizeArray && i <= index; i++)
				{
					if (tree[i].returnID() == sID)
					{
						cout << sID << " found. Printing Record:" << endl;
						tree[i].printRecord();
						i = sizeArray + 1; // exits loop;
						sID = "Found"; // now uses sID for different purpose: telling if the variable was found or not
					}

				}
				if (sID != "Found")
				{
					cout << "The ID you searched for was not found.\n"
						<< "Returning to main command line." << endl;
				}
		}
		if (input == "U" || input == "Update")
		{
			// still needs done
		}
		else
		{
			/*
			//Needs finished. If the level is full, make
			//a new array with +1 level, copy contents
			//from original array, then set the old array
			// to the new array?
			if (index + 1 == sizeArray)
			{
				
				int temp = pow(2, level + 1) - 1;;
				Node** new_array = new Node*[temp];
				Node *a = tree;
				for (int i = 0; i < sizeArray - 1; i++)
				{
					new_array = &a;
				}
				sizeArray = pow(2, level + 1) - 1;
				cout << new_array[0]->returnID;
			}
			*/

			//now create a new node at the next available slot
			index++;
			tree[index].setRawE(input); //set rawE to input
			tree[index].setParentID(tree[index / 2].returnID());	// set parent ID to it's parent using integer division (P= N/2)
			// Now make the current nodes ID by hashing parentID + rawE
			tree[index].setID(hashFunc(tree[index].returnParentID() + tree[index].returnRawE()));

			//------------------------------------------------------
			// Now percolate up, update parents LHash / RHash
			//------------------------------------------------------
			//
			// These are preliminary things we need to keep track of
			// before entering the for loop.
			string relation;
			if (index % 2 == 0)
			{
				relation = "left";
			}
			if (index % 2 == 1)
			{
				relation = "right";
			}
			int prevChildI(index);
			//
			//For loop to percolate up:
			for (int i = index / 2; i >= 0; i /= 2) // finds parent(s) up to the root
			{
				if (relation == "left") // if the child is the left then update LHash
				{
					tree[i].newLHash(hashFunc( // Hash the following contents, store in current node's LHash & lHist
						tree[prevChildI].returnID()			//child ID
						+ tree[i].returnID()				// parent ID
						+ tree[prevChildI].returnRawE()		// child rawE
						+ tree[prevChildI].returnLHash()	// child lHash
						+ tree[prevChildI].returnLHash())); // child rHash
				}
				if (relation == "right") // if the child is the right then update RHash
				{
					tree[i].newRHash(hashFunc(	// Hash the following contents, store in current node's RHash & rHist
						tree[prevChildI].returnID()			//child ID
						+ tree[i].returnID()				// parent ID
						+ tree[prevChildI].returnRawE()		// child rawE
						+ tree[prevChildI].returnLHash()	// child lHash
						+ tree[prevChildI].returnLHash())); // child rHash
				}

				// Same as preliminary things, but now for the next time around. 
				//
				// find relation of current node to it's parent for next time around loop
				if (i % 2 == 0)
				{
					relation = "left";
				}
				if (i % 2 == 1)
				{
					relation = "right";
				}
				prevChildI = i; //save current node index for the next time around loop
			}
		}
	}


	system("pause");
	return 0;
}

string getRand(void)
{
	const int len = 8;
	char s[len];
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
		//cout << alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len-1] = 0;
	return s;
}

string hashFunc(string input)
{
	// figure out how to write a hash function
	//return input % "hash";
	return "hash";
}