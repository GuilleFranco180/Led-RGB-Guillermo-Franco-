/*
  Fundación Kinal
  Centro Educativo Técnico Labral Kinal
  Electrónica
  Grado: Quinto
  Sección: A
  Curso: Taller de Electrónica Digital y Reparación de Computadoras I
  Nombre: Jose Javier Juarez Rivera
  Carné: 2022252
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trig 2
#define echo 3

int medidas; 
int i, a;
int medicion();

LiquidCrystal_I2C lcdFranco(0x27, 16, 2);

byte customChar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  Serial.begin(9600);
  lcdFranco.init();
 lcdFranco.backlight();
  lcdFranco.createChar(0, customChar);
  lcdFranco.home();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);

}

void loop() {
  medidas = medicion();
  if (medidas > 70) {
    lcdjj.clear();
  }
  switch (medidas) {
    case 50:
     lcdFranco.setCursor(7, 0);
     lcdFranco.print("50    ");
     lcdFranco.setCursor(0, 1);
    lcdFranco.print("     LIBRE     ");
      i = 0;
      a = 13;
      for (i == 0; i <= 2; i++) {
       lcdFranco.setCursor(i, 0);
       lcdFranco.write(byte(0));
      lcdFranco.setCursor(3, 0);
     lcdFranco.print("    ");
      }
      for (a == 13; a <= 15; a++) {
       lcdFranco.setCursor(a, 0);
        lcdFranco.write(byte(0));
      }
      break;

    case 30:
      lcdFranco.setCursor(7, 0);
      lcdFranco.print("30  ");
      lcdFranco.setCursor(0, 1);
      lcdFranco.print("    CUIDADO!     ");
      i = 0;
      a = 11;
      for (i == 0; i <= 4; i++) {
        lcdFranco.setCursor(i, 0);
        lcdFranco.write(byte(0));
       lcdFranco.setCursor(5, 0);
        lcdFranco.print("  ");
      }
      for (a == 11; a <= 15; a++) {
        lcdFranco.setCursor(a, 0);
        lcdFranco.write(byte(0));
      }
      break;

    case 10:
      lcdjj.setCursor(7, 0);
      lcdFranco.print("10");
      lcdFranco.setCursor(0, 1);
      lcdFranco.print("     ALTO!!     ");
      i = 0;
      a = 9;
      for (i == 0; i <= 6; i++) {
        lcdFranco.setCursor(i, 0);
        lcdFranco.write(byte(0));
      }
      for (a == 9; a <= 15; a++) {
        lcdFranco.setCursor(a, 0);
        lcdFranco.write(byte(0));
      }
      break;
  }
}

int medicion() {
  long d;
  long t;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);
  d = t / 58;
  Serial.println(d);
  return d;
}
