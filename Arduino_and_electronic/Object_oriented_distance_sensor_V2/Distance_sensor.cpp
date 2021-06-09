#include "Distance_sensor.h"
#include <arduino.h>

//*** CONSTRUCTOR ***
Distance_sensor::Distance_sensor (int pin_trig, int pin_echo, int maxDistance) {
  this -> pin_trig = pin_trig;
  this -> pin_echo = pin_echo;
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);

  this -> maxDistance = maxDistance;

  for (int i = 0; i < numReadings; i++){
    readings [i] = 150;
  }
  total = 150 * numReadings;
}
  
//*** FUNCTIONS ***

uint32_t Distance_sensor::get_distance_measurement(){
  uint32_t old_measured_distance = measured_distance;
  // Clears the trigPin
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(10);
  // Sets the pin_trig on HIGH state for 10 micro seconds
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  sound_journey_duration = pulseIn(pin_echo, HIGH, 25000);
  // Calculating the distance
  measured_distance = sound_journey_duration * 0.034 / 2;
  //measured_distance = sound_journey_duration / 29 / 2;
  // Prints the distance on the Serial Monitor


  //--- Ignore extrem values and  ---
  if (measured_distance > maxDistance){
    measured_distance = maxDistance;
  }else if (measured_distance < 1){
    measured_distance = old_measured_distance + 10;
  }
  old_measured_distance = measured_distance;

  //--- Make average and keep values between min and max ---
  measured_distance = this -> compute_sliding_mean(measured_distance); 
  if (measured_distance >= maxDistance){
    measured_distance = 700;
  }else if (measured_distance < 1){
    measured_distance = old_measured_distance;
  } 
  
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


void Distance_sensor::calibrate_max_distance(){
  uint32_t total = 0;
  delay(20);
  //for (int i = 0; i < 20; i++){
    digitalWrite(pin_trig, LOW);
    delayMicroseconds(10);
    digitalWrite(pin_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin_trig, LOW);
    sound_journey_duration = pulseIn(pin_echo, HIGH);
    measured_distance = sound_journey_duration * 0.034 / 2;
    total += measured_distance;
    delay(10);
  //}

  //maxDistance = (total / 20) - 30;
    maxDistance = total - 20;
    
  if (maxDistance > 700){
    Serial.println("Try again - too big");
    if (calibrationTryingCounter < 3){
      calibrationTryingCounter++;
      calibrate_max_distance();
      return;
    }
    else{
      maxDistance = 700;
    }
  }
  
  if (maxDistance < 10){
    Serial.println("Try again - too few");
    if (calibrationTryingCounter < 3){
      calibrationTryingCounter++;
      calibrate_max_distance();
      return;
    }
    else{
      maxDistance = 700;
    }
  }
  Serial.println(maxDistance);
}
