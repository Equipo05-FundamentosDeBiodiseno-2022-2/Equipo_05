int sensorPh = A2; //Sensor de pH PH-4502C
int ledR = 11; //led roja (nivel elevado) conectado al pin 8
int ledV = 9; //led verde (nivel óptimo) conectado al pin 12
int ledA = 10; //led amarillo (nivel intermedio) conectado al pin 13
double potValue;
double pH;

void setup()
{
  pinMode(sensorPh, INPUT); //entrada sensor pH
  pinMode(ledR, OUTPUT); //salida led
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  Serial.begin (9600);
}

void loop() {
int sensorValue = analogRead(A2);

//Calibración: Se debe realizar una correción del valor de pH realizando una curva de calibración
//La curva fue realizada en el laboratorio. Se obtuvo la siguiente ecuación: 
// y = 2.24x - 0.2
//Donde y es el valor de pH esperado y x es el valor de pH obtenido


float valor_pH = (2.24*(sensorValue * (5.0 / 1023.0)) - 0.2);
  digitalWrite(ledR, LOW);
  digitalWrite(ledV, LOW);
  digitalWrite(ledA, LOW);
Serial.println(volt);
delay(300);

 
 //NIVEL ELEVADO:
 //Si la concentración de glutamato es mayor a 10 μmol/L se enciende led ROJA. 
 //[H+]>10 μmol/L. La solución es más ácida. 

if (6.4 < valor_pH && valor_pH < 6.6) {
    digitalWrite(ledR, HIGH);
    delay(1000);
  }

  //NIVEL INTERMEDIO:
  //Si la concentración de glutamato está entre 2 - 9.99 μmol/L, se enciende la luz AMARILLA
  // 2 < [H+] < 10: 
  if (6.6 < valor_pH && valor_pH < 6.8) {
    digitalWrite(ledA, HIGH);
    delay(1000);
  }

  //NIVEL ÓPTIMPO:
  //Si la concentración de glutamato está entre 0.1 - 1.99 μmol/L, se enciende la luz VERDE
  // 0 < [H+] < 2: 

  if (6.8 < valor_pH && valor_pH < 7) {
    digitalWrite(ledV, HIGH);
    delay(1000);
  }

}
