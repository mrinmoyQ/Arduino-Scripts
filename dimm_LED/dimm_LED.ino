int LED = 3;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  analogWrite(LED, 0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j <= 150; j = j + 1) {
    analogWrite(LED, j);
     Serial.println(j);
    delay(20);
  }
  for (int j=150;j>=0; j= j-1){
    analogWrite(LED, j);
    Serial.println(j);
    delay(20);
  }
}