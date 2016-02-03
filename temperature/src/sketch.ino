//
// These libs are required:
//
// https://github.com/PaulStoffregen/OneWire.git
// https://github.com/milesburton/Arduino-Temperature-Control-Library
//
// copy them to /usr/share/arduino/libraries/
//
// sensor data pin connected to Arduino pin 2
// 4.7 K resistor between VCC and DATA

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 // use pin #2 for data

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


void setup()
{
    Serial.begin(9600);
    sensors.begin();
}

void loop()
{
    Serial.print("Requesting temperatures...");
    sensors.requestTemperatures(); // Send the command to get temperatures
    Serial.println("DONE");
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(sensors.getTempCByIndex(0));  
    delay(1000);
}
