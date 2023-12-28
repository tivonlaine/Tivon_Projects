/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef ASYMMETRIC_HPP
#define ASYMMETRIC_HPP
#include <iostream>
#include "core_type.hpp"
using std::cout, std::endl;
enum asymmetric_geometry { triangle, rectangle, polygon };
class asymmetric_core : public core_type {
 private:
  asymmetric_geometry shape;
  float intermediate_differential;
 public:
  asymmetric_core(string, float, float, float, asymmetric_geometry);
  void compute_intermediate_differential();
  ~asymmetric_core();
  void compute_differential(const float*) override;
    string geometry_to_string() const override;
    void print() const override;};
  asymmetric_core::asymmetric_core(string a, float b, float c, 
  float d, asymmetric_geometry e):core_type(a, b, c, d){
    differential = 0;
    intermediate_differential=0;
    this->shape=e;
    compute_intermediate_differential();}  asymmetric_core::~asymmetric_core(){}
 void asymmetric_core::compute_intermediate_differential(){
    switch(shape){
      case 0:
      intermediate_differential+=0.05;
      break;
      case 1:
      intermediate_differential+=.1;
      break;
      case 2:
      intermediate_differential+=.2; } }
/**
 * @brief
 *  Provides a description of a symmetric bowling ball
 */
void asymmetric_core::print() const {
  cout << "Asymmetric bowling ball statistics" << endl
       << "\tName: " << get_name() << endl
       << "\tPancake weight: " << get_pancake_mass() << endl
       << "\tCore shape:  " << geometry_to_string() << endl
       << "\tCore weight: " << get_mass() << " lbs" << endl
       << "\tRadius of Gyration: " << rg << endl
       << "\tDifferential: " << differential << endl
       << "\tIntermediate Differential: " << intermediate_differential << endl;}
string asymmetric_core::geometry_to_string() const {
  switch(shape){
  case 0:
  return "Triangle";
  break;
  case 1:
  return "Rectangle";
  break;
  case 2:
  return "Polygon"; }}
void asymmetric_core::compute_differential(const float* drill_layout) {
  const float PTVR = 0.3f,  // Pin to VAL ratio
      OFFSET_MAX = 6,       // Maximum length from PaP
      DIFF_MAX = 0.6f;      // Maximum differential of a symmetric ball
  float PTP = DIFF_MAX - (DIFF_MAX * PTVR);        // Pin to PaP value
  float PTV = DIFF_MAX - (DIFF_MAX * (1 - PTVR));  // Pin to VAL value
  PTP *= *drill_layout;
  PTP = PTP/OFFSET_MAX+intermediate_differential;
  if (*(drill_layout + 2) != 0) {
    PTV = PTV * (1 - (*(drill_layout + 2) / OFFSET_MAX));}
  differential = PTP + PTV;}
#endif  // ASYMMETRIC_HPP