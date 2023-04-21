/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Maquina expendedora 
   Nombre: Guillermo Antonio Franco Longo
   Fecha: 21 de Abril
*/

#define botton  2
#define botton1  3
int a=0;
  struct producto {
    char Nombre [20];
    int Stock;
    int Precio;
    }

 producto1 ={"Lays",18,3},
 producto2 ={"Doritos",20,5},
 producto3 ={"Chetos",11,7},
 producto4 ={"Crujitos",12,2};

void setup() {
    pinMode(botton, INPUT);
    pinMode(botton1, INPUT);

}

void loop() {
  Serial.begin(9600);
  bool estado_boton1 = digitalRead(botton);
  bool estado_boton2 = digitalRead(botton1);

  if((estado_boton1 == HIGH) && (estado_boton2 == LOW))
  {
    delay(200);
    a++ ;
    if(a == 1){
          Serial.println("Nombre     Stock    Precio");
          Serial.print(producto1.Nombre);
          Serial.print("        ");
          Serial.print(producto1.Stock);
          Serial.print("        ");
          Serial.println(producto1.Precio);
          a++;
          delay(50);
    }
    if(a == 3){
          Serial.print(producto2.Nombre);
          Serial.print("     ");
          Serial.print(producto2.Stock);
          Serial.print("        ");
          Serial.println(producto2.Precio);
          a++;
          delay(50);
    }
    if(a == 5){
          Serial.print(producto3.Nombre);
          Serial.print("      ");
          Serial.print(producto3.Stock);
          Serial.print("        ");
          Serial.println(producto3.Precio);
          a++;
          delay(50);
        }  
        if(a == 7){
          Serial.print(producto4.Nombre);
          Serial.print("    ");
          Serial.print(producto4.Stock);
          Serial.print("        ");
          Serial.println(producto4.Precio);
          a++;
          delay(50);
          if(a>7){
            a = 0;
                     }
        }  
     }
        if((estado_boton2 == HIGH) && (estado_boton1 == LOW))
        {
          delay(200);
          a--;
          if(a == 1){
          Serial.print(producto4.Nombre);
          Serial.print("    ");
          Serial.print(producto4.Stock);
          Serial.print("        ");
          Serial.println(producto4.Precio);
          delay(50);
          a==8;
          }
           if(a == 3){
          Serial.print(producto1.Nombre);
          Serial.print("        ");
          Serial.print(producto1.Stock);
          Serial.print("        ");
          Serial.println(producto1.Precio);
          delay(50);
          a--;
          }
           if(a == 5){
          Serial.print(producto2.Nombre);
          Serial.print("     ");
          Serial.print(producto2.Stock);
          Serial.print("        ");
          Serial.println(producto2.Precio);
          delay(50);
          a--;
          }
           if(a == 7){
          Serial.print(producto3.Nombre);
          Serial.print("      ");
          Serial.print(producto3.Stock);
          Serial.print("        ");
          Serial.println(producto3.Precio);
          delay(50);
          a--;
          }
           if(a<0){
            a = 8;
                     }
      }
         
}
