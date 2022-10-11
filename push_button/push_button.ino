int ledState = 0;
int led = 12;
int buttonPin = 2;
int buttonRead;
int buttonOld=1;
int dt = 250;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(dt);
  if (buttonOld == 1 && buttonOld == 0) {
    if (ledState == 0) {
      digitalWrite(led, HIGH);
      ledState=1;
    }
  } else {
    digitalWrite(led, LOW);
    ledState=0;
  }
  buttonOld=buttonPin;
}