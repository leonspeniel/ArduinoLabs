int ir=7;
int x;

void setup(){
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop(){
  x=digitalRead(ir);
  Serial.println(x);
  delay(300);
}