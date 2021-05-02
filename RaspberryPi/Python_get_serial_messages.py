# Module de lecture/ecriture du port série
import serial
import re

# Port série ttyACM0
# Vitesse de baud : 9600
# Timeout en lecture : 1 sec
# Timeout en écriture : 1 sec
with serial.Serial(port="COM6", \
                   baudrate=9600, \
                   timeout=1, \
                   writeTimeout=1) \
                   as port_serie:
                       
    if port_serie.isOpen():
        
        while True:
            received_values = str(port_serie.readline())
            received_values=re.sub("[^0-9,.]","",received_values)
            
            
            if received_values:
                values = received_values.split(',')
                print("Values: " + received_values)
                values_float = []
                
                for value in values:
                    if (value):
                        values_float.append(float(value))
             
                smallest_value = min(values_float)

                print("smallest_value: " + str(smallest_value))

