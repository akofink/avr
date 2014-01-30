char* pass = "cookie";
char* passBuf = (char*) malloc(sizeof(char) * 1000);

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  Serial.println("Password: ");
}

void loop() {
  // send data only when you receive data:
  while (Serial.available() > 0) {
      // read and write the incoming byte:
      Serial.readBytesUntil(*(pass + strlen(pass)), passBuf, strlen(pass));
      *(passBuf + strlen(passBuf) + 1) = '\0';
      Serial.println((char*) passBuf);
      if (!strcmp(pass, passBuf)) {
        Serial.println("You are successful!");
        passBuf = "";
      } else {
        Serial.println("You are a failure.");
        Serial.flush();
        passBuf = "";
        Serial.println("Password: ");
      }
  }
}
