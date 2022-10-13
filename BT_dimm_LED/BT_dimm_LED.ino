#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3); // RX, TX

String btOutput;
int led = 11;
int j;
void setup() {
  Serial.begin(115200);
  btSerial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  if (btSerial.available()) {
    btOutput=btSerial.readString();
    String cmd = getValue(btOutput,'_',0);
    String val = getValue(btOutput,'_',1);
    if(cmd=="off"){
      digitalWrite(led, LOW);
      Serial.println("OFF");

    }
    if(cmd=="on"){
      analogWrite(led, val.toInt());
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
