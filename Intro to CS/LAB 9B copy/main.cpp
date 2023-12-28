/*
Name: Tivon Laine, 2002167255, 1021, LAB 9A
Description: Using user defined functions and overloading functions
Input: Numbers and strings
Output: Numbers and strings
*/
#include<iostream>
using namespace std;
int add(int num1, int num2);
string add(string str1, string str2);
int multiply(int num1, int num2);
string multiply(string str, int num);
int main(){int num1=0;int num2=0;string str=" ";string str1=" ";
string str2=" ";
const int min=1, max=50;
do{cout<<"Enter an integer between 1 and 50\n**";
    cin>>num1;
    if(num1<min||num1>max||cin.fail()){
        cout<<"\nError: Invalid input!\n";
        cin.clear();
        cin.ignore(100, '\n');}
}while(num1<min||num1>max||cin.fail());
cout<<endl;
do{ cout<<"Enter another integer between 1 and 50\n**";
    cin>>num2;
    if(num2<min||num2>max||cin.fail()){
        cout<<"\nError: Invalid input!\n";
        cin.clear();
        cin.ignore(100, '\n');}
}while(num2<min||num2>max||cin.fail());
cout<<endl;cout<<"Enter a string\n**";
cin>>str1;cout<<endl;
cout<<"Enter another string\n**";cin>>str2;
cout<<endl;int first=add(num1, num2);
cout<<num1<<" + "<<num2<<" = "<<first<<endl;
string second=add(str1, str2);
cout<<str1<<" + "<<str2<<" = "<<second<<endl;
int third=multiply(num1, num2);
cout<<num1<<" * "<<num2<<" = "<<third<<endl;
string four=multiply(str1, num1);//overloaded function
cout<<str1<<" * "<<num1<<" = "<<four<<endl;
string five=multiply(str2, num2);//overloaded function
cout<<str2<<" * "<<num2<<" = "<<five<<endl;return 0;}
int add(int num1, int num2){int add=0;add=num1+num2;//adding integers
return add;}string add(string str1, string str2){//adding strings
string word;word=str1.append(str2);
return word;}int multiply(int num1, int num2){//multiplying integers
int times=num1*num2;return times;}
string multiply(string str, int num){string wornum;//multiplying strings
for(int i=0;i<num;i++){ wornum+=str;}return wornum;
}
