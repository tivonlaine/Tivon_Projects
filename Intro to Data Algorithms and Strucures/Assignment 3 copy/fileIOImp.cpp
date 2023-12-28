/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 3
Description: Writing to File
Input: File content
Output: Text file
*/
#include "fileIO.h"
unsigned int fileIO::readWriteDataFile(ifstream &inFile, ofstream &outData){
    stocksPortfolio name2;
    string typeName="";
    string stockName="";
    string firstName="";
    string lastName="";
    string id="";
    double stockPrice=0;
    double stockCount=0; 
    unsigned int counter=0;
    double priceOne=0;
    double priceTwo=0;
    double priceThree;
    double stockValue=0;
    getline(inFile, typeName);
    while(inFile>>id>>firstName>>lastName>>typeName>>stockName>>
    stockCount>>stockPrice>>priceOne>>priceTwo>>priceThree){
       counter++;
       double stock=double(stockCount);
       investorType name1(id, firstName, lastName, typeName,stockName, stock, stockPrice, outData);
        name1.print(outData);
        name2.setPortfolio(priceOne, priceTwo, priceThree, name1);
        name2.calculateStockValue(name1, outData);
    }
     string stars;
        stars.append(65, '*');
    outData<<stars<<endl;
    cout<<"Total entries: "<<counter;
    outData<<"Total entries: "<<counter;
    return counter;
    
}
