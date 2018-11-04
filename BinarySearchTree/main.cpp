//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "BinarySearchTree.h"  // ADT binary tree operations
#include<time.h> 
#include <vector>

using namespace std;

//driver method to fill binary search tree with 10000 unique integers with value up to 100000
 void fillTree(BinarySearchTree<int>* bst,int first,int fiveHundred,int fiveThousand, int tenThousand)
{
	srand(time(NULL));
	vector<int>uniqueRandom;
	int count = 0;
	while (uniqueRandom.size() < 10000)
	{
		int number = rand() % 100000 + 1;
		int count = std::count(uniqueRandom.begin(), uniqueRandom.end(), number);
		if (count == 0 || uniqueRandom.size() == 0)
		{
			if (number != 100)
			{
				uniqueRandom.push_back(number);
				if (uniqueRandom.size() == 1) //save the first entry to search for
				{
					first = number;
				}
				if (uniqueRandom.size() == 500) //save the five hundredth entry to search for
				{
					fiveHundred = number;
				}
				if (uniqueRandom.size() == 5000) //save the five thousandth entry to search for
				{
					fiveThousand = number;
				}
				if (uniqueRandom.size() == 10000) //save the ten thousandth entry to search for
				{
					tenThousand = number;
				}
			}
		}
		
	}
	
	for (int i = 0; i < uniqueRandom.size();i++)
	{
		bst->add(uniqueRandom.at(i));
	}
	
}
 
int main()
{
	int first = 0;
	int fiveHundred =0;
	int fiveThousand = 0;
	int tenThousand = 0; 

	int target = 0;
	int counter = 0;
	
	

	cout << "\nBinary Search Tree\n\n";
	BinarySearchTree<int>* bst = new BinarySearchTree<int>();
	fillTree(bst,first,fiveHundred,fiveThousand,tenThousand); //fill tree with 10000 random integers except for number 100

	//find the node with element equal to first. (position 0 in vector)
	target = first;
	counter = bst->findTargetAndCount(target);
	cout << endl << endl << "the number of times binary tree was searched = " << counter;

	//find the node with element equal to fiveHundred (position 499 in vector)
	target = fiveHundred;
	counter = bst->findTargetAndCount(target);
	cout << endl << endl << "the number of times binary tree was searched for 500th number = " << counter;

	//find the node with element equal to fiveThousand (position 4999 in vector)
	target = fiveThousand;
    counter = bst->findTargetAndCount(target);
	cout << endl << endl << "the number of times binary tree was searched for 5000th number= " << counter;

	//find the element equal to tenThousand (position 9999 in vector)
	target = tenThousand;
	counter = bst->findTargetAndCount(target);
	cout << endl << endl << "the number of times in binary tree was searched fpr 10000th number = " << counter;

	//find an element larger than then what is stored in the binary search tree
	//elements ranch from 0 to 100000, seach for 110000
	target = 110000;
	counter = bst->findTargetAndCount(target);
	cout << endl << endl << "the number of times in binary tree was searched for number too large = " << counter;

	//find element not in list,100 excluded from random generation, search for 100
	target = 100;
	counter = bst->findTargetAndCount(target);
	cout << endl << endl << "the number of times binary tree was searched for number not there, but in range = " << counter;
	cout << "\n\n\n\n\n finished";

}
