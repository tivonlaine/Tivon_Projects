/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 3
Description: Checking if valid
Input: Name and ID
Output: Name and ID
*/
    #include "stockInvestor.h"
    #include <iostream>
    stockInvestor::stockInvestor(){
         firstName="";
         lastName="";
         ID="";
    } 
    stockInvestor::stockInvestor(string fName, string lName, string id){
        firstName=fName;
        lastName=lName;
        ID=id;
    }
   void stockInvestor::setStockInvestor(string fName, string lName, string id){
        firstName=fName;
        lastName=lName;
        ID=id;
    }
    bool stockInvestor::checkInvestorID(string investorIDTemp) const{
        string check=investorIDTemp.substr(1);
        if(investorIDTemp.length()<6){

            return false;
        }
       if((investorIDTemp[0]!='T')&&(investorIDTemp[0]!='P')){

        return false;
       }
      for (int i = 0; i < check.length(); i++) {
      if (!isdigit(check[i])) { 
        return false;
    }
      }
       return true;
    }
    void stockInvestor::setInvestorID(string id){
        ID=id;
         if(!checkInvestorID(id)){
            cout<<"Error:- "<<id<<" is invalid investorID for "<<getFirstName();
            cout<<endl;
        }else if(checkInvestorID(id)==true){
            ID=id;
        }
    }
    void stockInvestor::setName(string fName, string lName){
        firstName=fName;
        lastName=lName;
    }
   string stockInvestor::getID() const{
        return ID;
   }
   string stockInvestor::getFirstName() const{
        return firstName;
   }
   string stockInvestor::getLastName() const{
        return lastName;
   }
   void stockInvestor::print(ostream &output) const{
        output<<"Investor ID: "<<ID<<endl;
        output<<"First Name: "<<firstName<<endl;
        output<<"Last Name: "<<lastName<<endl;
        output<<endl;
   }
