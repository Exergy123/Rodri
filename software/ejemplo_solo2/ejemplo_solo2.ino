#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

void setup() {
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}

void loop() {
  
    setServo(0,0);
    setServo(1,0);
    setServo(2,0);
    setServo(3,0);
    /*
    setServo(4,0);
    setServo(5,0);
    setServo(6,0);
    setServo(7,0);
    setServo(8,0);
    setServo(9,0);
    setServo(10,0);
    setServo(11,0);
    setServo(12,0);
    setServo(13,0);
    setServo(14,0);
    setServo(15,0);
    */   
    delay(1000);
    setServo(0,90);
    setServo(1,90);
    setServo(2,90);
    setServo(3,90);
   /*
    setServo(4,0);
    setServo(5,0);
    setServo(6,0);
    setServo(7,0);
    setServo(8,0);
    setServo(9,0);
    setServo(10,0);
    setServo(11,0);
    setServo(12,0);
    setServo(13,0);
    setServo(14,0);
    setServo(15,0);
    */
    delay(1000);
    setServo(0,180);
    setServo(1,180);
    setServo(2,180);
    setServo(3,180);
     /*
    setServo(4,0);
    setServo(5,0);
    setServo(6,0);
    setServo(7,0);
    setServo(8,0);
    setServo(9,0);
    setServo(10,0);
    setServo(11,0);
    setServo(12,0);
    setServo(13,0);
    setServo(14,0);
    setServo(15,0);
    */



    delay(1000);
    setServo(0,60);
    setServo(1,60);
    setServo(2,60);
    setServo(3,60);
     /*
    setServo(4,0);
    setServo(5,0);
    setServo(6,0);
    setServo(7,0);
    setServo(8,0);
    setServo(9,0);
    setServo(10,0);
    setServo(11,0);
    setServo(12,0);
    setServo(13,0);
    setServo(14,0);
    setServo(15,0);
    */
    delay(1000);
}