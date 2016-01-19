#ifndef ESPWS_h
#define ESPWS_h
#include <Arduino.h>
#include <ESP8266WiFi.h>

class Espws
{
  public:
  	char Uptime();
  	char * FloatToChar(float charester);
  	String FreeMem();
  	String IpLocalStr();
  	char MacStr();
  	IPAddress StrToIp (String strIp);
    
  private:
    int _pin;

    long _secsUp;
	long _day=0;
	int _hour =0;
	int _minute=0;
	int _second=0;
	int _highMillis=0;
	int _rollover=0;
};

#endif