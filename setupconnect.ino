
void startWebServer(){
  webServer.on("/",mainpage);
  webServer.on("/getIP",get_IP);
  webServer.on("/writeEEPROM",write_EEPROM);
  webServer.on("/restartESP",restart_ESP);
  webServer.on("/clearEEPROM",clear_EEPROM);
  webServer.begin();
  Serial.println("Web Server is started!");
}

void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}

void get_IP(){
  String s = WiFi.localIP().toString();
  webServer.send(200,"text/html", s);
}

boolean read_EEPROM(){
  Serial.println("Reading EEPROM...");
  if(EEPROM.read(0)!=0){
    ssid = "";
    pass = "";
    auth = "";
    for (int i=0; i<32; ++i){
      ssid += char(EEPROM.read(i));
    }
    Serial.print("SSID: ");
    Serial.println(ssid);
    for (int i=32; i<96; ++i){
      pass += char(EEPROM.read(i));
    }
    Serial.print("PASSWORD: ");
    Serial.println(pass);
    for (int i=96; i<128; ++i){
      auth += char(EEPROM.read(i));
    }
    Serial.print("AUTH: ");
    Serial.println(auth);
    ssid = ssid.c_str();
    pass = pass.c_str();
    auth = auth.c_str();
    return true;
  }else{
    Serial.println("Data wifi not found!");
    return false;
  }
}

void write_EEPROM(){
  ssid = webServer.arg("ssid");
  pass = webServer.arg("pass");
  auth = webServer.arg("auth");
  Serial.println("Clear EEPROM!");
  for (int i = 0; i < 128; ++i) {
    EEPROM.write(i, 0);           
    delay(10);
  }
  for (int i = 0; i < ssid.length(); ++i) {
    EEPROM.write(i, ssid[i]);
  }
  for (int i = 0; i < pass.length(); ++i) {
    EEPROM.write(32 + i, pass[i]);
  }
  for (int i = 0; i < auth.length(); ++i) {
    EEPROM.write(96 + i, auth[i]);
  }
  EEPROM.commit();
  Serial.println("Writed to EEPROM!");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("PASS: ");
  Serial.println(pass);
  Serial.print("AUTH: ");
  Serial.println(auth);
 

  WiFi.begin(ssid,pass);
  Serial.print("IP connection: ");
  Serial.println(WiFi.localIP());
  String s = "Wifi configuration saved!";
  webServer.send(200, "text/html", s);
}

void clear_EEPROM(){
  Serial.println("Clear EEPROM!");
  for (int i = 0; i < 512; ++i) {
    EEPROM.write(i, 0);           
    delay(10);
  }
  EEPROM.commit();
  String s = "Device has been reset!";
  webServer.send(200,"text/html", s);
}

void restart_ESP(){
  ESP.restart();
}

void Checkbutton(){
  int couter_Mode = 0;
        x=0;
    if (digitalRead(Button_Mode) == LOW)
    {
            long startTime = millis(); 
    while (digitalRead(Button_Mode) == LOW) 
        {
            Serial.println(millis() - startTime);
            couter_Mode = (millis() - startTime) / 1000;
            couter_Mode = couter_Mode / 1 % 10;
             display.clearDisplay(); 
             display.setTextSize(1);
             display.setCursor(110,15); 
            display.println(couter_Mode);
            display.display();
            if (couter_Mode >= 5)
            {
             x=1;
                 modedisplay=1;
            }
 
            yield();
        }
    }

}

boolean checkConnection() {
  Serial.println();
  Serial.print("Check connecting to ");
  Serial.println(ssid);
  WiFi.disconnect();
  delay(100);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pass);
  int count=0;
  while(count < 50)
  {
    if(WiFi.status() == WL_CONNECTED)
    {
      Serial.println();
      Serial.print("Connected to ");
      Serial.println(ssid);
      Serial.print("Web Server IP Address: ");
      Serial.println(WiFi.localIP());
      return true;
    }
    delay(200);
    Serial.print(".");
    count++;
  }
  Serial.println("Timed out.");
  return false;
}
