//*** LIBRAIRIES ***
#include "Distance_sensor.h"

//*** ATTRIBUTS ***
#define pin_trig_sensor_1 3
#define pin_echo_sensor_1 4
#define pin_trig_sensor_2 5
#define pin_echo_sensor_2 6
#define pin_trig_sensor_3 7
#define pin_echo_sensor_3 8
#define pin_trig_sensor_4 9
#define pin_echo_sensor_4 10

Distance_sensor sensor_1(pin_trig_sensor_1, pin_echo_sensor_1, 500);
Distance_sensor sensor_2(pin_trig_sensor_2, pin_echo_sensor_2, 500);
Distance_sensor sensor_3(pin_trig_sensor_3, pin_echo_sensor_3, 500);
Distance_sensor sensor_4(pin_trig_sensor_4, pin_echo_sensor_4, 500);

Distance_sensor distance_sensors[] = {
 sensor_1,
 sensor_2,
 sensor_3,
 sensor_4
};

uint32_t sensors_distances_measuremes[4];

void setup() {
  Serial.begin(9600);
  Serial.println("1,1,1,1");
}

void loop() {
  while (true){
    for (int i = 0; i < 4; i++){
      Serial.print((String)distance_sensors[i].get_distance_measurement());
      if(i < 3){
        Serial.print(",");
      }
      delay(8);
    }
    Serial.println();
  }
}
