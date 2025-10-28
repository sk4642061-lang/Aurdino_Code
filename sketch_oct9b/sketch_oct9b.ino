int a=8;
int b=3;
int c=2;
void setup() {
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(c,OUTPUT);
}
void loop() {
  delay(10000);
 digitalWrite(a,HIGH);
 delay(1000);
 digitalWrite(b,HIGH);
 delay(1000);
 digitalWrite(c,HIGH);
 delay(1000);
 digitalWrite(a,LOW);
delay(1000);
digitalWrite(b,LOW);
delay(1000);
digitalWrite(c,LOW);
delay(1000);
}
