/*

	Este sketch fue hecho para ser el servidor que pueda encender una led 
	mediante metodo wifi.

	Por ahora solo se programa Solo el server y no multidireccional

 */

#include <WiFi.h>

const char* ssid     = "blink";
const char* password = "blink123";

#define PIN_BLINK  22
#define PIN_BUTTON 23

WiFiServer server(80);

void setup(){

	Serial.begin(9600);
	pinMode(PIN_BLINK , OUTPUT); // set the LED    pin mode
	pinMode(PIN_BUTTON,  INPUT); // set the BUTTON pin mode

	delay(1000);

	  Serial.println();
  	Serial.println("Configuring access point...");

  	if (!WiFi.softAP(ssid, password)) {

    	Serial.println("Soft AP creation failed.");
    	while(true);

     }

    IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
  	Serial.println(myIP);
  	server.begin();

  	Serial.println("Server started");


 }

void loop(){

	WiFiClient client = server.available();   

  	if (client){

    	Serial.println("New Space Client.");           

    	while (client.connected()){  // Mientras el cliente este conectado

    		Serial.println("Client connected");
        delay(1000);

	      	if (client.available()){ // Mientras el cliente envie datos 

	        	char c = client.read();
	        	Serial.println("[Client] Send: ");             
	        	Serial.write(c); 

		        if (c == '1'){                   

					digitalWrite(PIN_BLINK, HIGH);
					delay(2000); 

		         }

		        if (c == '0'){

		          digitalWrite(PIN_BLINK, LOW);
		          delay(2000);                	

		         }
	      	 }
	     }
	 }
 }