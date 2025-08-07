// C++ code
//
#include <LiquidCrystal.h>
#define trigPin 2
#define echoPin 3
long duration;
int distance;
const int buzzer = 9;
LiquidCrystal lcd(12,11,7,6,5,4);

void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Obstacle:");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm ");
  
  if (distance < 50){
    lcd.print("WARNING");
    tone(buzzer, 2000);
  }
  else if (distance >= 50 && distance < 100){
    lcd.print("OK");
    tone(buzzer, 200);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
  else{
    lcd.print("SAFE");
    noTone(buzzer);
  }
  
  delay(500);
}