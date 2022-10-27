
int interruptor =3; //Switch para encender y apagar el circuito
int intval = 0; //Valor para el interruptor
int sensorPh =A0; //potenciómetro conectado a A0. Este simulará el sensor de pH PH-4502C
int ledR =8; //led roja (nivel elevado) conectado al pin 8
int ledV =12; //led verde (nivel óptimo) conectado al pin 12
int ledA = 13; //led amarillo (nivel intermedio) conectado al pin 13
double potValue;
double pH;

void setup()
{
  pinMode(sensorPh, INPUT); //entrada sensor pH
  pinMode (interruptor, INPUT); //entrada switch encendido/apagado
  pinMode(ledR, OUTPUT); //salida led
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  //Primero se debe identificar si el switch está encendido o apagado
  intval = digitalRead(interruptor); 
  
  if (intval == LOW){
    digitalWrite(ledR, LOW);
    digitalWrite(ledV, LOW);
    digitalWrite(ledA, LOW);
   }
  else {
    Serial.println (pH); //imprime por monitor el valor de pH
  	potValue = analogRead (sensorPh); //se almacena el valor en potValue
    digitalWrite(ledR, LOW);
  	digitalWrite(ledV, LOW);
  	digitalWrite(ledA, LOW);
  
  	//Para hallar el pH se utiliza la siguiente fórmula: 
  	//pH = -log([H+])
  
 	 //Corrección valor de pH para obtener un rango de 0 a 14
 	 pH = (14 * potValue / 1023);
  
  	//NIVEL ELEVADO:
  	//Si la concentración de glutamato es mayor a 10 μmol/L se enciende led roja
  	//[H+]>10 μmol/L -> 0 < pH < 5. La solución es muy ácida:
 	 if (0 < pH && pH < 5){
   	  digitalWrite(ledR, HIGH);
   	  delay(1000); 
  	}
  
 	 //NIVEL INTERMEDIO: 
  	//Si la concentración de glutamato está entre 2 - 9.99 μmol/L, se enciende la luz amarilla
  	// 2 < [H+] < 9.99 -> 5.01 < pH < 5.69 
  	if (5.01 < pH && pH < 5.69){
   	 digitalWrite(ledA, HIGH);
     delay(1000);
  	} 
  
  	//NIVEL ÓPTIMPO:
  	//Si la concentración de glutamato está entre 0.1 - 1.99 μmol/L, se enciende la luz verde
  	// 0.1 < [H+] < 1.99 -> 5.70 < pH < 7
  	if (5.70 < pH && pH < 7){
   	 digitalWrite(ledV, HIGH);
     delay(1000);
     }
   }   
 }


    


