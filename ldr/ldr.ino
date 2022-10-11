int ldr = A0;
int lightVal;
int led = 12;
int dt = 50;
void setup() {
  // put your setup code here, to run once:
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(ldr);
  Serial.println(lightVal);
  delay(dt);
  if (lightVal >= 200) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}