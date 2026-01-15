int led=2;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led ,HIGH );
delay(1000);
//Serial.println("led on");
Serial.println("led chalu hai");




digitalWrite(led, LOW);
delay(3000);
//Serial.println("led off");
Serial.print("     Band    hai  ");
}
