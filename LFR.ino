
int sensor[]={4,7,8,10,11,12};
int motor[]={3,5,9,6};
int lfa,rfa;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<6;i++){
    pinMode(sensor[i],INPUT);
  }
  for(int i=0;i<4;i++){
    pinMode(motor[i],OUTPUT);
  }
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  lfa=digitalRead(sensor[0])+digitalRead(sensor[1])+digitalRead(sensor[2]);
  rfa=digitalRead(sensor[3])+digitalRead(sensor[4])+digitalRead(sensor[5]);
  Serial.print(lfa);
  Serial.print("\t");
  Serial.println(rfa);
  
  if((rfa==1 && lfa==1)){
    analogWrite(motor[0],150);
    analogWrite(motor[1],0);
    analogWrite(motor[2],150);
    analogWrite(motor[3],0);
  }/*
  if(rfa==lfa){
    analogWrite(motor[0],150);
    analogWrite(motor[1],0);
    analogWrite(motor[2],150);
    analogWrite(motor[3],0);
  }*/
  else if(rfa>lfa){
    analogWrite(motor[0],150);
    analogWrite(motor[1],0);
    analogWrite(motor[2],0);
    analogWrite(motor[3],0);
  }
  else if(rfa<lfa){
    analogWrite(motor[0],0);
    analogWrite(motor[1],0);
    analogWrite(motor[2],150);
    analogWrite(motor[3],0);
  }
  else if(lfa<=1 && rfa>=2){
    analogWrite(motor[0],0);
    analogWrite(motor[1],0);
    analogWrite(motor[2],150);
    analogWrite(motor[3],0);
  }
  else if(lfa==3 && rfa==3){
    analogWrite(motor[0],0);
    analogWrite(motor[1],0);
    analogWrite(motor[2],0);
    analogWrite(motor[3],0);
  }
  else {
    analogWrite(motor[0],150);
    analogWrite(motor[1],0);
    analogWrite(motor[2],0);
    analogWrite(motor[3],0);
  }/*
  else{
    analogWrite(motor[0],150);
    analogWrite(motor[1],0);
    analogWrite(motor[2],150);
    analogWrite(motor[3],0);
  }*/

}
