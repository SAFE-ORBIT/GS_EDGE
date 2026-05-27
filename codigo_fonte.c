#include <Wire.h>
#include <Adafruit_LiquidCrystal.h> // Alterado para a biblioteca compatível com Tinkercad

// Inicialização padrão do Tinkercad para o LCD I2C
Adafruit_LiquidCrystal lcd(0);

// Sensor ultrassônico de 3 pinos (SIG)
#define SENSOR 9

// LEDs
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4

// Buzzer
#define BUZZER 8

long duracao;
float distancia;

//============================

float medirDistancia() {
  // Configura o pino como saída para enviar o trigger
  pinMode(SENSOR, OUTPUT);
  digitalWrite(SENSOR, LOW);
  delayMicroseconds(2);
  digitalWrite(SENSOR, HIGH);
  delayMicroseconds(5);   // pulso de 5us (ajuste fino para o Tinkercad)
  digitalWrite(SENSOR, LOW);

  // Muda para entrada para ler o echo
  pinMode(SENSOR, INPUT);
  duracao = pulseIn(SENSOR, HIGH);

  // Calcula distância em cm (velocidade do som 0.034 cm/us)
  return duracao * 0.034 / 2;
}

//============================

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  // Inicializa o LCD da forma que o Tinkercad aceita
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  
  lcd.setCursor(0, 0);
  lcd.print("SpaceClean");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando");
  delay(2000);
  lcd.clear();
}

//============================

void loop() {
  distancia = medirDistancia();

  // Debug no Serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Exibe a distância na primeira linha do LCD
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print((int)distancia);
  lcd.print(" cm  "); // espaços extras para apagar caracteres antigos

  // Lógica de alerta
  if (distancia > 100) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
    lcd.setCursor(0, 1);
    lcd.print("SEGURANCA OK   ");
  }
  else if (distancia > 50) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
    lcd.setCursor(0, 1);
    lcd.print("ALERTA         ");
  }
  else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER, 1500);
    lcd.setCursor(0, 1);
    lcd.print("ALERTA CRITICO ");
  }

  delay(400);
}