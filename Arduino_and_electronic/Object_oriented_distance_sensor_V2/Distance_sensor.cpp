#include "Distance_sensor.h"
#include <arduino.h>

//*** ATTRIBUTS ***
const int numReadings = 10;

//*** CONSTRUCTOR ***
Distance_sensor::Distance_sensor (int pin_trig, int pin_echo, int maxDistance) {
  this -> pin_trig = pin_trig;
  this -> pin_echo = pin_echo;
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  this -> maxDistance = maxDistance;
}
  
//*** FUNCTIONS ***

uint32_t Distance_sensor::get_distance_measurement(){
  uint32_t old_measured_distance = measured_distance;
  // Clears the trigPin
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);
  // Sets the pin_trig on HIGH state for 10 micro seconds
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  sound_journey_duration = pulseIn(pin_echo, HIGH);
  // Calculating the distance
  measured_distance = sound_journey_duration*0.034/2;
  // Prints the distance on the Serial Monitor

  if (measured_distance > maxDistance){
    //measured_distance = 800;
    return(800);
  }else if (measured_distance < 1){
    measured_distance = old_measured_distance;
  }//else{
    measured_distance = this -> compute_sliding_mean(measured_distance); 
    if (measured_distance > maxDistance){
      measured_distance = 800;
    }else if (measured_distance < 1){
      measured_distance = old_measured_distance;
    }  
  //}
  return(measured_distance);
}


uint32_t Distance_sensor::compute_sliding_mean(long distance){
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total = total - readings[readIndex];
  // read the sensor:
  readings[readIndex] = distance;
  // add value to total:
  total = total + readings[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;

  return average;
}
