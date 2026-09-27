# esp_smart_home

A minimal, retrofitted smart-home switch: an **ESP8266** drives a **servo** that flips a physical light switch, controlled from anywhere through a **Telegram bot** over Wi-Fi. No rewiring or smart bulbs required — it just actuates the existing switch.

## How It Works

- The ESP8266 connects to Wi-Fi and polls Telegram for new messages.
- `/open` rotates the servo to 60° to flick the switch on.
- `/close` returns the servo to 0° to switch it off.
- The bot replies with a confirmation message.

## Hardware

| Component | Role |
|-----------|------|
| ESP8266 (NodeMCU/Wemos D1 mini) | Wi-Fi + Telegram client |
| Micro servo (SG90) | Physically actuates the switch |
| 5V supply | Powers the servo |

## Setup

1. Install the `UniversalTelegramBot` library (Arduino Library Manager).
2. Create a Telegram bot with [@BotFather](https://t.me/BotFather) and get its token.
3. Fill in the credentials at the top of `simple_smart_home.ino`:

   ```cpp
   String ssid  = "YOUR_WIFI_SSID";
   String pass  = "YOUR_WIFI_PASSWORD";
   String token = "YOUR_TELEGRAM_BOT_TOKEN";
   String chatid = "YOUR_TELEGRAM_CHAT_ID";
   ```

4. Flash to the ESP8266 and mount the servo against the switch.
5. Send `/open` or `/close` to the bot.

## Notes

- Credentials and tokens are placeholders — never commit real values.
