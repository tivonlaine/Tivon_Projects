/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 3
Description: Getting stocks information
Input: Stocks
Output: Text file
*/
#include "investorType.h"
#include<iomanip>
#include<iostream>
#include<fstream>
using namespace std;
  investorType::investorType()
  {
    typeName="";
    stockName="";
    stockCount=0.00;
    stockPrice=0;
  }
investorType::investorType(string id, string fName, string lName,
    string tyName, string stName, int stCount, double stPrice,   
    ostream &output) : stockInvestor(fName, lName, id)
    {   typeName=tyName;
        stockName=stName;
        stockCount=stCount;
        stockPrice=stPrice;
        setInvestorID(id);
        if(checkInvestorID(id)==false){
           // output<<"Error :- "<<id<<" is invalid investorID for "<<fName<<endl;
            output<<"Invalid ID; No calculations for "<<fName<<"; ID "<<id<<endl;
        }
        else if(stCount<0){
            output<<fName<<"'s stock count is invalid"<<endl;
        }
        else if(stPrice<0){
            output<<fName<<"'s stock price is invalid"<<endl;
        }
    }
void investorType::setInvestorInfo(string id, string fName, string lName,
string tyName, string stName, int stCount, double stPrice)
{
       setName(fName, lName);
        setInvestorID(id);
        typeName=tyName;
        stockName=stName;
        stockCount=stCount;
        stockPrice=stPrice;
       
       
}
  void investorType:: setType(string tyName){
        typeName=tyName;
  }
  void investorType::setStockName(string stName){
        stockName=stName;
  }
  void investorType::setStockCount(int stCount){
        stockCount=stCount;
  }
    void investorType::setStockPrice(double stPrice){
        stockPrice=stPrice;
    }
  string investorType::getID() const{
        return stockInvestor::getID();
  } 
  string investorType::getFirstName() const{
        return stockInvestor::getFirstName();
  }
  string investorType::getLastName() const{
        return stockInvestor::getLastName();
  }
  string investorType::getType() const{
        return typeName;
  }
  string investorType::getStockName() const{
        return stockName;
  }
  double investorType::getStockPrice() const{
        return stockPrice;
  }
  double investorType::getStockCount() const{
        return stockCount;
  }
  void investorType::print(ostream &outFile) const{
        string stars;
        stars.append(65, '*');
        outFile<<stars<<endl;
        outFile<<"Investor Type:"<<endl;
        outFile<<"Type Name: "<<typeName<<endl;
        outFile<<"Investor ID: "<<getID()<<endl;
        outFile<<"First Name: "<<getFirstName()<<endl;
        outFile<<"Last Name: "<<getLastName()<<endl;
        outFile<<endl;
        outFile<<"\nStock Name: "<<stockName<<endl;
        outFile<<"Stock Count: "<<fixed<<showpoint<<setprecision(2)<<getStockCount()<<endl;
        outFile<<"Stock Price: "<<stockPrice<<endl;
        string dashes;
        dashes.append(50, '_');
        outFile<<dashes<<endl;
  }
    void investorType::writeDataToFile(ofstream &outFile,investorType tempObj)
    { 
      double count=static_cast<double>(stockCount);
      outFile<<setw(10)<<tempObj.getID()<<setw(10)<<tempObj.getFirstName()<<setw(10)
    <<tempObj.getLastName()<<setw(10)<<typeName<<setw(10)<<stockName
    <<setw(12)<<count<<setw(12)<<stockPrice<<setw(10);
    }
