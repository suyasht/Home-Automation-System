int light=4;
int fan=6;
int plug=8;

int Received=0;
int light_state =0;
int fan_state =0;
int plug_state=0;



void setup(){
Serial.begin(9600);

pinMode(light,OUTPUT);
digitalWrite(light,HIGH);

pinMode(fan,OUTPUT);
digitalWrite(fan,HIGH);

pinMode(plug,OUTPUT);
digitalWrite(plug,HIGH);
}



void loop()
{
  if(Serial.available()>0)
  {
    Received = Serial.read();
  }

//Light
  
  if (light_state == 0 && Received == '1')
  {
    digitalWrite(light,HIGH);
    light_state=1;
    Received=0;
  }
  if (light_state ==1 && Received == '1')
  {
      digitalWrite(light,LOW);
      light_state=0;
      Received=0;
  }



//FAN


  if (fan_state == 0 && Received == '2')
  {
      digitalWrite(fan,HIGH);
      fan_state=1;
      Received=0;
  }
  if (fan_state ==1 && Received == '2')
  {
      digitalWrite(fan,LOW);
      fan_state=0;
      Received=0;
  }


  if (plug_state == 0 && Received == '3')
  {
      digitalWrite(plug,HIGH);
      plug_state=1;
      Received=0;
  }
  if (plug_state ==1 && Received == '3')
  {
      digitalWrite(plug,LOW);
      plug_state=0;
      Received=0;
  }
}
