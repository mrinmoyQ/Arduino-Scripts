#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3); // RX, TX

String command;
int led = 12;
void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  if (btSerial.available()) {
    command=btSerial.readString();
    Serial.println(command);
    if(command=="On" ||command== "on" ||command== "ON"){
      digitalWrite(led, HIGH);
    }
    else{
      digitalWrite(led, LOW);
    }
  }
  // if (Serial.available()) {
  //   btSerial.write(Serial.read());
  // }
}
