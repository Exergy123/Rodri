Tutorial Módulo Controlador de servos PCA9685 con Arduino
EL controlador PCA9685 fue diseñado para controlar leds por PWM, pero también nos permite controlar servos, ya que estos también se controlan por PWM, aplicación que actualmente es muy usada.


El Módulo Controlador de servos PCA9685 tiene la placa diseñada para el control de servos, tiene los pines en el orden correcto para simplemente conectar los servomotores, además una bornera para la alimentación de los servos y conectores para la alimentación de la parte lógica junto con los pines I2C para comunicarse con arduino.

Se puede establecer la dirección I2C soldando los puentes A0-A5 con esto podemos usar el mismo bus I2C para controlar más módulos PCA9685 u otros dispositivos I2C

 Módulo Controlador de servos PCA9685

EL PCA9685 nos permite controlar individualmente 16 salidas PWM con 12 bits de resolución y con frecuencia máxima de 1600Hz.

La salida PWM que envía el PCA9685 es de la siguiente forma:

 Pulso PWM PCA9685 

 

Básicamente lo se tiene que establecer es la frecuencia de la señal PWM, frecuencia que será la misma para las 16 salidas PWM. Para establecer el ciclo de trabajo (Duty) tenemos que manipular el flanco de subida (Up) y flanco de bajada (Down), esto se configura individualmente para cada salida PWM, La resolución del PWM es de 12 bits (de 0 a 4095)

Conexión Entre Arduino y Modulo PCA9685
 

Módulo PCA9685

Arduino Uno, Nano, Mini.

Arduino Mega , DUE

Arduino Leonardo

  GND

GND

GND

GND

  OE

GND

GND

GND

  SCL

A5

21

3

  SDA

A4

20

2

  VCC

5V

5V

5V

  +V

No conectado

No conectado

No conectado

 

VCC es la alimentación para la parte lógica del módulo y V+ es la alimentación para los servomotores, entonces adicionalmente se tienen que conectar una fuente externa a V+ y GND, fuente que debe ser  del voltaje correspondiente a los servos. No usar los 5V que entrega Arduino para alimentar a lo servos pues los 5V que entrega la placa Arduino es de poca corriente.

La mayoría de servos trabajan con voltajes de 4.5 y 6V nosotros usaremos una fuente de 5V / 5A.

La corriente mínima de la fuente externa depende del tipo de servomotores que se use y de la cantidad de servos que estarán conectados, Si bien la corriente no es un dato constante en el servomotor es mejor sobredimensionar la fuente para que trabaje correctamente, si la fuente no es muy estable o genera ruido, es necesario soldar un condensador en el espacio de la placa del Módulo con una valor de 1000uF o el equivalente a 100uF por cada servomotor.

Entonces, gráficamente las conexiones serian dela siguiente forma:

 Conexion arduino y PCA9685 

 

Librería PCA9685 para Arduino
Usaremos la librería de Adafruit el cual lo pueden descargar aquí:
https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library

Después de descargar necesitan importar la librería al IDE Arduino

Expliquemos como usar la librería:

Como cualquier librería inicialmente se incluyen las librerías correspondientes y se declara la variable u objeto:

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(dirección);

La dirección si no han modificado en su placa del módulo PCA9685 es 0x40, si desean modificar la dirección, necesitan soldar los puentes de la placa, y queda establecida por: Dirección=0|1|A5|A4|A3|A2|A1|A0, por ejemplo si no sueldan ningún puente seria 01000000=0x40, si sueldan el segundo puente seria: 01000100=0x44

El siguiente paso es inicializar el objeto creado anteriormente.

  servos.begin();  
Posteriormente configurar la frecuencia del PWM, que será la misma para los 16 canales PWM

  servos.setPWMFreq(60); 

La frecuencia que usamos es de 60Hz que equivale una señal PWM con periodo 16,6ms que se encuentra dentro del rango del ciclo de trabajo de la mayoría de los servos

Para establecer el ancho de pulso de una salida PWM usamos la siguiente función

  servos.setPWM(n_servo, up, down);  

En este caso n_servo es el número de servo o salida que van a configurar (valor entre 0 y 15), up es el valor de cuentas en el que se producirá el flanco de subida, y down el valor para el flanco de bajada, ambos valores deben estar entre el valor de 0 y 4096 (12bits). El ancho de pulso será la resta de down-up.

Explicado el uso de la librería vamos a ver unos ejemplos:

 
