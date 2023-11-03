/**
  add seconds offset from utc 
  +1 hour eqaul to +3600 
  -1 hour equal to -3600
  */
extern int timeOffset = 3600; 

/**
  ssid is your WIFI name
  password is your wifi password
  */
extern const char* ssid = "ssid";
extern const char* password = "password";

/**
  Option for debugging
  @param debug = true if you wan to print to the Serial 
  else no output
  */
extern bool debug = false;

/**
  If you want to change ports you can do that manualy in the ino file
  */