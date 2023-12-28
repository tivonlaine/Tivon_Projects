/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 7
Description: Recursion
Input: Num
Output: Array of numbers
*/
#ifndef RECURSION_H
#define RECURSION_H
#include <iostream>
#include <string>
using namespace std;
//This file contains several functions that solve generic recursive problems. 
//TODO: Please finish each and test them using the provided main
/* Your description here */
void countBackwards(int num)
{	if(num<0){
		return;}
		if(num>0){
			cout<<num<<", ";
		}else{
		cout<<num;}
	return countBackwards(num-1);
	
	//This function should recursively print all integers backwards stopping at 0
	/*Consider your base case and how you might print the next number*/}
/* */
int sumToN(int n)
{	if(n==0){
		return 0;}
	return n+sumToN(n-1);
	//Recursively compute the sum up to n of a number. 
	//To problem solve, consider how you might break up the problem to reduce it
	/*And what a trivial base case that is easy to sum might be*/}
/* */
bool isValueInArray(int arr[], int start, int length, const int& value)
{	
	int leftLength = length / 2; //Length of the left array
	int rightLength = length - leftLength; //Length of the right subarray
	int middle = start + leftLength;
	if(length==0){
		return false;}
	if(length==1){
		return arr[start]==value;
		}
	if(value==arr[middle]){
		return true;}
	if(value<arr[middle]){
		return isValueInArray(arr,start,leftLength,value);}
	if(value>arr[middle]){
		return isValueInArray(arr,middle,rightLength,value);}
		return false;
	/*
	*Check if the array is of length 0, in which case, the solution is trivial
	*(we can't find any value in an empty array)
	*Check if the current element being looked at is a match
	*If so, we found it
	*If we did not find the element, recursively search for it.
	*Knowing that the list is already sorted, if the value is less than the middle of the list,
	*search the sub array to the left, else search the array to the right.
	*Please see the provided video for a more detalied explanation */
	}
#endif
