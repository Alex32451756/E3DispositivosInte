// ToDo before uploading the software to your ESP8266 target


// 1) Replace with your network credentials
const char* ssid     = "TP-Link_AF92";
const char* password = "71425719";

//Programa para capturar el pulso cardiaco- Version 1.0
//Revisado Prof: Bolaños 2018- Programa base tomado de Internet

// la variable pulso contiene los datos brutos entrantes pudiendo variar entre 0-1024
int pulso;

// Determina qué señal “se contará como un latido” y qué señal ignorar.
  int limite = 522;//original 550- Ver los picos en Ploter y reprogramar


#include <Wire.h>
#include "DHT.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 2) Set the right Time-zone
// Set offset time in seconds to adjust for your timezone, for example:
// GMT +1 = 3600 // Europe
// GMT +8 = 28800
// GMT -1 = -3600
// GMT 0 = 0
const int TZ=-18000;


#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#include "OledTwi.h"
#include "OledPix.h"

  /*Reloj*/
  static char buf[20];

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;

// Variables for the Quartz Clock
int h,m,s =0;
boolean AM_PM, S_Tick = false; 

// For accurate elapsed Time counting, use Arduino Real Time Clock on the fly readings and not delay()
static uint32_t last_time, now = 0; // RTC
  /*fin reloj*/

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);
unsigned long delayTime;

// Uncomment one of the lines below for whatever DHT sensor type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT21 // DHT 21 (AM2301)
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//DHT Sensor;
uint8_t DHTPin = 12;
DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;
float Temp_Fahrenheit;

void setup() {
  Serial.begin(9600);
   get_time(); //reloj
  pinMode(DHTPin, INPUT);
  dht.begin();
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
   // init done
  display.display();
  delay(100);
  display.clearDisplay();
  display.display();
  display.setTextSize(1.75);
  display.setTextColor(WHITE);


}
void loop() {

  Humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  Temperature = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  Temp_Fahrenheit= dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(Humidity) || isnan(Temperature) || isnan(Temp_Fahrenheit)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(Humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(Temperature);
  Serial.print(F("°C "));
  Serial.print(Temp_Fahrenheit);
  Serial.println(F("°F "));

  display.setCursor(0,0);
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(Temperature);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(Humidity);
  display.print(" %");
  
  display.display();
  delay(10000);

  /*Fin del sensor de Temperatura*/

  now=millis();
if (( now-last_time)>=1000 ) // importance of >=
 {
  last_time=last_time+1000; //now; // prepare for next loop 
   s=s+1; //increment sec. counting
     
// ---- manage seconds, minutes, hours am/pm overflow ----
 if(s==60){
  s=0;
  m=m+1;
  //get_time(); for Test 
 }
 if(m==60)
 {
  m=0;
  h=h+1;
 }
 if(h==24)
 {
  h=0;
  get_time(); 
  //flag=flag+1;
  //if(flag==2)flag=0;
 } 

// update OLED

LiCol(0,110);
   Dec99(s); // second ticker

   
 LiCol(7,0); 
 BigDec99(h); // hour

 LiCol(7,48); 
 if (S_Tick==false){
  S_Tick=true;
  Big(0x3c); //: separator
 } else {
 S_Tick=false;
 Big(0x3b); // blank for blink effect 
 }

 LiCol(7,72); 
 BigDec99(m); // minute

 delay(700); // give some air to the ESP Task to avoid reset  
 // 800 fait retarder la clock
 // 700 ok
 // 500, 600 produit des reset
 }
 

 /*Fin De Reloj*/
 /*Cardiaco*/
// Lee el valor del pin analógico 0, y Asigna este valor a la variable “pulso”.
pulso = analogRead(A0);

//Este caracter lo filtra la aplicación en APP inventor
//Serial.print("*"); // NOTA DJB: no usada en esta version
// Envíe el valor de pulso al Plotter serial. Comentar si queremos visualizar en “serial ploter”
Serial.println(pulso);
  display.setCursor(0,0);
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("cardiaco: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(pulso);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  //display.write(167);
  //display.setTextSize(2);
 // display.print("C");
//Retardo de 35ms
display.display();
delay(10000);
 
 /*fin cardiaco*/
  

}
