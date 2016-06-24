// code for detecting car using ultrasonic sensor 
//and opening gate(servomotor) 
 #include<Servo.h>

 Servo myservo;

 int pos=0;
 const int trig=2;
 const int echo=4;
 int pre=0,current=0;
 long duration,cm;
 
void setup() {
  // put your setup code here, to run once:
    myservo.attach(9);
    myservo.write(90);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 pinMode(trig,OUTPUT);
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
  digitalWrite(trig,LOW);

  pinMode(echo,INPUT);
  duration=pulseIn(echo,HIGH);
 pre=current;
  cm=microsecondsToCM(duration);
  current=cm;
 
  if(current < pre-3)
  {
    action_90_0();
    
  }
  if(current > pre+3)
  {
     delay(5000);
    action_0_90();
   
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();


  delay(100);
}

void action_0_90(){
  for(pos=0;pos<=90;pos+=1){
    myservo.write(pos);
    delay(15);
  }
  
}
void action_90_0(){
  for(pos=90;pos>=0;pos-=1){
    myservo.write(pos);
    delay(15);
  }
  
  }

long microsecondsToCM(long d){
  return d /29 /2;
}

