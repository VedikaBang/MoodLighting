#include <SoftwareSerial.h>
SoftwareSerial blSerial(2, 3); //(RX(2) <-B L_TX , TX(2) -> BL_RX)
#define LED1 8
#define LED2 9
#define LED3 10

char blresponse[128];
int index=0;
void setup() {
  Serial.begin(9600);
  blSerial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  Serial.println("Emotion Detction Started");
}

void loop() {
  if(blSerial.available()){
    delay(200);
    index=0;
    while(blSerial.available()){
      blresponse[index++]=blSerial.read();
      delay(2);
    }
    blresponse[index]=0;
    Serial.println(blresponse);
    if(strstr(blresponse,"Sad")){
      Serial.print("Sad Valid: ");Serial.println(blresponse);
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);      
    }    
    else if(strstr(blresponse,"Angry")){
      Serial.print("Anger Valid: ");Serial.println(blresponse);
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,HIGH);
    }
    else if(strstr(blresponse,"Happy")){
      Serial.print("Happy Valid: ");Serial.println(blresponse);    
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
    }
    else{
      Serial.print("Invalid : ");Serial.println(blresponse);
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
    }
  }
  delay(10);
}
