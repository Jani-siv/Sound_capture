/*
  A simple TCP Client
  Uses the following libraries:
  http://librarymanager/All#WiFi101   // use this for MKR1000
  http://librarymanager/All#WiFiNINA    // use this for MKR1010 or Nano 33 IoT
  created 22 Oct 2018
  updated 17 Jan 2021
  by Tom Igoe
*/
#define LED 2
#define LED2 3
#include <SPI.h>
//#include <WiFiNINA.h> // use this for MKR1010 board or Nano 33 IoT
#include <WiFi101.h>        // use this for the MKR1000 board
#include "secrets.h"

//// Initialize the Wifi client library
//WiFiClient client;

WiFiServer server(8889);
boolean alreadyConnected = false; // whether or not the client was connected previously

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(LED2,OUTPUT);
  delay(3000);
  // while you're not connected to a WiFi AP,
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(SECRET_SSID);          // print the network name (SSID)
    WiFi.begin(SECRET_SSID, SECRET_PASS); // try to connect
    delay(2000);
  }

  // When you're connected, print out the device's network status:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  // start the server:
  server.begin();
}
static bool light=false;

void loop() {

  // wait for a new client:
  WiFiClient client = server.available();

  // when the client sends the first byte, say hello:
  if (client) {
    if (!alreadyConnected) {
      // clear out the input buffer:
      client.flush();
      Serial.println("We have a new client");
      client.println("Hello, client!");
      alreadyConnected = true;
    }

    if (client.available() > 0) {
      // read the bytes incoming from the client:
      char thisChar = client.read();
      if (thisChar == '1')
        {
          light = true;
          digitalWrite(LED,HIGH);
           digitalWrite(LED2,HIGH);
        }
      else if (thisChar == '0')
      {
        light = false;
        digitalWrite(LED,LOW);
        digitalWrite(LED2,LOW);
        }
        Serial.println(light);
      }
      // echo the bytes back to the client:
     // server.write(thisChar);
      // echo the bytes to the server as well:
     // Serial.write(thisChar);
    }
  }
