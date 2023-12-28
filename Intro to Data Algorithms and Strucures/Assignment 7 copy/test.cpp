#include "general_recursion.h"
//#include "sweepminer.h"
//#include "matryoshka.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

//Static initializers
//int MatryoshkaDoll::count = 0;
const int DOLL_AMOUNT = 9; //How many dolls to make
const int BOMB_COUNT = 5;
const int MINESWEEPER_WIDTH = 16;
const int MINESWEEPER_HEIGHT = 8;

//Function prototypes
int readInteger(istream& in);

//Variables for test cases
//const int SEARCH_ARR_SIZE = 16;
//int arr[SEARCH_ARR_SIZE]{ 1, 2, 6, 8, 10, 12, 13, 18, 19, 20, 21, 21, 22, 23, 28, 30 }; //Array for the search function

int main()
{
	//Print a message about what functions are available to test
	cout << "Please select a function to test:" << endl;
	cout << "(0) countBackwards" << endl;
	cout << "(1) sumToN" << endl;
	cout << "(2) isValueInArray" << endl;
	cout << "(3) Matryoshka class" << endl;
	cout << "(4) Sweepminer class" << endl;

	//Test cases for the functions
	switch (readInteger(cin))
	{
		case 0: //Testing countBackwards
			cout << "Counting backwards from 4:" << endl;
			countBackwards(4);
			cout << endl << "Counting backwards from 86:" << endl;
			countBackwards(86);
			break;	
	/*	case 1: //Testing sumToN
			cout << "Sum of 1 to 10: " << sumToN(10) << endl;
			cout << "Sum of 1 to 99: " << sumToN(99) << endl;
			break;	
		case 2: //Testing isValueInArray
			cout << "Array:" << endl;
			for (int i = 0; i < SEARCH_ARR_SIZE - 1; i++)
				cout << arr[i] << ", ";
			cout << arr[SEARCH_ARR_SIZE - 1] << endl;

			cout << "Is 18 in the array? ";
			cout << (isValueInArray(arr, 0, SEARCH_ARR_SIZE, 18) ? "Yes" : "No") << endl;

			cout << "Is 9 in the array? ";
			cout << (isValueInArray(arr, 0, SEARCH_ARR_SIZE, 9) ? "Yes" : "No") << endl;

			cout << "Is 23 in the array? ";
			cout << (isValueInArray(arr, 0, SEARCH_ARR_SIZE, 23) ? "Yes" : "No") << endl;
			break;*/
    }
}