#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "Node";           // your network SSID
const char* password = "anfkscck";   // your network password
WiFiClient client;
unsigned long myChannelNumber = 1548484;
String myWriteAPIKey = "BW8CO98QBL2XGIAP";

const int ledPin = 14;   // D5 pin (GPIO14)
const int sensorPin = 5; // D1 pin (GPIO5)

void setup() {
  Serial.begin(9600);           // Initialize serial
  pinMode(ledPin, OUTPUT);      // LED pin as output
  pinMode(sensorPin, INPUT);    // Sensor pin as input

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);     // Initialize ThingSpeak
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(5000);
      Serial.print(".");
    }
    Serial.println("\nConnected.");
  }

  int val = digitalRead(sensorPin); // Read sensor value
  Serial.print("Sensor value: ");
  Serial.println(val);

  if (val == 0) {
    digitalWrite(ledPin, HIGH);  // LED ON
  } else {
    digitalWrite(ledPin, LOW);   // LED OFF
  }

  String postStr = "field1=" + String(val);

  if (client.connect("api.thingspeak.com", 80)) {
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + myWriteAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    client.stop();
  }

  delay(15000); // ThingSpeak allows updates every 15 seconds
}
