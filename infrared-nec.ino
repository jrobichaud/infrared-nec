#include <IRLibAll.h>

IRsendNEC sender;
char buf[1024];
void setup() {
  Serial.begin(115200);
}

void loop() {
  while (!Serial.available());
  String inputString = Serial.readString();
  int bufferLength = inputString.length() + 1;
  inputString.toCharArray(buf, bufferLength);
  char *p = buf;
  char *str;
  while ((str = strtok_r(p, ";", &p)) != NULL) {
    unsigned long code = atol(str);
    sender.send(code);
  }
}
