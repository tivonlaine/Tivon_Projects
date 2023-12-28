/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 6
Description: Making a custom string class
Input: Strings
Output: Strings
*/
#include <iostream>
#include <cstdlib>
#include "myString.h"
using namespace std;

/*---------------------------------------------
Default constructor
---------------------------------------------*/
myString::myString()
{   s=NULL;
    sLength=0;}
/*---------------------------------------------
Constructor that sets the object equal to a
string literal passed into it
---------------------------------------------*/
myString::myString(const char str[])
{     int j=0;
    while(str[j]!='\0'){
      j++;
    }
    s=new char[j];
     sLength=j;
    for(int i=0;i<j;i++){
      s[i]=str[i];
    }
   }
/*---------------------------------------------
Overloading the default copy constructor since
we have a pointer variable in the class
---------------------------------------------*/
myString::myString(const myString& str)
{   sLength=str.sLength;
     s=new char[sLength];
     for(int i=0;i<sLength;i++){
      s[i]=str.s[i];}}
/*---------------------------------------------
Constructor that sets the object equal to a
character passed into it
---------------------------------------------*/
myString::myString(char c)
{   sLength=1;
   s=new char[1];
    s[0]=c;}
/*---------------------------------------------
Function: char& myString::operator[](int i)
Parameters: Int i
Return: s[i]
Description: overloads the [] operator
---------------------------------------------*/
char& myString::operator[](int i)
{  return s[i];}
/*---------------------------------------------
Function: int myString::length() const
Parameters: none
Return: sLength
Description: returns the sLength field
---------------------------------------------*/
int myString::length() const
{   return sLength;}
/*---------------------------------------------
Function: const myString& myString::operator=(const myString& str)
Parameters: str
Return: *this
Description: default assignment operator
---------------------------------------------*/
const myString& myString::operator=(const myString& str)
{ if (this != &str)
  { if(s!=nullptr){
    delete [] s;
    s=nullptr;}
  sLength=str.sLength;
  s=new char[sLength];
  for(int i=0;i<sLength;i++){
  this->s[i]=str.s[i];
  }
    //Your code goes here  
  }
  return *this; }
/*---------------------------------------------
Function: const myString& myString::operator=(const char str[])
Parameters: str[]
Return: *this
Description: an assignment operator that assigns the object that called the function with a string literal str
---------------------------------------------*/
const myString& myString::operator=(const char str[])
{  if(s!=nullptr){
    delete [] s;
    s=nullptr;}
    int j=0;
    while(str[j]!='\0'){
      j++;
    }
    s=new char[j+1];
    for(int i=0;i<j;i++){
      this->s[i]=str[i];
    }
    sLength=j;
    return *this;} 
/*---------------------------------------------
Function: const myString& myString::operator=(char rhs)
Parameters: rhs
Return: *this
Description: an assignment operator that that assigns the object that called the function with a character rhs
---------------------------------------------*/
const myString& myString::operator=(char rhs)
{if(s!=nullptr){
    delete [] s;
    s=nullptr;}
    s=new char[1];
    s[0]=rhs;
    sLength=1;
    return *this;}
/*---------------------------------------------
Function: bool myString::operator==(const myString& str) const
Parameters: str
Return: bool
Description: the comparison operator
---------------------------------------------*/
bool myString::operator==(const myString& str) const
{   for(int i=0;i<sLength;i++){
    if(s[i]!=str.s[i]){
    return false;}}
if (s==nullptr&&str.s==nullptr){
  return false;}
  return true;}
/*---------------------------------------------
Function: myString myString::operator+(const myString& str) const
Parameters: str
Return: tmp
Description: will overload the + operator which will
concatenate the myString object with the str object
---------------------------------------------*/
myString myString::operator+(const myString& str) const
{ myString tmp;
  tmp.sLength=sLength+str.sLength;
  tmp.s=new char[tmp.sLength];
  for(int i=0;i<sLength;i++){
    tmp.s[i]=s[i];}
  for(int i=0;i<str.sLength;i++){
    tmp.s[i+sLength]=str.s[i];}
  return tmp;}
/*---------------------------------------------
Function: myString myString::operator+(const char rhs[]) const
Parameters: rhs[]
Return: *this+tmp
Description: will overload the + operator which will
concatenate the myString object with a string literal rhs
---------------------------------------------*/
myString myString::operator+(const char rhs[]) const
{   myString tmp(rhs);
  return *this+tmp;}
/*---------------------------------------------
Function: myString myString::operator+(char rhs) const
Parameters: rhs
Return: *this+tmp
Description: will overload the + operator which will concatenate the
myString object on the left side with a character rhs on the right side
---------------------------------------------*/
myString myString::operator+(char rhs) const
{   myString tmp(rhs);
  return *this+tmp;}
/*---------------------------------------------
Function: const myString& myString::operator+=(const myString& rhs)
Parameters: rhs
Return: *this
Description: will overload the += operator which will concatenate the myString object  on the left side 
with the rhs object on the right side and will assign the new concatenated myString to the left side object
---------------------------------------------*/
const myString& myString::operator+=(const myString& rhs)
{ *this=*this+rhs;
  return *this;}
/*---------------------------------------------
Function: const myString& myString::operator+=(const char rhs[])
Parameters: rhs[]
Return: *this
Description: will overload the += operator which will concatenate the myString object on the left side with
 the string literal rhs on the right side and will assign the new concatenated myString to the left side object
---------------------------------------------*/
const myString& myString::operator+=(const char rhs[])
{  myString tmp(rhs);
  *this+=tmp;
  return *this;}
/*---------------------------------------------
Function: const myString myString::operator+=(char rhs)
Parameters: rhs
Return: *this
Description: will overload the += operator which will concatenate the myString object on the left side 
with a character rhs on the right side and will assign the new concatenated myString to the left side object,
---------------------------------------------*/
const myString myString::operator+=(char rhs)
{  myString tmp(rhs);
  *this+=tmp;
  return *this;}
/*---------------------------------------------
Function: myString::~myString()
Parameters: none
Return: none
Description: destructor
---------------------------------------------*/
myString::~myString()
{    delete []s;
      }
/*---------------------------------------------
Function: myString operator+(const char lhs[], const myString& rhs)
Parameters: lhs[], rhs
Return: tmp+rhs
Description: will be a friend function that allows us to concatenate a string literal with a myString object
---------------------------------------------*/
myString operator+(const char lhs[], const myString& rhs)
{    myString tmp(lhs);
    return tmp+rhs;}
/*---------------------------------------------
Function: myString operator+(char lhs, const myString& rhs)
Parameters: lhs, rhs
Return: tmp+rhs
Description: will be a friend function that allows us to concatenate a character with a myString object
---------------------------------------------*/
myString operator+(char lhs, const myString& rhs)
{  myString tmp(lhs);
  return tmp+rhs;}
/*---------------------------------------------
Function: ostream& operator<<(ostream& out, const myString& str)
Parameters: out, str
Return: out 
Description:friend function that overload the << operator that will output the string using the ostream variable out
---------------------------------------------*/
ostream& operator<<(ostream& out, const myString& str)
{if(str.s!=nullptr){
  for(int i=0;i<str.sLength;i++){
    out<<str.s[i];}}
  return out;}
/*---------------------------------------------
Function: istream& operator>>(istream& in, myString& str)
Parameters: in, str
Return: in
Description: friend function that overloads the >> operator that will read in a string and assign it to str.s array
---------------------------------------------*/
istream& operator>>(istream& in, myString& str)
{myString tmp;
  char ch;
  while(in.get(ch)&&ch!='\n'){
    tmp+=ch;}
  str=tmp;
  //Your code goes here
  return in;}
