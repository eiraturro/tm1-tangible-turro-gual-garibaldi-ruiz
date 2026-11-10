const int LED_PIN = 2;
const int LDR_PIN = A0;
const int BUZZER_PIN = 3;
const int SOUND_PIN = A3;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SOUND_PIN, INPUT);
}

void loop() {
  int lo = 1023, hi = 0; // punts maxims i minims del so
  int light = analogRead(LDR_PIN);
  

  for (int i = 0; i < 100; i++) {
  int sound = analogRead(SOUND_PIN);

  if (sound < lo) lo = sound;
  if (sound > hi) hi = sound;
}
// difència maxim i minim
int sound = hi - lo;

  Serial.println(sound);

  if (light < 80) { // Comprova si la caixa està TANCADA
    digitalWrite(LED_PIN, LOW); // Apaga el LED
  noTone(BUZZER_PIN); // Atura el buzzer
   

  } else { // Si la llum és igual o superior a 80. Caixa OBERTA
    digitalWrite(LED_PIN, HIGH); // Encén el LED
  
     if (sound > 100) { // Si piquem de mans i el so supera 100 (APLAUDIMENT)
      tone(BUZZER_PIN, 1000, 2000);  // El buzzer sona durant 2 seg i s'atura sol
      
    }
  }

  delay(5);
}
