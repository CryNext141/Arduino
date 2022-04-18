const int buttonOn = 6;
const int buttonOff = 7;

void setup(){
DDRD = DDRD | B11111111 ; 
}

void loop() {
if (digitalRead(buttonOn)==HIGH) {
while (digitalRead(buttonOff)!=HIGH){
for(int i=0; i <= 5; i++){
PORTD = (1<<i);
delay (500);
if (digitalRead(buttonOff)==HIGH){
PORTD = LOW;
break;
        }
      }
    }
  }
}
