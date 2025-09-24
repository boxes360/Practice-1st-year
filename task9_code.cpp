#define LED_PIN_RED 9
#define LED_PIN_GREEN 5
#define PHOTO_PIN A0

void setup() {
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
  Serial.begin(11520);

  digitalWrite(LED_PIN_RED, HIGH);
  digitalWrite(LED_PIN_GREEN, LOW);
  Serial.println("CLOSED");

}

void loop() {
  const float GAMMA = 0.7;
  const float RL10 = 50;

  int analogValue = analogRead(PHOTO_PIN);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

  if (lux > 512) {
    digitalWrite(LED_PIN_RED, LOW);
    digitalWrite(LED_PIN_GREEN, HIGH);
    Serial.println("OPEN");

    delay(3000);

    int analogValue = analogRead(PHOTO_PIN);
    float voltage = analogValue / 1024. * 5;
    float resistance = 2000 * voltage / (1 - voltage / 5);
    float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));   

    if (lux > 512) {
      digitalWrite(LED_PIN_RED, LOW);
      digitalWrite(LED_PIN_GREEN, HIGH);
    } else {
      digitalWrite(LED_PIN_RED, HIGH);
      digitalWrite(LED_PIN_GREEN, LOW);
      Serial.println("CLOSED");
    }
  }
  delay(100);
}
