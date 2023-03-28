
WidgetLED led1(V21);// led trạng thái
WidgetLED led2(V27);
WidgetLED led3(V33);
WidgetLED led4(V39);
int Relay1State = HIGH; // trạng thái đặt ở mức cao
int Relay2State = HIGH;
int Relay3State = HIGH;
int Relay4State = HIGH;
void Relay1on(){
pcf8574.digitalWrite(P0, LOW);
  Blynk.virtualWrite(V1,LOW);
  led1.on();
}
void Relay1off(){
pcf8574.digitalWrite(P0,HIGH);
  Blynk.virtualWrite(V1,HIGH);
  led1.off();
}
void Relay2on(){
pcf8574.digitalWrite(P1,LOW);
  Blynk.virtualWrite(V7,LOW);
  led2.on();
}
void Relay2off(){
pcf8574.digitalWrite(P1,HIGH);
  Blynk.virtualWrite(V7,HIGH);
  led2.off();
}
void Relay3on(){
pcf8574.digitalWrite(P2,LOW);
  Blynk.virtualWrite(V13,LOW);
  led3.on();
}
void Relay3off(){
pcf8574.digitalWrite(P2,HIGH);
  Blynk.virtualWrite(V13,HIGH);
  led3.off();
}
void Relay4on(){
pcf8574.digitalWrite(P3,LOW);
  Blynk.virtualWrite(V19,LOW);
  led4.on();
}
void Relay4off(){
pcf8574.digitalWrite(P3,HIGH);
  Blynk.virtualWrite(V19,HIGH);
  led4.off();
}

BLYNK_WRITE(V1) {
  Relay1State = param.asInt();
  pcf8574.digitalWrite(P0, Relay1State);
   if (Relay1State == HIGH) { led1.off();} else {led1.on();}
}
BLYNK_WRITE(V2) {
  Relay2State = param.asInt();
  pcf8574.digitalWrite(P1, Relay2State);
  if (Relay2State == HIGH) {led2.off();} else {led2.on();}
}
BLYNK_WRITE(V3) {
 Relay3State = param.asInt();
 pcf8574.digitalWrite(P2, Relay3State);
 if (Relay3State == HIGH) {led3.off();} else {led3.on();}
}
BLYNK_WRITE(V4) {
  Relay4State = param.asInt();
  pcf8574.digitalWrite(P3, Relay4State);
  if (Relay4State == HIGH) {led4.off();} else {led4.on();}
}
BLYNK_WRITE(V22) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(4+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(4+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(1,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(2, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(3,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(4, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V23) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(15+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(15+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(12,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(13, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(11+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(14,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(15, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V24) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(26+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(26+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(23,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(24, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(22+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(25,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(26, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V25) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(37+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(37+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(34,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(35, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(33+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(36,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(37, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V26) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(48+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(48+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(45,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(46, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(44+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(47,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(48, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V28) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(59+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(59+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(56,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(57, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(55+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(58,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(59, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V29) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(70+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(70+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(67,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(68, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(66+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(69,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(70, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V30) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(81+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(81+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(78,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(79, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(77+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(80,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(81, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V31) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(92+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(92+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(89,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(90, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(88+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(91,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(92, t.getStopMinute());
    delay(10);
  }
  else  {  }
}
BLYNK_WRITE(V32) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(103+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(103+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(100,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(101, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(99+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(102,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(103, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V34) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(114+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(114+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(111,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(112, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(110+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(113,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(114, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V35) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(125+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(125+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(122,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(123, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(121+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(124,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(125, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V36) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(136+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(136+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(133,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(134, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(132+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(135,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(136, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V37) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(147+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(147+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(144,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(145, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(143+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(146,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(147, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V38) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(158+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(158+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(155,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(156, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(154+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(157,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(158, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V40) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(169+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(169+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(166,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(167, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(165+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(168,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(169, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V41) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(180+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(180+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(177,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(178, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(176+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(179,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(180, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V42) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(191+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(191+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(188,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(189, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(187+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(190,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(191, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V43) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(202+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(202+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(199,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(200, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(198+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(201,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(202, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
BLYNK_WRITE(V44) {
  TimeInputParam t(param);
    for (int i = 1; i <= 7; i++) {
    if (t.isWeekdaySelected(i)) {
      eeprom.write_1_byte(213+i, i);
      delay(10);
    } else {
      eeprom.write_1_byte(213+i, 0);
      delay(10);
    }
  }
  if (t.hasStartTime())
  {
    eeprom.write_1_byte(210,t.getStartHour());
    delay(10);
    eeprom.write_1_byte(211, t.getStartMinute());
    delay(10);
  }
  else{
     for (int i = 1; i <= 11; i++) {
      eeprom.write_1_byte(209+i, 0);
      delay(10);
    }
  }
  if (t.hasStopTime())
  {
     eeprom.write_1_byte(212,t.getStopHour());
     delay(10);
    eeprom.write_1_byte(213, t.getStopMinute());
    delay(10);
 
  }
  else  {  }
}
