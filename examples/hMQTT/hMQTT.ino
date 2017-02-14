/*******************************************************************************
 * @file		hMQTT_example.ino
 * @brief		This file is an Arduino example for HoYa's MQTT.
 * @author	llHoYall <hoya@ixys.net>
 * @version	v0.0
 *
 * @revision history
 * 	v0.0 - 2017.02.13 - Start
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
#include <Arduino.h>
#include <WiFi101.h>

/* Definition ----------------------------------------------------------------*/
// Configuration
#define WIFI_SSID		"RP_RND_A"
#define WIFI_PWD		"radio1106"

/* Global Variable -----------------------------------------------------------*/
int 				wifiStatus = WL_IDLE_STATUS;
WiFiClient	wifiClient;

/* Function ------------------------------------------------------------------*/
void setup(void) {
	Serial.begin(115200);
	while (!Serial) { ; }		// wait for serial connection

	if (wifiStatus != WL_CONNECTED) {
		Serial.print("[APP] WiFi connect to: ");
		Serial.println(WIFI_SSID);

		wifiStatus = WiFi.begin(WIFI_SSID, WIFI_PWD);

		delay(3000);		// wait for wifi connection
	}
	Serial.println("[APP] WiFi is connected");
	Serial.print("[APP] IP: ");
	Serial.println(WiFi.localIP());
}

void loop(void) {
	while (wifiClient.available()) {
		char c = wifiClient.read();
		Serial.write(c);
	}

	if (!wifiClient.connected()) {
//		Serial.println("[APP] Dieconnecting from server");
		wifiClient.stop();
	}
}

