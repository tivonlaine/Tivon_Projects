/*
Name: Tivon Laine, 2002167255, 1021, LAB 8B
Description: Using user defined functions to output circumference and area
Input: A number
Output: Radius, circumference, and area as doubles
*/
#include<iostream>
#include<cmath>//for pi and using exponents
#include<iomanip>//for set precision
using namespace std;
double getDoubleInput(string prompt, double min, double max);
bool checkFailure(double input, double min, double max);
double circumference(double radius);
double area(double radius);
int main(){
const double min=0.500000;//minimum
const double max=20.500000;//maximum
string prompt="Enter a circle radius between "+to_string(min)+//prompt
" and "+to_string(max)+"\n**";
double rad=getDoubleInput(prompt, min, max);
double cir=circumference(rad);
double ar=area(rad);
cout<<endl;
cout<<"Radius: "<<fixed<<setprecision(2)<<rad<<endl;//outputting radius
cout<<"Circumference: "<<fixed<<setprecision(2)<<cir<<endl;//outputting circumference
cout<<"Area: "<<fixed<<setprecision(2)<<ar<<endl;//outputting area
}
double getDoubleInput(string prompt, double min, double max){
double radius=0;
do{cout<<prompt;
cin>>radius;//getting radius
checkFailure(radius, min, max);//checking for true or false
}while(radius>max||radius<min||cin.fail());
return radius;
}//returning radius
bool checkFailure(double input, double min, double max){//failure input
    do{
    if(input>max||input<min||cin.fail()){
    cout<<"\nError: Invalid radius!\n";
    cin.clear();
    cin.ignore(100, '\n');
    return false;
    }return true;
}while (false);
}
double circumference(double radius){
    double rad=radius*2*M_PI;//calculating circumference
    return rad;}//returning circumference
double area(double radius){
    double rad=M_PI*pow(radius, 2);//calculating area
    return rad;}//returning area
