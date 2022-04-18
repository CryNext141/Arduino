#define PIN_TRIG 2
#define PIN_ECHO 3
#define PIN_LED_1 6
#define PIN_LED_2 7
#define PIN_LED_3 8
#define PIN_LED_4 9
#define PIN_LED_5 10
#define PIN_LED_6 11
#define PIN_LED_7 12
#define PIN_LED_8 13

void setup() {
Serial.begin(9600);
pinMode(PIN_TRIG, OUTPUT);
pinMode(PIN_ECHO, INPUT);
  
DDRD=DDRD | B11000000;
DDRB=DDRB | B00111111;
}

void loop() {

digitalWrite(PIN_TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(PIN_TRIG, LOW);
  
int duration = pulseIn(PIN_ECHO, HIGH);
  if(duration/58 == 10){
  PORTD=B11000000;
  PORTB=B00000000;
}
else if(duration/58 == 20){
  PORTB=B00000011;
  PORTD=B00000000;
}
else if(duration/58 == 30){
  PORTB=B00001100;
  PORTD=B00000000;
}
else if(duration/58 == 40){
  PORTB=B00110000;
  PORTD=B00000000;
}
else {
  PORTB=B00000000;
  PORTD=B00000000;
}
Serial.print("Distance in cm: ");
Serial.println(duration / 58);
  
delay(5000);
}
