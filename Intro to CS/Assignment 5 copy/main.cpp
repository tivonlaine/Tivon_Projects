/*
Name: Tivon Laine, 2002167255, 1002, Assignment 5
Description: Calculating the cost for staying at the Krusty Towers
Input: Cost to rent a room, number of rooms booked, number of days
Output: Costs, discounts and taxes in a neat table
*/
#include<iostream>
#include<fstream>
#include<iomanip>//for formatting purposes
#include<sstream>//for string stream
using namespace std;
int main(){
 string file;
ifstream input;
const double eur = 1.0828;
const double gbp = 1.2048;
const double jpy = 0.0076;
const double cny = 0.1276;
const double inr = 0.01212;
const double fee = 0.01;
double n1=0;
double tran=1;
double valid=0;
double total=0;
do{ cout<<"Enter transaction file: ";
    cin>>file;//user entering filename
    input.open(file);//opening file
    if(!input){//invalid file name
        cout<<"File not found!\n";}
}while(!input);
while(!input.eof()){
getline(input, file);
stringstream ss(file);
string w;
string n2;
if(file.empty()){//if the line is empty
    continue;}
getline(ss, w, ' ');//getting the currency
getline(ss, n2, ' ');//getting the amount
bool s = true;
bool t = true;
if(w!="EUR"&&w!="GBP"&&w!="JPY"&&w!="CNY"&&w!="INR"){
    s=false;
} if(n2[0]<48||n2[0]>57){
    t=false;
 } if((s==false)&&(t==true)){//currency is not valid
 cout<<"Transaction "<<tran<<" has unknown currency type"<<endl; 
 }else if((t==false)&&(s==true)){//number is not valid
  cout<<"Transaction "<<tran<<" contains an invalid amount"<<endl;
    }else if ((s==false)&&(t==false)){//both are not valid
 cout<<"Transaction "<<tran<<" contains an invalid amount"<<endl; 
         } else if ((t==true)&&(s==true)){//both are valid
    n1=stod(n2);//converting string to double
    valid++;
    if(w=="EUR"){
        n1=n1*eur;//eur to usd
        total+=n1;
    }else if(w=="GBP"){
        n1=n1*gbp;//gbp to usd
        total+=n1;
    }else if(w=="JPY"){
        n1=n1*jpy;//jpy to usd
        total+=n1;
    }else if(w=="CNY"){
        n1=n1*cny;//cny to usd
        total+=n1;
    }else if(w=="INR"){
        n1=n1*inr;//inr to usd
        total+=n1;/*total amount*/ } } tran++/*transaction number*/;}
double profit=total*fee;//profit made without the fee
cout<<"\nTransactions made "<<setw(21)<<right<<valid<<endl;
cout<<"Total exchanges made "<<setfill(' ')<<setw(8)<<"$"
<<right<<setw(10)<<fixed<<setprecision(2)<<total<<endl;
cout<<"Profit made "<<setfill(' ')<<setw(17)<<"$"
<<right<<setw(10)<<right<<profit<<endl;
}
