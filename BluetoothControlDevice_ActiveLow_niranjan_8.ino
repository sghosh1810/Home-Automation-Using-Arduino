


#define PIN1  4
#define PIN2  5
#define PIN3  6
#define PIN4  7
#define PIN5  8
#define PIN6  9
#define PIN7  10
#define PIN8  11


int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte
boolean status_unlock;
boolean status_bluetooth;

long interval = 1000;           // interval at which to blink (milliseconds)
long previousMillis = 0;        // will store last time LED was updat
int minite,sec;


void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  //pinMode(2, INPUT);   // digital sensor is on digital pin 2
  //establishContact();  // send a byte to establish contact until receiver responds 
  
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  pinMode(PIN5, OUTPUT);
  pinMode(PIN6, OUTPUT);
  pinMode(PIN7, OUTPUT);
  pinMode(PIN8, OUTPUT);

 
  
  digitalWrite(PIN1, HIGH);  // switch on relay1
  digitalWrite(PIN2, HIGH);  // switch on relay2
  digitalWrite(PIN3, HIGH);  // switch on relay3
  digitalWrite(PIN4, HIGH);  // switch on relay4
  digitalWrite(PIN5, HIGH);  // switch on relay5
  digitalWrite(PIN6, HIGH);  // switch on relay6
  digitalWrite(PIN7, HIGH);  // switch on relay7
  digitalWrite(PIN8, HIGH);  // switch on relay8


  status_bluetooth = true;
  status_unlock = false;
  sec = 0;
}

void loop()
{
  if (Serial.available() > 0) {   
       
    inByte = Serial.read();             // get incoming byte:  

    if(inByte == 'A'){    
      Serial.print('A');         // send a char
      digitalWrite(PIN1, LOW);        // switch on relay1
      status_unlock = false;
      inByte = 0;     
    }
    
    if(inByte == 'a'){    
      digitalWrite(PIN1, HIGH);        // switch off relay1
      Serial.print('a');         // send a char      
      status_unlock = true;
      sec = 0;
      inByte = 0;     
    }
    
    if(inByte == 'B'){    
      digitalWrite(PIN2, LOW);        // switch on relay2
      Serial.print('B');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'b'){    
      digitalWrite(PIN2, HIGH);        // switch off relay2
      Serial.print('b');         // send a char
      inByte = 0;     
    }
	
	if(inByte == 'C'){    
      digitalWrite(PIN3, LOW);        // switch on relay3
      Serial.print('C');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'c'){    
      digitalWrite(PIN3, HIGH);        // switch off relay3
      Serial.print('c');         // send a char
      inByte = 0;     
    }
	
	if(inByte == 'D'){    
      digitalWrite(PIN4, LOW);        // switch on relay4
      Serial.print('D');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'd'){    
      digitalWrite(PIN4, HIGH);        // switch off relay4
      Serial.print('d');         // send a char
      inByte = 0;     
    }
	
	if(inByte == 'E'){    
      digitalWrite(PIN5, LOW);        // switch on relay5
      Serial.print('E');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'e'){    
      digitalWrite(PIN5, HIGH);        // switch off relay5
      Serial.print('e');         // send a char
      inByte = 0;     
    }
    
	
   if(inByte == 'F'){    
      digitalWrite(PIN6, LOW);        // switch on relay6
      Serial.print('F');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'f'){    
      digitalWrite(PIN6, HIGH);        // switch off relay6
      Serial.print('f');         // send a char
      inByte = 0;     
    }
	
	if(inByte == 'G'){    
      digitalWrite(PIN7, LOW);        // switch on relay7
      Serial.print('G');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'g'){    
      digitalWrite(PIN7, HIGH);        // switch off relay7
      Serial.print('g');         // send a char
      inByte = 0;     
    }
	
	if(inByte == 'H'){    
      digitalWrite(PIN8, LOW);        // switch on relay8
      Serial.print('H');         // send a char
      inByte = 0;     
    }
    
    if(inByte == 'h'){    
      digitalWrite(PIN8, HIGH);        // switch off relay8
      Serial.print('h');         // send a char
      inByte = 0;     
    }
	
  } // if(Serial
}
  
 
