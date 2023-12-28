/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef URETHANE_HPP
#define URETHANE_HPP
#include "performance.hpp"
class urethane : public performance {
 private:
  const float URETHANE_BASE_RATE = 0.8f;
 public:
  urethane(string, float, int, density);
  float compute_oil_absorption_rate();
  void print() const;
  ~urethane(){};};
urethane::urethane(string name, float mass, int grit, density hardness)
    : performance(name, mass, grit, hardness) {
      set_oil_absorption_rate(compute_oil_absorption_rate());}
float urethane::compute_oil_absorption_rate() {
  float ans=URETHANE_BASE_RATE*performance::compute_oil_absorption_rate()/2;
  return ans;
/*(URETHANE_BASE_RATE/get_grit())*performance::compute_oil_absorption_rate();*/}
void urethane::print() const {
  cout << "Urethane Coverstock statistics" << endl
       << "\tName: "                << this->get_name() << endl 
       << "\tCoverstock Type:     " << this->hardness_to_string() << endl
       << "\tCoverstock Grit:     " << this->get_grit() << " grit" << endl
       << "\tOil absorption Rate: " << this->get_oil_absorption_rate() << endl;}
#endif // URETHANE_HPP
