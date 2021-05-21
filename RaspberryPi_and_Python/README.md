![Alt text](../Ressources/FR.png?raw=true "FR") Instructions d'installation

![Alt text](../Ressources/EN.png?raw=true "EN") Installation insctructions

![Alt text](../Ressources/ES.png?raw=true "ES") Instrucciones de instalación




![Alt text](../Ressources/FR.png?raw=true "FR")

## Vue d'ensemble du processus d'installation

Le programme est codé en Python et tourne sur un RaspberryPi3.

La première étape consiste à installer une distribution Linux sur le RaspberryPi.

Ensuite il nous faut configurer les RaspberryPi pour pourvoir utiliser le module de son HifiBerry amp2.

Plusieurs librairies python sont à installer, nottament mplayer qui permet de contrôler le son.

Enfin il faut configurer le RaspberryPi pour qu'il lance le programme tout seul au démarrage, sans intervention humaine.

## Distribution Linux du RaspberryPi

La distrubition Linux utilisée pour ce projet est Raspbian. L'installation est expliquée sur le site officiel de RaspberryPi :

[https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)

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
sudo nano HOME/.mplayer/config
```
- Ajouter cette ligne au fichier :
```
lirc = no
```
- Quitter l'éditeur de texte avec la commande **ctrl+x**, confirmez les modifications avec la lettre **o** puis tapez **Entrer** pour valider.

## Lancer le programme automatiquement au démarrage

Nous sohaitons que le programme se lance automatiquement lors du démarrage du RaspberryPi. Pour cela nous allons confugrer le fichier autostart du RaspberryPi afin de lancer le code Python dans un terminal.

- Copier et coller les fichiers **Python_get_serial_messages.py** et **Run_singing_flower.sh** sur le bureau du Raspberry Pi.

- Lancer une console et ouvrir le fichier autostart avec la commande suivante :
```
sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
```
- Ajouter cette ligne à la fin du fichier :
```
@lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
```
- Quitter et enregistrer les modifications

# [EN] Installation insctructions [FR] Instructions d'installation [CA] Instrucciones de instalación

![Alt text](../Ressources/EN.png?raw=true "EN")

Installation Instructions:

- Copy and paste the files **Python_get_serial_messages.py** and **Run_singing_flower.sh** on the Raspberry Pi desktop.
- Launch a terminal and open the autostart file with the following command:
   sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
- Add this line at the end of the file:
   @lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
- Exit and save changes


![Alt text](../Ressources/ES.png?raw=true "ES")