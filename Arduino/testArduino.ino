int LEFT_FAN_PINS[3] = {
  5, 6 ,7};
int MIDDLE_FAN_PINS[3] = {
  2, 3 ,4};
int RIGHT_FAN_PINS[3] = {
  8, 9 ,10};

int panpos = 90;
int tiltpos = 90;

void setup() 
{
  Serial.begin(9600);	// opens serial port, sets data rate to 9600 bps
  //Serial.println("ready");
  for (int i=2; i<=10; i++)
  {
    pinMode(i, OUTPUT);
  }
  setSpeeds(0, 0, 0);
}

void serialEvent(){
  byte speeds = 0;
  while (Serial.available()) 
  {
    speeds = Serial.read();	 // read the incoming byte:
  }
  
  if (speeds == 0xc0)
  {
    delay(5);
    Serial.write(121);
    return;
  }
  setSpeeds(speeds&0x3, (speeds>>2)&0x3, (speeds>>4)&0x3);  
}

void loop() 
{
  delay(50);
}  

void setSpeeds(int left, int middle, int right)
{
  setFanMode(LEFT_FAN_PINS, left, 0);
  setFanMode(MIDDLE_FAN_PINS, middle, 1);  
  setFanMode(RIGHT_FAN_PINS, right, 0);
}

void setFanMode(int *fan_pins, int speed, int high)
{
  int low = (high==1)?0:1;
  switch (speed)
  {
  default:
  case 0:
    digitalWrite(fan_pins[0], low);
    digitalWrite(fan_pins[1], low);
    digitalWrite(fan_pins[2], low);
    break;
  case 1:
    digitalWrite(fan_pins[0], high);
    digitalWrite(fan_pins[1], low);
    digitalWrite(fan_pins[2], low);
    break;
  case 2:
    digitalWrite(fan_pins[0], low);
    digitalWrite(fan_pins[1], high);
    digitalWrite(fan_pins[2], low);
    break;
  case 3:
    digitalWrite(fan_pins[0], low);
    digitalWrite(fan_pins[1], low);
    digitalWrite(fan_pins[2], high);    
    break;
  }
}
