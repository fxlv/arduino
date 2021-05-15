int relay_1_1 = 8;
int relay_1_2 = 9;
int relay_1_3 = 10;
int relay_1_4 = 11;


int switch_out = 5;
int switch_in = 6;

int switch1 = 0;

void setup()
{
    pinMode(relay_1_1, OUTPUT);
    pinMode(relay_1_2, OUTPUT);
    pinMode(relay_1_3, OUTPUT);
    pinMode(relay_1_4, OUTPUT);


    pinMode(switch_out, OUTPUT);
    pinMode(switch_in, INPUT_PULLUP);
    digitalWrite(switch_out, HIGH);
    Serial.begin(9600);
    delay(5000);
}

void loop()
{
    switch1 = digitalRead(switch_in);
    delay(100);
    Serial.println("Switch:");
    Serial.println(switch1);


    if (switch1 == 1){

        Serial.println("Relay ON");
        digitalWrite(relay_1_1, HIGH);
        digitalWrite(relay_1_2, HIGH);
        digitalWrite(relay_1_3, HIGH);
        digitalWrite(relay_1_4, HIGH);
    } else {

        Serial.println("Relay OFF");
        digitalWrite(relay_1_1, LOW);
        digitalWrite(relay_1_2, LOW);
        digitalWrite(relay_1_3, LOW);
        digitalWrite(relay_1_4, LOW);
    }

}
