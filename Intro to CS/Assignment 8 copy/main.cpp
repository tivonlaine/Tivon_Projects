/*
Name: Tivon Laine, 2002167255, 1002, Assignment 8
Description: Using structs to mimic an atm
Input: Account number and pin
Output: One of the options
*/
#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;
struct Transactions
{   string type; int amount;};struct Account{int accnum;  int pin;  
double balance; vector<Transactions> numb;};int main()
//all accounts
{ Account b1; b1.accnum = 111000; b1.pin = 123456;b1.balance = 65938.91;
 Account b2; b2.accnum = 111001; b2.pin = 123456; b2.balance = 100.53;
   Account b3; b3.accnum = 111002; b3.pin = 123456; b3.balance = 25.13;
 Account b4;b4.accnum = 111003; b4.pin = 123456; b4.balance = 100983.11;
 Account b5; b5.accnum = 111004;b5.pin = 123456; b5.balance = 83764.17;
  Account banks[5] = {b1, b2, b3, b4, b5};//banks array
cout << "\n-------- Welcome to the Banking Application --------" << endl;
  cout << endl;  int in = 0; const int size = 5;  int user = -1;
 bool s = true, d = true; bool con = true; int pin = 0; int attempt = 0;
 int option = 0; double wit = 0;
    char letter = ' ';
    double dep = 0;
do { do{ do  {if (s == true){
                    cout << "Enter account number or -1 to exit:\n";
s = false; }else  {  cout << "Enter account number:\n"; } cin >> in;
if (in == -1)  {cout << "Thank you!";return 0;}
string num = to_string(in)/*converting int to string*/;if ((num.size() 
!= 6) || cin.fail()){//input failure
cout << "Account number must consist of 6 digits\n";cin.clear();
cin.ignore(100, '\n');in = -3;}} while (in == -3);
for (int i = 0; i < size; i++){if (in == banks[i].accnum){
user = i;d = true;}}
if (user == -1) {//if account number is invalid
                cout << "Incorrect account number!\n";
                cout << "Try again or enter -1 to exit\n";
                in = -1;
                s = true;
                d = false; } } while (d == false);
        do{
            cout << "Enter pin:\n";
            cin >> pin;
            if (cin.fail()){//if letter are entered
                cout << "Pin should contain numbers only\n";
                pin = 0;
                cin.clear();
            cin.ignore(100, '\n');}
            else if (pin != banks[user].pin){//if pin is incorrect
                cout << "Incorrect pin\n";
                pin = 0;
                attempt++;}
            if (attempt == 3){//maximum three attempts
     cout << "You have exceeded the number of allowed pin attempts\n"
                     << "See a banker to complete your transaction\n"
                     << "Thank you!";
                return 0;}
        } while (pin == 0);//while pin is not valid
        cout << "Select from menu:\n"
             << "1. Withdraw.\n"
             << "2. Deposit.\n"
             << "3. Show balance.\n"
             << "4. Show transactions.\n"
             << "5. Cancel.";
        cin >> option;
        if (option == 1) {//withdrawal option
     cout << "\nEnter amount to withdraw:\n$ ";
            cin >> wit;
     if (wit <= banks[user].balance){//withdrawal is less than balance
    banks[user].balance = banks[user].balance-wit;//getting new balance
                Transactions tra;
tra.amount = wit;//getting the amount for transaction struct
tra.type = "Withdrawal";//getting the type of transaction for the struct
//putting the transaction at the end of the list
 banks[user].numb.push_back(tra);
                cout << "New balance: $" << banks[user].balance;
}else{cout << "Insufficient balance!\n"
                     << "Transaction cancelled.";}}
        else if (option == 2)//deposit option
        {cout << "\nEnter amount to deposit:\n$ ";
        cin >> dep;
    banks[user].balance = banks[user].balance + dep;//adding to balance
            Transactions acc;
            acc.amount = dep;
            acc.type = "Deposit";
            banks[user].numb.push_back(acc);
            cout << "New balance: $" << banks[user].balance;
        }else if (option == 3)/*showing current balance*/{ 
cout<<"\nCurrent balance: $"<<fixed<<setprecision(2)
<<banks[user].balance;
        }else if (option == 4)
        {if(banks[user].numb.size() == 0)//if there were no transactions
            {cout << "\nNo recent transactions found";}else{
//while i is less than the number of transactions
for (unsigned int i = 0; i < banks[user].numb.size(); i++){
cout << i + 1<< "- Type: "<< 
/*the type of transaction*/banks[user].numb[i].type << ", Amount: $"<<
fixed<<setprecision(2)<< 
/*transaction amount*/banks[user].numb[i].amount << endl;}}}
cout << "\nWould you like another transaction? (y/n)\n";cin >> letter;
 if (letter == 'y')
{ con = true;/*flag to redo the application again */s = true;}else
 {cout << "Thank you!";return 0;break;} } while (con == true);
}
