 #include <RCSwitch.h>
 
int LW_Forward=7;
int LW_Backward=6;
int RW_Forward=5;
int RW_Backward=4;
RCSwitch mySwitch = RCSwitch();


void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
 pinMode(RW_Forward,OUTPUT);
pinMode(RW_Backward,OUTPUT);
pinMode(LW_Forward,OUTPUT);
pinMode(LW_Backward,OUTPUT);

pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
}

int data1, data2;

void loop() {
  if (mySwitch.available()) {
    //output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());

    if(mySwitch.getReceivedBitlength() == 18){
      data1 = mySwitch.getReceivedValue();      
    }
    if(mySwitch.getReceivedBitlength() == 20){
      data2 = mySwitch.getReceivedValue();      
    }
   
   
    Serial.print("Data1: ");
    Serial.println(data1);
    Serial.print("Data2: ");
    Serial.println(data2);
   
    if((data1>=380 && data1<=450) && (data2>=380 && data2<=470) )
{
  Stop();
}
else if((data1>=320 && data1<=380))
{
  Forward();
  
}
else if(data1>=450 && data1<=510)
{
  
  Backward();
}

else if((data2>=470 && data2<=510)&&(data1>=380 && data1<=450))
{
  Right();
}
else if((data2>=300 && data2<=380)&&(data1>=380 && data1<=450))
{
  Left();
}
    mySwitch.resetAvailable();
  }
}

void Stop(){
  digitalWrite(RW_Forward, LOW);  
   digitalWrite(RW_Backward, LOW); 
   digitalWrite(LW_Forward, LOW);   
   digitalWrite(LW_Backward, LOW);
   mySwitch.resetAvailable();
}

void Backward()
{
    digitalWrite(RW_Forward, HIGH);  
   digitalWrite(RW_Backward, LOW); 
   digitalWrite(LW_Forward, HIGH);   
   digitalWrite(LW_Backward, LOW);
  analogWrite(8,100);
   analogWrite(9,100);
   mySwitch.resetAvailable();
  }
  
void Forward()
{
   digitalWrite(RW_Forward, LOW);  
   digitalWrite(RW_Backward, HIGH); 
   digitalWrite(LW_Forward, LOW);   
   digitalWrite(LW_Backward, HIGH);
   analogWrite(8,100);
   analogWrite(9,100);
   mySwitch.resetAvailable();
   
}
  
void Left()
{
  
  digitalWrite(RW_Forward, LOW);  
   digitalWrite(RW_Backward, HIGH); 
   digitalWrite(LW_Forward, LOW);   
   digitalWrite(LW_Backward, LOW);
   analogWrite(8,100);
   analogWrite(9,100);
   
   
 
  
  mySwitch.resetAvailable();
 }
void Right()
{
      digitalWrite(RW_Forward, LOW);  
   digitalWrite(RW_Backward, LOW); 
   digitalWrite(LW_Forward, LOW);   
   digitalWrite(LW_Backward, HIGH);
   analogWrite(8,100);
   analogWrite(9,100);
   mySwitch.resetAvailable();
  }

  

