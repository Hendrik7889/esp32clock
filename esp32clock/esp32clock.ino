#include <WiFi.h>
#include "time.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "config.h"

int zMinutes=0;
int zHours=12;
struct tm timeinfo;

void setup(){
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
  pinMode(33, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid,password);
  //connect to wifi
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    print(".");
  }
  println("");
  println("Connected");

  initTime(timeZoneString);

  digitalWrite(1, HIGH); //always on this will be "IT"
  digitalWrite(2, HIGH); //always on this will be "IS"
  digitalWrite(3, HIGH); //always on this will be "O'CLOCK"
}

void loop() {
  //updates time
  if(!getLocalTime(&timeinfo)){
    println("Failed to obtain time");
    return;
  }
  printDate();

  zHours = timeinfo.tm_hour;
  zMinutes = timeinfo.tm_min;

  if(zMinutes>=45){       //because then time is calculated in *to*
    zHours=zHours+1;
  }

  if(zHours>=13){         // only hours until 12 allowed
    zHours=(zHours % 12);
  }

  if(zHours==0){          //we have no hour 0 only 12
    zHours=12;
  }
  print("Hours: ");
  println(zHours);
  print("Minutes: ");
  println(zMinutes);
  println("~~~");
  
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
    case 0 ... 4:     digitalWrite(21,LOW); digitalWrite(33,LOW); break; //display nothing 
    case 5 ... 29:    digitalWrite(33,HIGH);digitalWrite(21,LOW); break; //dispaly is past 
    case 30 ... 39:   digitalWrite(21,LOW); digitalWrite(33,LOW); break; //display nothing 
    case 40 ... 60:   digitalWrite(21,HIGH);digitalWrite(33,LOW); break; //display is to
    default:          digitalWrite(21,LOW); digitalWrite(33,LOW); break; //display nothing  
  }

  switch(zMinutes){
    case 0 ... 4:   digitalWrite(16,LOW); digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
    case 5 ... 9:   digitalWrite(16,HIGH);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
    case 10 ... 14: digitalWrite(17,HIGH);digitalWrite(16,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
    case 15 ... 19: digitalWrite(18,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
    case 20 ... 29: digitalWrite(19,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(20,LOW); break;
    case 30 ... 39: digitalWrite(20,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW); break;
    case 40 ... 44: digitalWrite(19,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(20,LOW); break;
    case 45 ... 49: digitalWrite(18,HIGH);digitalWrite(16,LOW);digitalWrite(17,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
    case 50 ... 54: digitalWrite(17,HIGH);digitalWrite(16,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
    default:        digitalWrite(16,LOW); digitalWrite(17,LOW);digitalWrite(18,LOW);digitalWrite(19,LOW);digitalWrite(20,LOW); break;
  }

  print("delay:");
  print((60-timeinfo.tm_sec+1));
  println("sec");
  delay((60-timeinfo.tm_sec+1)*1000);
}

/**
  initiates the time 
  @param timezone the String that specifies the timezone and the daylight savings
  look config.h
  */
void initTime(String timezone){
  println("Setting up time");
  configTime(0, 0, "pool.ntp.org");    // First connect to NTP server, with 0 TZ offset
  if(!getLocalTime(&timeinfo)){
    println("Failed to obtain time");
    return;
  }
  println("Got the time from NTP");
  // Now we can set the real timezone
  setenv("TZ",timezone.c_str(),1);  //  Now adjust the TZ.  Clock settings are adjusted to show the new local time
  tzset();
}

/**
  Function to controll the Output
  */
void printDate(){
  if(debug){
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S zone %Z %z ");
  }
}

void print(char arr[]){
  if(debug){
    Serial.print(arr);
  }
}

void print(int integer){
  if(debug){
    Serial.print(integer);
  }
}

void print(bool boolean){
  if(debug){
    Serial.print(boolean);
  }
}

void println(char arr[]){
  if(debug){
    Serial.println(arr);
  } 
}

void println(int integer){
  if(debug){
    Serial.println(integer);
  } 
}

void println(bool boolean){
  if(debug){
    Serial.println(boolean);
  }
}