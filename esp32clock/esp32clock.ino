#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "config.h"
// Replace with your network credentials

const char* ssid = "YOUR WIFI NAME";
const char* password = "YOUR WIFI PASSWORD";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup() {
  initWiFi();
  timeClient.begin();
  timeClient.setTimeOffset(7200); //utc 
                                  //+3600 if +1hour -3600 if -1hour 

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(26, OUTPUT);
  }

void loop() {
  while(!timeClient.update()) {
    timeClient.forceUpdate();
  }

  int zMinutes = timeClient.getMinutes();
  int zHours = timeClient.getHours()%12; //only 12 hour clocks are implemented because of canvas size
  
  if(zMinutes>=45){
    zHours=zHours+1;//because then time is calculated in to 
  }

  if(zHours==0){  //we have no hour 0 only 12
    zHours=12;
  }

  digitalWrite(1, HIGH); //allways on this will be "IT"
  digitalWrite(2, HIGH); //allways on this will be "IS"
  digitalWrite(3, HIGH); //allways on this will be "O'CLOCK"
  
 
  switch(zHours){
    case 1:  digitalWrite(4 , HIGH);  digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);digitalWrite(10, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 2:  digitalWrite(5 , HIGH);  digitalWrite(4, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);digitalWrite(10, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 3:  digitalWrite(6 , HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);digitalWrite(10, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 4:  digitalWrite(7 , HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);digitalWrite(10, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 5:  digitalWrite(8 , HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(9, LOW);digitalWrite(10, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 6:  digitalWrite(9 , HIGH);digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(10, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 7:  digitalWrite(10, HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);
                                      digitalWrite(11, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 8:  digitalWrite(11, HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);
                                      digitalWrite(10, LOW);digitalWrite(12, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 9:  digitalWrite(12, HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);
                                      digitalWrite(10, LOW);digitalWrite(11, LOW);digitalWrite(13, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 10: digitalWrite(13, HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);
                                      digitalWrite(10, LOW);digitalWrite(11, LOW);digitalWrite(12, LOW); digitalWrite(14, LOW);digitalWrite(15, LOW);
                                      break;
    case 11: digitalWrite(14, HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);
                                      digitalWrite(10, LOW);digitalWrite(11, LOW);digitalWrite(12, LOW); digitalWrite(13, LOW);digitalWrite(15, LOW);
                                      break;
    case 12: digitalWrite(15, HIGH);  digitalWrite(4, LOW);digitalWrite(5, LOW);digitalWrite(6, LOW);digitalWrite(7, LOW);digitalWrite(8, LOW);digitalWrite(9, LOW);
                                      digitalWrite(10, LOW);digitalWrite(11, LOW);digitalWrite(12, LOW); digitalWrite(13, LOW);digitalWrite(14, LOW);
                                      break;
  }

  switch(zMinutes){
    case 0-4:     digitalWrite(21,LOW); digitalWrite(26,LOW); break; //display nothing 
    case 5-29:    digitalWrite(26,HIGH);digitalWrite(21,LOW); break; //dispaly is past 
    case 30-39:   digitalWrite(21,LOW); digitalWrite(26,LOW); break; //display nothing 
    case 40-60:   digitalWrite(21,HIGH);digitalWrite(26,LOW); break; //display is to
    default:      digitalWrite(21,LOW); digitalWrite(26,LOW); break; //display nothing  
  }

    if(0<=zMinutes<=4)  { digitalWrite(16,LOW); digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);} //display nothing
    if(5<=zMinutes<=9)  { digitalWrite(16,HIGH);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);}  //display 5
    if(10<=zMinutes<=14){ digitalWrite(17,HIGH);digitalWrite(16,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);}  //display 10
    if(15<=zMinutes<=19){ digitalWrite(18,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);}  //display 15
    if(20<=zMinutes<=29){ digitalWrite(19,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(20,LOW);}  //display 20
    if(30<=zMinutes<=39){ digitalWrite(20,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);}  //display 30
    if(40<=zMinutes<=44){ digitalWrite(19,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(20,LOW);}  //display 20
    if(45<=zMinutes<=49){ digitalWrite(18,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);}  //diaplay 15
    if(50<=zMinutes<=54){ digitalWrite(17,HIGH);digitalWrite(16,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);}  //display 10
    if(55<=zMinutes<=60){ digitalWrite(16,LOW); digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW);}  //display 5


  
}


void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
  }
  Serial.println(WiFi.localIP());
}

