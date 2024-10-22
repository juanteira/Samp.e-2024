// pines de los sensores infrarrojos
const int sensorIzquierdo = 2;
const int sensorDerecho = 4;
const int sensorGiroFrenado = 10;

const int switchSensProx = 11;

// pines de los sensores ultrasonicos
const int pinEcho = 5;
const int pinTrigger = 6;

// pines para el avance
const int acelerar = 9;

// pines del Puente H
const int puenteHDer = 8;
const int puenteHIzq = 7;

long duracion;
long distancia;

void setup() {

  //pines de sensores ultrasonicos
    Serial.begin (9600);
    pinMode (pinEcho, INPUT);
    pinMode (pinTrigger, OUTPUT);
    
  // pines de sensores como entradas
    pinMode(sensorIzquierdo, INPUT);
    pinMode(sensorDerecho, INPUT);
    pinMode(sensorGiroFrenado, INPUT);

    pinMode(switchSensProx, INPUT);

  // pines de motores como salidas
    pinMode(acelerar, OUTPUT); 
    pinMode(puenteHDer, OUTPUT); 
    pinMode(puenteHIzq, OUTPUT); 

    digitalWrite(acelerar, LOW);
}

void loop() {
  // leer valores de los sensores
  int lecturaIzquierdo = digitalRead(sensorIzquierdo);
  int lecturaDerecho = digitalRead(sensorDerecho);
  int lecturaGiroFrenado = digitalRead(sensorGiroFrenado);
  int lecturaSensProx = digitalRead(switchSensProx);

  //Para estabilizar nuestro módulo ultrasónico
  digitalWrite(pinTrigger,LOW);
  delayMicroseconds(4);
  //disparo de un pulso en el trigger de longitud 10us
  digitalWrite(pinTrigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger,LOW);

    if (lecturaSensProx == LOW) {
        duracion = pulseIn(pinEcho, HIGH);
        distancia = duracion / 58.4;
        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.print("cm---");

        if (distancia <= 25) {
            detener();
            Serial.print("OBSTACULO---");
        }
    }

    if (lecturaGiroFrenado == HIGH) {
        detenerGiro();
    } else {
        if(lecturaIzquierdo == HIGH && lecturaDerecho == HIGH) {
            adelante();
        } else if (lecturaIzquierdo == HIGH && lecturaDerecho == LOW) {
            giraIzquierda();
        } else if (lecturaIzquierdo == LOW && lecturaDerecho == HIGH) {
            giraDerecha();
        } else {
            detener();
        }
    }
}

void adelante() {
    digitalWrite(acelerar, HIGH);
    digitalWrite(puenteHIzq, LOW);
    digitalWrite(puenteHDer, LOW);
    Serial.print("Adelante---");
}

void giraIzquierda() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHIzq, HIGH);
  digitalWrite(puenteHDer, LOW);
  Serial.print("Izquierda---");
}

void giraDerecha() {
  digitalWrite(acelerar, HIGH);
  digitalWrite(puenteHDer, HIGH);
  digitalWrite(puenteHIzq, LOW);
  Serial.print("Derecha---");
}

void detener() {
  digitalWrite(acelerar, LOW);
  digitalWrite(puenteHDer, LOW);
  digitalWrite(puenteHIzq, LOW);
  Serial.print("Detener---");
}

void detenerGiro() {
    digitalWrite(acelerar, HIGH);
    digitalWrite(puenteHDer, LOW);
    digitalWrite(puenteHIzq, LOW);
    Serial.print("DetenerGiro---");
}

