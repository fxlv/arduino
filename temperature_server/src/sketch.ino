// Arduino temperature monitor that servers temperature over network
//
// https://www.arduino.cc/en/Reference/ServerConstructor
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

#include <SPI.h>
#include <Ethernet.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 // use pin #2 for data

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


byte mac[] = { 0xEE, 0xAA, 0xB1, 0xE1, 0xFE, 0xED };
byte ip[] = { 10, 111, 102, 125 };
byte gateway[] = { 10, 111, 102, 1 };
byte subnet[] = { 255, 255, 255, 0 };

// listen on port 2000
EthernetServer server(2000);

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}


void loop() {
    float temp;
    EthernetClient client = server.available();
    if (client == true) {
        sensors.requestTemperatures(); 
        temp = sensors.getTempCByIndex(0);  
        // print tempereture to anyone who connects
        client.println(temp); 
        client.stop();
    }
}


