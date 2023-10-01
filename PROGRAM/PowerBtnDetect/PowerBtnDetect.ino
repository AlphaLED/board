int powerPin = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(powerPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(powerPin)) {
    Serial.println("Clicked!");
    delay(500);
  }

}
