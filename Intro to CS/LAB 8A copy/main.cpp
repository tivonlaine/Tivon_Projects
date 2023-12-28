/*
Name: Tivon Laine, 2002167255, 1021, LAB 8A
Description: Using user defined functions to output shapes
Input: A number and character
Output: Upside down and right side up shapes using symbols
*/
#include<iostream>
using namespace std;
int getIntegerInput(string prompt1, int MIN, int MAX);
char getCharacterInput(string prompt2);
void writeUpsideDownTriangle(int size, char character);
void writeRightsideUpTriangle(int size, char character);
int main(){
	// Minimums/maximums
	const int MIN = 2;
	const int MAX = 20;
	// Prompt for integer input
	string prompt1 = "Enter a count between " +
		to_string(MIN) + " and " +
		to_string(MAX) + "\n**";
	// Prompt for character input
	string prompt2 = "\nEnter a character\n**";
	// Get size of triangle
	int size = getIntegerInput(prompt1, MIN, MAX);
	// Get character to use when printing triangle
	char character = getCharacterInput(prompt2);
	// Write both triangles
	writeUpsideDownTriangle(size, character);
	writeRightsideUpTriangle(size, character);
	cout << endl;
	// Terminate the program
	return 0;}
int getIntegerInput(string prompt1, int MIN, int MAX){
int size=0;
do{cout<<prompt1;
cin>>size;
if(size>MAX||size<MIN||cin.fail()){
    cout<<"\nError: Invalid input!\n";
    cin.clear();
    cin.ignore(100, '\n');}
}while(size>MAX||size<MIN||cin.fail());
return size;}//returning the size entered
char getCharacterInput(string prompt2){
    char character=' ';
    cout<<prompt2;
    cin>>character;
    return character;}//returning the character entered
void writeUpsideDownTriangle(int size, char character){
int outputCount=0;
outputCount=size;
cout<<endl;
for(int i=1;i<=outputCount;i++){
    for(int j=i;j<=outputCount;j++){
        cout<<character;
    }cout<<endl;}}
void writeRightsideUpTriangle(int size, char character){
int outputCount=1;
while(outputCount<=size){
int i=1;
while(i<=outputCount){
 cout<<character;
 i++;}
outputCount++;
cout<<endl;}
}