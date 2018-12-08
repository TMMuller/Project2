
// Node.cpp
// Jordan Pierson & Todd Muller
// COSC 2030, Fall 2018
// Project 2, Tracking Tree:
//  -Function definitions for the Node class
//
#include <cstdlib>
#include "Node.h"
#include <iostream>
using namespace std;

string getRand(void);

int main()
{
	Node tree[3];

	tree[0].setParentID("Hi");
	//cout << getRand();
	tree[0].setParentID(getRand());
	cout << tree[0].returnParentID();

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