
int motionSensorPin = 3;
int motionSensorValue = LOW;

int power_led = 2;
int motion_led = 5;
int relayPin = 4;

void setup(){
    pinMode(power_led, OUTPUT);
    pinMode(motion_led, OUTPUT);
    pinMode(relayPin, OUTPUT);
    Serial.begin(9600);
    digitalWrite(power_led, HIGH);
    digitalWrite(relayPin, HIGH); // high == relay off
}

void blinker(int led){
    int i = 0;
    int delay_time = 700;
    while(i < 20){
        digitalWrite(led,HIGH);
        delay(delay_time);
        digitalWrite(led,LOW);
        delay(500);
        i++;
        delay_time = delay_time - i * 5;
        if(delay_time < 10){
            delay_time = 10;
        }
    }

}

void lightOn(){
    digitalWrite(relayPin, LOW);
    blinker(motion_led);
}

void lightOff(){
    digitalWrite(relayPin, HIGH);
}

int getMotion(){
    motionSensorValue = digitalRead(motionSensorPin);
    return motionSensorValue;
}

void loop(){
    while(getMotion()){
        lightOn();
    }
    lightOff(); // tur off the relay
}
