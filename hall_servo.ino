#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);   // attaches the servo on pin 9 to the servo object
  pinMode(13,OUTPUT);  // LED output
  pinMode(8,INPUT);    // Hall input
}

void loop() {

  digitalWrite(13, LOW);  // LED on
  
  while (digitalRead(8) == LOW);  // Wait for Hall to activate
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  while (digitalRead(8) == HIGH);  // Wait for Hall to deactivate
  
  digitalWrite(13, HIGH);  // LED off
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

}

