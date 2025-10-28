int a=8;
int b=10;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  Serial.begin(300);

}

void loop() {
 //Serial.print("code 1");
 digitalWrite(a,HIGH);
 Serial.print("a led on\n");
 digitalWrite(b,LOW);
Serial.print("b led off\n");
 delay(1000);
 digitalWrite(a,LOW);
  Serial.print("a led off\n");
 digitalWrite(b,HIGH);
 Serial.print("b led on\n");
 delay(1000);

}
