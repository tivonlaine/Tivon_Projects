/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef PERFORMANCE_HPP
#define PERFORMANCE_HPP
#include "coverstock_type.hpp"
enum density { soft, medium, hard };
class performance : public coverstock_type {
 private:
  density hardness;
 protected:
  virtual float compute_oil_absorption_rate();
 public:
  performance(string, float, int, density);
  string hardness_to_string() const; 
  virtual ~performance(){};};
performance::performance(string name, float mass, int grit, density hardness)
    : coverstock_type(name, mass, grit) {
  this->hardness=hardness;
  this->set_oil_absorption_rate(compute_oil_absorption_rate());}    //getting the oil absorption rate
string performance::hardness_to_string() const {
  switch(hardness){
    case 0:
    return "Soft";                //returning a string
    break;
    case 1:
    return "Medium";
    break;
    case 2:
    return "Hard";}}
float performance::compute_oil_absorption_rate() {
  switch(hardness){
    case 0:
    return 1.5;
    break;                        //returning the oil absorption rate
    case 1:
    return 1;
    break;  
    case 2:
    return 0.8;}}
#endif // PERFORMANCE_HPP