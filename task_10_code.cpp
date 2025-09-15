#include <Servo.h>

#define SERVO_PIN 3

Servo myServo;
int currentAngle = 0;
int targetAngle = 0;

void setup() {
  Serial.begin(11520);
  myServo.attach(SERVO_PIN);
  myServo.write(currentAngle);
  Serial.println("Введите угол поворота от 0 до 180 градусов: ");
}

bool isValidNumber(String str) {
  for (byte i = 0; i < str.length(); i++) {
    if (!isDigit(str.charAt(i))) {
      return false;
    }
  }
  return str.length() > 0;
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();

    if (isValidNumber(data)) {
      int Angle = data.toInt();

      if ((Angle >= 0) && (Angle <= 180)) {
        if (Angle != currentAngle) {
          targetAngle = Angle;
        } else {
          Serial.print("Сервопривод уже повернут на ");
          Serial.print(Angle);
          Serial.println(" градусов");
        }
      } else {
        Serial.println("Ошибка! Введено недопустимое значение");
      } 
    } else {
      Serial.println("Ошибка! Введено недопустимое значение");
    }
  }

  if (currentAngle != targetAngle) {
    if (currentAngle < targetAngle) {
      currentAngle++;
    } else {
      currentAngle--;
    }
    myServo.write(currentAngle);
    delay(15);
  }
}
