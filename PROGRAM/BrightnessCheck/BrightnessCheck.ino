int analogPin = 1;   // Pin, na którym podłączony jest czujnik analogowy
int analogReadPin = 2;
int minValue = 820;   // Minimalna wartość (5%)
int maxValue = 4090;  // Maksymalna wartość (80%)

void setup() {
  pinMode(analogReadPin, OUTPUT);
  digitalWrite(analogReadPin, HIGH);
  Serial.begin(9600);  // Rozpoczęcie komunikacji szeregowej
}

void loop() {
  int sensorValue = analogRead(analogPin);  // Odczyt wartości czujnika
  float percentage;

  // Sprawdzenie, czy wartość jest poniżej minimalnej
  if (sensorValue < minValue) {
    percentage = 5.0;  // 5% dla wartości poniżej minimalnej
  }
  // Sprawdzenie, czy wartość jest powyżej maksymalnej
  else if (sensorValue > maxValue) {
    percentage = 80.0;  // 80% dla wartości powyżej maksymalnej
  }
  // Wartość mieści się pomiędzy minimalną a maksymalną
  else {
    // Obliczenie procentowej wartości w zakresie od minValue do maxValue
    percentage = map(sensorValue, minValue, maxValue, 5, 80);
  }

  // Wyświetlenie wyniku w monitorze szeregowym
  Serial.print("Odczyt czujnika: ");
  Serial.println(sensorValue);
  Serial.print("Procent: ");
  Serial.println(percentage);

  delay(1000);  // Poczekaj sekundę przed kolejnym odczytem
}
