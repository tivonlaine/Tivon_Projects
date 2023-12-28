/*
Name: Tivon Laine, 2002167255, 1021, LAB 7B
Description: Finding the highest, lowest, and average temperatures
Input: A file
Output: Highest, lowest, and average temperatures
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;
int main(){
string file;
ifstream input;
double max=0;
double avglow=0;//average low temp
double avghigh=0;//average high temp
double min=99999;//high as possible
do{cout<<"Enter file name\n**";
    cin>>file;//user inputting filename
    input.open(file);//open file
    if(!input){//file not valid
 cout<<"\nError: Invalid File Name\n";  }
}while(!input);
    string l;
  getline(input, l);//first line of file
    stringstream ss(l);
    string first;
    string second;
    getline(ss, first, ' ');
    getline(ss, second, ' ');
const int r=12, c=2;
double array[r][c];//initializing array
cout<<endl;
cout<<first<<" "<<second<<endl;
while(!input.eof()){
    for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
        input>>array[i][j];
        if(file.empty()){
            continue; } }}
}for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
    if(j==1){
        if(array[i][j]>max){
        max=array[i][j];//finding max
        }  avghigh+=array[i][j];
    } if(j==0){
        if(array[i][j]<min){
            min=array[i][j];//finding min
     } avglow+=array[i][j]; }}}
cout<<"Lowest temperature of the year was "<<fixed<<
setprecision(2)<<min<<"° F."<<endl;
cout<<"Highest temperature of the year was "<<fixed<<
setprecision(2)<<max<<"° F."<<endl;
cout<<"Average low temperature of the year was "<<avglow/12//average
<<"° F."<<endl;
cout<<"Average high temperature of the year was "<<avghigh/12//average
<<"° F."<<endl;
}
