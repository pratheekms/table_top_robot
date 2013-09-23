int mr1=3;  
int mr2=5;
int ml1=9;
int ml2=10;
int enr=7;
int enl=8;

void setup()
{
  Serial.begin(9600);
  pinMode(mr1,OUTPUT);
  pinMode(mr2,OUTPUT);
  pinMode(ml2,OUTPUT);
  pinMode(ml1,OUTPUT);
  pinMode(enr,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(12,OUTPUT);
}
void loop()
{
  digitalWrite(enr,HIGH);
  digitalWrite(enl,HIGH);

  
  int value_l=analogRead(A5);
  int value_r=analogRead(A0);
  
  
   Serial.println(value_l);
   Serial.println(value_r);
  
  if(value_l>200 && value_r>200)
  {
    Serial.println("forward");
    analogWrite(ml1,255);
    analogWrite(ml2,0);
    analogWrite(mr2,0);
    analogWrite(mr1,255);
    
  }
  else if(value_l<200 && value_r>200)
  {
    backright();
}
  
  else if(value_l>200 && value_r<200)
  {
    backleft();
  }
  else if(value_l<200 && value_r<200)
  {
    Serial.println("backward");
    analogWrite(ml1,0);
    analogWrite(ml2,255);
    analogWrite(mr2,255);
    analogWrite(mr1,0);

  }
  
  
}

void backleft()
{ int t1,t2;
  t1=millis();
  t2=millis();
  while(t2-t1<3000)
  {
    t2=millis();
   Serial.println("back left");
    analogWrite(ml1,0);
    analogWrite(ml2,255);
    analogWrite(mr1,0);
    analogWrite(mr2,50);
  }
}

void backright()
{
  
  unsigned long int t1,t2;
  t1=millis();
  t2=millis();
  while(t2-t1<3000)
  {
  Serial.println("back right");
   t2=millis();
    analogWrite(ml1,0);
    analogWrite(ml2,50);
    analogWrite(mr1,0);
    analogWrite(mr2,255);
  }
}
