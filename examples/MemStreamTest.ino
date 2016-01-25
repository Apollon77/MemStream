#include <MemStream.h>


void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("START");
  // put your setup code here, to run once:
  unsigned char buf[100] = "0123456789ABCDEFGHIJKLMNOPQRST";
  MemStream testStream(buf,100,30,false);
  testStream.write("XYZ");
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

  testStream.flush();
  testStream.write("UVW123456");
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
  // put your main code here, to run repeatedly:

}
