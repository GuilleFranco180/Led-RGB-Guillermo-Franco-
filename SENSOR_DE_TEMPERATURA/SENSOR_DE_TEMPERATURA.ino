/*
  FUNDACION KINAL
  CENTRO: EDUCATIVO TECNICO LABORAL KINAL
  PERITO EN ELECTRONICA
  QUINTO PERITO
  SECCION: A
  CURSO: TALLER DE ELECTRONICA DIGITAL Y REPARACION DE COMPUTADORAS
  ALUMNOS: Guillermo Antonio Franco Longo
  CARNETS: 2022357
  proyecto: SENSOR DE TEMPERATURA
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define led0 3   
#define led1 4
#define led2 5

LiquidCrystal_I2C lcdFranco(0x27,16,2);
OneWire ourWire(2);
DallasTemperature sensor(&ourWire);

int sensortF();
int sensortC();
int TempF, TempC;

byte termometro[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};

byte caliente[] = {
  B00000,
  B01111,
  B01000,
  B01000,
  B01000,
  B01000,
  B01111,
  B00000
};

byte frio[] = {
  B00000,
  B01111,
  B01000,
  B01110,
  B01000,
  B01000,
  B01000,
  B01000
};

byte templado[] = {
  B00000,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte grados[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  Serial.begin(9600);   //Inicio la comunicacion serial
  lcdFranco.init();  
  lcdFranco.backlight();
  sensor.begin();   //Se inicia el sensor
  lcdFranco.createChar(0, termometro);
  lcdFranco.createChar(1, caliente);
  lcdFranco.createChar(2, frio);
  lcdFranco.createChar(3, templado);
  lcdFranco.createChar(4, grados);
  lcdFranco.home();
  pinMode(led0,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led1,OUTPUT);
}

void loop() {
   TempF = sensortF();
  TempC = sensortC();
 
 
  lcdFranco.setCursor(0,0);
  lcdFranco.print("  TERMOMETRO ");
  lcdFranco.write(byte(0));
  //Temperatura en Celsius
  lcdFranco.setCursor(2,1);
  lcdFranco.print(TempC);
  lcdFranco.write(byte(4));
  lcdFranco.print("C");
  //Temperatura en Fahrenheit
  lcdFranco.setCursor(8,1);
  lcdFranco.print(TempF);
  lcdFranco.write(byte(4));
  lcdFranco.print("F ");


  if(TempC >= 15 && TempC <= 30){
    lcdFranco.setCursor(13,1);
    lcdFranco.write(byte(3));
    delay(800);
    lcdFranco.setCursor(13,1);
    lcdFranco.print(" ");
    digitalWrite(led0,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }

  if(TempC > 30){
    lcdFranco.setCursor(13,1);
    lcdFranco.write(byte(1));
    delay(800);
    lcdFranco.setCursor(13,1);
    lcdFranco.print(" ");
    digitalWrite(led0,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
  }

  if(TempC < 15){
    lcdFranco.setCursor(13,1);
    lcdFranco.write(byte(2));
    delay(800);
    lcdFranco.setCursor(13,1);
    lcdFranco.print(" ");
    digitalWrite(led0,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
  }
}

int sensortC(){
  sensor.requestTemperatures();  
  int temp= sensor.getTempCByIndex(0);
  return temp;
}

int sensortF(){
  sensor.requestTemperatures();  
  int temp1 = sensor.getTempFByIndex(0);
  return temp1;
}
