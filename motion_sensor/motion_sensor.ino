// using motion sensor
// LEDs connected to pins 2 and 3
// motion sensor output connected to A0

int motionSensorPin = A0;
int motionSensorValue = 0;
int ledPin1 = 2;
int ledPin2 = 3;

void setup(){
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
 Serial.begin(9600);
}

void blinker(int led1, int led2 ){
  digitalWrite(led1,HIGH);
  delay(100);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  delay(100);
  digitalWrite(led2,LOW);
}

void loop(){
 Serial.println("Motion: ");
 motionSensorValue = analogRead(motionSensorPin);
 Serial.println(motionSensorValue);
 while(motionSensorValue > 500){
   blinker(ledPin1, ledPin2);
   motionSensorValue = analogRead(motionSensorPin);
 }
 delay(1000);
}
