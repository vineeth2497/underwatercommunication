
#define redled 8
#define blueled 6
#define greenled 7
#define red_led 5
#define blue_led 9
int brightness = 50;
int buttonone = 2;
int buttontwo = 3;
int buttonthree = 4;

void setup() 
{
  // initialize digital pin 13 as an output.
  Serial.begin(9600);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(blueled,OUTPUT);
  pinMode(red_led,OUTPUT);
  pinMode(blue_led,OUTPUT);
  
  pinMode(buttonone,INPUT_PULLUP);
  pinMode(buttontwo,INPUT_PULLUP);
  pinMode(buttonthree,INPUT_PULLUP);
  
 
  
}

// the loop function runs over and over again forever
void loop() 
{/*
 if (digitalRead(buttonone) == HIGH)
  { 
      WriteChar('d');
      delay(1500);
      WriteChar('a');
      delay(1500);
      WriteChar('n');
      delay(1500);
      WriteChar('g');
      delay(1500);
      WriteChar('e');
      delay(1500);
      WriteChar('r');
      delay(1500);
  } 
  else if(digitalRead(buttontwo) == HIGH) 
  {
      WriteChar('h');
      delay(1500);
      WriteChar('e');
      delay(1500);
      WriteChar('l');
      delay(1500);
      WriteChar('p');
      delay(1500);
  }
  else if ( digitalRead(buttonthree) == HIGH)
  {
      WriteChar('s');
      delay(1500);
      WriteChar('o');
      delay(1500);
      WriteChar('s');
      delay(1500);
      
  }
  else
  {*/
      /*WriteChar('h');
      delay(2500);
      WriteChar('e');
      delay(2500);
      WriteChar('l');
      delay(2500);
      WriteChar('l');
      delay(2500);
      WriteChar('o');
      delay(2500);
      */
      WriteChar('0');
    
      
/*}*/
 
}

void WriteChar(char str){
  switch (str){
    case 'a':
      //code for a is 00001
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      digitalWrite(blue_led,LOW);
      break;
    case 'b':
      //code for b is 00010
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      digitalWrite(blue_led,LOW);
      break;
    case 'c':
      //code for c is 00011
      digitalWrite(redled,HIGH);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      digitalWrite(blue_led,LOW);
      break;
    case 'd':
      //code for d is 00100
      digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      digitalWrite(blue_led,LOW);
      break;
    case 'e':
      //code for e is  00101
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      //analogWrite(red_led,brightness);
      digitalWrite(blue_led,LOW);
      break;
    case 'f':
      //code for f is 00110
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      digitalWrite(blue_led,LOW);
      break;
    case 'g':
      //code for g is 00111
       digitalWrite(redled,HIGH);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      digitalWrite(blue_led,LOW);
      break;
    case 'h':
      //code for h is 01000
      digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,brightness);
      digitalWrite(blue_led,LOW);
      break;
    case 'i':
      //code for i is  01001
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,HIGH);
      digitalWrite(blue_led,LOW);
    break;
    case 'j':
      //code for j is 01010
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,HIGH);
      digitalWrite(blue_led,LOW);
      break;
    case 'k':
      //code for k is 01011
      digitalWrite(redled,HIGH);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,HIGH);
      digitalWrite(blue_led,LOW);
      break;
    case 'l':
      //code for l is 01100
      digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,HIGH);
      //digitalWrite(red_led,HIGH);
      analogWrite(red_led,brightness);
      digitalWrite(blue_led,LOW);
      break;
    case 'm':
      //code for m is 01101
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,HIGH);
      digitalWrite(blue_led,LOW);
      break;
    case 'n':
      //code for n is 01110
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,HIGH);
      digitalWrite(blue_led,LOW);
      break;
    case 'o':
      //code for o is 01111
      analogWrite(red_led,brightness);
     //digitalWrite(blueled,HIGH);
      analogWrite(blueled,brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(redled,HIGH);
      //digitalWrite(red_led,HIGH);
      digitalWrite(blue_led,LOW);
      break;
    case 'p':
      //code for p is 10000
      digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'q':
      //code for q is 10001
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'r':
      //code for r is 10010
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 's':
      //code for s is 10011
      digitalWrite(redled,HIGH);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      
      break;
    case 't':
      //code for t is 10100
       digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'u':
      //code for u is 10101
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'v':
      //code for v is 10110
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'w':
      //code for w is 10111
      digitalWrite(redled,HIGH);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,LOW);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'x':
      //code for x is 11000
      digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,HIGH);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'y':
      //code for y is 11001
      digitalWrite(redled,HIGH);
      digitalWrite(blueled,LOW);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,HIGH);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      break;
    case 'z':
      //code for z is 11010
      digitalWrite(redled,LOW);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,LOW);
      digitalWrite(red_led,HIGH);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led, brightness);
      case'0':
      digitalWrite(redled,HIGH);
      //digitalWrite(blueled,HIGH);
      analogWrite(blueled, brightness);
      digitalWrite(greenled,HIGH);
      digitalWrite(red_led,HIGH);
      //digitalWrite(blue_led,HIGH);
      analogWrite(blue_led,HIGH);
      break;
    default:
      Serial.println(str - '0');
      break;
  }
}

