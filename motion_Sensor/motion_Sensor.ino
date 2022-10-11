#define led 8
#define pir 2
int pirValue;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pirValue = digitalRead(pir);
  Serial.println(pirValue);
  if (pirValue == 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}