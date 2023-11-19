
#include "PinDefinitionsAndMore.h" //Define macros for input and output pin etc.
#include <IRremote.hpp>


char buf[1024];
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  IrSender.begin();
}

void loop() {
  while (!Serial.available());
  String inputString = Serial.readString();
  int bufferLength = inputString.length() + 1;
  inputString.toCharArray(buf, bufferLength);
  char *p = buf;
  char *str;
  unsigned long a = -1;
  while ((str = strtok_r(p, ";", &p)) != NULL) {
    if (a == -1) {
     a = atol(str);
    } else { 
      unsigned long code = atol(str);
      if (code != 0) {
        IrSender.sendNEC(a, code, 0);
        delay(100);
      }
    }
  }
}
