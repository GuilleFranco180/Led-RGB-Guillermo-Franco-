/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: SECUENCIA DE LUCES AUTOMATICAS.
   Nombre: Guillermo Antonio Franco Longo 
   Encardo: Profe. Alejandro Lopez Navas
   Fecha: 13 de Abril
*/
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define L5 6
#define L6 7
#define L7 8
#define L8 9
#define L9 10
#define A 11
#define setpinOutput(pin)       pinMode(pin, OUTPUT) 
#define SBI(pin)                digitalWrite(pin, HIGH)  
#define CBI(pin)                digitalWrite(pin, LOW)

void setup()
{
 pinMode(L1,OUTPUT);
 pinMode(L2,OUTPUT);
 pinMode(L3,OUTPUT);
 pinMode(L4,OUTPUT);
 pinMode(L5,OUTPUT);
 pinMode(L6,OUTPUT);
 pinMode(L7,OUTPUT);
 pinMode(L8,OUTPUT);
 pinMode(L9,OUTPUT);
 pinMode(A,OUTPUT);
 

}

void loop()  
{
 digitalWrite(L1,HIGH);
 delay(500);
 digitalWrite(L1,LOW);
 delay(100);
 
 digitalWrite(L2,HIGH);
 delay(500);
 digitalWrite(L2,LOW);
 delay(100);
 
 digitalWrite(L3,HIGH);
 delay(500);
 digitalWrite(L3,LOW);
 delay(100);
 
 digitalWrite(L4,HIGH);
 delay(500);
 digitalWrite(L4,LOW);
 delay(100);
 
 digitalWrite(L5,HIGH);
 delay(500);
 digitalWrite(L5,LOW);
 delay(100);
 
 digitalWrite(L6,HIGH);
 delay(500);
 digitalWrite(L6,LOW);
 delay(100);
 
 digitalWrite(L7,HIGH);
 delay(500);
 digitalWrite(L7,LOW);
 delay(100);
 
 digitalWrite(L8,HIGH);
 delay(500);
 digitalWrite(L8,LOW);
 delay(100);

 digitalWrite(L9,HIGH);
 delay(500);
 digitalWrite(L9,LOW);
 delay(100);
 
 digitalWrite(A,HIGH);
 delay(500);
 digitalWrite(A,LOW);
 delay(100);

 digitalWrite(L9,HIGH);
 delay(500);
 digitalWrite(L9,LOW);
 delay(100);
 
 digitalWrite(L8,HIGH);
 delay(500);
 digitalWrite(L8,LOW);
 delay(100);
 
 digitalWrite(L7,HIGH);
 delay(500);
 digitalWrite(L7,LOW);
 delay(100);
 
 digitalWrite(L6,HIGH);
 delay(500);
 digitalWrite(L6,LOW);
 delay(100);
 
 digitalWrite(L5,HIGH);
 delay(500);
 digitalWrite(L5,LOW);
 delay(100);
 
 digitalWrite(L4,HIGH);
 delay(500);
 digitalWrite(L4,LOW);
 delay(100);
 
  digitalWrite(L3,HIGH);
 delay(500);
 digitalWrite(L3,LOW);
 delay(100);
 
 digitalWrite(L2,HIGH);
 delay(500);
 digitalWrite(L2,LOW);
 delay(100);
 
 digitalWrite(L1,HIGH);
 delay(500);
 digitalWrite(L1,LOW);
 delay(100);
 
}
