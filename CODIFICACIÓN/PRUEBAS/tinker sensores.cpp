// pines de los sensores
const int sensorIzquierdo = 2;
const int sensorCentral = 3;
const int sensorDerecho = 4;
const int pinEcho = 5;
const int pinTrigger = 6;


// pines del Puente H
const int puenteHIzq = 7;
const int puenteHDer = 8;

// pines para el avance
const int acelerar = 9;


void setup() {
  // pines de sensores como entradas
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorCentral, INPUT);
  pinMode(sensorDerecho, INPUT);
  
  //pines de sensores de proximidad
  serial.begin(9600);
  pinMode(pinEcho, INPUT);
  pinMode(pinTrigger, OUTPUT);

  // pines de motores como salidas
  pinMode(acelerar, OUTPUT); 
  pinMode(puenteHDer, OUTPUT); 
  pinMode(puenteHIzq, OUTPUT); 

  digitalWrite(acelerar, LOW);
}


void loop() {

    digitalWrite(pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigger, HIGH); // genera el pulso de trigger por 10ms
    delayMicroseconds(10);
    digitalWrite(pinTrigger, LOW);

    duracion = pulseIN(pinEcho, HIGH);
    distancia = (duracion/2) / 29;      // calcula la distancia en centimetros

    if (distancia >= && distancia <= 1) {
        detener();                      // si la distancia es menor a (definir) se frena
    }
    delay(400);

  // leer valores de los sensores
  int lecturaIzquierdo = digitalRead(sensorIzquierdo);
  int lecturaCentral = digitalRead(sensorCentral);
  int lecturaDerecho = digitalRead(sensorDerecho);

  // si el sensor central detecta la linea, sigue adelante
  if (lecturaCentral == LOW && lecturaIzquierdo == HIGH && lecturaDerecho == HIGH) {
    adelante();
  }
  // si el sensor izquierdo detecta la linea, gira a la izquierda
  else if (lecturaIzquierdo == LOW) {
    giraIzquierda();
  }
  // si el sensor derecho detecta la linea, gira a la derecha
  else if (lecturaDerecho == LOW) {
    giraDerecha();
  }
  // si ningun sensor detecta la linea, detener el montacargas
  else {
    detener();
  }
}

// funcion para avanzar
void adelante() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHDer, LOW);
  digitalWrite(puenteHIzq, LOW);
}

// funcion para girar a la izquierda
void giraIzquierda() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHIzq, HIGH);
  digitalWrite(puenteHDer, LOW);

}

// funcion para girar a la derecha
void giraDerecha() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHDer, HIGH);
  digitalWrite(puenteHIzq, LOW);
}

// funcion para detener
void detener() {
  digitalWrite(acelerar, LOW);
  digitalWrite(puenteHDer, LOW);
  digitalWrite(puenteHIzq, LOW);
}
