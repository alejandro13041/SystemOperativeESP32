#include <WiFi.h>

const char* ssid     = "blink";
const char* password = "blink123";

#define PIN_BLINK  22
#define PIN_BUTTON 23

void setup(){

	Serial.begin(9600);
	pinMode(PIN_BLINK , OUTPUT); // set the LED    pin mode
	pinMode(PIN_BUTTON,  INPUT); // set the BUTTON pin mode

	delay(1000);

	Serial.println();
  Serial.print("[WiFi] Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED){

    	Serial.println("Conecting ...");
      delay(2000);
      
     };

   	Serial.println("[Wifi] Connected.");
    delay(2000);

 }

void loop(){

    WiFiClient client;

    Serial.println();
    Serial.print("[Button] State");
    Serial.print(digitalRead(PIN_BUTTON));

   	delay(1000);

    if (digitalRead(PIN_BUTTON) == 0){

		client.write('1');
		delay(1000);
		client.write('0');

     }


 }