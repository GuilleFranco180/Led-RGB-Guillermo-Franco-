/*
  FUNDACION KINAL
  CENTRO: EDUCATIVO TECNICO LABORAL KINAL
  PERITO EN ELECTRONICA
  QUINTO PERITO
  SECCION: A
  CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
  ALUMNOS: Guillermo Antonio Franco Longo
  CARNETS: 2022357
  proyecto: ALARMA DE DISTANCIA
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trig 2
#define echo 3
#define buz  4
#define led0 5
#define led1 6
#define led2 7
#define led3 8
#define led4 9
#define led5 10
#define led6 11
#define led7 12
#define led8 A1
#define led9 A2

int distancia;

int medicion();


LiquidCrystal_I2C lcdFranco(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcdFranco.init();
  lcdFranco.backlight();
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trig, LOW);

}

void loop() {
  distancia = medicion();
  if (distancia > 45) {
    lcdFranco.setCursor(0, 0);
    lcdFranco.print("Fuera                 ");
    lcdFranco.setCursor(0, 1);
    lcdFranco.print("de alcance    ");
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);

  }

  if (distancia >= 30 && distancia < 45) {
    lcdFranco.setCursor(0, 0);
    lcdFranco.print("Persona/objeto      ");
    lcdFranco.setCursor(0, 1);
    lcdFranco.print("Acercandose         ");
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
  }

  if (distancia >= 15 && distancia < 30) {
    
    lcdFranco.setCursor(0, 0);
    lcdFranco.print("Cuidado,           ");
    lcdFranco.setCursor(0, 1);
    lcdFranco.print("espacio Privado    ");
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
    digitalWrite(led9, LOW);
    tone(buz, 800, 5000);
    delay(100);
    noTone(buz);
  }

  if (distancia >= 5 && distancia < 15) {
    lcdFranco.setCursor(0, 0);
    lcdFranco.print("Invadiendo            ");
    lcdFranco.setCursor(0, 1);
    lcdFranco.print("Espacio Privado       ");
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, HIGH);
    digitalWrite(led9, HIGH);
    tone(buz, 200, 10000);
    delay(100);
    noTone(buz);
  }
}

int medicion() {
  long t;
  long d;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  t = pulseIn(echo, HIGH);
  d = t / 58;
  Serial.println(d);
  return d;
}
