#define BLYNK_TEMPLATE_ID "TMPLDG-mhjGj"
#define BLYNK_DEVICE_NAME "Rubboto"
#define BLYNK_AUTH_TOKEN "KQGTtuMUoNbAUgK6pGGvZLS2yQLkuSle"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "LD";
char pass[] = "1010Kali";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  Blynk.begin(auth, ssid, pass);
  delay(200);
//  Blynk.begin(auth, ssid, pass, "blynk-cloud", 80);
}

void loop() {
  // put your main code here, to run repeatedly:

//  Serial.println();
//  Serial.print("ADC : ");
//  Serial.println(analogRead(A0));
  
  Blynk.run();

  SendBlynk();
  delay(200);
  
//  Serial.println("Enter Deep Sleep");
  ESP.deepSleep(30e6); 
//  Serial.println("Time to Wake Up");
}


void SendBlynk(){
  while(Blynk.connect()==0){}
  int adc = analogRead(A0); 
  Blynk.setProperty(V1,"onLabel",String(adc));
  Blynk.setProperty(V1,"offLabel",String(adc));
}
