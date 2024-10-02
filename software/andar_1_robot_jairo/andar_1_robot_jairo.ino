#define pierna_dcha 0
#define codo_dcho 1
#define pierna_izda 2
#define codo_izdo 3
#define rotacion_hombro_dcho 11
#define flexion_hombro_dcho 5
#define giro_codo_dcho 6
#define rotacion_hombro_izdo 7
#define flexion_hombro_izdo 8
#define giro_codo_izdo 9
#define rodilla_dcha 10
#define rodilla_izda 4
#define cuello 12
#define cabeza 13
#define pie_dcho 14
#define pie_izdo 15


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
    setServo(pierna_dcha,40);
    setServo(pierna_izda,20);
    setServo(rotacion_hombro_dcho,0);
    setServo(giro_codo_dcho,120);
    setServo(flexion_hombro_izdo,0);
    setServo(rodilla_dcha,30);
    setServo(cuello,90);
    setServo(pie_dcho,170);
    //Impares
    setServo(codo_dcho,40);
    setServo(codo_izdo,0);
    setServo(flexion_hombro_dcho,60);
    setServo(rotacion_hombro_izdo,0);
    setServo(giro_codo_izdo,40);
    setServo(rodilla_izda,90);
    setServo(cabeza,180);
    setServo(pie_izdo,120);

    delay(700);

    //Pares
    setServo(pierna_dcha,120);
    setServo(pierna_izda,70);
    setServo(rotacion_hombro_dcho,90);
    setServo(giro_codo_dcho,30);
    setServo(flexion_hombro_izdo,45);
    setServo(rodilla_dcha,160);
    setServo(cuello,90);
    setServo(pie_dcho,30);
    //Impares
    setServo(codo_dcho,40);
    setServo(codo_izdo,0);
    setServo(flexion_hombro_dcho,90);
    setServo(rotacion_hombro_izdo,40);
    setServo(giro_codo_izdo,30);
    setServo(rodilla_izda,90);
    setServo(cabeza,180);
    setServo(pie_izdo,120);
    
    delay(700);
    
}

