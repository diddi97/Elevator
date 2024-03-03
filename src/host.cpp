// #include <Arduino.h>
// #include <WiFi.h>

// const char *ssid = "skynet";
// const char *password = "terminator";

// const int ledPin = 14;
// const int ledon = 25;

// WiFiServer server(80);

// void setup() {
//   Serial.begin(115200);
//   pinMode(ledPin, OUTPUT);
//   pinMode(ledon, OUTPUT);

//   Serial.println();
//   Serial.println("Setting access point");
//   WiFi.mode(WIFI_AP);
//   WiFi.softAP(ssid, password);

//   IPAddress IP = WiFi.softAPIP();
//   Serial.print("AP IP address: ");
//   Serial.println(IP);

//   Serial.println("");
//   digitalWrite(ledon, HIGH);
//   server.begin();
// }

// void loop() {
//   WiFiClient client = server.available();
//   if (!client) {
//     return;
//   }

//   Serial.println("New client");
//   while (!client.available()) {
//     delay(1);
//   }

//   String request = client.readStringUntil('\r');
//   Serial.println(request);
//   client.flush();

//   if (request.indexOf("LED_ON") != -1) {
//     digitalWrite(ledPin, HIGH);
//     Serial.println("LED ON");
//   } else if (request.indexOf("LED_OFF") != -1) {
//     digitalWrite(ledPin, LOW);
//     Serial.println("LED OFF");
//   }

//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println("Connection: close");
//   client.println();
// }