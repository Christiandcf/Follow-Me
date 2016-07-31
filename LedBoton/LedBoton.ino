
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;

int ledPin6 = 6;
int ledPin7 = 7; // choose the pin for the LED
int ledPin8 = 8;

int right = A0; // choose the input pin (for a pushbutton)
int left = A1;
int val = 0;     // variable for reading the pin status
int val2 = 0;

void setup() {
  pinMode(ledPin2, OUTPUT);  // declare LED as output
  pinMode(ledPin3, OUTPUT); 
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin6, OUTPUT);  // declare LED as output
  pinMode(ledPin7, OUTPUT); 
  pinMode(ledPin8, OUTPUT);
  
  pinMode(right, INPUT);    // declare pushbutton as input
  pinMode(left, INPUT);
}

void loop(){
  val = digitalRead(right);  // read input value
  val2 = digitalRead(left);
  
//  if (val == HIGH) {         // check if the input is HIGH (button released)
//    digitalWrite(ledPin7, HIGH); 
//    delay(500);
//    digitalWrite(ledPin8, HIGH);
//  } else {
//    digitalWrite(ledPin7, LOW);  // turn LED ON
//    delay(500);
//    digitalWrite(ledPin8, LOW);
//  }

 while(val == HIGH && val2==HIGH)
  {
    digitalWrite(ledPin7, HIGH); 
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin6, HIGH); 
    digitalWrite(ledPin4, HIGH); 
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, HIGH); 

    delay(50);
      
    digitalWrite(ledPin7, LOW); 
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin6, LOW); 
    digitalWrite(ledPin4, LOW); 
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW); 

    val=LOW;
    val2=LOW;
  }

  while(val == HIGH)
  {
    
    digitalWrite(ledPin7, HIGH); 
    delay(300);
    digitalWrite(ledPin7, LOW);

    digitalWrite(ledPin8, HIGH); 
    delay(300);
    digitalWrite(ledPin8, LOW);

    digitalWrite(ledPin6, HIGH); 
    delay(300);
    digitalWrite(ledPin6, LOW);

    val = LOW;
  }

  while(val2 == HIGH)
  {
    
    digitalWrite(ledPin4, HIGH); 
    delay(300);
    digitalWrite(ledPin4, LOW);

    digitalWrite(ledPin3, HIGH); 
    delay(300);
    digitalWrite(ledPin3, LOW);

    digitalWrite(ledPin2, HIGH); 
    delay(300);
    digitalWrite(ledPin2, LOW);

    val2 = LOW;
  }

 

  }

