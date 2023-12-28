/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef COVERSTOCK_HPP
#define COVERSTOCK_HPP
#include <iostream>
#include <string>
using std::cout, std::endl;
using std::string;
class coverstock_type {
 private:
  string name;
  float mass;
  int grit;
  float oil_absorption_rate;
 protected:
  void set_oil_absorption_rate(float);
 public:
  static const int GRIT_BASE = 500;
  coverstock_type(string , float , int );
  /* Getter functions don't need a virtual classification */
  string  get_name()  const { return name; }
  float   get_mass()  const { return mass; }
  int     get_grit()  const { return grit; }
  float   get_oil_absorption_rate() const { return oil_absorption_rate; }
  void set_grit(int);
  virtual void print() const=0;
  virtual ~coverstock_type(){};};
coverstock_type::coverstock_type(string name, float mass, int grit) {
    this->name=name;
    this->mass=mass;
    this->grit=grit;}
void coverstock_type::set_oil_absorption_rate(float oil_absorption_rate) {
  this->oil_absorption_rate = oil_absorption_rate;}
void coverstock_type::set_grit(int grit) {
  string lesser_grit = "!Error:\tCannot sand to a grit lower than 500";
  string greater_grit = "!Error:\tCannot polish to a grit higher than 4000";
  string sanding = "Sanding the coverstock to a lower grain";
  string polishing = "Polishing the coverstock to a finer grain";
  if(grit<500){
    cout<<lesser_grit<<endl;
    exit(1);}                     //Checking the grit amount
  else if(grit>4000){
    cout<<greater_grit<<endl;
    exit (1);}                        //Checking if it needs to be polished or sanded
  if(this->grit<grit){
    cout<<sanding<<endl;}
  else if(this->grit>grit){
    cout<<polishing<<endl;}
  this->grit=grit;}           //setting private grit to grit
#endif  // COVERSTOCK_HPP