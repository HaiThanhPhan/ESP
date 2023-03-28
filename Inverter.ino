BLYNK_WRITE(V5)  {
  frequency1 = param.asInt(); 
  node1.writeSingleRegister(0x2001, frequency1);

}
BLYNK_WRITE(V6)  {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
     node1.writeSingleRegister(0x2000, 1);
   Blynk.virtualWrite(V7, LOW); 
      Blynk.virtualWrite(V8, LOW); 
  }  
}
BLYNK_WRITE(V7)  {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
  node1.writeSingleRegister(0x2000, 2);
  Blynk.virtualWrite(V6, LOW); 
     Blynk.virtualWrite(V8, LOW); 
  }  
}
BLYNK_WRITE(V8)  {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
    node1.writeSingleRegister(0x2000, 5);
    Blynk.virtualWrite(V6, LOW); 
    Blynk.virtualWrite(V7, LOW); 
  }  
}
BLYNK_WRITE(V9)  {
  frequency2 = param.asInt(); 
  node2.writeSingleRegister(0x2001, frequency2);
}
BLYNK_WRITE(V10) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
     node2.writeSingleRegister(0x2000, 1);
   Blynk.virtualWrite(V11, LOW); 
      Blynk.virtualWrite(V12, LOW); 
  }  
}
BLYNK_WRITE(V11) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
  node2.writeSingleRegister(0x2000, 2);
  Blynk.virtualWrite(V10, LOW); 
     Blynk.virtualWrite(V12, LOW); 
  }  
}
BLYNK_WRITE(V12) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
    node2.writeSingleRegister(0x2000, 5);
    Blynk.virtualWrite(V10, LOW); 
    Blynk.virtualWrite(V11, LOW); 
  }  
}
BLYNK_WRITE(V13) {
  frequency3 = param.asInt(); 
  node3.writeSingleRegister(0x2001, frequency3);
}
BLYNK_WRITE(V14) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
     node3.writeSingleRegister(0x2000, 1);
   Blynk.virtualWrite(V15, LOW); 
      Blynk.virtualWrite(V16, LOW); 
  }  
}
BLYNK_WRITE(V15) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
  node3.writeSingleRegister(0x2000, 2);
  Blynk.virtualWrite(V14, LOW); 
     Blynk.virtualWrite(V16, LOW); 
  }  
}
BLYNK_WRITE(V16) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
    node3.writeSingleRegister(0x2000, 5);
    //Serial.println("BIEN TAN 2: DUNG");
    Blynk.virtualWrite(V14, LOW); 
    Blynk.virtualWrite(V15, LOW); 
  }  
}
BLYNK_WRITE(V17) {
  frequency4 = param.asInt(); 
  node4.writeSingleRegister(0x2001, frequency4);
}
BLYNK_WRITE(V18) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
     node4.writeSingleRegister(0x2000, 1);
   Blynk.virtualWrite(V19, LOW); 
    Blynk.virtualWrite(V20, LOW);
  }  
}
BLYNK_WRITE(V19) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
  node4.writeSingleRegister(0x2000, 2);
  Blynk.virtualWrite(V18, LOW); 
   Blynk.virtualWrite(V20, LOW);
  }  
}
BLYNK_WRITE(V20) {
  uint8_t pinValue = param.asInt();
  if (pinValue == 1)
  {
    node4.writeSingleRegister(0x2000, 5);
    Blynk.virtualWrite(V18, LOW); 
    Blynk.virtualWrite(V19, LOW); 
  }  
}
