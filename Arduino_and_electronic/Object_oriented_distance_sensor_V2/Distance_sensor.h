#ifndef Distance_sensor_h
#define Distance_sensor_h

const int numReadings = 10;

//*** LIBRARIES ***
#include <arduino.h>

class Distance_sensor
{
  public:
  //*** CONSTRUCTOR ***
  Distance_sensor (int pin_trig, int pin_echo, int maxDistance);

  //*** PUBLIC FUNCTIONS ***
  uint32_t get_distance_measurement();
  void calibrate_max_distance();

  //*** PUBLIC VARIABLES ***
  int pin_trig;
  int pin_echo;
  int calibrationTryingCounter = 0;
  
  private:
  //*** PRIVATE FUNCTIONS ***
  uint32_t compute_sliding_mean(long distance);

  //*** PRIVATE VARIABLES ***
  uint32_t measured_distance;
  uint32_t sound_journey_duration;
  int maxDistance;


  // Variables for the sliding mean computation
  int readings [numReadings];
  int readIndex = 0;
  long total = 0;
};

#endif
