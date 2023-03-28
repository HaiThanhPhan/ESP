void TimerA(){
 for (int i = 1; i <= 7; i++){
  byte data = eeprom.read_1_byte(4+i);
  if (tweek == data){
    timerA1();
  }
 }
  for (int i = 1; i <= 7; i++){
  byte data1 = eeprom.read_1_byte(15+i);
  if (tweek == data1){
    timerA2();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data2 = eeprom.read_1_byte(26+i);
  if (tweek == data2){
    timerA3();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data3 = eeprom.read_1_byte(37+i);
  if (tweek == data3){
    timerA4();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data4 = eeprom.read_1_byte(48+i);
  if (tweek == data4){
    timerA5();
  }
 }
}
void timerA1(){
  uint8_t TonA1h,TonA1m,ToffA1h,ToffA1m;
   TonA1h = eeprom.read_1_byte(1);
   TonA1m = eeprom.read_1_byte(2);
   ToffA1h = eeprom.read_1_byte(3);
   ToffA1m = eeprom.read_1_byte(4);
  if(( TonA1h == tnowHour ) && (TonA1m == tnowMinute)){
    Relay1on();
  }
  if((ToffA1h == tnowHour ) && (ToffA1m == tnowMinute)){
    Relay1off();
  }
}
void timerA2(){
  uint8_t TonA2h,TonA2m,ToffA2h,ToffA2m;
   TonA2h = eeprom.read_1_byte(12);
   TonA2m = eeprom.read_1_byte(13);
   ToffA2h = eeprom.read_1_byte(14);
   ToffA2m = eeprom.read_1_byte(15);
  if(( TonA2h == tnowHour ) && (TonA2m == tnowMinute)){
    Relay1on();
  }
  if((ToffA2h == tnowHour ) && (ToffA2m == tnowMinute)){
    Relay1off();
  }
}
void timerA3(){
  uint8_t TonA3h,TonA3m,ToffA3h,ToffA3m;
   TonA3h = eeprom.read_1_byte(23);
   TonA3m = eeprom.read_1_byte(24);
   ToffA3h = eeprom.read_1_byte(25);
   ToffA3m = eeprom.read_1_byte(26);
  if(( TonA3h == tnowHour ) && (TonA3m == tnowMinute)){
    Relay1on();
  }
  if((ToffA3h == tnowHour ) && (ToffA3m == tnowMinute)){
    Relay1off();
  }
}
void timerA4(){
  uint8_t TonA4h,TonA4m,ToffA4h,ToffA4m;
   TonA4h = eeprom.read_1_byte(34);
   TonA4m = eeprom.read_1_byte(35);
   ToffA4h = eeprom.read_1_byte(36);
   ToffA4m = eeprom.read_1_byte(37);
  if(( TonA4h == tnowHour ) && (TonA4m == tnowMinute)){
    Relay1on();
  }
  if((ToffA4h == tnowHour ) && (ToffA4m == tnowMinute)){
    Relay1off();
  }
}
void timerA5(){
  uint8_t TonA5h,TonA5m,ToffA5h,ToffA5m;
   TonA5h = eeprom.read_1_byte(45);
   TonA5m = eeprom.read_1_byte(46);
   ToffA5h = eeprom.read_1_byte(47);
   ToffA5m = eeprom.read_1_byte(48);
  if(( TonA5h == tnowHour ) && (TonA5m == tnowMinute)){
    Relay1on();
  }
  if((ToffA5h == tnowHour ) && (ToffA5m == tnowMinute)){
    Relay1off();
  }
}
void timerB1(){
  uint8_t TonB1h,TonB1m,ToffB1h,ToffB1m;
   TonB1h = eeprom.read_1_byte(56);
   TonB1m = eeprom.read_1_byte(57);
   ToffB1h = eeprom.read_1_byte(58);
   ToffB1m = eeprom.read_1_byte(59);
  if(( TonB1h == tnowHour ) && (TonB1m == tnowMinute)){
    Relay2on();
  }
  if((ToffB1h == tnowHour ) && (ToffB1m == tnowMinute)){
    Relay2off();
  }
}
void timerB2(){
  uint8_t TonB2h,TonB2m,ToffB2h,ToffB2m;
   TonB2h =  eeprom.read_1_byte(67);
   TonB2m =  eeprom.read_1_byte(68);
   ToffB2h = eeprom.read_1_byte(69);
   ToffB2m = eeprom.read_1_byte(70);
  if(( TonB2h == tnowHour ) && ( TonB2m == tnowMinute)){
    Relay2on();
  }
  if((ToffB2h == tnowHour ) && (ToffB2m == tnowMinute)){
    Relay2off();
  }
}
void timerB3(){
  uint8_t TonB3h,TonB3m,ToffB3h,ToffB3m;
    TonB3h = eeprom.read_1_byte(78);
    TonB3m = eeprom.read_1_byte(79);
   ToffB3h = eeprom.read_1_byte(80);
   ToffB3m = eeprom.read_1_byte(81);
  if(( TonB3h == tnowHour ) && ( TonB3m == tnowMinute)){
    Relay2on();
  }
  if((ToffB3h == tnowHour ) && (ToffB3m == tnowMinute)){
    Relay2off();
  }
}
void timerB4(){
  uint8_t TonB4h,TonB4m,ToffB4h,ToffB4m;
    TonB4h = eeprom.read_1_byte(89);
    TonB4m = eeprom.read_1_byte(90);
   ToffB4h = eeprom.read_1_byte(91);
   ToffB4m = eeprom.read_1_byte(91);
  if(( TonB4h == tnowHour ) && ( TonB4m == tnowMinute)){
    Relay2on();
  }
  if((ToffB4h == tnowHour ) && (ToffB4m == tnowMinute)){
    Relay2off();
  }
}
void timerB5(){
  uint8_t TonB5h,TonB5m,ToffB5h,ToffB5m;
    TonB5h = eeprom.read_1_byte(100);
    TonB5m = eeprom.read_1_byte(101);
   ToffB5h = eeprom.read_1_byte(102);
   ToffB5m = eeprom.read_1_byte(103);
  if(( TonB5h == tnowHour ) && ( TonB5m == tnowMinute)){
    Relay2on();
  }
  if((ToffB5h == tnowHour ) && (ToffB5m == tnowMinute)){
    Relay2off();
  }
}
void TimerB(){
 for (int i = 1; i <= 7; i++){
  byte data = eeprom.read_1_byte(59+i);
  if (tweek == data){
    timerB1();
  }
 }
  for (int i = 1; i <= 7; i++){
  byte data1 = eeprom.read_1_byte(70+i);
  if (tweek == data1){
    timerB2();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data2 = eeprom.read_1_byte(81+i);
  if (tweek == data2){
    timerB3();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data3 = eeprom.read_1_byte(92+i);
  if (tweek == data3){
    timerB4();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data4 = eeprom.read_1_byte(103+i);
  if (tweek == data4){
    timerB5();
  }
 }
}
void timerC1(){
  uint8_t TonC1h,TonC1m,ToffC1h,ToffC1m;
    TonC1h = eeprom.read_1_byte(111);
    TonC1m = eeprom.read_1_byte(112);
   ToffC1h = eeprom.read_1_byte(113);
   ToffC1m = eeprom.read_1_byte(114);
  if(( TonC1h == tnowHour ) && ( TonC1m == tnowMinute)){
    Relay3on();
  }
  if((ToffC1h == tnowHour ) && (ToffC1m == tnowMinute)){
    Relay3off();
  }
}
void timerC2(){
  uint8_t TonC2h,TonC2m,ToffC2h,ToffC2m;
    TonC2h = eeprom.read_1_byte(122);
    TonC2m = eeprom.read_1_byte(123);
   ToffC2h = eeprom.read_1_byte(124);
   ToffC2m = eeprom.read_1_byte(125);
  if(( TonC2h == tnowHour ) && ( TonC2m == tnowMinute)){
    Relay3on();
  }
  if((ToffC2h == tnowHour ) && (ToffC2m == tnowMinute)){
    Relay3off();
  }
}
void timerC3(){
  uint8_t TonC3h,TonC3m,ToffC3h,ToffC3m;
    TonC3h = eeprom.read_1_byte(133);
    TonC3m = eeprom.read_1_byte(134);
   ToffC3h = eeprom.read_1_byte(135);
   ToffC3m = eeprom.read_1_byte(136);
  if(( TonC3h == tnowHour ) && ( TonC3m == tnowMinute)){
    Relay3on();
  }
  if((ToffC3h == tnowHour ) && (ToffC3m == tnowMinute)){
    Relay3off();
  }
}
void timerC4(){
  uint8_t TonC4h,TonC4m,ToffC4h,ToffC4m;
    TonC4h = eeprom.read_1_byte(144);
    TonC4m = eeprom.read_1_byte(145);
   ToffC4h = eeprom.read_1_byte(146);
   ToffC4m = eeprom.read_1_byte(147);
  if(( TonC4h == tnowHour ) && ( TonC4m == tnowMinute)){
    Relay3on();
  }
  if((ToffC4h == tnowHour ) && (ToffC4m == tnowMinute)){
    Relay3off();
  }
}
void timerC5(){
  uint8_t TonC5h,TonC5m,ToffC5h,ToffC5m;
    TonC5h = eeprom.read_1_byte(155);
    TonC5m = eeprom.read_1_byte(156);
   ToffC5h = eeprom.read_1_byte(157);
   ToffC5m = eeprom.read_1_byte(158);
  if(( TonC5h == tnowHour ) && ( TonC5m == tnowMinute)){
    Relay3on();
  }
  if((ToffC5h == tnowHour ) && (ToffC5m == tnowMinute)){
    Relay3off();
  }
}
void TimerC(){
 for (int i = 1; i <= 7; i++){
  byte data = eeprom.read_1_byte(114+i);
  if (tweek == data){
    timerC1();
  }
 }
  for (int i = 1; i <= 7; i++){
  byte data1 = eeprom.read_1_byte(125+i);
  if (tweek == data1){
    timerC2();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data2 = eeprom.read_1_byte(136+i);
  if (tweek == data2){
    timerC3();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data3 = eeprom.read_1_byte(147+i);
  if (tweek == data3){
    timerC4();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data4 = eeprom.read_1_byte(158+i);
  if (tweek == data4){
    timerC5();
  }
 }
}
void timerD1(){
  uint8_t TonD1h,TonD1m,ToffD1h,ToffD1m;
    TonD1h = eeprom.read_1_byte(166);
    TonD1m = eeprom.read_1_byte(167);
   ToffD1h = eeprom.read_1_byte(168);
   ToffD1m = eeprom.read_1_byte(169);
  if(( TonD1h == tnowHour ) && ( TonD1m == tnowMinute)){
    Relay4on();
  }
  if((ToffD1h == tnowHour ) && (ToffD1m == tnowMinute)){
    Relay4off();
  }
}
void timerD2(){
  uint8_t TonD2h,TonD2m,ToffD2h,ToffD2m;
    TonD2h = eeprom.read_1_byte(177);
    TonD2m = eeprom.read_1_byte(178);
   ToffD2h = eeprom.read_1_byte(179);
   ToffD2m = eeprom.read_1_byte(180);
  if(( TonD2h == tnowHour ) && ( TonD2m == tnowMinute)){
    Relay4on();
  }
  if((ToffD2h == tnowHour ) && (ToffD2m == tnowMinute)){
    Relay4off();
  }
}
void timerD3(){
  uint8_t TonD3h,TonD3m,ToffD3h,ToffD3m;
    TonD3h = eeprom.read_1_byte(188);
    TonD3m = eeprom.read_1_byte(189);
   ToffD3h = eeprom.read_1_byte(190);
   ToffD3m = eeprom.read_1_byte(191);
  if(( TonD3h == tnowHour ) && ( TonD3m == tnowMinute)){
    Relay4on();
  }
  if((ToffD3h == tnowHour ) && (ToffD3m == tnowMinute)){
    Relay4off();
  }
}
void timerD4(){
  uint8_t TonD4h,TonD4m,ToffD4h,ToffD4m;
    TonD4h = eeprom.read_1_byte(199);
    TonD4m = eeprom.read_1_byte(200);
   ToffD4h = eeprom.read_1_byte(201);
   ToffD4m = eeprom.read_1_byte(202);
  if(( TonD4h == tnowHour ) && ( TonD4m == tnowMinute)){
    Relay4on();
  }
  if((ToffD4h == tnowHour ) && (ToffD4m == tnowMinute)){
    Relay4off();
  }
}
void timerD5(){
  uint8_t TonD5h,TonD5m,ToffD5h,ToffD5m;
    TonD5h = eeprom.read_1_byte(210);
    TonD5m = eeprom.read_1_byte(211);
   ToffD5h = eeprom.read_1_byte(212);
   ToffD5m = eeprom.read_1_byte(213);
  if(( TonD5h == tnowHour ) && ( TonD5m == tnowMinute)){
    Relay4on();
  }
  if((ToffD5h == tnowHour ) && (ToffD5m == tnowMinute)){
    Relay4off();
  }
}
void TimerD(){
 for (int i = 1; i <= 7; i++){
  byte data = eeprom.read_1_byte(169+i);
  if (tweek == data){
    timerD1();
  }
 }
  for (int i = 1; i <= 7; i++){
  byte data1 = eeprom.read_1_byte(180+i);
  if (tweek == data1){
    timerD2();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data2 = eeprom.read_1_byte(191+i);
  if (tweek == data2){
    timerD3();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data3 = eeprom.read_1_byte(202+i);
  if (tweek == data3){
    timerD4();
  }
 }
   for (int i = 1; i <= 7; i++){
  byte data4 = eeprom.read_1_byte(213+i);
  if (tweek == data4){
    timerD5();
  }
 }
}
