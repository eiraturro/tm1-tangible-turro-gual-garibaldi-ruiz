#include <FastLED.h>
#include <SharpIR.h>
#define model 1080
// ---------- DEFINES ----------
#define NUM_BTNS     3
#define CODE_LEN     3
#define NUM_LEDS     60
#define LEDS_SECCIO  20
#define LED_PIN      2
#define BUZZER_PIN   10
#define IR_PIN       A3

SharpIR SharpIR(IR_PIN, model);
// ---------- CONFIGURACIO DEL HARDWARE (canvia-ho segons el que tingueu) ----------
const bool IR_DIGITAL   = false;  // true si el sensor te sortida DO/OUT (modul amb potenciometre blau)
const bool BUZZER_ACTIU = false;  // true si el brunzidor xiula sol nomes donant-li 5V (actiu)
const bool DEBUG_IR     = true;   // escriu el valor del sensor al Monitor Serie

const int btnPins[NUM_BTNS]   = {5, 6, 7};
const int password[CODE_LEN]  = {0, 2, 1};   // boto 1, boto 3, boto 2
int codePos = 0;

// ---------- ESTATS ----------
const int APAGAT = 0, ESPERA = 1, JOC = 2, OBERT = 3;
int state = APAGAT;

bool lastBtnState[NUM_BTNS] = {HIGH, HIGH, HIGH};

unsigned long last = 0;
const unsigned long ESPERA_TIME  = 1000;   // 5 s detectant per comencar
const unsigned long OPEN_TIME    = 1000;   // es tanca sola als 5 s
const unsigned long JOC_TIMEOUT  = 5000;  // 10 s sense premer -> error
const unsigned long IR_TOLERANCIA = 500;   // ignora talls del sensor de menys de 0,5 s
const int IR_LLINDAR = 200;                // calibrar mirant el Monitor Serie
const uint8_t BRIGHTNESS = 80;

CRGB leds[NUM_LEDS];
int posLlum = 0;
int valorIR = 0;

// ---------- SETUP ----------
void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  for (int i = 0; i < NUM_BTNS; i++) {
    pinMode(btnPins[i], INPUT_PULLUP);
  }
  pinMode(BUZZER_PIN, OUTPUT);
  

  // Prova del brunzidor: si aqui no sona, el problema es el cablejat o el tipus
  Serial.println("Prova brunzidor...");
  so(1000, 300);

  goApagat();
}

// ---------- LOOP ----------
void loop() {
  int btn = readButton();   // -1 si no s'ha premut cap boto
  bool hiHaAlgu = detecta();
  debugIR(hiHaAlgu);

  switch (state) {
    case APAGAT:
      if (hiHaAlgu) {
        Serial.println("ESPERA");
        beepStart();
        posLlum = 0;
        last = millis();
        state = ESPERA;
      }
      break;

    case ESPERA:
      llumCorrent();
      if (!hiHaAlgu) {
        goApagat();
      } else if (millis() - last >= ESPERA_TIME) {
        showColor(CRGB::Black);
        codePos = 0;
        last = millis();
        state = JOC;
        Serial.println("JOC");
      }
      break;

    case JOC:
      if (btn != -1) {
        last = millis();
        checkDigit(btn);
      } else if (millis() - last >= JOC_TIMEOUT) {
        Serial.println("Temps esgotat");
        error();
      }
      break;

    case OBERT:
      if (millis() - last >= OPEN_TIME) {
        beepLock();
        goApagat();
      }
      break;
  }
}

// ---------- ENTRADES ----------
int readButton() {
  for (int i = 0; i < NUM_BTNS; i++) {
    bool btnState = digitalRead(btnPins[i]);
    bool pressed = (btnState == LOW && lastBtnState[i] == HIGH);
    lastBtnState[i] = btnState;
    if (pressed) {
      delay(50);   // antirebot
      return i;
    }
  }
  return -1;
}

// Lectura directa del sensor
bool llegeixIR() {
 int dis=SharpIR.distance(); 
 Serial.println(dis);
 return dis;      // Sharp: valor mes alt = mes a prop
}

// Detecta amb tolerancia: un tall curt no compta com "se n'ha anat"
bool detecta() {
  static bool vist = false;
  static unsigned long ultimaDeteccio = 0;
  if (llegeixIR()) {
    vist = true;
    ultimaDeteccio = millis();
  }
  return vist && (millis() - ultimaDeteccio < IR_TOLERANCIA);
}

void debugIR(bool hiHaAlgu) {
  static unsigned long ultimPrint = 0;
  if (!DEBUG_IR || millis() - ultimPrint < 300) return;
  ultimPrint = millis();
  Serial.print("IR = ");
  Serial.print(valorIR);
  Serial.print("   detecta = ");
  Serial.println(hiHaAlgu ? "SI" : "no");
}

// ---------- LOGICA ----------
void checkDigit(int btn) {
  Serial.print("Boto ");
  Serial.println(btn + 1);

  if (btn == password[codePos]) {
    codePos++;
    showSeccions(codePos);   // seccio 1, 1-2, 1-2-3 en verd
    beepKey();

    if (codePos == CODE_LEN) {
      Serial.println("OBERT");
      beepOpen();
      last = millis();
      state = OBERT;
    }
  } else {
    Serial.println("Incorrecte");
    error();
  }
}

void error() {
  pulseColor(CRGB::Red, 200);
  beepWrong();
  if (detecta()) {           // la persona encara hi es -> torna a ESPERA
    last = millis();
    codePos = 0;
    posLlum = 0;
    state = ESPERA;
    Serial.println("ESPERA");
  } else {
    goApagat();
  }
}

void goApagat() {
  codePos = 0;
  showColor(CRGB::Black);
  noTone(BUZZER_PIN);
  digitalWrite(BUZZER_PIN, LOW);
  state = APAGAT;
  Serial.println("APAGAT");
}

// ---------- LLUMS ----------
void showColor(CRGB color) {
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
}

void showSeccions(int n) {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  fill_solid(leds, n * LEDS_SECCIO, CRGB::Green);
  FastLED.show();
}

void pulseColor(CRGB color, int ms) {
  for (int i = 0; i < 3; i++) {
    showColor(color);
    delay(ms);
    showColor(CRGB::Black);
    delay(ms);
  }
  showColor(color);
}

void llumCorrent() {         // llum blanca que corre per la tira
  fadeToBlackBy(leds, NUM_LEDS, 60);
  leds[posLlum] = CRGB::White;
  FastLED.show();
  posLlum = (posLlum + 1) % NUM_LEDS;
  delay(20);
}

// ---------- SONS ----------
// Toca una nota i espera que acabi (aixi la tira de LEDs no talla el so)
void so(int freq, int durada) {
  if (BUZZER_ACTIU) {
    digitalWrite(BUZZER_PIN, HIGH);   // l'actiu no canvia de nota, nomes xiula
    delay(durada);
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    tone(BUZZER_PIN, freq);
    delay(durada);
    noTone(BUZZER_PIN);
  }
  delay(30);                          // petita pausa entre notes
}

void beepStart() {
  so(523, 120);
  so(659, 120);
  so(784, 200);
}

void beepKey() {
  so(1047, 120);
}

void beepWrong() {
  so(180, 600);
}

void beepOpen() {
  int notes[] = {523, 659, 784, 1047, 784, 1047};
  int durs[]  = {150, 150, 150, 300, 150, 500};
  for (int i = 0; i < 6; i++) {
    so(notes[i], durs[i]);
  }
}

void beepLock() {
  so(784, 100);
  so(523, 150);
}
