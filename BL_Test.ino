#include <SoftwareSerial.h>
SoftwareSerial blSerial(2, 3); //(RX(2) <-B L_TX , TX(2) -> BL_RX)
char blresponse[128];
int index=0;
void setup() {
  Serial.begin(9600);
  blSerial.begin(9600);
  Serial.println("Bluetooth Testing");
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
   }
   delay(10);
}
