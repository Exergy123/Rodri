//https://naylampmechatronics.com/blog/41_tutorial-modulo-controlador-de-servos-pca9685-con-arduino.html

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
  
    setServo(0,30);
    setServo(2,90);
    setServo(4,180);
    setServo(6,120);
    setServo(8,0);
    setServo(10,30);
    setServo(12,90);
    setServo(14,170);
    delay(1000);
    setServo(1,30);
    setServo(3,90);
    setServo(5,180);
    setServo(7,120);
    setServo(9,30);
    setServo(11,90);
    setServo(13,180);
    setServo(15,120);
    delay(1000);
    setServo(0,120);
    setServo(2,180);
    setServo(4,90);
    setServo(6,60);
    setServo(8,45);
    setServo(10,160);
    setServo(12,170);
    setServo(14,30);
    delay(1000);
    setServo(1,120);
    setServo(3,0);
    setServo(5,90);
    setServo(7,60);
    setServo(9,120);
    setServo(11,180);
    setServo(13,0);
    setServo(15,30);
    delay(1000);
    
}