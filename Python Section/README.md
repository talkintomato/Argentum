### Python Mosquitto Temperature 
------
**Publisher** is a program that outputs a random temperature (between 20 and 30 deg. C) every 10 seconds to a public MQTT server.

------
**Subscriber** is a program that responds to the following user commands:
1. *start* - Start receiving the information from publisher and store it in a file.
2. *stop* -  Stop receiving the information (the program keeps running)
3. *clear* - Clear all stored information 
4. *list* - Lists the highest and lowest recorded temperatures.

Recorded data is saved to temperatures.txt

------
## How to use: 
1. Start Mosquitto locally in terminal
2. Run Publisher 
3. Run Subsciber


Link to MQTT Specification:
https://mqtt.org/

Link to public MQTT server:
https://test.mosquitto.org/