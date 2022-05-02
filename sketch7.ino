int pinPIR = 2;
int pinLED = 13;

void setup() {
  pinMode(pinLED, OUTPUT);
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pinPIR) == HIGH) {
    digitalWrite(pinLED, HIGH);
    }  else {
    digitalWrite(pinLED, LOW);
    }
}