# Installation Instructions:
#
# - Copy and paste the files Singing_Flower.py and Run_singing_flower.sh on the Raspberry Pi desktop.
# - Launch a terminal and open the autostart file with the following command:
#    sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
# - Add this line at the end of the file:
#    @lxterminal -e /home/pi/Desktop/Run_singing_flower.sh
# - Exit and save changes

#!/bin/bash
sleep 3
lxterminal -e python3 /home/pi/Desktop/Singing_flower.py
