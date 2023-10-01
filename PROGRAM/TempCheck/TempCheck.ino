#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntec to the Arduino digital pin 10
const int TempPin = 10;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(TempPin);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup()
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the library
  sensors.setResolution(9);
  sensors.begin();
}

void loop()
{ 
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  Serial.println(sensors.getTempCByIndex(0)); 

  delay(1000);
}