#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "your host"
#define FIREBASE_AUTH "your key"
#define WIFI_SSID "your ssid" 
#define WIFI_PASSWORD "your password" 
const int LED=13;
void setup() {
   Serial.begin(9600);
   pinMode(LED, OUTPUT);
   digitalWrite(LED,LOW);
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
  Firebase.setString("LED",0);
  
}

void loop() {
  char data=Firebase.getBool("LED");
  if (data=='1')
  {digitalWrite(LED, HIGH);}  
  if (data=='0')
  {digitalWrite(LED, LOW);} 
  
  
  delay(200);
}
