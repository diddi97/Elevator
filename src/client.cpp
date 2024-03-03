// #include <Arduino.h>
// #include <WiFi.h>

// #define btn1 32
// #define btn2 35
// #define btn3 34
// #define ledPin 15
// #define ledon 2

// const char *ssid = "skynet";
// const char *password = "terminator";

// int sensorValue0 = 0;  //sensor value, I'm using 0/1 button state
// int sensorValue1 = 0;
// int sensorValue2 = 0;
// int sensorValue3 = 0;

// void setup() {
//   Serial.begin(115200);
//   delay(10);
//   pinMode(btn1, INPUT_PULLUP);
//   pinMode(btn2, INPUT_PULLUP);
//   pinMode(btn3, INPUT_PULLUP);
//   pinMode(ledon, OUTPUT);
//   digitalWrite(btn1, HIGH);

//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.println("not connected");
//   }
//   digitalWrite(ledon, HIGH);
//   Serial.println("Connected to skynet!");
// }

// void loop() {
//   if (digitalRead(btn1) == LOW) sensorValue1 = 1;
//   if (digitalRead(btn2) == LOW) sensorValue2 = 1;
//   if (digitalRead(btn3) == LOW) sensorValue3 = 1;

//   if (digitalRead(btn1) == HIGH) sensorValue1 = 0;
//   if (digitalRead(btn2) == HIGH) sensorValue2 = 0;
//   if (digitalRead(btn3) == HIGH) sensorValue3 = 0;


//   WiFiClient client;
//   const char *host = "192.168.4.1";  //host IP
//   const int httpPort = 80;

//   if (!client.connect(host, httpPort)) {
//     Serial.println("connection failed");
//     return;
//   }

//   // Prepare the LED command based on sensor readings
//   String ledCommand = "";
//   if (sensorValue1 == 1) ledCommand = "LED_ON";
//   else ledCommand = "LED_OFF";

//   // Prepare the URL to include LED command
//   String url = "/data/";
//   url += "?sensor_reading=";
//   url += "{\"sensor0_reading\":\"sensor0_value\",\"sensor1_reading\":\"sensor1_value\",\"sensor2_reading\":\"sensor2_value\",\"sensor3_reading\":\"sensor3_value\",\"led_command\":\"" + ledCommand + "\"}";

//   url.replace("sensor1_value", String(sensorValue1));
//   url.replace("sensor2_value", String(sensorValue2));
//   url.replace("sensor3_value", String(sensorValue3));

//   // This will send the request to the server
//   client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

//   // unsigned long timeout = millis();
//   // while (client.available() == 0) {
//   //   if (millis() - timeout > 5000) {
//   //     Serial.println(">>> Client Timeout !");
//   //     client.stop();
//   //     return;
//   //   }
//   // }
// }