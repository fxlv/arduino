#include "dht.h"

dht DHT;

int dhtPin = 2;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    DHT.read22(dhtPin);
    Serial.println("Reading temperature");
    Serial.println(DHT.temperature);
    Serial.println(DHT.humidity);
    delay(1000);
}
