#include <Firebase.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "your host"
#define FIREBASE_AUTH "your key"
#define WIFI_SSID "your ssid" 
#define WIFI_PASSWORD "your password" 

int trigger = 11;    //Trigger of module is connected to pin 11 of Arduino
int echo=10;         //Echo of module is connected to pin 10 of Arduino
int duration;        //Will be used later on
float distance;       //Will be used later on

void setup() {
  Serial.begin (9600);      //Do not edit
  pinMode(trigger, OUTPUT);    //Do not edit
  pinMode(echo, INPUT);        //Do not edit
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
      digitalWrite(trigger, LOW);  
      delayMicroseconds(2); 
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      duration = pulseIn(echo, HIGH);
      distance = (duration / 2) / 29.1;
      digitalWrite(trigger, LOW);  

      Serial.print("Distance= ");
      Serial.print(distance);
      Firebase.setFloat("Distance(cm): ",distance)
      Serial.println(" cm");
delay(1000);
}
