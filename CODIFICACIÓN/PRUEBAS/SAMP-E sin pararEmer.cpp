// pines de los sensores infrarrojos
const int sensorIzquierdo = 2;
const int sensorCentral = 3;
const int sensorDerecho = 4;

//pines de los sensores de parada
const int pararGiro = 5;

// pines de los sensores ultrasonicos
const int switchUltrasonico = 6;

// pines para el avance
const int acelerar = 9;

// pines del Puente H
const int puenteHDer = 8;
const int puenteHIzq = 7;


void setup() {

  // pines de sensores de parada
    pinMode(pararGiro, INPUT);

  //pines de sensores ultrasonicos
    pinMode (switchUltrasonico, INPUT);
    
  // pines de sensores como entradas
    pinMode(sensorIzquierdo, INPUT);
    pinMode(sensorCentral, INPUT);
    pinMode(sensorDerecho, INPUT);

  // pines de motores como salidas
    pinMode(acelerar, OUTPUT); 
    pinMode(puenteHDer, OUTPUT); 
    pinMode(puenteHIzq, OUTPUT); 

    digitalWrite(acelerar, LOW);
}

void loop() {
  // leer valores de los sensores
  int lecturaIzquierdo = digitalRead(sensorIzquierdo);
  int lecturaCentral = digitalRead(sensorCentral);
  int lecturaDerecho = digitalRead(sensorDerecho);
  int lecturaUltrasonico = digitalRead(switchUltrasonico);
  int lecturaPararGiro = digitalRead(pararGiro);

  if(lecturaPararGiro = HIGH) {
    detenerGiro();
  } else {

  // si el sensor central detecta la linea, sigue adelante
  if (lecturaCentral == LOW && lecturaIzquierdo == HIGH && lecturaDerecho == HIGH && lecturaUltrasonico == LOW) {
    adelante();
  }
  // si el sensor izquierdo detecta la linea, gira a la izquierda
  else if (lecturaIzquierdo == HIGH && lecturaDerecho == LOW && lecturaUltrasonico == LOW) {
    giraIzquierda();
  }
  // si el sensor derecho detecta la linea, gira a la derecha
  else if (lecturaDerecho == HIGH && lecturaIzquierdo == LOW && lecturaUltrasonico == LOW) {
    giraDerecha();
  }
  // si ningun sensor detecta la linea, detener el montacargas
  else {
    detener();
  }
  delay(100);
}
}
// funcion para avanzar
void adelante() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHDer, LOW);
  digitalWrite(puenteHIzq, LOW);
  Serial.print("Adelante");
}

// funcion para girar a la izquierda
void giraIzquierda() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHIzq, HIGH);
  digitalWrite(puenteHDer, LOW);
  Serial.print("Izquierda");
}

// funcion para girar a la derecha
void giraDerecha() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHDer, HIGH);
  digitalWrite(puenteHIzq, LOW);
  Serial.print("Derecha");
}

// funcion para detener
void detener() {
  digitalWrite(acelerar, LOW);
  digitalWrite(puenteHDer, LOW);
  digitalWrite(puenteHIzq, LOW);
  Serial.print("Detener");
}

// funcion para detener giro
void detenerGiro() {
    digitalWrite(acelerar, HIGH);
    digitalWrite(puenteHDer, LOW);
    digitalWrite(puenteHIzq, LOW);
    Serial.print("Giro Detenido");
}



