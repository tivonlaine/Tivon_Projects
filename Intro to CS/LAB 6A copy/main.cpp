/*
Name: Tivon Laine, 2002167255, 1021, LAB 6A
Description: Being able to read a file into an array and use arithmetic equations
Input: A file
Output: The numbers in the file, the max, the min, the average, and the sum
*/
#include<iostream>
#include<fstream>//for file reading
#include<iomanip>//for set precision
using namespace std;
int main(){
string file;
ifstream input;
do{ cout<<"Enter a file name\n**";
    cin>>file;
    input.open(file);//opening file
    if(!input){//if file name doesn't exist
    cout<<"\nError: Invalid file name.\n";
    }
}while(!input);
const int size=100;
double array[size];
int num=0;
while(!input.eof()){//not at the end of the file
   input>>array[num];//inputting
    if(!input){
    if(!input.eof()){
    input.clear();
    input.ignore(100, '\n');
    cout<<"\nError: Invalid input in file.";
    }
     } else{
    num++;
    }}
input.close();//closing the file
double sum=0;
cout<<endl;
cout<<"\nAmount of Elements Read In: "<<num<<endl;
cout<<"Forwards: ";
for(int i=0; i<num; i++){
    cout<<fixed<<setprecision(2)<<array[i];
    if(i!=num-1){
        cout<<", ";
    }
    sum+=array[i];}//adding all the numbers
    cout<<endl;
cout<<"Backwards: ";
for(int i=num-1; i>=0; i--){
    cout<<fixed<<setprecision(2)<<array[i];
    if(i!=0){
   cout<< ", ";
}
}
double count2=0;
for(int i=0; i<num; i++){
    if(array[i]>count2){//finding minimum
        count2=array[i];
    }}
    double count1=count2;
    for(int i=0; i<num; i++){
    if(array[i]<count1){//finding maximum
        count1=array[i];
    }}
cout<<endl;
cout<<"Minimum: "<<fixed<<setprecision(2)<<count1<<endl;
cout<<"Maximum: "<<fixed<<setprecision(2)<<count2;
cout<<"\nSum: "<<sum<<endl;
cout<<"Average: "<<fixed<<setprecision(2)<<sum/num;//finding the average
    }



