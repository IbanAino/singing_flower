# -*- coding: utf-8 -*-
"""
Created on Sat Jun  5 18:24:21 2021

@author: Iban
"""

import serial
import re
from mplayer import Player
import time

volume = 0.0
programm_running = True



def manage_sound_volume(sound_player, distance):
    global volume
    #new_volume = (smallest_value * 0.625) - 21.25
    new_volume = (distance * 0.9) - 50
    print("Computed volume: " + str(new_volume))

    if volume >= new_volume:
        volume = volume - 2
    else:
        volume = volume + 1
    
    if volume > 60:
        volume = 60
    elif volume < 0:
        volume = 0
    
    sound_player.volume = volume
    print("Final volume filtered: " + str(volume))



def open_serial_connexion(serial_connexion):
    connection = False
    while connection == False: 
        try:
            serial_connexion = serial.Serial(port = 'COM7', \
            #serial_connexion = serial.Serial(port = '/dev/ttyACM0', \
                             baudrate = 9600, \
                             timeout = 1)
            print("serial is OK \n")
            connection = True           
        except:
            print("serial not connected. \nCheck the Serial connection. \nTry again to connect.")
            time.sleep(3)      
    return(serial_connexion)



def close_serial_connexion(serial_connexion):
    serial_connexion.close()
 
    
    
def read_distances_from_arduino(serial_connexion):
    try:
        received_values = str(serial_connexion.readline())
        if received_values:
            return(received_values)
		else:
			return(0)
    except:
        print("ERROR - serial connexion broken \n")
        return(0)
    
    
    
def get_smallest_value_from_measurements(measurements):
    measurements = re.sub("[^0-9.]",",",measurements)
    values = measurements.split(',')
    print("Values: " + measurements)
    values_float = []  
    for value in values:
        if (value):
            values_float.append(float(value))
    smallest_value = min(values_float)
    print("Closer obstacle: " + str(smallest_value))
    return(smallest_value)


def calibrate_distance_sensors(serial_connexion):
    sound_player_2 = Player()
    sound_player_2.loadfile("/home/pi/Desktop/sound/calibration_begin.mp3")
    sound_player_2.volume = 60
    time.sleep(10)
    sensors_calibration_done = False    
    try_calibration_counter = 0
    
    while sensors_calibration_done == False:
        try:
            # the buffer immediately receives data, so ensure it is empty before writing command
            while serial_connexion.inWaiting()>0:
                serial_connexion.read(1)  
            serial_connexion.write(bytes("o", 'utf-8'))
            time.sleep(4)
            sensors_calibration_done == True
        except:
            print("ERROR - calibration failed.")
            try_calibration_counter = try_calibration_counter + 1
            if try_calibration_counter == 4:
                return(False)
            
    sound_player_2.volume = 60
    sound_player_2.loadfile("/home/pi/Desktop/sound/calibration_done.mp3")
    time.sleep(3)
    sound_player_2.quit()
    sensors_calibration_done = True
    return(True)
    
    
def main():
    global programm_running
    
    serial_connexion = object()
    serial_connexion = open_serial_connexion(serial_connexion)
    
    while True:
        result = calibrate_distance_sensors(serial_connexion)
        if result is True:
            break
        else:
            close_serial_connexion(serial_connexion)
            open_serial_connexion(serial_connexion)
            
    sound_player = Player()
    sound_player.loadfile("/home/pi/Desktop/sound/voix.wav")
    sound_player.volume = 0.0
    sound_player.loop = 0
        
    while programm_running is True:
		measured_distances = read_distances_from_arduino   
		if measured_distances == 0:
			print("ERROR - cannot get data from Arduino.")
            serial_connexion.close(serial_connexion)
            serial_connexion = open_serial_connexion(serial_connexion)		
		else:
			distance = get_smallest_value_from_measurements(measured_distances)
			manage_sound_volume(sound_player, distance)

            
    # Executed when the programm ends:
    serial_connexion.close()
    sound_player.quit()
        
        
if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        programm_running = False

        
    
    

        
            
        
    
                        





