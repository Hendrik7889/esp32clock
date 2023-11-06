/**
  @param ssid is your WIFI name
  @param password is your wifi password
  */
extern const char* ssid = "Wlan";
extern const char* password = "Password";

/**
  Option for debugging
  @param debug = true if you wan to print to the Serial
  else no output
  */
extern bool debug = true;

/**
  @param timeZoneString contains a String that specifies the time with repect to daylight savings
  look your time up here: https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv
  */

extern const char* timeZoneString = "CET-1CEST,M3.5.0,M10.5.0/3";

/**
  If you want to change ports you can do that manualy in the ino file
  */