#define BLYNK_TEMPLATE_ID "TMPL3gm4zVgDj"
#define BLYNK_TEMPLATE_NAME "led control"
#define BLYNK_AUTH_TOKEN "vibHzafI-3Hk614SSGK2hr19K_UWbIvy"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "jio airfiber 0";
char pass[] = "12345678";

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

if(pinValue==0)
{ 
  digitalWrite(2, LOW);
}
else
{ 
  digitalWrite(2, HIGH);
}
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
  pinMode(2, OUTPUT);
}

void loop()
{
  Blynk.run();
}
