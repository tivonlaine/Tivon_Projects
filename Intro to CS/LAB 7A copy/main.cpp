/*
Name: Tivon Laine, 2002167255, 1021, LAB 7A
Description: Being able to read a file into a 2D array and use arithmetic equations
Input: A file
Output: Sums of numbers in each row
*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main(){
ifstream input;
string file;
do{ cout<<"Enter a file name\n**";
    cin>>file;//user input
    input.open(file);//opening file
    if(!input){
    cout<<"\nError: Invalid File Name\n";
}}while(!input);//invalid file name
const int r=7, c=10;//array dimensions
double array[r][c];//declaring array
cout<<endl;
cout<<"Row Sums:\n";
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        input>>array[i][j];}}
for(int i=0;i<r;i++){
    double total=0;
    for(int j=0;j<c;j++){
    cout<<setw(4)<<fixed<<setprecision(1)<<left<<array[i][j];
    if(j<c-1){
            cout<<" + ";}
        total+=array[i][j];}
        cout<<" = "<<total<<endl;}cout<<endl;
cout<<"Column Sums:\n";
for(int i=0;i<c;i++){
    double total=0;
    for(int j=0;j<r;j++){
     cout<<fixed<<setprecision(1)<<setw(4)<<left<<array[j][i];
        if(j<r-1){
            cout<<setw(2)<<" + ";}
        total+=array[j][i];}
        cout<<" = "<<total<<endl;}

}









