int trig = 4;
int echo  = 5;
int buz  = 3;
int duracion;
int distancia;

void setup() {
 pinMode(trig, OUTPUT);
 pinMode(echo, OUTPUT);
 pinMode(buz, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / 50.2;
  Serial.println(distancia);
  delay(200);
    if((distancia <= 0 && distancia >= 4)) {
  
  Serial.print(" ");
    tone(buz, 0, 500 );
    digitalWrite(buz, LOW);
    delay(500);
    digitalWrite(buz, LOW);
  }
  if((distancia <= 5 && distancia >= 10)) {
  
  Serial.print("DO");
    tone(buz, 261.63, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
   if((distancia <= 11 && distancia >= 15)) {
  
  Serial.print("RE");
    tone(buz, 293.66, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
   if((distancia <= 16 && distancia >= 20)) {
  
  Serial.print("MI");
    tone(buz, 329.63, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
    if((distancia <= 21 && distancia >= 25)) {
  
  Serial.print("FA");
    tone(buz, 349.23, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
    if((distancia <= 26 && distancia >= 30)) {
  
  Serial.print("SOL");
    tone(buz, 392, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
    if((distancia <= 31 && distancia >= 35)) {
  
  Serial.print("LA");
    tone(buz, 440, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
    if((distancia <= 36 && distancia >= 40)) {
  
  Serial.print("SI");
    tone(buz, 493.88, 500 );
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(buz, LOW);
  }
  else {
    noTone(buz);
  }
  }

 
