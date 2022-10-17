#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3);  // RX, TX

String btOutput;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
int led5 = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (btSerial.available()) {
    btOutput = btSerial.readString();
    Serial.println(btOutput);
    String val1 = getValue(btOutput, '_', 0);
    String val2 = getValue(btOutput, '_', 1);
    String val3 = getValue(btOutput, '_', 2);
    String val4 = getValue(btOutput, '_', 3);
    String val5 = getValue(btOutput, '_', 4);

    Serial.println(val1);


    if(val1=="off"){
      digitalWrite(led1, LOW);
    }
    if(val2=="off"){
      digitalWrite(led2, LOW);
    }
    if(val3=="off"){
      digitalWrite(led3, LOW);
    }
    if(val4=="off"){
      digitalWrite(led4, LOW);
    }
    if(val5=="off"){
      digitalWrite(led5, LOW);
    }
    if(val1=="on"){
      digitalWrite(led1, HIGH);
    }
     if(val2=="on"){
      digitalWrite(led2, HIGH);
    }
     if(val3=="on"){
      digitalWrite(led3, HIGH);
    }
     if(val4=="on"){
      digitalWrite(led4, HIGH);
    }
     if(val5=="on"){
      digitalWrite(led5, HIGH);
    }
  }
}

String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }

  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}