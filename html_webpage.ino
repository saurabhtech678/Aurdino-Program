void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(115200);
sendtoESP("AT+RST",2000);
sendtoESP("AT+CWMODE=1",2000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"",8000);
sendtoESP("AT+CIFSR",2000);
sendtoESP("AT+CIPMUX=1",2000);
sendtoESP("AT+CIPSERVER=1,80",5000);
}

void loop()
 {
  int a = random(100,500);
  String data="HTTP/1.1 200 OK\r\n"
          "Content-type: text/html\r\n"
          "Connection: close\r\n\r\n"
          "<!DOCTYPE html>"
          "<html>"
          "<head>"
          "<meta http-equiv='refresh' content='10'>"
          "<title>GSP_BPL</title>"
          "<style>"
          "body{font-family:Arial;text-align:center;margin-top:50px;}"
          "h1{font-size:32px;color:#6FF527;}"
          "p{font-size:24px;color:#F59127;}"
          "</style>"


          "</head>"
          "<body>"
          "<h1> IOT Lab Data</h1>"
          "<p> Sensor Value: <b>"+ String(a) +"</b></p>"
          "<p> This page will auto refresh every 10 sec</p>"
          "</body>"
          "</html>";


int ConnectionID;
if (Serial3.available())
 {   
  if (Serial3.find("+IPD,"))
  {
  ConnectionID = Serial3.read()+1;
  Serial.print("ConnectionID: ");
  Serial.println(ConnectionID);
  Serial.print("Data string length = ");
  Serial.println(data.length());

 String send = "AT+CIPSEND="+ String(ConnectionID) +","+String( data.length());
 sendtoESP(send, 2000);
 sendtoESP(data, 2000);
 sendtoESP("AT+CIPCLOSE="+String(ConnectionID),1000);

  }
 }
}
void sendtoESP(String cmd,int delayTime)
{   
  Serial3.println(cmd);
  delay(delayTime);
  while(Serial3.available())
   {
  Serial.write(Serial3.read());
  }
}
