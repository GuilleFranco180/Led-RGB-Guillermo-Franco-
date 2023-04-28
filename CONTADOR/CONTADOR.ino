
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: keypad
   alumno:Guillermo Antonio Franco Longo
   Fecha: 27 de abril 2023
*/

#define led 2
#define H(pin) digitalWrite(pin, HIGH)
#define L(pin) digitalWrite(pin, LOW)

void configPinesInput(void);
void configpinesOutput(void);
int contador_display(int a, int b, int c, int d, int e, int f, int g, int B);
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador=0;
int dis7;

void setup() {
  Serial.begin(9600);
  configPinesInput();
  configpinesOutput(); 

  
  
}

void loop() {


  
  digitalWrite(trig, LOW);
  delay(10); 
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
             


  duracion = pulseIn(echo, HIGH); 
                                  
  
  distancia= duracion*0.034/2;    
  Serial.print(String(distancia));
  Serial.println(" cm");
  delay(400);
if(distancia>=6 && distancia <=10)
  {
    contador++;
     Serial.println("contador");
     delay(1000);
    }
  else
  {

    }
  

    contador_display(3,4,5,6,7,8,9,2);

           
          
     
}
 void configPinesInput(void){
  pinMode(echo, INPUT);
  
 }

void configpinesOutput(void)
{
     pinMode(led, OUTPUT);
     pinMode(trig, OUTPUT);  
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(2, OUTPUT);           
                     
}
int contador_display(int a, int b, int c, int d, int e, int f, int g, int B){
switch(contador){
          case(0):
            L(a);
            L(b);
            L(c);
            L(d);
            L(e);
            L(f);
            H(g);
            break;
          case(1):
            H(a);
            L(b);
            L(c);
            H(d);
            H(e);
            H(f);
            H(g);
         break;
           case(2):
            L(a);
            L(b);
            H(c);
            L(d);
            L(e);
            H(f);
            L(g);
         break;
          case(3):
            L(a);
            L(b);
            L(c);
            L(d);
            H(e);
            H(f);
            L(g);
         break;
          case(4):
            H(a);
            L(b);
            L(c);
            H(d);
            H(e);
            L(f);
            L(g);
         break;                
          case(5):
            L(a);
            H(b);
            L(c);
            L(d);
            H(e);
            L(f);
            L(g);
         break;       
          case(6):
            L(a);
            H(b);
            L(c);
            L(d);
            L(e);
            L(f);
            L(g);
         break;        
          case(7):
            L(a);
            L(b);
            L(c);
            H(d);
            H(e);
            H(f);
            H(g);
         break;
          case(8):
            L(a);
            L(b);
            L(c);
            L(d);
            L(e);
            L(f);
            L(g);
         break;
           case(9):
            L(a);
            L(b);
            L(c);
            L(d);
            H(e);
            L(f);
            L(g);
            L(B);
            contador=9;
            H(led);
         break; 
             
    }
  
}
