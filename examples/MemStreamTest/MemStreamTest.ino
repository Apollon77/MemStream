#include <MemStream.h>


void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("START");
  unsigned char buf[100] = "0123456789ABCDEFGHIJKLMNOPQRST";
  // Initialize instance with a 100 byte buffer and 30 byte of available content, not writable
  MemStream testStream(buf,100,30,false);
  // add three more characters
  testStream.write("XYZ");
  // print out all available characters
  while (testStream.available()) {
    Serial.print("Avail: ");
    Serial.print(testStream.available());
    Serial.print(", Read:");
    char c=testStream.read();
    Serial.print(c);
    Serial.print(" (");
    Serial.print(c,HEX);
    Serial.println(")");
  }

  Serial.println();
  Serial.println();
  Serial.println();

  // reset cursor position to 0
  testStream.flush();
  // write some data
  testStream.write("UVW123456");
  // print out all available characters
  while (testStream.available()) {
    Serial.print("Avail: ");
    Serial.print(testStream.available());
    Serial.print(", Read:");
    char c=testStream.read();
    Serial.print(c);
    Serial.print(" (");
    Serial.print(c,HEX);
    Serial.println(")");
  }

Serial.println("DONE");
}

void loop() {
}
