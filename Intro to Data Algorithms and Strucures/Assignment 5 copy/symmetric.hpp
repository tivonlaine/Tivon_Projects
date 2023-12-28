/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef SYMMETRIC_HPP
#define SYMMETRIC_HPP
#include <iostream>
#include "core_type.hpp"
using std::cout, std::endl;
enum symmetric_geometry { sphere, lightbulb, oval, other };
class symmetric_core : public core_type {
 private:
  bool axis;
  symmetric_geometry shape;
 public:
  symmetric_core(std::string, float, float, float, bool, symmetric_geometry);
  string axis_to_string() const;
  ~symmetric_core();
    void compute_differential(const float*) override;
    string geometry_to_string() const override;
    void print() const override;};
string symmetric_core::axis_to_string() const {
  if (axis) return "Ball is axisymmetric ";
  return "Ball is non-axisymmetric";}
 symmetric_core::symmetric_core(std::string a, float b, float c, 
 float d, bool e, symmetric_geometry f):core_type(a,b,c,d){
     differential=0;   //HELP
     this->axis=e;
     this->shape=f;                                                   }
symmetric_core::~symmetric_core(){}
/* YOUR CODE HERE - 2 more function definitions (6 total) */
/**
 * @brief
 *  Provides a description of a symmetric bowling ball
 */
void symmetric_core::print() const {
  cout << "Symmetric bowling ball statistics" << endl
       << "\tName: " << get_name() << endl
       << "\tPancake weight: " << get_pancake_mass() << endl
       << "\tCore shape:  " << geometry_to_string() << endl
       << "\tCore weight: " << get_mass() << " lbs" << endl
       << "\tSymmetry: " << axis_to_string() << endl
       << "\tRadius of Gyration: " << rg << endl
       << "\tDifferential: " << differential << endl;}
string symmetric_core::geometry_to_string() const {
  switch(shape){                         //HELP
    case 0:
    return "Sphere";
    break;
    case 1:
    return "Lightbulb";
    break;
    case 2:
    return "Oval";
    break;
    case 3:
    return "Other";}}
void symmetric_core::compute_differential(const float* drill_layout) {
  const float PTVR = 0.3f,  // Pin to VAL ratio
      OFFSET_MAX = 6,       // Maximum length from PaP
      DIFF_MAX = 0.6f;      // Maximum differential of a symmetric ball
  float PTP = DIFF_MAX - (DIFF_MAX * PTVR);        // Pin to PaP value
  float PTV = DIFF_MAX - (DIFF_MAX * (1 - PTVR));  // Pin to VAL value
  PTP *= *drill_layout;
  PTP = PTP/OFFSET_MAX;
  if (*(drill_layout + 2) != 0) {
    PTV = PTV * (1 - (*(drill_layout + 2) / OFFSET_MAX));}
  differential = PTP + PTV;}
#endif  // SYMMETRIC_HPP