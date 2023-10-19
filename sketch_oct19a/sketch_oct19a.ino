#include <WiFi.h>
#include <FirebaseESP32.h>
#define FIREBASE_HOST "your-firebase-url.firebaseio.com"
#define FIREBASE_AUTH "your-firebase-secret-auth-token"
#define WIFI_SSID "your-wifi-ssid"
#define WIFI_PASSWORD "your-wifi-password"

FirebaseData firebaseData;

void setup() {
  // Inicializar la conexión Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.begin(115200);

  // Esperar hasta que la conexión Wi-Fi esté establecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Inicializar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // Escuchar cambios en un nodo específico de Firebase
  Firebase.stream(firebaseData, "/data/sensor1");
}

void loop() {
  // Enviar datos a Firebase
  Firebase.setDouble(firebaseData, "/data/sensor1", 123.45);

  // Esperar un tiempo
  delay(1000);
}