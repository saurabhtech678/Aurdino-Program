const int TempPin = A6;
const int HumPin = A7;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = temp();
  float humidity = Hum();

Serial.println("******************************");
Serial.print("Temperature  :");
Serial.print(temperature);
Serial.println("°c");

Serial.print("Relative Humidity  : ");
Serial.print(humidity);
Serial.println("%RH");
Serial.println("********************************"); 
delay(1000);

}

float temp()
{ 
  float sumTemp = 0;
  for (int i=0;i<10;i++) 
  {
   int t = analogRead(TempPin);
  float Temp_voltage = (t)* (5.0/1023);
  float temp = ((2*Temp_voltage) -0.5)*100;
  sumTemp += temp;
  }  
  return(sumTemp/10);
}
float Hum()
{ 
  float sumHum = 0;
  for (int i=0;i<10;i++) 
  {
  float h = analogRead(HumPin);
  float Hum_voltage = (h)* (5.0/1023);
  float Humi = ((2*Hum_voltage/5.0)-0.16)/0.0062;

  sumHum += Humi;
  }
  return(sumHum/10);
}