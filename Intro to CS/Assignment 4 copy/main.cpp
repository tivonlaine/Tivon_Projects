/*
Name: Tivon Laine, 2002167255, 1002, Assignment 4
Description: Calculating the cost for staying at the Krusty Towers
Input: Cost to rent a room, number of rooms booked, number of days
Output: Costs, discounts and taxes in a neat table
*/
#include<iostream>
#include<iomanip>//to organize the prices neatly
using namespace std;
int main(){
char letter=' ';//letter to continue or quit program

do{//contains the entire program
    double n1=0;//cost for a room
do{
    cout<<"Cost to rent a room: ";
    cin>>n1;
    if(cin.fail()||n1<1||n1>199.99){//fail condition
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Input failure, can't be processed! :(\n";
       
    }


}while(cin.fail()||n1<1||n1>199.99);

double n2=0;//number of rooms
do{
    cout<<"Number of rooms booked: ";
    cin>>n2;
    if(cin.fail()||n2<1||n2>300){//fail condition
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Input failure, can't be processed! :(\n";
       
    }


}while(cin.fail()||n2<1||n2>300);

double n3=0;//number of days
do{
    cout<<"Number of days: ";
    cin>>n3;
    if(cin.fail()||n3<1||n3>90){//fail condition
        cin.clear();
        cin.ignore(100, '\n');
        cout<<"Input failure, can't be processed! :(\n";
       
    }


}while(cin.fail()||n3<1||n3>90);
cout<<endl;
double total = n1*n2*n3;//equation to get total price
double discount1 = 0;//discount from number of rooms booked
double discount2 = 0;//discount from number of days stayed
const double tax = .0815;//tax rate
const double ten = .10;
const double twenty = .20;
const double thirty = .30;
if(n2>=10 && n2<20){//between 10 and 19
    discount1=total*ten;//10% discount
}
else if(n2>=20 && n2<30){//between 20 and 29
    discount1=total*twenty;//20% discount
}
else if(n2>=30){//greater than 30
    discount1=total*thirty;//30% discount
}
if(n3>=3){//greater than 3 days
    discount2=total*.05;//5% discount
}
double discount=discount1+discount2;//total discount amount
double disprice=total-discount;//discounted price/price after discount
double final=disprice+(disprice*tax);//the final cost
cout<<"Total cost"<<setfill('.')<<setw(31)<<"$"<<setfill(' ')
<<setw(10)<<fixed<<setprecision(2)<<total;
cout<<"\nDiscounts"<<setfill('.')<<setw(32)<<"$"<<setfill(' ')<<setw(10)
<<fixed<<setprecision(2)<<discount;
cout<<"\nCost after discount"<<setfill('.')<<setw(22)<<"$"<<setfill(' ')
<<setw(10)<<fixed<<setprecision(2)<<disprice;
cout<<"\nTaxes"<<setfill('.')<<setw(36)<<"$"
<<setfill(' ')<<setw(10)<<fixed<<setprecision(2)<<disprice*tax;
cout<<"\nFinal cost"<<setfill('.')<<setw(31)<<"$"<<setfill(' ')<<setw(10)
<<fixed<<setprecision(2)<<final;
cout<<endl;
cout<<"\nEnjoy your stay! :)\n";
cout<<endl;
cout<<"Do you wish to continue or quit? ";
cin>>letter;//inputting a C or Q
if(letter=='q'||letter=='Q'){//whether user wants to continute or not
    cout<<"Until next time, try and have a great day! :)";
}}while(letter=='c'||letter=='C');//rerunning program if C key is hit
}

