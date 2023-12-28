/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 7
Description: Opening a Matryoshka Doll
Input: ID and count
Output: Doll
*/
#include "matryoshka.h"
/* */
void MatryoshkaDoll::openDoll()
{
	printDoll();
	if(dollInside){
		dollInside->openDoll();
	}
	//TODO: Finish the function
	//This should print the doll that is being opened, and then open the next doll
	//To do the same if there is a doll inside this one.
}
/* */
MatryoshkaDoll::~MatryoshkaDoll()
{
	if(dollInside!=nullptr){
	delete dollInside;}
	//TODO: Finish the function
	//Deallocate any dolls contained within this one if they exist
}
/* Prints that the doll is being opened alongside its id */
void MatryoshkaDoll::printDoll()
{
	cout << "Opening doll (" << id << " / " << count << ")" << endl;
}