/* 
Ejemplo de servos



Basado en Sweep  by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo_1;
Servo myservo_2; 
Servo myservo_3; 
Servo myservo_4;   // create servo object to control a servo
Servo myservo_5; 
Servo myservo_6; 
Servo myservo_7; 
Servo myservo_8; 
Servo myservo_9; 
Servo myservo_10;
Servo myservo_11;
Servo myservo_12;   
Servo myservo_13; 
Servo myservo_14; 
Servo myservo_15; 
Servo myservo_16; 


// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  //For Arduino Mega
  myservo_1.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo_2.attach(2);  // attaches the servo on pin 9 to the servo object
  myservo_3.attach(3);  // attaches the servo on pin 9 to the servo object
  myservo_4.attach(4);  // attaches the servo on pin 9 to the servo object
  myservo_5.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo_6.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo_7.attach(7);  
  myservo_8.attach(8);  
  myservo_9.attach(9);  
  myservo_10.attach(10); 
}

void loop() {


  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
