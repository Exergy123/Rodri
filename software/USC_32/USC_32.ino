


// Este programa va en el arduino y se conecta al USC-32 a traves de comunicación serie (RX Y TX)
//

/*
El controlador USC-32 recibe comandos a través del puerto serie. Estos comandos tienen la forma


[channel] P[pw] ... #[channel] P[pw] T[time] \n\r
Siendo,

[channel] = Número de servo (1 a 32)
[pw] = Ancho del pulso = posición deseada (rango de 500 a 2500, en us)
[time] = Tiempo para mover todos los servos del comando (en ms)
\n\r = Salto de línea
Un ejemplo de comando sería el siguiente,

*/
//#11 P2000 #30 P2500 T1500 \n\r
//[channel] P[pw] ... #[channel] P[pw] T[time] \n\r



uint8_t ServoMinMs = 500; // ancho de pulso en ms para pocicion 0°
uint8_t ServoMaxMs = 2500; // ancho de pulso en ms para la pocicion 180°

void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  for (uint8_t servo = 0; servo < 32; servo++)
  {
    for (uint16_t servoPos = ServoMinMs; servoPos < ServoMaxMs; servoPos++)
    {
      moveServo(servo, servoPos, 500);
    }
  }
  delay(750
  for (uint8_t servo = 0; servo < 32; servo++)
  {
    for (uint16_t servoPos = ServoMaxMs; servoPos > ServoMinMs; servoPos--)
    {
      moveServo(servo, servoPos, 500);
    }
  }
  delay(750);
}

void moveServo(uint8_t servo, uint16_t position, uint16_t time)
{
  Serial.print("#");
  Serial.print(servo);
  Serial.print("P");
  Serial.print(position);
  Serial.print("T");
  Serial.println(time);
}