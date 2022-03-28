int pins[8]={2,3,4,5,6,7,8,9}; 
int data[] = { 1, 4, 11, 0, 2, 11, 2, 0, 0, 2}; 

void setup() {
  for(int i=0;i<8;i++){
    pinMode(pins[i],OUTPUT); 
    digitalWrite(pins[i],HIGH); 
  }
}

void loop() {

  for (int i = 0; i<sizeof(data)/sizeof(data[0]); i++){
    for(int j=0;j<8;j++){
        digitalWrite(pins[j],HIGH); 
        delay(25);
    }
    switch (data[i]){
      case 11:
        digitalWrite(3,LOW);
        delay(750);
      break; 
      case 0: 
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        delay(750);
        break;
      case 1:
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        delay(750);
        break;
      case 2:    
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        digitalWrite(3,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        delay(750);
        break;
      case 3:
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        digitalWrite(3,LOW);
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        delay(750);
        break;  
      case 4:
        digitalWrite(4,LOW);
        digitalWrite(8,LOW);
        digitalWrite(3,LOW);
        digitalWrite(7,LOW);
        delay(750);
        break;
      case 5:
        digitalWrite(9,LOW);
        digitalWrite(4,LOW);
        digitalWrite(3,LOW);
        digitalWrite(7,LOW);
        digitalWrite(6,LOW);
        delay(750);
        break;
      case 6:
        for(int six = 0; six<8; six++){
          if(six == 6) {continue;}
          digitalWrite(pins[six],LOW);
        }
        delay(750);
        break;
      case 7:
        digitalWrite(9,LOW);
        digitalWrite(8,LOW);
        digitalWrite(7,LOW);
        delay(750);
        break;
      case 8:
        for(int eight=1;eight<8;eight++){
          digitalWrite(pins[eight],LOW);
        }
        delay(750);
        break; 
      case 9:
        for(int nine = 0; nine<8; nine++){
          if(nine == 3) {continue;}
          digitalWrite(pins[nine],LOW);
        }
        delay(750);
        break;
    }
  }
  for(int j=0;j<8;j++){
    digitalWrite(pins[j],HIGH); 
    delay(25);
  }
  delay(750);
}
