#include <Servo.h>
Servo servo1, servo2;
int angle = 10;
// defines pins numbers
const int trigPin = 12;
const int echoPin = 11;
// defines variables
long duration;
int distance;

void setup() {
  servo1.attach(8);
  servo1.write(angle);
  
  servo2.attach(9);
  servo2.write(angle);
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Distance: ");
Serial.println(distance);
delay(10);

if(distance<20)
{
  servo1.write(45);
  servo2.write(45);
  delay(100);
  servo1.write(135);
  servo2.write(135);
  delay(100);
  servo1.write(180);
  servo2.write(180);
  delay(1000);
  servo1.write(0);
  servo2.write(0);
  delay(3000);
}
}
