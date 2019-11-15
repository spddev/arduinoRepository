#include <TroykaThermometer.h>
#define LED 13

int blinks = 0;

// создаём объект для работы с аналоговым термометром
// и передаём ему номер пина для выходного сигнала
TroykaThermometer thermometer (A0);

void setup() {
  // установка пина со светодиодом в режим выхода
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
int checkTemp(){
  float celsius = 0;
  float hotTemp = 26;
  float coldTemp = 20;
  int result;

  // считываем данные с аналогового термометра
  thermometer.read();
  celsius = thermometer.getTemperatureC();
  Serial.print("celsius = ");
  Serial.print(celsius);
  Serial.print(" C");

  // Выполнить действия для разных диапазонов температур
  if (celsius < coldTemp){
    result = 2;  
  }
  else if (celsius >= coldTemp && celsius <= hotTemp) {
    result = 4;
  }
  else{
    result = 6; // (celsius > hotTemp)
  }
  return result;
}

void blinkLED(int cycles, int del){
    for(int z = 0; z < cycles; z++){
      digitalWrite(LED, HIGH);
      delay(del);
      digitalWrite(LED, LOW);
      delay(del);  
    }
}

void loop() {
  blinks = checkTemp();
  blinkLED(blinks, 500);
  delay(2000);
}
