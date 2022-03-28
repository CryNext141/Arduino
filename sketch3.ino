void setup() {
DDRD = DDRD | B11111111 ; 
}
void loop() {
for (int i = 0; i <=7; i++) {
PORTD =(1<<i);

delay(500);
}
}
