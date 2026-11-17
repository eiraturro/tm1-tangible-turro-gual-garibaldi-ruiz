#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 8
#define BUTTON_PIN 7
#define BUZZER_PIN 3

CRGB leds[NUM_LEDS];

// Comprova si es prem el botó
void comprovarBoto() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    noTone(BUZZER_PIN); // Apaga el buzzer
    FastLED.clear(); // Apaga tots els LED
    FastLED.show();

    while (true) {
      delay(100); // Manté l'alarma apagada
    }
  }
}

// Espera comprovant el botó
void esperar(int temps) {
  for (int i = 0; i < temps; i += 10) {
    comprovarBoto();
    delay(10);
  }
}

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  FastLED.setBrightness(0); // Brillantor inicial
  fill_solid(leds, NUM_LEDS, CRGB::White);

  // Augmenta la brillantor progressivament
  for (int bright = 0; bright <= 255; bright += 1.5) {
    comprovarBoto();
    FastLED.setBrightness(bright);
    FastLED.show();
    esperar(30);
  }
}

void loop() {
  // Encén els LED i el buzzer
  comprovarBoto();
  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  tone(BUZZER_PIN, 1000);
  esperar(300);

  // Apaga els LED i el buzzer
  FastLED.clear();
  FastLED.show();
  noTone(BUZZER_PIN);
  esperar(300);
}