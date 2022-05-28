#include <IRLibAll.h>

IRsend sender;

void setup() {
  Serial.begin(115200);
}

void loop() {
  while (!Serial.available());
  String inputString = Serial.readString();
  short bufferLength = inputString.length() + 1;
  char buffer[bufferLength];
  inputString.toCharArray(buffer, bufferLength);

  unsigned long code = atol(buffer);
  sender.send(NEC, code);
}
