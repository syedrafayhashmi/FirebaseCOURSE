#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "your host"
#define FIREBASE_AUTH "your key"
#define WIFI_SSID "your ssid" 
#define WIFI_PASSWORD "your password" 
#define SensorPin A0 
float sensorValue = 0; 
void setup() { 
 Serial.begin(9600); 
 WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Serial.println("connected!!!");
  
} 
void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
 sensorValue = sensorValue/100.0; 
 Firebase.setFloat("SOIL SENSOR",sensorValue);
 Serial.println(sensorValue); 
 delay(30); 
} 
