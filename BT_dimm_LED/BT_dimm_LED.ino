#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3); // RX, TX

String btOutput;
int red=9;
int green=10;
int blue=11;
int j;
void setup() {
  Serial.begin(115200);
  btSerial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

void loop() {
  if (btSerial.available()) {
    btOutput=btSerial.readString();
    String cmd = getValue(btOutput,'_',1);
    String valA = getValue(btOutput,'_',0);
    String valB = getValue(btOutput,'_',0);
    String valC = getValue(btOutput,'_',0);
    if(cmd=="off"){
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
      Serial.println("OFF");

    }
    if(cmd=="on"){
      analogWrite(red, val.toInt());
      analogWrite(green, val.toInt());
      analogWrite(blue, val.toInt());
      Serial.print("ON_");
      Serial.println(val.toInt());
    }
  }
  // if (Serial.available()) {
  //   btSerial.write(Serial.read());
  // }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
