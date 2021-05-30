'''
[FR] FLEURS QUI CHANTONNENT
[EN] SINGING FLOWER
[CA] FLORES QUE CANTAN





'''

import serial # [FR] Communication avec l'Arduino [EN] Communication with the Arduino [CA] Communicion con el Arduino
import re # Regular Expressions [FR] Traduire les messages reçus l'arduino [EN] Translate messages received from the Arduino [CA] Traducir mensajer recivios del Arduino
from mplayer import Player # [FR] Lire des fichiers audio [EN] Read audio files [CA] Leer archivos de sondido
import time

def main():

    try:
        sound_player = Player()
        sound_player.loadfile("/home/pi/Desktop/sound/voix.wav")
        sound_player.loop = 0
        
        volume = 0.0
        
        with serial.Serial(port="/dev/ttyACM0", \
                           baudrate=9600, \
                           timeout=1, \
                           writeTimeout=1) \
                           as port_serie:
                               
            if port_serie.isOpen():
                
                while True:
                    
                    '''
                    [FR] La première étape consiste à traiter les données reçues de l'Arduino pour en faire une liste de valeurs.
                            Les Regular Expressions permettent d'avoir les valeurs séparées par une virgule.
                            Ensuite la fonction split met les valeurs dans un tableau.
                            Ces valeurs sont converties en float pour les calculs suivants.
                    [EN] The first step consists on manage data from the Arduino to have a list of values.
                            The Regular Expressions gives values separated by comas.
                            Then the split function puts the values inside a table.
                            The values are cast to float fot the nex computations.
                    [CA] La primera etapa es de procesar datos recibio del Arduino para tener una lista de valores.
                            Las Regular Expressions permittent de tener valores separadas por comas.
                            Luego el function split pone las valores en una junta.
                            Esos valores son convertidos en float par las proximas calculos.
                    '''
                    
                    try:
                        #port_serie.flush()
                        received_values = str(port_serie.readline())
                        received_values=re.sub("[^0-9,.]","",received_values)
                        
                        if received_values:
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
                            
                            
                         
                            smallest_value = min(values_float)

                            print("smallest_value: " + str(smallest_value))
                            
                            #new_volume = (smallest_value * 0.625) - 21.25
                            new_volume = (smallest_value * 0.9) - 50
                            
                            
                            if volume >= new_volume:
                                volume = volume - 2
                            else:
                                volume = volume + 0.2
                            
                            if volume > 60:
                                volume = 60
                            elif volume < 10:
                                volume = 10
                            
                            sound_player.volume = volume
                            
                            print("volume: " + str(volume))
                            
                            #time.sleep(0.2)
                    except:
                        print("ERROR - serial connexion with Arduino broken")
                        time.sleep(1)
                             
    except KeyboardInterrupt:
        print("EXIT")
        sound_player.quit()
         
                    
if __name__=='__main__':
    main()
