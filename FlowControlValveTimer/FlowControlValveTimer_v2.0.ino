//Test Code for turning ON & Off Motorized Ball Valve

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

  void valveON() {
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);  //Set valve's position to Open position (Blue wire)
    delay(5000);
    delay(5000);
    delay(5000);
    delay(5000);
    digitalWrite(12,HIGH); //Reset valve's position
    delay(2000);
  }

  void valveOFF() {
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);  //Set valve's position to Close position (Brown wire)
    delay(5000);
    delay(5000);
    delay(5000);
    delay(5000);
    digitalWrite(11,HIGH); //Reset valve's position
    delay(2000);
  }
  
void setup() {
  pinMode(12,OUTPUT); //Connected for Ball Valve's Open position wire
  pinMode(11,OUTPUT); //Connected for Ball Valve's Close position wire
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  while (!Serial); 
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
  }
}
void loop() {

  int on_hour = 7;
  int on_minute = 40;

  int off_hour = 9;
  int off_minute = 10;

  DateTime var = rtc.now();
  Serial.print(var.hour());
  Serial.print(var.minute());
  Serial.print(var.second());
  
  if(var.hour() == on_hour && var.minute() == on_minute)
  {
    Serial.print("Device Switched ON");
    Serial.println();
    valveON();  
  }

  else if(var.hour() == off_hour && var.minute() == off_minute)
  {
    Serial.print("Device Switched OFF");
    Serial.println();
    valveOFF();  
  }

  delay(5000);
  
}
