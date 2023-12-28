/*
Name: Tivon Laine, 2002167255, 1021, LAB 6B
Description: Being able to read a file into an array and use arithmetic equations
Input: A file and a name
Output: Scores in file, names in file, results for name, max, min, average, and sum
*/
#include<iostream>
#include<fstream>
#include<sstream>//string stream
using namespace std;
int main(){
ifstream input;
string file;
do{ cout<<"Enter a file name\n**";
    cin>>file;
    input.open(file);//opening file
    if(!input){
        cout<<"\nError: Invalid file name.\n";}
    }while(!input);
const int size=100;
string array1[size];//names
string array2[size];//scores
int num=0;
string name;
while(!input.eof()){
    getline(input, file);
    if(input.eof()){
        break;}
    input>>array1[num]>>array2[num];
    num++;}
while(!input.eof()){
    input>>array1[num]>>array2[num];
    num++;}
input.close();//closing file
cout<<endl;
cout<<"Names Forward: ";//outputting the names forwards
for(int i=0;i<num;i++){
    cout<<array1[i];
    if(i!=num-1){
        cout<<", ";}
}cout<<endl;
cout<<"Scores Forward: ";//outputting the scores forwards
for(int i=0;i<num;i++){
    cout<<array2[i];
    if(i!=num-1){
    } cout<<", ";
}cout<<endl;
cout<<"Names Reverse: ";//outputting the names backwards
for(int i=num-1;i>0;i--){
    cout<<array1[i];
 if(input.eof()){
    if(i!=0){
    cout<<", ";
    }}  }cout<<endl;
    cout<<"Enter a name to search for: ";
    cin>>name;
    cout<<endl;

}