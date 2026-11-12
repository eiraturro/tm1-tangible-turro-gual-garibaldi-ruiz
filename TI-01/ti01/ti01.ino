
const int LED_PIN1 = 2;
const int LED_PIN2 = 3;
const int BUZZER = 4;

int beat = 200; 

int onTime = 500;
int offTime = 500;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  
  // "S" = 3 senyals curtes ---------------------------------------------

  // ------- 1r so (curt)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(400);//so curt

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(500);

  // ------- 2n so (curt)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(400); //so curt

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(500);

  // ------- 3r so (curt)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(400);//so curt

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);//so curt
  delay(600); // més llarg per canviar de lletra


  // "O" = 3 sons mitjans ---------------------------------------------

  // ------- 1r so (llarg)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(1000);//so llarg

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(500);

  // ------- 2n so (llarg)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(1000);//so llarg

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(500);

  // ------- 3r so (llarg)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800); //tonalitat
  delay(1000);//so llarg

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(1200); // més llarg per canviar de lletra


  // "S" = 3 senyals curtes ---------------------------------------------

  // ------- 1r so (curt)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(400);//so curt

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(500);

  // ------- 2n so (curt)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(400);//curt

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(500);

  // ------- 3r so (curt)
  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(400);//so curt
 
  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(600); // més llarg per canviar al remate final


  // REMAT FINAL = 1 so llarg que tanca la paraula SOS -------------------

  //obert
  digitalWrite(LED_PIN1, HIGH);
  digitalWrite(LED_PIN2, HIGH);
  tone(BUZZER, 800);//tonalitat
  delay(3000);//so final (2.0 s, el més llarg)

  //apagat
  digitalWrite(LED_PIN1, LOW);
  digitalWrite(LED_PIN2, LOW);
  noTone(BUZZER);
  delay(5000); // més llarg final de tot

}