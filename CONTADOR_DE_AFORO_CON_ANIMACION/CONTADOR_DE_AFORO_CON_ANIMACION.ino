/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: CONTADOR DE AFORO CON ANIMACION 
   alumno: Guillermo Antonio Franco Longo
   Fecha: 5 de Mayo 2023
*/

#include <LiquidCrystal.h>


#define rs 2
#define enable 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
int contador=0;
int buzzer=10;
int trig=8;
int echo=9;
int tiempo;
int distancia;
 LiquidCrystal LCD_FRANCO(rs,enable,D4,D5,D6,D7);
byte customChar[] = {
  B01110,
  B01110,
  B01110,
  B00100,
  B11111,
  B00100,
  B01010,
  B01010
};
byte m1[] = {
  B01110,
  B01110,
  B01110,
  B10101,
  B01110,
  B00100,
  B01010,
  B10001
};

 void setup(){
   LCD_FRANCO.begin(16, 2);
  LCD_FRANCO.createChar(0, customChar);
   LCD_FRANCO.begin(16, 2);
  LCD_FRANCO.createChar(1, m1);
  pinMode(buzzer,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  LCD_FRANCO.begin(16,2);
 }
 void loop(){
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  tiempo=pulseIn(echo, HIGH);
  distancia=tiempo/50.2;
 
     if ((distancia>6) && (distancia<10)){
 contador++;
     }
   if(contador<17){
      LCD_FRANCO.setCursor(0,0);
  LCD_FRANCO.print("personas");
  LCD_FRANCO.setCursor(0,1);
  LCD_FRANCO.println(contador);
     delay(1000);
 
     }
   if ((contador > 17)){
 tone(buzzer,261.63);
     noTone(buzzer);
      LCD_FRANCO.setCursor(0,1);
  LCD_FRANCO.clear();
  LCD_FRANCO.setCursor(0,2);
  LCD_FRANCO.clear();
     LCD_FRANCO.setCursor(0,0);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(1,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(2,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(3,0);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(4,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(5,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(6,0);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(7,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(8,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(9,0);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(10,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(11,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(12,0);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(13,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(14,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(15,0);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(0,2);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(1,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(2,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(3,2);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(4,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(5,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(6,2);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(7,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(8,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(9,2);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(10,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(11,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(12,2);
       LCD_FRANCO.write(byte(0));
      LCD_FRANCO.setCursor(13,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(14,2);
       LCD_FRANCO.write(byte(0));
     LCD_FRANCO.setCursor(15,2);
       LCD_FRANCO.write(byte(0));
     delay(500);
     LCD_FRANCO.setCursor(0,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(1,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(2,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(3,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(4,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(5,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(6,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(7,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(8,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(9,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(10,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(11,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(12,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(13,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(14,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(15,0);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(0,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(1,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(2,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(3,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(4,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(5,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(6,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(7,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(8,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(9,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(10,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(11,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(12,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(13,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(14,2);
       LCD_FRANCO.write(byte(1));
     LCD_FRANCO.setCursor(15,2);
       LCD_FRANCO.write(byte(1));
     delay(500);
     tone(buzzer,261.63);
     delay(500);
     noTone(buzzer);
     delay(100);
      contador=16;
 
     }
 }
