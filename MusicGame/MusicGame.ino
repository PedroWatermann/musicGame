#include <LinkedList.h>

// --------------- //
#define C4 261.626
#define D4 293.665
#define E4 329.628
#define F4 349.228
#define G4 391.995
#define A4 440.000
#define B4 493.883
// --------------- //
#define C5 523.221
#define D5 587.330
#define E5 659.225
#define F5 698.456
#define G5 783.991
#define A5 880.000
#define B5 987.767
// --------------- //
#define C6 1046.500
// --------------- //

#define axisX A0 // direita > 550 -- esquerda < 500
#define axisY A1 //   cima  > 550 --  baixo   < 500
#define click 8

int led1 = 9;
int led2 = 10;
int buzz = 11;
int btnU = 2;
int btnR = 3;
int btnD = 4;
int btnL = 5;

LinkedList<String> sequencia;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(click, INPUT_PULLUP);
  pinMode(btnU, INPUT_PULLUP);
  pinMode(btnR, INPUT_PULLUP);
  pinMode(btnD, INPUT_PULLUP);
  pinMode(btnL, INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(axisX);
  int yValue = analogRead(axisY);
  int clicVa = digitalRead(click);
  int estBtU = digitalRead(btnU);
  int estBtR = digitalRead(btnR);
  int estBtD = digitalRead(btnD);
  int estBtL = digitalRead(btnL);

  int toneFreq = 0;  // Variável para armazenar a frequência do som

  char note;

  // E5, D5, C5, B4, C5, D5, E5, D5, C5, B4, E5, C5, B4, C5, D5, E5, F5

  // Verificar se o botão clic está pressionado
  if (clicVa == HIGH) {  // Quando o botão clic não está pressionado
    // Verificar condições de botões e posição do joystick para definir a frequência
    if (estBtU == LOW && (yValue > 550)) {
      toneFreq = D5;
      Serial.println("Tocando D5 (Ré)");
    } else if (estBtU == LOW && (yValue >= 500) && (yValue <= 550)) {
      toneFreq = C4;
      Serial.println("Tocando C (Dó)");
    } else if (estBtU == LOW && (yValue < 500)) {
      toneFreq = D4;
      Serial.println("Tocando D (Ré)");
    } else if (estBtR == LOW && (xValue >= 500) && (xValue <= 550)) {
      toneFreq = E4;
      Serial.println("Tocando E (Mi)");
    } else if (estBtR == LOW && (xValue < 500)) {
      toneFreq = F4;
      Serial.println("Tocando F (Fá)");
    } else if (estBtD == LOW && (yValue > 550)) {
      toneFreq = A4;
      Serial.println("Tocando A (Lá)");
    } else if (estBtD == LOW && (yValue >= 500) && (yValue <= 550)) {
      toneFreq = G4;
      Serial.println("Tocando G (Sol)");
    } else if (estBtL == LOW && (xValue >= 500) && (xValue <= 550)) {
      toneFreq = B4;
      Serial.println("Tocando B (Si)");
    } else if (estBtL == LOW && (xValue > 550)) {
      toneFreq = C5;
      Serial.println("Tocando C5 (Dó)");
    } else if (estBtR == LOW && (xValue > 550)) {
      toneFreq = F5;
      Serial.println("Tocando F5 (Fá)");
    } else if (estBtD == LOW && (yValue < 500)) {
      toneFreq = A5;
      Serial.println("Tocando A5 (Lá)");
    } else if (estBtL == LOW && (xValue < 500)) {
      toneFreq = C6;
      Serial.println("Tocando C6 (Dó)");
    }
  } else {  // Quando o botão clic está pressionado
    // Verificações diferentes com o botão click pressionado
    if (estBtU == LOW && (yValue >= 500) && (yValue <= 550)) {
      toneFreq = E5;
      Serial.println("Tocando E5 (Mi)");
    } else if (estBtR == LOW && (xValue <= 550) && (xValue >= 500)) {
      toneFreq = G5;
      Serial.println("Tocando G5 (Sol)");
    } else if (estBtD == LOW && (yValue >= 500) && (yValue <= 550)) {
      toneFreq = B5;
      Serial.println("Tocando B5 (Si)");
    }
  }

  // Controla o buzzer apenas uma vez com base na frequência definida
  if (toneFreq > 0) {
    tone(buzz, toneFreq);
    Serial.println(toneFreq);
  } else {
    noTone(buzz);
  }

  delay(100);  // Pequeno delay para evitar leituras muito rápidas no serial
}
