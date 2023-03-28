#include "Arduino.h"
#include "PCF8574.h"
PCF8574 pcf8574(0x27);

#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <ESP8266Ping.h>
#include <BlynkSimpleEsp8266.h>
#include "WebserverWifiEEPROM.h"

#include <ModbusMaster.h> // là giao thức truyền thông kết nói RS485 để điều khiển PLC
#define IDSL1 1  
#define IDSL2 2  
#define IDSL3 3  
#define IDSL4 4  
#define DC D7    
uint16_t frequency1 = 0;   
uint16_t frequency2 = 0;
uint16_t frequency3 = 0;
uint16_t frequency4 = 0;
ModbusMaster node1;
ModbusMaster node2;
ModbusMaster node3;
ModbusMaster node4;
void preTransmission(){
  digitalWrite(DC, 1);
}
void postTransmission(){
  digitalWrite(DC, 0);
}


#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

const char* host = "esp8266-webupdate";
const char* updateUsername = "admin";
const char* updatePassword = "admin";
ESP8266HTTPUpdateServer httpUpdater;

#include <Wire.h>
#include "RTClib.h" // thư viện thời gian thực
RTC_DS3231 rtc;
uint8_t daysOfTheWeek[7] = {1,2,3,4,5,6,7}; // khai báo các ngày trong tuần
#include <Eeprom24Cxx.h> //thư viện EROOM
static Eeprom24C eeprom(32,0x57); 
 
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // thư viện Oled
#include <Fonts/FreeSerif9pt7b.h>
Adafruit_SSD1306 display(128, 32, &Wire, -1);

WidgetLED led0(V0);
BlynkTimer timer;

ESP8266WebServer webServer(80);
const int Button_Mode = D5;  // button 
const int Switch = D6;  // button
int screenplay = 0; // đặt ở trạng thái thấp bằng 0     
int modedisplay = 0;
 int x=10;                

 
uint8_t tnowHour,tnowMinute,tweek;


char* ssid_ap = "ESP8266";
char* pass_ap = "00000000";
IPAddress ip_ap(192,168,1,1);
IPAddress gateway_ap(192,168,1,1);
IPAddress subnet_ap(255,255,255,0);

String ssid;
String pass;
String auth;


void setup() {
        Serial.begin(9600);   
        EEPROM.begin(512);   
        #ifndef ESP8266
        while (!Serial); // for Leonardo/Micro/Zero
        #endif

      rtc.begin();
      MDNS.begin(host);
      httpUpdater.setup(&webServer, updateUsername, updatePassword);
      webServer.begin();
      MDNS.addService("http", "tcp", 80);
      Serial.printf("HTTPUpdateServer ready! Open http://%s.local/update in your browser\n", host);
      pinMode(Button_Mode, I NPUT); // nhỏ vào 
      pinMode(Switch, INPUT); // ngỏ vào     
      pcf8574.pinMode(P0, OUTPUT); // ngõ ra thiết bị1
      pcf8574.pinMode(P1, OUTPUT); // ngõ ra thiết bị2
      pcf8574.pinMode(P2, OUTPUT); // ngõ ra thiết bị3
      pcf8574.pinMode(P3, OUTPUT); // ngõ ra thiết bị4
      pcf8574.digitalWrite(P0, HIGH);// đặt thiết bị trạng thái cao
      pcf8574.digitalWrite(P1, HIGH);
      pcf8574.digitalWrite(P2, HIGH);
      pcf8574.digitalWrite(P3, HIGH);

  pinMode(DC, OUTPUT); /// đặt DC là ngõ ra
  digitalWrite(DC, 0); // trạng thái thấp

  node1.begin(1, Serial);
  node1.preTransmission(preTransmission);
  node1.postTransmission(postTransmission);
  node2.begin(2, Serial);
  node2.preTransmission(preTransmission);
  node2.postTransmission(postTransmission);
  node3.begin(3, Serial);
  node3.preTransmission(preTransmission);
  node3.postTransmission(postTransmission);
  node4.begin(4, Serial);
  node4.preTransmission(preTransmission);
  node4.postTransmission(postTransmission);
 
        if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  
        Serial.println("SSD1306 allocation failed");
        // for(;;);
        }
        delay(2000);
        display.setFont(&FreeSerif9pt7b);
        display.clearDisplay();  
        display.setTextColor(WHITE);    
        delay(10);
        timer.setInterval(1000L, clockDisplay); // hàm con
        timer.setInterval(100L, TimerA);
        timer.setInterval(100L, TimerB);
        timer.setInterval(100L, TimerC);
        timer.setInterval(100L, TimerD);
}
void loop() {
    if (digitalRead(Switch) == LOW){ // nếu trạng thái nút nhấn Switch ở trạng thái thấp thì
        screenplay = 1;
        display.clearDisplay(); 
        display.setTextSize(1);       
        display.setCursor(0,15);             
        display.println("OFFLINE");
        display.display();
    }
    else { screenplay = 0;}
// khỏi động 
    webServer.handleClient();
    MDNS.update(); // khỏi động cập nhật MDNS
    DateTime now = rtc.now();
    tnowHour = now.hour();
    tnowMinute =now.minute();
    tweek = now.dayOfTheWeek();

    while(x==10){
    if(read_EEPROM()){
        if(checkConnection()){
            Blynk.begin(auth.c_str(),ssid.c_str(),pass.c_str());
            x=0;
            } else {x=0;}
        } else {x=0;}
    }
    Blynk.run();
    timer.run();
    Checkbutton();   
    while (x==1){ 
      WiFi.disconnect();
      delay(100);
      Serial.println("vào chế độ cài");
      WiFi.mode(WIFI_AP);
      WiFi.softAPConfig(ip_ap, gateway_ap, subnet_ap);
      WiFi.softAP(ssid_ap,pass_ap,1,false);
      Serial.println("Soft Access Point mode!");
      Serial.print("Please connect to ");
      Serial.println(ssid_ap);
      Serial.print("Web Server IP Address: ");
      Serial.println(ip_ap);
      startWebServer();
      x=0;
    }
}

void clockDisplay(){
  if (led0.getValue()) {led0.off();} else {led0.on();}
  DateTime now = rtc.now();
  char bufTime[] = "00:00"; // khai báo mảng giờ phút
  char bufDate[] = "00/00/0000"; // khái báo mảng ngày tháng năm
  sprintf(bufTime,"%02i:%02i",now.hour(),now.minute());
  sprintf(bufDate,"%02i/%02i/%04i",now.day(),now.month(),now.year());
if (screenplay == 0){
      switch (int modedisplay) {
      case 0:
              display.clearDisplay(); 
              display.setTextSize(1);       
              display.setCursor(0,15);             
              //display.println(bufDate);
              display.println(WiFi.localIP());
              display.setTextSize(1);
              display.setCursor(40,30);             
              display.println(bufTime);
              display.display();
      break;
      case 1:
              display.clearDisplay(); 
              display.setTextSize(1);       
              display.setCursor(0,15);             
              display.println(ssid_ap);
              display.setTextSize(1);       
              display.setCursor(0,30);             
              display.println(ip_ap);
              display.display();
      break;
  }
 } 
}
