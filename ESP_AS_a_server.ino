void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial3.begin(115200);
sendtoESP("AT+RST",2000);
sendtoESP("AT+CWMODE=1",2000);
sendtoESP("AT+CWJAP=\"GSP-STAFF\",\"55r@G5b#\"",5000);
sendtoESP("AT+CIFSR",2000);
sendtoESP("AT+CIPMUX=1",2000);
sendtoESP("AT+CIPSERVER=1,80",5000);
sendtoESP("AT+CIPSEND=0,56",3000);
sendtoESP("MY NAME IS SAURABH AND I AM CURRENTLY PURSUING IN SSRGSP",5000);
sendtoESP("AT+CIPCLOSE=0",1000);
sendtoESP("AT+CIPSERVER=0",3000);
}

void loop()
 {
  // put your main code here, to run repeatedly:
int connectinID;
if(Serial3.available()
{   
  if(Serial3.find("+IPD,"))
  {    
   connectinID=Serial3.read()-48;
   String send = "AT+CIPSEND=" +String(connectinID)+ data.length();
   sendtoESP(send,2000);
   sendtoESP(String(a),1000);
   sendtoESP("AT+CIPCLOSE="+String,)

    //sendtoESP("AT+CIPSEND=String(connectinID),data.length(),3000");
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
