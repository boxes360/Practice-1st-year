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
  int value_photo = analogRead(PHOTO_PIN);

  if (value_photo < 245) {
    digitalWrite(LED_PIN_RED, LOW);
    digitalWrite(LED_PIN_GREEN, HIGH);
    Serial.println("OPEN");

    delay(3000);

    int value_photo = analogRead(PHOTO_PIN);    

    if (value_photo < 245) {
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
