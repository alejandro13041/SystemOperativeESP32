#include <WiFi.h>
#include "esp_wifi.h"
#include <FirebaseESP32.h>


FirebaseData firebaseData;

#define FIREBASE_HOST "https://esp-32-af28f-default-rtdb.europe-west1.firebasedatabase.app/"
#define FIREBASE_AUTH "twvppSKKJ2RNkqv41vxvXQqOVg0C1nMKCTOsMWi8"


const char* ssid = "ETITC-DOCENTES";
const char* password = "Navegar2018..";
const char* ap_ssid = "C_O_N_E_C_T_I_V_E";
const char* ap_password = "28546429";
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  // Conexión al WiFi principal
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red principal...");
  }
  Serial.println("Conectado a la red principal");

  // Configuración del punto de acceso
  IPAddress local_IP(192, 168, 0, 1);
  IPAddress gateway(192, 168, 0, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ap_ssid, ap_password);

  // Inicializa Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // Mostrar la dirección IP del punto de acceso
  Serial.print("Dirección IP del Punto de Acceso: ");
  Serial.println(WiFi.softAPIP());

  
}

String nodo = "/roots";

struct root{

    /*string*/
    int8_t id;    
    String user;
    String pass;
    String mail;
    String rank;

 };

void values(){

  root r1;
  root roots[256];

  for(int i = 0;i< 256; i++ ){

    r1.id = i;
    r1.user = "user" + String(i);
    r1.pass = "pass" + String(i); 
    r1.mail = "mail" + String(i);
    r1.rank = "rank" + String(i);

    roots[i].id = r1.id;
    roots[i].user = r1.user;
    roots[i].pass = r1.pass;
    roots[i].mail = r1.mail;
    roots[i].rank = r1.rank;

   }

  Firebase.getInt(firebaseData, nodo + "/id",0);
  Serial.println(firebaseData.intData());
  Firebase.getString(firebaseData,nodo + "/user", roots[0].user);
  Serial.println(firebaseData.stringData());
  Firebase.getString(firebaseData,nodo + "/pass", roots[0].pass);
  Serial.println(firebaseData.stringData());
  Firebase.getString(firebaseData,nodo + "/mail", roots[0].mail);
  Serial.println(firebaseData.stringData());
  Firebase.getString(firebaseData,nodo + "/rank", roots[0].rank);
  Serial.println(firebaseData.stringData());

  /*
  Firebase.setInt(firebaseData, nodo + "/id",0);
  Firebase.setString(firebaseData,nodo + "/user", roots[0].user);
  Firebase.setString(firebaseData,nodo + "/pass", roots[0].pass);
  Firebase.setString(firebaseData,nodo + "/mail", roots[0].mail);
  Firebase.setString(firebaseData,nodo + "/rank", roots[0].rank);
  */

 }

void loop() {
 
  // Parpadeamos el LED para indicar que el programa sigue en ejecución

  digitalWrite(LED_BUILTIN, HIGH);
  values();
  delay(60000);


  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

}