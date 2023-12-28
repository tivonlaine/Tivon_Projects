/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#include "performance.hpp"
enum material { solid, pearl, hybrid };
class reactive : public performance {   //derived from the parents class
 private:
  const float REACTIVE_BASE_RATE = 0.7f;
  material compound;   
 public:
  reactive(string, float, int, density, material); 
  string material_to_string() const; 
  float compute_oil_absorption_rate(); 
  void print() const; 
  ~reactive(){}; };
reactive::reactive(string name, float mass, int grit, density hardness, material compound)
    : performance(name, mass, grit, hardness) {
  this->compound=compound;      //making the private compound equal to the one in the constructor
  this->set_oil_absorption_rate(compute_oil_absorption_rate());}    //calculating the oil absorption rate
string reactive::material_to_string() const {
  switch(compound){
    case 0:
    return "Solid";
    break;                  //returning a string
    case 1:
    return "Pearl";
    break;
    case 2:
    return "Hybrid";}}
float reactive::compute_oil_absorption_rate() {
  float rate=0;
  switch(compound){
    case 0: 
    rate=0.65;
    break;              //getting the rate
    case 1:
    rate=0.9;
    break;
    case 2:
    rate=0.7;}
  return REACTIVE_BASE_RATE*rate*performance::compute_oil_absorption_rate();}   //returning the absorption rate
void reactive::print() const {
  cout << "Performance Coverstock statistics" << endl
       << "\tName: "                << this->get_name() << endl 
       << "\tCoverstock Type:     " << this->hardness_to_string() 
       << " "                       << this->material_to_string() << endl
       << "\tCoverstock Grit:     " << this->get_grit() << " grit" << endl
       << "\tOil absorption Rate: " << this->get_oil_absorption_rate() << endl;}