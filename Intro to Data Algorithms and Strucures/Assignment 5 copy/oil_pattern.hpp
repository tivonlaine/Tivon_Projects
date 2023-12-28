/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef OIL_PATTERN_H
#define OIL_PATTERN_H
#include <iomanip>
using std::setw, std::setprecision, std::fixed;
enum layout_ids { cheetah, scorpion, shark };
/* Possible oil layouts */
const int BOARD_SEGMENTS = 12;
const float CHEETAH_PATTERN[BOARD_SEGMENTS] = 
  {1, .95f, .9f, .85f, .8f, .7f, 0.5f, 0, 0, 0, 0 , 0};
const float SCORPION_PATTERN[BOARD_SEGMENTS] = 
  {1, 1, .9f, .8f, .8f, .7f, 0.6f, .5f, .3f, 0, 0, 0};
const float SHARK_PATTERN[BOARD_SEGMENTS] = 
  {1, 1, .8f, .7f, .68f, .65f, 0.6f, .52f, .5f, .4f, 0, 0};
class oil_pattern {
 private:
  string name;
  layout_ids layout; 
  float* oil_volume_segments;
 public:
  oil_pattern(layout_ids);
  float* get_oil_volume_segments() { return oil_volume_segments; }  //getting the oil volume segments
  void copy_oil_volume_segments();
  string layout_to_string();
  void print();
  ~oil_pattern();};
oil_pattern::oil_pattern(layout_ids layout) {
  this->layout = layout;      //making the private layout equal to the layout
  name = layout_to_string();  
  oil_volume_segments = new float[BOARD_SEGMENTS];  //allocating an array of oil volume segments
  copy_oil_volume_segments();}
string oil_pattern::layout_to_string() { 
  switch(layout){
    case 0:
    return "Cheetah";                 //returning a string
    break;
    case 1:
    return "Scorpion";
    break;
    case 2:
    return "Shark";}}
void oil_pattern::copy_oil_volume_segments() { 
  switch(layout){
    case 0:
    for(int i =0 ; i<BOARD_SEGMENTS ; i++){
    oil_volume_segments[i]=CHEETAH_PATTERN[i]; }
    break;
    case 1:
    for(int i =0 ; i<BOARD_SEGMENTS ; i++){                     //returning the oil volume segments
    oil_volume_segments[i]=SCORPION_PATTERN[i];}
    break;
    case 2:
    for(int i =0 ; i<BOARD_SEGMENTS ; i++){
    oil_volume_segments[i]=SHARK_PATTERN[i];}}}
void oil_pattern::print() {
  cout << setprecision(4) << setw(8) << "Current pattern: ";
  for (int i = 0; i < BOARD_SEGMENTS; i++)
    if(i < 11) {
        cout << setw(5) << *(oil_volume_segments + i) << ",";}else {
    cout << setw(5) << *(oil_volume_segments + i); }cout << "\n";}
oil_pattern::~oil_pattern() { 
  delete [] oil_volume_segments;}   //deallocating oil volume segments
#endif // OIL_PATTERN_H
