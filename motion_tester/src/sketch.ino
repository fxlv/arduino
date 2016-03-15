int motionSensor = 7;
void setup(){
    Serial.begin(9600);
    pinMode(motionSensor, INPUT);
}


void loop(){
    int pirval = digitalRead(motionSensor);
    Serial.print("Pir value: ");
    Serial.println(pirval);
    delay(1000);
}
