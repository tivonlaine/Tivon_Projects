/*
Name: Tivon Laine, 2002167255, Section 1002, Assignment 5
Description: Making a bowling simulation
Input: Bowling ball features
Output: Bowling ball strike probability
*/
#ifndef LANE_TYPE_H
#define LANE_TYPE_H
#include "bowling_ball.hpp"
#include "oil_pattern.hpp"
class lane_type {
 private:
  oil_pattern* pattern;
 public:
  lane_type(layout_ids);
  float compute_board_track(bowling_ball*, bool) const;
  void transition_oil(bowling_ball*, bool);
  void print() const;
  ~lane_type();};
lane_type::lane_type(layout_ids layout) { pattern = new oil_pattern(layout); }
void lane_type::print() const { pattern->print(); }
lane_type::~lane_type() { 
  delete pattern; }
float lane_type::compute_board_track(bowling_ball* ball, bool debug) const {
  cout << fixed << setprecision(2);
  const float OIL_BOARDS_PER_SEGMENT = -2.f;
  const float HOOK_BOARDS_PER_SEGMENT = 2.5f;
  float hook_potential = ball->get_hook_potential();        //getting the hook potential
  float* oil_volume_segments = pattern->get_oil_volume_segments();      //getting the oil volume segments
  float current_board = 20.f;  
  float glide_transition, hook_transition;
  for (int i = 0; i < BOARD_SEGMENTS; i++) {
    if (debug) cout << "Current Board: " << current_board << endl;
    float oil=OIL_BOARDS_PER_SEGMENT* (oil_volume_segments[i]);   //calculating the oil
    float friction=(1-oil_volume_segments[i])*HOOK_BOARDS_PER_SEGMENT*hook_potential; //calculating the friction
    current_board+=friction+oil;}
  if (debug) cout << "Final Board:   " << current_board << endl << endl;
  return current_board;}
void lane_type::transition_oil(bowling_ball* ball, bool debug) {
  const float MAX_OIL_ABSORBED = 0.03f;
  const float MAX_OIL_DISSIPATED = 0.01f;
  float oil_volume = 0.f;
  float oil_absorbed = 0.f;
  float oil_absorption_rate = ball->get_coverstock_type()->get_oil_absorption_rate();  //getting the oil absorption
  float* oil_volume_segments = pattern->get_oil_volume_segments();      
  cout << fixed << setprecision(3);
  for (int i = 0; i < BOARD_SEGMENTS; i++) {
    if(oil_volume_segments[i]>0){    
    oil_volume=oil_volume_segments[i]*MAX_OIL_ABSORBED*oil_absorption_rate;   //calculating the volume of the oil
    oil_volume_segments[i]-=oil_volume;
    oil_absorbed+=oil_volume;}
    if(oil_absorbed>0){
    float ans=MAX_OIL_DISSIPATED*oil_absorbed;
      oil_absorbed-=ans;
      oil_volume_segments[i]+=ans;}}
  if (debug) pattern->print();}
#endif  // LANE_TYPE_H
