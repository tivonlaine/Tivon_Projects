/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 2
Description: To define all functions used in implementation file
Input: User inputs file name
Output: Text file
*/

#include "fileInputOutput.h"
#include <fstream>
#include<iostream>
using namespace std;

 FileClass::FileClass(string file_name){
        inFile.open(file_name);//opening file
        if(!inFile){//checking if file can be opened
            cout<<"File could not be opened"<<endl;
        }
    }
FileClass::~FileClass(){
        inFile.close();//closing input file
        outFile.close();//closing output file
    } 

void getData(std::vector<Multiplication> &multiplications, 
const std::string &filename){
    ifstream inFile;
    inFile.open(filename);
    if(!inFile){
        cout<<"Failed to open file.";//failed message
    }
    cout<<"File opened successfully.";
    int num1;
    int num2;
    int num3;
    string read="";
    getline(inFile, read);//reading the first line of file
    while(!inFile.eof()){
    inFile>>num1>>num2>>num3;//reading every other line of file
    Multiplication slm(num1, num2, num3);
    multiplications.push_back(slm);
    }
    
}