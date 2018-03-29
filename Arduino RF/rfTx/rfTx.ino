#include <RCSwitch.h>
int x= A0;
int y=A1;

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  mySwitch.enableTransmit(8);  // Using Pin #10
}

void loop() {
  //mySwitch.send("10000100011000000000010100");
   int X=analogRead(x);
 int Y=analogRead(y);
  mySwitch.send(X,18);
  //delay(1000);  
  mySwitch.send(Y,20);
 // delay(1000);  
  
}
