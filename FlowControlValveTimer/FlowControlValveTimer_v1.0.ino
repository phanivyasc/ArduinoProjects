#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;


void setup() {

while (!Serial); 

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12,HIGH);
  
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
  int on_minute = 35;

  int off_hour = 8;
  int off_minute = 55;

  DateTime var = rtc.now();

  
  
  if(var.hour() == on_hour && var.minute() == on_minute)
  {
    Serial.print("Device Switched ON");
    Serial.println();
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(12, LOW);
  }

  else if(var.hour() == off_hour && var.minute() == off_minute)
  {
    Serial.print("Device Switched OFF");
    Serial.println();
    digitalWrite(LED_BUILTIN, LOW); 
    digitalWrite(12, HIGH);
  }
  
   delay(5000);

}
