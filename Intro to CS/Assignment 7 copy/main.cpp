/*
Name: Tivon Laine, 2002167255, 1002, Assignment 7
Description: Using functions to read from a file and output selections
Input: Filename and number
Output: One of the options
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

    /* DO NOT CHANGE ANYTHING IN THE PROTOTYPES
       CHANGING ANYTHIN IN THE THESE WILL 
       RESULT IN RECEIVING A SCORE OF ZERO
       FOR THIS ASSIGNMENT
    */

// function prototypes
void showMenu();
// fills the arrays with data from files
bool readIntoArrays(string filename, string items[],double retails[],
double costs[], int quantities[], int size);
// returns the most popular item in terms of sale quantity
string mostPopularItem(string items[], int quantities[], int size);
// returns the item that has the highest profit margin
// profit = retail - cost
string mostProfitablItem(string items[],double retails[], 
double costs[], int size);
// shows all items on the screen, check assignment document for spacing
void showItems(string items[],double retails[],double costs[], 
int quantities[], int size);
// returns the item that generated the most profit
// generated profit = (retail - cost) * quantity sold
string generatedMostProfit(string items[],double retails[],
double costs[], int quantities[], int size);

int main(int argc , char * argv[]){

   /*
   make sure to handle the no argument and
   too many arguments cases here. Terminate
   the application when those are detected. 
   */ 
    if (argc < 2){
        cout << "Must enter data file name!";
        return 0;
    }
    if (argc > 2){
        cout << "Too many arguments!";
        return 0;
    }
    string filename = argv[1]/* get it from the command line arguments*/;
    const int size = 10 ; 
    // parallel arrays to store data
    string items[size]={""};
    double retails[size]={0.0};
    double costs[size]={0.0};
    int quantities[size]={0};
    // trying to read data into arrays
    bool fileOpenend = readIntoArrays(filename, items,retails,costs, 
    quantities,size);
    /* use the bool above to terminate the application
     if the file was not opened. */
     if(!fileOpenend){
        cout << "File can not be found!\nCheck filename and try again!";
        return 0;
     }
    
    cout<<"Openning "<<filename<<endl;
    int choice = 0;
    bool flag = false;
    cout<<"--- Welcome to the sales data analyzer ---\n";

    /* DO NOT CHANGE ANYTHING IN THIS LOOP
       CHANGING ANYTHIN IN THE LOOP WILL 
       RESULT IN RECEIVING A SCORE OF ZERO
       FOR THIS ASSIGNMENT
    */
    do{
        if (flag){
            cin.clear();
            cin.ignore(100,'\n');
            flag = false;
        }
        showMenu();
        cout<<"Select from the menu above:\n";
        cin>>choice;
        if(cin.fail() || choice < 1 || choice >5){
            cout<<"Invalid selection!\n";
            flag = true;
            continue;
        }
        switch (choice)
        {
        case 1:
        showItems(items, retails, costs, quantities, size);
        break;
        case 2:
        cout<<"Most popular item is: "
        <<mostPopularItem(items,quantities,size)<<endl;
        break;
        case 3:
        cout<<"The with highest profit margin is: "<<
        mostProfitablItem(items,retails,costs,size)<<endl;
        break;
        case 4:
        cout<<"The item that generated most profit is: "
        <<generatedMostProfit(items,retails,costs,quantities,size)
        <<endl;
        break;
        case 5: 
        cout<<"--- Thank you for using the sales data analyzer! ---\n";
        return 0;
        }
    }while(cin.fail()|| choice !=5);
    
    
    return 0;
}
// Implement the functions here
void showMenu(){
    cout<<"1. Show all items.\n";
    cout<<"2. Show most popular item.\n";
    cout<<"3. Show item with highest profit margin.\n";
    cout<<"4. Show item that generated most profit.\n";
    cout<<"5. Exit.\n";

}
void showItems(string items[],double retails[],double costs[], 
int quantities[], int size){
    cout<<left<<setw(25)<<"Item";
    cout<<setw(16)<<"Retail";
    cout<<setw(16)<<"Cost";
    cout<<"Quantity"<<endl;
    for(int i=0;i<size;i++){
        cout<<left<<setw(25)<<items[i]<<"$";
        cout<<setw(15)<<retails[i]<<"$";
        cout<<setw(15)<<costs[i]<<quantities[i]<<endl;
    }cout<<endl;
}
bool readIntoArrays(string filename, string items[],double retails[],
double costs[], int quantities[], int size){
    ifstream input;
    input.open(filename);
    string line;
    int count=0;

if(input.is_open()){
    getline(input, line);  //getting first line of file
   while(!input.eof()){
    getline(input, line, ',');  //getting item
    items[count]=line;
    getline(input, line, ',');  //getting retail price
    retails[count]=stod(line);
    getline(input, line, ',');  //getting cost
    costs[count]=stod(line);
    getline(input, line);  //getting quantities sold
    quantities[count]=stoi(line);
    count++;//going through every line of file
   }
   return true;
}else{
    return false;
}
}//getting the most popular item
string mostPopularItem(string items[], int quantities[], int size){
 int pop=0;
for(int i=0;i<size;i++){
    if(quantities[pop]<quantities[i]){
        pop=i;
    }
}return items[pop];//returning the most popular item



} //getting the most profitable item
string mostProfitablItem(string items[],double retails[], 
double costs[], int size){
 int pop=0;
 int c=0;
for(int i=0;i<size;i++){
    double rc=retails[i]-costs[i];
    if(pop<rc){
        c=i;
        pop=rc;
    }
}return items[c];//returning the most profitable item
}

string generatedMostProfit(string items[],double retails[],
double costs[], int quantities[], int size){//getting item w/ most profit
double q=quantities[0];//getting quantities at first index
double rc=(retails[0]-costs[0]);//calculating profit
double total=q*rc;//multiplying profit by quantities
int count=0;
for(int i=0;i<size;i++){//linear search
    double quan=quantities[i];
    double dif=(retails[i]-costs[i]);
    double tot=quan*dif;
    if(total<tot){
        total=tot;
        count=i;
    }
}
return items[count];//returning the most profitable item
}
