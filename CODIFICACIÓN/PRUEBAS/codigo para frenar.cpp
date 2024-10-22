int sensorParada = 10;


void setup() {
    pinMode(sensorParada, INPUT);
}

void loop() { 
    lecturaParada = digitalRead(sensorParada)
    if (lecturaParada == HIGH) {
        detenerGiro()  
    }
}
