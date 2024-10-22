// pines de los sensores
const int sensorIzquierdo = 2;
const int sensorDerecho = 4;

// pines para el avance
const int acelerar = 9;

// pines del Puente H
const int puenteHDer = 8;
const int puenteHIzq = 7;

void setup() {
  // pines de sensores como entradas
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorDerecho, INPUT);

  // pines de motores como salidas
  pinMode(acelerar, OUTPUT); 
  pinMode(puenteHDer, OUTPUT); 
  pinMode(puenteHIzq, OUTPUT); 

  digitalWrite(acelerar, LOW);
  
  Serial.begin(9600);
}

void loop() {
  	// leer valores de los sensores
  	int lecturaIzquierdo = digitalRead(sensorIzquierdo);
	int lecturaDerecho = digitalRead(sensorDerecho);

  // si el sensor central detecta la linea, sigue adelante
  if (lecturaIzquierdo == HIGH && lecturaDerecho == HIGH) {
    adelante();
    Serial.println("Adelante");
  }
  // si el sensor izquierdo detecta la linea, gira a la izquierda
  else if (lecturaIzquierdo == HIGH && lecturaDerecho == LOW) {
    giraIzquierda();
    Serial.println("Izquierda");
  }
  // si el sensor derecho detecta la linea, gira a la derecha
  else if (lecturaDerecho == HIGH && lecturaIzquierdo == LOW) {
    giraDerecha();
    Serial.println("Derecha");
  }
  // si ningun sensor detecta la linea, detener el montacargas
  else {
    detener();
    Serial.println("Detener");
  }
  
  delay(100);
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