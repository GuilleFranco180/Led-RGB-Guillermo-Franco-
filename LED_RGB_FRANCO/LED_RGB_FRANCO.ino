/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: CONTROL DE UN LED RGB POR MEDIO DE BOTONES
   Nombre: Guillermo Antonio Franco Longo
   Fecha: 14 de Abril
*/


#define push_button 2
#define LedR        4  
#define push_button1 3
#define LedG        5
#define LedB        6
#define setpinInput(pin)        pinMode(pin,INPUT)
#define setpinInputPullup(pin)  pinMode(pin, INPUT_PULLUP)
#define setpinOutput(pin)       pinMode(pin, OUTPUT)      
#define SBI(pin)                digitalWrite(pin, HIGH)  
#define CBI(pin)                digitalWrite(pin, LOW)    

void setup()
{
  setpinInput(push_button);
  setpinInput(push_button1);
  setpinOutput(LedR);
  CBI(LedR);
  setpinOutput(LedG);
  CBI(LedG);
  setpinOutput(LedB);
  CBI(LedB);
  Serial.begin(9600);
}

void loop()
{
 
  bool estado_boton = digitalRead(push_button);
  bool estado_boton1 = digitalRead(push_button1);
 
  if (digitalRead(push_button) == HIGH && digitalRead(push_button1) == HIGH )
  {
    SBI(LedR);
    CBI(LedG);
    CBI(LedB);
    delay(1000);  
    SBI(LedG);
    CBI(LedR);
    CBI(LedB);
    delay(1000);
    SBI(LedB);
    CBI(LedG);
    CBI(LedR);
    delay(1000);
  }

  if (digitalRead(push_button) == HIGH && digitalRead(push_button1) == LOW )
  {
    SBI(LedR);
    SBI(LedG);
    CBI(LedB);
    delay(1000);
  }
  if (digitalRead(push_button) == LOW && digitalRead(push_button1) == HIGH )
  {
    CBI(LedR);
    SBI(LedG);
    SBI(LedB);
    delay(1000);
  }
  if (digitalRead(push_button) == LOW && digitalRead(push_button1) == LOW )
  {
   
    SBI(LedR);
    CBI(LedG);
    SBI(LedB);
    delay(1000);
}
}
