/*
Name: Tivon Laine, 2002167255, 102, LAB 9A
Description: Using user defined functions to execute arithmetic equation
Input: Two numbers
Output: Sum, difference, product, quotient
*/
#include<iostream>
#include<iomanip>
using namespace std;
double getDoubleInput(string prompt, double min, double max);
bool checkFailure(double input, double min, double max);
void getDoubleInputs(double& input1, double& input2);
void addsubtract(double& num1, double& num2);
void multiplydivide(double& num1, double& num2);
int main(){
double input1=0;
double input2=0;
getDoubleInputs(input1, input2);
addsubtract(input1, input2);
multiplydivide(input1, input2);}
double getDoubleInput(string prompt, double min, double max){
double input=0;
do{cout<<prompt;
    cin>>input;//getting radius
    checkFailure(input, min, max);//checking for true or false
} while(input>max||input<min||cin.fail());
return input;}//returning radius}
bool checkFailure(double input, double min, double max){//failure input
    do{if(input>max||input<min||cin.fail()){
    cout<<"\nError: Invalid input!\n";
    cin.clear();
    cin.ignore(100, '\n');
    return false;
    }return true;
}while (false);}
void getDoubleInputs(double& input1, double& input2){//getting both inputs
string prompt="Enter double between 0.500000 and 20.500000 \n**";
string prompt2="Enter another double between 0.500000 and 20.500000 \n**";
const double min=0.500000, max=20.500000;
input1=getDoubleInput(prompt, min, max);
cout<<endl;
input2=getDoubleInput(prompt2, min, max);}
void addsubtract(double& input1, double& input2){//adding/subtracting
double num1=0;
double num2=0;
num1=input1+input2;
cout<<endl;
cout<<fixed<<setprecision(2)<<input1<<" + "<<input2<<" = "<<num1;
num2=input1-input2;
cout<<endl;
cout<<fixed<<setprecision(2)<<input1<<" - "<<input2<<" = "<<num2;}
void multiplydivide(double& input1, double& input2){//multiply/divide
double num1=0;
double num2=0;
num1=input1*input2;
cout<<endl;
cout<<fixed<<setprecision(2)<<input1<<" * "<<input2<<" = "<<num1;
num2=input1/input2;
cout<<endl;
cout<<fixed<<setprecision(2)<<input1<<" / "<<input2<<" = "<<num2;}
