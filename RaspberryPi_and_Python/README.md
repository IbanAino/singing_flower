# [EN] Installation insctructions[FR] Instructions d'installation [CA] Instrucciones de instalación

[ENGLISH]

Installation Instructions:

- Copy and paste the files **Python_get_serial_messages.py** and **Run_singing_flower.sh** on the Raspberry Pi desktop.
- Launch a terminal and open the autostart file with the following command:
   sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
- Add this line at the end of the file:
   @lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
- Exit and save changes



[FRANCAIS]

## Distribution Linux du RaspberryPi

## Configurer le RaspberryPi pour activer le module de son HifiBerry Amp2

Par défaut le RaspberryPi n'envoie pas la son au module HifiBerry. Il faut donc le configurer.

Ouvrir le fichier de configuration avec la commande suivante :
'''
sudo nano /boot/config.txt
'''
Supprimer la ligne suivante :
'''
dtparam=audio=on
'''
Ecrire la ligne suivante :
'''
dtoverlay=hifiberry-dacplus
'''
Quitter l'éditeur de texte avec la commande **ctrl+x**, confirmez les modifications avec la lettre **o** puis tapez **Entrer** pour valider.

Le RaspberryPi est maintenant configuré pour utiliser le module HifiBerry.

## Librairie Python pour le son

Pour lancer des sons sur le module HifiBerry nous utilisons le module Python mplayer.

Pour l'installer, lancer la commande suivante dans un terminal :
'''
pip3 install mplayer.py
'''
Afin de d'évier le message d'erreur suivant ** ** nous allons configurer mplayer.

Ouvrir le fichier de configuration de mplayer avec la commande suivante :
'''
sudo nano HOME/.mplayer/config
'''
Ajouter cette ligne au fichier :
'''
lirc = no
'''
Quitter l'éditeur de texte avec la commande **ctrl+x**, confirmez les modifications avec la lettre **o** puis tapez **Entrer** pour valider.

## Lancer le programme automatiquement au démarrage

La dernière étape de l'installation consiste

Copier et coller les fichiers **Python_get_serial_messages.py** et **Run_singing_flower.sh** sur le bureau du Raspberry Pi.

Lancer une console et ouvrir le fichier autostart avec la commande suivante :
'''
sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
'''
- Ajouter cette ligne à la fin du fichier :
'''
@lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
'''
- Quitter et enregistrer les modifications