
import serial # [FR] Communication avec l'Arduino [EN] Communication with the Arduino [CA] Communicion con el Arduino
import re # Regular Expressions [FR] Traduire les messages reçus l'arduino [EN] Translate messages received from the Arduino [CA] Traducir mensajer recivios del Arduino
from mplayer import Player # [FR] Lire des fichiers audio [EN] Read audio files [CA] Leer archivos de sondido
import time


volume = 0.0

def manage_Sound_volume(received_values):

    global volume
    
    print("Raw values: " + received_values)
    received_values = re.sub("[^0-9.]",",",received_values)
    
    values = received_values.split(',')
    print("Values: " + received_values)
    
    values_float = []  
    
    for value in values:
        if (value):
            values_float.append(float(value))
    
    '''
    [FR] La plus petite valeur est choisie.
            Cette valeur est convertie en volume avec un coefficient.
            

    '''
    print("Values float")
    print(values_float)
    
    smallest_value = min(values_float)
    
    print("smallest_value: " + str(smallest_value))
    
    #new_volume = (smallest_value * 0.625) - 21.25
    new_volume = (smallest_value * 0.9) - 50
    
    print("New volume: ")
    print(new_volume)
    
    if volume >= new_volume:
        volume = volume - 2
    else:
        volume = volume + 1
    
    if volume > 60:
        volume = 60
    elif volume < 10:
        volume = 10
    
    sound_player.volume = volume
    
    print("volume: " + str(volume))


if __name__ == "__main__":
    
    sensors_calibration_done = False
    programm_running = True
    
    try:        
        sound_player = Player()
        sound_player.loadfile("/home/pi/Desktop/sound/voix.wav")
        sound_player.volume = 0.0
        sound_player.loop = 0
        volume = 0.0
        
        connection = False
        
        while programm_running:         
            if connection == False: 
                try:
                    serial_connexion = serial.Serial(port = '/dev/ttyACM0', \
                                     baudrate = 9600, \
                                     #bytesize = 8, \
                                     #parity = 'N', \
                                     #stopbits = 1, \
                                     timeout = 1, \
                                     #xonxoff = 1, \
                                     #rtscts = 0)
                                     )
                    print("serial is OK \n")
                    connection = True
                    
                    if sensors_calibration_done == False:
                        sound_player_2 = Player()
                        sound_player_2.loadfile("/home/pi/Desktop/sound/calibration_begin.mp3")
                        sound_player_2.volume = 60
                        time.sleep(14)
                        serial_connexion.write(bytes("o", 'utf-8'))
                        time.sleep(0.05)
                        sound_player_2.volume = 100
                        sound_player_2.loadfile("/home/pi/Desktop/sound/calibration_done.mp3")
                        time.sleep(3)
                        sound_player_2.quit()
                        sensors_calibration_done = True
                        
                except:
                    print("serial not connected \n Check the Serial connection \n")
                    time.sleep(3)     

            try:
                received_values = str(serial_connexion.readline())
                
                if received_values:
                    manage_Sound_volume(received_values)
                     
            except:
                print("ERROR - serial connexion broken \n")
                connection = False
                serial_connexion.close()
            
    except KeyboardInterrupt:
        serial_connexion.close()
        sound_player.quit()
        programm_running = False

    
    finally:        
        serial_connexion.close()
        sound_player.quit()
        print("Programm ends")