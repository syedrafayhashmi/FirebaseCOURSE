#include <Firebase.h>
#include <FirebaseArduino.h>
#include "DHT.h"
#include <Smoothed.h> 
#include <math.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "your host "
#define FIREBASE_AUTH "your key"
#define WIFI_SSID "your ssid" 
#define WIFI_PASSWORD "your password" 
#define DHTPIN 14 
#define DHTTYPE DHT11  // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Serial.println("connected!!!");
 
  
}

void loop() {
 
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Reading temperature as Celsius (the default)
  Serial.println (t);

  Firebase.setFloat("Temp",56);
  Firebase.setFloat("Humidity",63);
  
  delay(200);
}
