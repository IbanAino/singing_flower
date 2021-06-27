![Alt text](../Ressources/FR.png?raw=true "FR") Instructions d'installation

![Alt text](../Ressources/EN.png?raw=true "EN") Installation insctructions

![Alt text](../Ressources/ES.png?raw=true "ES") Instrucciones de instalación

---

![Alt text](../Ressources/FR.png?raw=true "FR")

## Vue d'ensemble du processus d'installation

Le programme est codé en Python et tourne sur un RaspberryPi3.

La première étape consiste à installer une distribution Linux sur le RaspberryPi.

Une fois le Raspberry Pi opérationnel, nous pouvons récupérer le code source sur GitHub pour le mettre sur le RaspberryPi.

Ensuite il nous faut configurer le RaspberryPi pour pourvoir utiliser le module de son HifiBerry amp2.

Plusieurs librairies python sont à installer, nottament mplayer qui permet de contrôler le son.

Enfin il faut configurer le RaspberryPi pour qu'il lance le programme tout seul au démarrage, sans intervention humaine.

## Distribution Linux du RaspberryPi

La distrubition Linux utilisée pour ce projet est Raspbian. L'installation est expliquée sur le site officiel de RaspberryPi :

[https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)

## Téléchargement des codes sources sur le Raspberry Pi

Copier et coller les fichiers **Python_get_serial_messages.py** et **Run_singing_flower.sh** sur le bureau du Raspberry Pi. Copier aussi les dossier **sound** et **mplayer** sur le bureau.


## Configuration du RaspberryPi pour activer le module de son HifiBerry Amp2

Par défaut le RaspberryPi n'envoie pas la son au module HifiBerry. Il faut donc le configurer.

- Ouvrir le fichier de configuration avec la commande suivante :
```
sudo nano /boot/config.txt
```
- Supprimer la ligne suivante :
```
dtparam=audio=on
```
- Ecrire la ligne suivante :
```
dtoverlay=hifiberry-dacplus
```
- Quitter l'éditeur de texte avec la commande **ctrl+x**, confirmez les modifications avec la lettre **o** puis tapez **Entrer** pour valider.

Le RaspberryPi est maintenant configuré pour utiliser le module HifiBerry.

## Librairie Python pour le son

Pour lancer des sons sur le module HifiBerry nous utilisons le module Python **mplayer**.

- Pour l'installer, lancer la commande suivante dans un terminal :
```
pip3 install mplayer.py
```
Afin de d'évier le message d'erreur suivant ** ** nous allons configurer mplayer.

- Ouvrir le fichier de configuration de mplayer avec la commande suivante :
```
sudo nano home/.mplayer/config
```
- Ajouter cette ligne au fichier :
```
lirc = no
```
- Quitter l'éditeur de texte avec la commande **ctrl+x**, confirmez les modifications avec la lettre **o** puis tapez **Entrer** pour valider.

## Lancer le programme automatiquement au démarrage

Nous sohaitons que le programme se lance automatiquement lors du démarrage du RaspberryPi. Pour cela nous allons configrer le fichier autostart du RaspberryPi afin de lancer le code Python dans un terminal.

- Lancer une console et ouvrir le fichier autostart avec la commande suivante :
```
sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
```
- Ajouter cette ligne à la fin du fichier :
```
@lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
```
- Quitter l'éditeur de texte avec la commande **ctrl+x**, confirmez les modifications avec la lettre **o** puis tapez **Entrer** pour valider.

Par défaut le fichier **Run_singing_flower.sh** n'est pas exécutable. Régler ses droits avec la commande suivante :
```
sudo chmod 777 /home/pi/Desktop/Run_singing_flower.sh
```

---

![Alt text](../Ressources/EN.png?raw=true "EN")

## Overview of the intallation process

The software is a Python program tha run on a RaspberryPi3 platform.

The first step consist on install a Linux distribition on the Raspberry Pi.

Once the Raspberry Pi is ready, we can get the source code on Gitlab an download them on the RAspberry Pi.

Then we have to configure the Raspberry Pi to use the sound module HifiBerry amp2.

Several libraries have to be installed, for example the module mplayer to manage sound.

Finally we have to set the Raspberry Pi in order to launch the program automatically at boot, without human intervention.

## Linux distribution for RaspberryPi

the Linux distribition used for this project is Raspbian. The installation instructions are explain on the officail RasperryPi website:

[https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)

## Download source codes on Raspberry Pi

Copy and paste the files **Python_get_serial_messages.py** and **Run_singing_flower.sh** on the Raspberry Pi desktop. Download the repertories **sound** and **mplayer** on the desktop too.

## RaspberryPi Configuration to activate the sound module HifiBerry Amp2

By deffault the RAspberry Pi doesn't send any sound to the module HifiBerry. We have to configure it.

- Open the configuration file with the following command:
```
sudo nano /boot/config.txt
```
- Delete the following line:
```
dtparam=audio=on
```
- Write the following line:
```
dtoverlay=hifiberry-dacplus
```
- Leave the text editor with the command **ctrl+x**, confirm the modifications withe the letter **o** and type **Enter** to validate.

The Raspberry Pi is now configurated to use the HifiBerry module.

## Automatic code launch at boot

We want the programm to launch automatically at the Raspberry Pi boot. We have to configure the autostart file of the Raspberry Pi to launch the Python code inside a terminal.

- Open a terminal an open the configuration file with the following command:
```
sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
```
- Add this line at the end of the file:
```
@lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
```
- Leave the text editor with the command **ctrl+x**, confirm the modifications withe the letter **o** and type **Enter** to validate.

By deffault, the file **Run_singing_flower.sh** is not executable. Set its rights with the following command:
```
sudo chmod 777 /home/pi/Desktop/Run_singing_flower.sh
```

---

![Alt text](../Ressources/ES.png?raw=true "ES")

## descripción general del proceso de instalación

## Distribucion Linux en el RaspberryPi

La distribucion Linux utilizada para este proyecto es Debian. La installacion esta explicanda en el sitio official de Raspberry Pi :

[https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)

## descargado de los códigos fuente en el Raspberry Pi

## Configuration del RaspberryPi para activar el sondido modulo HifiBerry Amp2

## Comenzar automáticamente el programmo al enciende de la computadora
