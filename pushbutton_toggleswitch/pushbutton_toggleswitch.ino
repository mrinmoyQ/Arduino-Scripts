int led = 12;
int buttonPin = 2;
int buttonRead;
bool isLightON=false;
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
  if(isLightON==true){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  if(buttonRead==HIGH){
    // if(isLightON==true){
    //   isLightON=false;
    // }
    // else{
    //   isLightON=true;
    // }
    isLightON = !isLightON;
    delay(250);
  }
}
