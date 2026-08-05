#include <Servo.h>  // Added for counter pull
// using pins 7 (relay 1) 6 (relay 2) and 5 (relay 3)

const int trigPin = 12;
const int echoPin = 13;
const int relayPin1 = 8;
const int relayPin2 = 7;
const int rapidPin = 6;
const int servoPin = 5;  // Added for counter pull


bool relaysActive = false;
Servo myServo;  // Added for counter pull


void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(relayPin1, OUTPUT);
 pinMode(relayPin2, OUTPUT);
 pinMode(rapidPin, OUTPUT);
 digitalWrite(relayPin1, LOW);
 digitalWrite(relayPin2, LOW);
 digitalWrite(rapidPin, LOW);
 Serial.begin(9600);


 myServo.attach(servoPin);  // Servo setup
 myServo.write(90);         // Neutral position
}


void loop() {
 if (!relaysActive) {
   if (checkSensorOverInterval(2000)) {
     relaysActive = true;
     crushCan();
     delay(4000);
     triggerRapidPin();
     relaysActive = false;


     // 🔧 Counter pull AFTER everything (angle adjusted from 130 → 140)
     delay(100);         // Small buffer
     myServo.write(140); // Stronger pull
     delay(500);         // Hold
     myServo.write(90);  // Reset
   }
 }


 delay(1000);
}


float getDistance() {
 long duration;
 float distance;


 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH);
 distance = (duration * 0.0133) / 2;


 return distance;
}


bool checkSensorOverInterval(unsigned long durationToCheck) {
 unsigned long startTime = millis();
 bool withinRange = false;


 while (millis() - startTime < durationToCheck) {
   float distance = getDistance();
   if (distance > 0 && distance <= 4.0) {
     withinRange = true;
   } else {
     return false;
   }
   delay(1000);
 }


 return withinRange;
}


void crushCan() {
 digitalWrite(relayPin1, HIGH);
 digitalWrite(relayPin2, HIGH);
 delay(8000);  // Shortened by 0.5 seconds
 digitalWrite(relayPin1, LOW);
 digitalWrite(relayPin2, LOW);
}


void triggerRapidPin() {
 delay(5000);
 for (int i = 0; i < 2; i++) {
   digitalWrite(rapidPin, HIGH);
   delay(50);
   digitalWrite(rapidPin, LOW);
   delay(50);
 }
}




