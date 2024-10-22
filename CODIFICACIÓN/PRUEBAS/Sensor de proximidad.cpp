int pinEcho = 6;
int pinTrigger = 7;
int led = 13

l

void setup() {
    serial.begin (9600);
    pinMode (pinEcho, INPUT);
    pinMode (pinTrigger, OUTPUT);
    pinMode (led, OUTPUT);
}

void loop () {
    digitalWrite(pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(pinTrigger, HIGH); // genera el pulso de trigger por 10ms
    delayMicroseconds(10);
    digitalWrite(pinTrigger, LOW);

    duracion = pulseIN(pinEcho, HIGH);
    distancia = (duracion/2) / 29;      // calcula la distancia en centimetros

    if (distancia >= 500 || distancia <= 0) { // si la distancia es mayor a 500cm o menor de 0cm
        serial.printin(---)                   // no mide nada
    } else {
        serial.print (distancia);   // imprime valor de distancia
        serial.print ("cm");        // le agrega cm para aclarar los centimetros
        digitalWrite (led, LOW);    // el led no se activa
    }

    if (distancia >= 10 && distancia <= 1) {
        digitalWrite(led, HIGH);    // se prende la led
        Serial.print ("ALARMA");    // imprime alarma
    }
    delay(400);                     // espera 400ms para que logre ver la f
}