


#define PIN1  4
#define PIN2  5


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
 
  
  digitalWrite(PIN1, HIGH);  // switch on relay1
  digitalWrite(PIN2, HIGH);  // switch on relay2 
  
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
    
   
  } // if(Serial
}
  
 
