#include <Battery.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int pin_batVoltage = 3, pin_enableAnalogRead = 2, pin_chrg = 4, pin_stdby = 5, pin_temp = 10;
const float adcVoltage = 2.83;

Battery batt = Battery(3000, 4200, pin_batVoltage);
float ratio = (40 + 9.75) / 9.75;

OneWire oneWire(pin_temp);
DallasTemperature tempSensor(&oneWire);

void setup() {
  Serial.begin(9600);

  pinMode(pin_chrg, INPUT);
  pinMode(pin_stdby, INPUT);

  analogReadResolution(10);
  batt.onDemand(pin_enableAnalogRead);
  batt.begin(adcVoltage*1000, ratio, &sigmoidal);

  tempSensor.setResolution(9);
  tempSensor.begin();
}

void loop() {

  bool isChrgOn = !digitalRead(pin_chrg);
  bool isStdbyOn = !digitalRead(pin_stdby);

  if(isChrgOn && isStdbyOn) Serial.print("!! SOME ERROR DURING CHARGING (");
  else if(isChrgOn) Serial.print("Charging... (");
  else if(isStdbyOn) Serial.print("Charged. Ready to unplug (");
  else Serial.print("Unplugged. (");

  Serial.print(batt.voltage()/1000.0);
  Serial.print("V, ");
  Serial.print(batt.level());
  Serial.print("%, ");
  tempSensor.requestTemperatures();
  Serial.print(tempSensor.getTempCByIndex(0)); 
  Serial.write(0xC2);
  Serial.write(0xB0);
  Serial.println("C)");

  delay(3000);
}