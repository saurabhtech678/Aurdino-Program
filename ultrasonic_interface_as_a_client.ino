int trig = 21;
int echo = 20;
float time, cm, inches;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
Serial3.begin(115200);
Serial.println("Serial Monitor Setup.....");
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
sendtoESP("AT+RST", 2000);
sendtoESP("AT+CWMODE=1", 1000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"", 5000);
sendtoESP("AT+CIFSR" ,2000);
sendtoESP("AT+CIPMUX=0", 5000);
sendtoESP("AT+CIPSERVER=1,80" , 5000);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);


  time = pulseIn(echo, HIGH);
  cm = 0.0343 * (time/2);  // distance in CM Speed is 0.0343 cm/usec
  inches = cm/2.54; 

   sendtoESP("AT+CIPMUX=0", 2000);
  sendtoESP("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80", 1000);
 
 String data = "GET /update?api_key=54L9GBKK389M8S3X&field2=" + String(cm)+ "&field4=" + String(inches)
                +"HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnections: close\r\n\r\n"; 

  sendtoESP("AT+CIPSEND="+String(data.length()),2000);
  
  sendtoESP(data,5000);
  //sendToESP("AT+CIPCLOSE",2000);
  //sendToESP("AT+CIPCLOSE",2000);
  delay(15000);
}

void sendtoESP(String command, int delayTime)
{
  Serial3.println(command);
  delay(delayTime);
  while(Serial3.available())
  {
    Serial.write(Serial3.read());  // show response on SM
  }
}

