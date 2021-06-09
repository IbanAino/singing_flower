//*** LIBRAIRIES ***
#include "Distance_sensor.h"

//*** ATTRIBUTS ***
#define pin_trig_sensor_1 2
#define pin_echo_sensor_1 22

#define pin_trig_sensor_2 3
#define pin_echo_sensor_2 24

#define pin_trig_sensor_3 4
#define pin_echo_sensor_3 26

#define pin_trig_sensor_4 5
#define pin_echo_sensor_4 28

#define pin_trig_sensor_5 6
#define pin_echo_sensor_5 30

#define pin_trig_sensor_6 7
#define pin_echo_sensor_6 32

#define pin_trig_sensor_7 8
#define pin_echo_sensor_7 34

#define pin_trig_sensor_8 9
#define pin_echo_sensor_8 36

#define pin_trig_sensor_9 10
#define pin_echo_sensor_9 38

#define pin_trig_sensor_10 11
#define pin_echo_sensor_10 40

#define pin_trig_sensor_11 12
#define pin_echo_sensor_11 42

#define pin_trig_sensor_12 13
#define pin_echo_sensor_12 44

#define pin_trig_sensor_13 45
#define pin_echo_sensor_13 47


Distance_sensor sensor_1(pin_trig_sensor_1, pin_echo_sensor_1, 800);
Distance_sensor sensor_2(pin_trig_sensor_2, pin_echo_sensor_2, 800);
Distance_sensor sensor_3(pin_trig_sensor_3, pin_echo_sensor_3, 800);
Distance_sensor sensor_4(pin_trig_sensor_4, pin_echo_sensor_4, 800);
Distance_sensor sensor_5(pin_trig_sensor_5, pin_echo_sensor_5, 800);
Distance_sensor sensor_6(pin_trig_sensor_6, pin_echo_sensor_6, 800);
Distance_sensor sensor_7(pin_trig_sensor_7, pin_echo_sensor_7, 800);
Distance_sensor sensor_8(pin_trig_sensor_8, pin_echo_sensor_8, 800);
Distance_sensor sensor_9(pin_trig_sensor_9, pin_echo_sensor_9, 800);
Distance_sensor sensor_10(pin_trig_sensor_10, pin_echo_sensor_10, 800);
Distance_sensor sensor_11(pin_trig_sensor_11, pin_echo_sensor_11, 800);
Distance_sensor sensor_12(pin_trig_sensor_12, pin_echo_sensor_12, 800);
Distance_sensor sensor_13(pin_trig_sensor_13, pin_echo_sensor_13, 800);


Distance_sensor distance_sensors[] = {
  sensor_1,
  sensor_2,
  sensor_3,
  sensor_4,
  sensor_5,
  sensor_6,
  sensor_7,
  sensor_8,
  sensor_9,
  sensor_10,
  sensor_11,
  sensor_12,
  sensor_13
};

int incomingByte = 0;
//String incomingByte = "";

uint32_t sensors_distances_measuremes[1];

void setup() {
  Serial.begin(115200);
  Serial.println("1,1,1,1,1,1,1,1,1,1,1,1");

  Serial.print("******* CALIBRATION *******");
  delay(1000);
  for (int i = 0; i < 13; i++) {
    Serial.print("Sensor ");
    Serial.println(i);
    distance_sensors[i].calibrate_max_distance();
  }
}

void loop() {
  for (int i = 0; i < 13; i++) {
    Serial.print((String)distance_sensors[i].get_distance_measurement());
    if (i < 12) {
      Serial.print(",");
    }
    delay(8);
  }
  Serial.println();
/*
  Serial.setTimeout(1);
  if (Serial.available()) {
    incomingByte = Serial.readString().toInt();

    if (incomingByte == 111) {
      Serial.print("******* CALIBRATION *******");
      for (int i = 0; i < 13; i++) {
        distance_sensors[i].calibrate_max_distance();
      }
    }
  }
  */
}
