#include "espws.h"


char Espws::Uptime() {
//** Making Note of an expected _rollover *****//   

char uptimeStr;

if(millis()>=3000000000){ 
  _highMillis=1;
}
//** Making note of actual _rollover **//
if(millis()<=100000&&_highMillis==1){
  _rollover++;
  _highMillis=0;
}

_secsUp = millis()/1000;

_second = _secsUp%60;
_minute = (_secsUp/60)%60;
_hour = (_secsUp/(60*60))%24;
_day = (_rollover*50)+(_secsUp/(60*60*24));  //First portion takes care of a _rollover [around 50 days]

sprintf_P(&uptimeStr, (const char *)F("%dd %02d:%02d"), _day, _hour, _minute);

#ifdef SERIAL_PRINT
Serial.print(F("Uptime: "));  Serial.print(uptimeStr);  Serial.print(F(":"));  Serial.print(_second/10);  Serial.println(_second%10);
#endif

return uptimeStr;
};




char * Espws::FloatToChar(float charester) {
	char * charData;
    dtostrf(charester, 1, 0, charData);
    return charData;
}



String Espws::FreeMem() {
  String freeMemory = String(ESP.getFreeHeap());
  return freeMemory;
}



String Espws::IpLocalStr() {
  IPAddress ip = WiFi.localIP();
  String ipData = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
  return ipData;
}



char Espws::MacStr() {
  char macString;
  uint8_t macData[6];
  WiFi.macAddress(macData);
  sprintf_P(&macString, (const char *)F("%x:%x:%x:%x:%x:%x"), macData[0],  macData[1], macData[2], macData[3], macData[4], macData[5]);
  return macString;
}



IPAddress Espws::StrToIp (String strIp) {

  String temp;
  IPAddress ip;

  int count = 0;
  for(int i=0; i <= strIp.length(); i++)
  {
    if(strIp[i] != '.')
    {
      temp += strIp[i];
    }
    else
    {
      if(count < 4)
      {
        ip[count] = atoi(temp.c_str());
        temp = "";
        count++;
      }
    }
    if(i==strIp.length())
    {
      ip[count] = atoi(temp.c_str());
    }
  }
  return ip;
}