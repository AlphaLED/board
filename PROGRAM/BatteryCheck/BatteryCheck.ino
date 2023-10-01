#include <Battery.h>

Battery batt = Battery(3000, 4200, 3);
float ratio = (40 + 9.75) / 9.75;

void setup() {
  
  Serial.begin(9600);

  analogReadResolution(10);

  batt.onDemand(2);
  batt.begin(2800, ratio, &sigmoidal);
}

void loop() {

	Serial.print("Battery voltage is ");
	Serial.print(batt.voltage());
	Serial.print("mV (");
	Serial.print(batt.level());
	Serial.println("%)");

  delay(2000);

}
