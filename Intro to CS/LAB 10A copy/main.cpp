/*
Name: Tivon Laine, 2002167255, 1021, LAB 10A
Description: Using user defined functions and structs
Input: Numbers and strings
Output: Numbers and strings
*/
#include<iostream>
#include<iomanip>//for formatting
using namespace std;
struct studentType{//creating struct
    string firstName;
    string lastName;
    int grade;
    char letterGrade;};
void getstudentdata(studentType&);
void getlettergrade(studentType&);
void printstudentdata(studentType);
studentType getstudent(string f, string l, double g);
int main(){
    studentType p1;//creating an instant
    getstudentdata(p1);
    getlettergrade(p1);
    printstudentdata(p1);}
void getstudentdata(studentType& student){//getting name and grade
    cout<<"Enter a first name\n**"; 
    string firstname;
    cin>>firstname;
    cout<<"\nEnter a last name\n**"; 
    string lastname;
    cin>>lastname;
    int grade=0;
    do{cout<<"\nEnter a grade\n**";
        cin>>grade;
        if(grade>4||grade<0||cin.fail()){//failure check
            cout<<"\nError: Invalid grade";
            cin.clear();
            cin.ignore(100, '\n');
            grade=-1;}//make sure age is invalid to not pass condition
    }while(grade>4||grade<0);
    student.firstName=firstname;
    student.lastName=lastname;
    student.grade=grade;}
void getlettergrade(studentType& student){//matching grade with letter
    if((student.grade)==4){
        (student.letterGrade)='A';
    }else if((student.grade)==3){
        (student.letterGrade)='B';
    }else if((student.grade)==2){
        (student.letterGrade)='C';
    }else if((student.grade)==1){
        (student.letterGrade)='D';
    }else if((student.grade)==0){
        (student.letterGrade)='F';}}
void printstudentdata(studentType student){//printing all the data
cout<<"\nData Entered"<<endl;
cout<<"  student.firstName"<<setw(5)//to have desired spaces
<<setfill(' ')<<" = "<<student.firstName<<endl;
cout<<"  student.lastName"<<setw(6)//for spacing
<<setfill(' ')<<" = "<<student.lastName<<endl;
cout<<"  student.grade"<<setw(9)<<setfill(' ')<<" = "<<student.grade<<endl;
cout<<"  student.letterGrade"<<" = "<<student.letterGrade;
}