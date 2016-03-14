
    int motionSensorPin = 3;
    int motionSensorValue = LOW;

    int power_led = 2;
    int motion_led = 5;
    int relayPin = 4;
    int buzzerPin = 6;

void warmup(){
    Serial.println("Motion sensor initializing...");
    for (int i = 0; i < 10; i++){
        delay(100);
        int led = 2;
        digitalWrite(led,HIGH);
        delay(100);
        digitalWrite(led,LOW);
        delay(500);
        led = 5;
        digitalWrite(led,HIGH);
        delay(100);
        digitalWrite(led,LOW);
        delay(500);
    }
    Serial.println("Setup complete");
}

void setup(){
    pinMode(power_led, OUTPUT);
    pinMode(motion_led, OUTPUT);
    pinMode(relayPin, OUTPUT);
    Serial.begin(9600);
    digitalWrite(relayPin, HIGH); // high == relay off
    warmup();
    digitalWrite(power_led, HIGH);
    readyBeep();

}

void readyBeep(){
    tone(buzzerPin, 100, 100);
    delay(100);
    tone(buzzerPin, 300, 100);
    delay(100);
    tone(buzzerPin, 500, 100);
    delay(100);
    tone(buzzerPin, 700, 100);
}

void lowBeep(){
    tone(buzzerPin, 100, 200);
    delay(100);
    tone(buzzerPin, 200, 200);
    delay(100);
    tone(buzzerPin, 300, 200);
}
void highBeep(){
    tone(buzzerPin, 500, 200);
    delay(100);
    tone(buzzerPin, 400, 200);
    delay(100);
    tone(buzzerPin, 500, 200);
}
void addBeep(){
    tone(buzzerPin, 100, 50);
    delay(50);
    tone(buzzerPin, 200, 50);
    delay(50);
    tone(buzzerPin, 250, 30);
    
}

void playWarning(){
    Serial.println("Playing the song");
    int buzzerPin = 6;
    tone(buzzerPin,261,100);
    delay(1000);
    tone(buzzerPin,470,205);
    delay(1000);
    tone(buzzerPin,180,74);
    delay(1000);
    tone(buzzerPin,100,300);
    delay(500);
    tone(buzzerPin,20,100);
    delay(500);
}

void blinker(int led){
    int wait_time = 60;
    int i = 0;
    int delay_time = 1000;
    int warning_played = 0;
    int critical_played = 0;

    // keep the light on for 'wait_time' seconds
    while(i < wait_time){
        int remaining_time = wait_time - i;
        if (remaining_time < 60){
        if(getMotion() == HIGH){
            Serial.println("Motion ongoing, adding extra time");
            wait_time = wait_time + 30;
            addBeep();
            delay(5000);
        }
        }
        if(remaining_time == 30){
            if(warning_played != 1){
            playWarning();
            warning_played = 1;
            }
        }
        if(remaining_time < 5){
            if(critical_played != 1){
            highBeep();
            critical_played = 1;
            }
        }
        Serial.print("Remaining time: ");
        Serial.println(remaining_time);
        digitalWrite(led,HIGH);
        delay(delay_time);
        digitalWrite(led,LOW);
        delay(500);
        i++;
        // the delay time also is how long the LED will be on
        // with every iteration the ON time becomes shorter
        delay_time = delay_time - i;
        Serial.println(delay_time);
        // don't go shorter than 10ms
        if(delay_time < 10){
            delay_time = 10;
        }
    }
    Serial.println("Wait time is over");
}

void lightOn(){
    digitalWrite(relayPin, LOW);
}

void lightOff(){
    digitalWrite(relayPin, HIGH);
}

 
int getMotion(){
    motionSensorValue = digitalRead(motionSensorPin);
    return motionSensorValue;
}


void loop(){                                                                        
    Serial.println("Entering loop...");
    if(getMotion() == HIGH){                                                 
        Serial.println("Motion detected");
        lowBeep();
        lightOn();
        blinker(motion_led);
        lightOff();
        delay(100);
    } else {                                                                               
        Serial.println("No motion, waiting...");
        delay(500);                                                                    
}                   
}
