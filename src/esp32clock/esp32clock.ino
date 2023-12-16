#include <WiFi.h>
#include "time.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "config.h"

int zMinutes=0;
int zHours=12;
struct tm timeinfo;

void setup(){
  pinMode(IT, OUTPUT);
  pinMode(IS, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(ONE, OUTPUT);
  pinMode(TWO, OUTPUT);
  pinMode(THREE, OUTPUT);
  pinMode(FOUR, OUTPUT);
  pinMode(FIVE, OUTPUT);
  pinMode(SIX, OUTPUT);
  pinMode(SEVEN, OUTPUT);
  pinMode(EIGHT, OUTPUT);
  pinMode(NINE, OUTPUT);
  pinMode(TEN, OUTPUT);
  pinMode(ELEVEN, OUTPUT);
  pinMode(TWELVE, OUTPUT);
  pinMode(FIVE2, OUTPUT);
  pinMode(TEN2, OUTPUT);
  pinMode(QUARTER2, OUTPUT);
  pinMode(TWENTY2, OUTPUT);
  pinMode(HALF2, OUTPUT);
  pinMode(TO, OUTPUT);
  pinMode(PAST, OUTPUT);
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

  digitalWrite(IT, HIGH); //always on this will be "IT"
  digitalWrite(IS, HIGH); //always on this will be "IS"
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
    case 1:   digitalWrite(ONE,HIGH); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 2:   digitalWrite(ONE, LOW); digitalWrite(TWO,HIGH); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 3:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE,HIGH); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 4:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR,HIGH); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 5:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE,HIGH); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 6:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX,HIGH); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 7:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN,HIGH); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 8:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT,HIGH); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 9:   digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE,HIGH); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 10:  digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN,HIGH); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
    case 11:  digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN,HIGH); digitalWrite(TWELVE, LOW); break;
    case 12:  digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE,HIGH); break;
    default:  digitalWrite(ONE, LOW); digitalWrite(TWO, LOW); digitalWrite(THREE, LOW); digitalWrite(FOUR, LOW); digitalWrite(FIVE, LOW); digitalWrite(SIX, LOW); digitalWrite(SEVEN, LOW); digitalWrite(EIGHT, LOW); digitalWrite(NINE, LOW); digitalWrite(TEN, LOW); digitalWrite(ELEVEN, LOW); digitalWrite(TWELVE, LOW); break;
  }

  switch(zMinutes){   //display to past and half
    case 0 ... 4:     digitalWrite(TO, LOW);  digitalWrite(PAST, LOW);  digitalWrite(CLOCK,HIGH); break; //display "O'CLOCK"
    case 5 ... 29:    digitalWrite(TO, LOW);  digitalWrite(PAST,HIGH);  digitalWrite(CLOCK, LOW); break; //dispaly is past 
    case 30 ... 39:   digitalWrite(TO, LOW);  digitalWrite(PAST, LOW);  digitalWrite(CLOCK, LOW); break; //display nothing 
    case 40 ... 60:   digitalWrite(TO,HIGH);  digitalWrite(PAST, LOW);  digitalWrite(CLOCK, LOW); break; //display is to
    default:          digitalWrite(TO, LOW);  digitalWrite(PAST, LOW);  digitalWrite(CLOCK, LOW); break; //display nothing  
  }

  switch(zMinutes){ //displays time until or to next hour
    case 0 ... 4:     digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
    case 5 ... 9:     digitalWrite(FIVE2,HIGH);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
    case 10 ... 14:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2,HIGH);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
    case 15 ... 19:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2,HIGH);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
    case 20 ... 29:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2,HIGH);  digitalWrite(HALF2, LOW); break;
    case 30 ... 39:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2,HIGH); break;
    case 40 ... 44:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2,HIGH);  digitalWrite(HALF2, LOW); break;
    case 45 ... 49:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2,HIGH);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
    case 50 ... 54:   digitalWrite(FIVE2, LOW);  digitalWrite(TEN2,HIGH);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
    default:          digitalWrite(FIVE2, LOW);  digitalWrite(TEN2, LOW);  digitalWrite(QUARTER2, LOW);  digitalWrite(TWENTY2, LOW);  digitalWrite(HALF2, LOW); break;
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