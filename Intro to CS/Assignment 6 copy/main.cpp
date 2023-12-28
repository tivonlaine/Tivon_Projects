#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main(){
ifstream input1;
ofstream output;
string cur;
const int size=100;
do{
    cout<<"Enter currency conversion file: \n";
    cin>>cur;
    input1.open(cur);
    if(!input1){
        cout<<"Invalid filename\n";
        cin.clear();
        cin.ignore(100, '\n');
    }
}
while(!input1);
string currencycodes[size];
double exchangerates[size];
int counter1=0;
int n1=0;
string line1;
while(!input1.eof()){
    getline(input1, line1, ',');
    getline(input1, line1, '\n');
    currencycodes[counter1]=line1;
    n1=stod(line1);
    exchangerates[counter1]=n1;
    counter1++;
}


ifstream input2;
string airport;
do{
    cout<<"Enter airport codes file: \n";
    cin>>airport;
    input2.open(airport);
    if(!input2){
        cout<<"Invalid filename\n";
        cin.clear();
        cin.ignore(100, '\n');
    }
}while(!input2);
string airport[size][2];
ifstream input3;
string transactions;
do{
    cout<<"Enter transactions file: \n";
    cin>>transactions;
    input3.open(transactions);
    if(!input3){
        cout<<"Invalid filename\n";
        cin.clear();
        cin.ignore(100, '\n');
    }
}while(!input3);
output.open("output.csv");
int trans=0;
string line;

}
