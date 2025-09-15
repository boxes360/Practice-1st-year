#include <Adafruit_NeoPixel.h>

#define PIN 3
#define LEDS 100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void Sqrt(uint32_t color) {
  strip.clear();  // Очищаем все светодиоды
  

    for (int i = 0; i < 100; i += 10) {
      strip.setPixelColor(i, color);
    }
    for (int i = 9; i < 100; i += 10) {
      strip.setPixelColor(i, color);
    }
    for (int i = 1; i < 9; i++) {
      strip.setPixelColor(i, color);
    }
    for (int i = 91; i < 99; i++) {
      strip.setPixelColor(i, color);
    }

  
  strip.show();
}

void Cross(uint32_t color) {
  strip.clear();
  
  // Рисуем крест (обе диагонали)
  for (int i = 0; i < 10; i++) {
    // Главная диагональ (i, i)
    strip.setPixelColor(i * 10 + i, color);
    
    // Побочная диагональ (i, 9-i)
    strip.setPixelColor(i * 10 + (9 - i), color);
  }
  
  strip.show();
}

void All() {
  for (int i = 0; i < LEDS; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
  }
  strip.show();
}


void loop() {
  uint32_t redColor = strip.Color(255, 0, 0);
  Sqrt(redColor);
  delay(1500);

  Cross(strip.Color(0, 0, 255));
  delay(1500);

  All();
  delay(1500);
}
