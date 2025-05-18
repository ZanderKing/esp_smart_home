#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <Servo.h>


String ssid  = "XXX"; //Enter Wifi Username
String pass  = "YYY"; // Enter Wifi Password
String token = "ZZZ";
String chatid="AAA";

Servo myServo;
WiFiClientSecure secured_client;
UniversalTelegramBot bot(token, secured_client);

void setup() {
Serial.begin(115200);
myServo.attach(D4);
WiFi.begin(ssid,pass);
while (WiFi.status() != WL_CONNECTED) delay(500);
secured_client.setInsecure();}

void loop() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  while(numNewMessages) {
    for (int i=0; i<numNewMessages; i++) {
      String text = bot.messages[i].text;
      if (text == "/open") {
        myServo.write(60);
        bot.sendMessage(chatid, "Lamp activated!", "");
      } else if (text == "/close") {
        myServo.write(0);
        bot.sendMessage(chatid, "Lamp deactivated!", "");
      }
    }
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }

  delay(1000);

}
