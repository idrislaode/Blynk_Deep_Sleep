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
  
  WiFi.mode(WIFI_STA); 
  Serial.println("Connect to " + String(ssid));
  if (pass && strlen(pass)) { 
    WiFi.begin(ssid, pass); 
  } else {
    WiFi.begin(ssid);
  }
  int tm = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    if(millis() - tm > 4000){Serial.println("Time to Sleep"); ESP.deepSleep(30e6);}
  } 
    
  Blynk.begin(auth, ssid, pass); 
//  delay(200); 
}

void loop() {
  // put your main code here, to run repeatedly:

//  Serial.println();
//  Serial.print("ADC : ");
//  Serial.println(analogRead(A0));
  
  Blynk.run();

  SendBlynk();
  delay(20); 
  
//  Serial.println("Enter Deep Sleep");
  ESP.deepSleep(30e6); 
//  Serial.println("Time to Wake Up");
}


void SendBlynk(){
  int tm = millis(); 
  
//  while(Blynk.connect()==false){if(millis() - tm > 3000){ESP.deepSleep(30e6);}}
  int adc = analogRead(A0); 
  int pers = map(adc, 50, 700, 100, 0);
  if(pers<0){pers=0;}
  if(pers>100){pers=100;}
    
//  Serial.print(String("ADC: ") + adc);
//  Serial.println(String(" VOL: ") + pers);
  
  Blynk.setProperty(V1,"onLabel",String(pers)+"%");
  Blynk.setProperty(V1,"offLabel",String(pers)+"%");
} 
