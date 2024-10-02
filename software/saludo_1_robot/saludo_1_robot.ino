
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
/*unsigned int pos0=500; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=2500; // ancho de pulso en cuentas para la pocicion 180°*/

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

void setup() {
  // put your setup code here, to run once:
servos.begin();  
  servos.setPWMFreq(50); //Frecuecia PWM de 60Hz o T=16,66ms
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}

void loop() {
  // put your main code here, to run repeatedly:

    //Pares
    setServo(0,60);
    setServo(2,90);
    setServo(4,180);
    setServo(6,120);
    setServo(8,0);
    setServo(10,30);
    setServo(12,90);
    setServo(14,170);
    
    delay(1000);

    //Impares
    setServo(1,20);
    setServo(3,90);
    setServo(5,60);
    setServo(7,120);
    setServo(9,40);
    setServo(11,90);
    setServo(13,180);
    setServo(15,120);

    delay(1000);
    //Pares
    setServo(0,60);
    setServo(2,90);
    setServo(4,45);
    setServo(6,30);
    setServo(8,45);
    setServo(10,160);
    setServo(12,170);
    setServo(14,30);

    delay(1000);
    //Impares
    setServo(1,15);
    setServo(3,30);
    setServo(5,90);
    setServo(7,120);
    setServo(9,30);
    setServo(11,90);
    setServo(13,180);
    setServo(15,120);

    delay(1000);
    
}

