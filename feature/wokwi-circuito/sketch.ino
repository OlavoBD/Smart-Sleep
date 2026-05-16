#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

const int ldrPin = A0;
const int ledPin = 9; // PWM
const int LDR_SAMPLES = 6;

DHT dht(DHTPIN, DHTTYPE);
// Ajuste o endereço se necessário: 0x27 ou 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(ledPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(700);
  lcd.clear();
}

int readLdrAverage() {
  long sum = 0;
  for (int i = 0; i < LDR_SAMPLES; ++i) {
    sum += analogRead(ldrPin);
    delay(8);
  }
  return (int)(sum / LDR_SAMPLES);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int ldrRaw = readLdrAverage();

  int ledPWM = map(ldrRaw, 0, 1023, 255, 0);
  ledPWM = constrain(ledPWM, 0, 255);
  analogWrite(ledPin, ledPWM);

  lcd.setCursor(0, 0);
  if (!isnan(t) && !isnan(h)) {
    lcd.print("T:");
    lcd.print(t, 1);
    lcd.print("C H:");
    lcd.print(h, 1);
    lcd.print("%  ");
  } else {
    lcd.print("DHT erro         ");
  }

  lcd.setCursor(0, 1);
  lcd.print("LDR:");
  lcd.print(ldrRaw);
  lcd.print(" LED:");
  lcd.print(map(ledPWM, 0, 255, 0, 100));
  lcd.print("%  ");

  Serial.print("Temp(C): ");
  if (isnan(t)) Serial.print("ERR"); else Serial.print(t, 1);
  Serial.print("  Hum(%): ");
  if (isnan(h)) Serial.print("ERR"); else Serial.print(h, 1);
  Serial.print("  LDR: ");
  Serial.print(ldrRaw);
  Serial.print("  LED PWM: ");
  Serial.println(ledPWM);

  delay(1500);
}
