/*
Name:Tivon Laine, 2002167255, Assignment 1
Description: Encrypting and Decrypting
Input: File name, shift key
Output: Deciphered files
*/
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <string>
using std::getline;
using std::string;

struct scheme_parameters {
  static const int stages = 3;
  int rotate[stages] = {22, 4, 40};
  int offset[stages] = {2, 4, 8};
};

/**
 * @brief 
 *
 * @param 
 * @param 
 * @return 
 * 
 * @details
 * If you write this function correctly, it should
 * only be 4 lines of code within the function.
 */
string offset(string message, int offset) {
  //for loop using arthemetic
  string after="";
  for(int i=0; i<message.length();i++){
    char a=message[i];
    a=(a+offset) % 128;
    after +=a;
  }
  return after;
}

/**
 * @brief Demonstrates the efficacy of the offset function
 */
void offset_encryption() {
  int s = 5;
  string message = "The orange cat, sleeping quietly, awoke.";
  string encry=offset(message,s);
cout<<"Text : "<<message<<"\n"<<endl;
cout<<"Cipher : "<<encry<<"\n"<<endl;
cout<<"Decipher : "<<offset(encry,-s)<<"\n"<<endl;
}

/**
 * @brief 
 *
 * @param  
 * @return ifstream
 */
ifstream _open_input_file(string name) {
    ifstream input;
    input.open(name);
    if(!input){
      cout<<"ERROR: Could not open file : "<<name<<endl;
    exit(-1);
    }
    return input;
}

/**
 * @brief 
 *
 * @param argc main function formal parameter
 * @param argv main function formal parameter
 * @return ifstream
 */
ifstream open_argv_file(int argc, const char** argv) {
  string name;
  if(argc!=2){
    cout<<"\nERROR: Incorrect usage!"<<endl;
    cout<<"./a.out <filename>"<<endl;
    exit(-1);
  }
  else{
    name=argv[1];
    return _open_input_file(name);

  }
}

/**
 * @brief 
 * 
 * @return ifstream
 */
ifstream open_input_file() {
  string name;
  cout<<"Please enter the name of your input file: "<<endl;
  cin>>name;
  return _open_input_file(name);
}

/**
 * @brief 
 *
 * @param 
 * @return ifstream
 */
ofstream _open_output_file(string file_name) {
  ofstream output;
  output.open(file_name);
  if(!output){
    cout<<"ERROR: Could not open file"<<file_name<<endl;
    exit(-1);
  } 
  return output;
}

/**
 * @brief 
 * 
 * @return ofstream
 */
ofstream open_output_file() {
  string name;
  cout<<"\nPlease enter the name of your output file: "<<endl;
  cin>>name;
  return _open_output_file(name);
}

/**
 * @brief Demonstrate the efficacy of the following functions
 *  open_input_file
 *  open_output_file
 *  offset
 *
 * @param output ofstream output file id
 * @param input ifstream input file id
 */
void sequential_file_encryption(ofstream output, ifstream input) {
  int offset_value;
  string input_stream;
  string reader="";

  cout << "What is your shift key? ";
  cin >> offset_value;
  while(getline(input,reader)){
    output<<offset(reader, offset_value)<<endl;
  }
  input.close();
  output.close();
}

/**
 * @brief 
 *
 * @param 
 * @param 
 * @return string
 *
 * @details
 * 
 *  Remember, no:
 *  1) Use of modulus or division operations within looping constructs
 *  2) Rotations greater than the length of the array must be reduced
 *  3) multiple iterations over the same elements of either array
 *  4) No built in functions other than length
 * 
 *  Engaging in any subset of these restrictions will result in 0 points
 */
string rotate(string message, int offset) {
  string after="";
  offset=offset*-1;
  if(offset<0){
    //offset*=-1;
    for(int i=message.length()+offset;i<message.length();i++){
      after+=message[i];
    }for(int i=0; i<message.length()+offset;i++){
       after+=message[i];
    }
    }else{
      for(int i=offset; i<message.length();i++){
       after+=message[i];
    }for(int i=0;i<offset;i++){
      after+=message[i];
    }
    }
  return after;
}
/**
 * @brief 
 * 
 * @return string
 */
string rotation_encryption(string message) {
  scheme_parameters es;
  char scheme;

  cout << "Are you encrypting(E) or decrypting(D)? ";
  cin >> scheme;
  int turnover=-1;

  if (scheme == 'E' || scheme == 'e') {
    for(int i=0;i<es.stages;i++){
      message= rotate(message,es.rotate[i]);
      message = offset(message, es.offset[i]);
    }
  } else if (scheme == 'D' || scheme == 'd') {
    for(int i=0;i<es.stages;i++){
      message= offset(message,turnover*es.offset[i]);
      message = rotate(message, turnover*es.rotate[i]);
    }
    
  } else {
    cerr << "ERROR: Encryption scheme unrecognized!" << endl;
  }
  return message;
}

/**
 * @brief Function to retrieve the password that unlocks
 * the second part of this assignment
 */
void rotation_file_encryption() {
  string message;
  ofstream output;
  ifstream input = open_input_file();
  getline(input, message);
  output.open("message.txt");
  output<<rotation_encryption(message);
}

int main(int argc, char const** argv) {


 offset_encryption();

sequential_file_encryption(open_output_file(),open_argv_file(argc, argv)
);   


  rotation_file_encryption();

  return 0;
}
