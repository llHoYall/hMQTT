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
#include <hMQTT.h>

/* Definition ----------------------------------------------------------------*/
// Configuration
#define WIFI_SSID		"RP_RND_A"
#define WIFI_PWD		"radio1106"

#define MQTT_SERVER	"broker.hivemq.com"

/* Global Variable -----------------------------------------------------------*/
int 				wifiStatus = WL_IDLE_STATUS;
WiFiClient	wifiClient;

hMQTT				hmqtt(wifiClient);

/* Private Function ----------------------------------------------------------*/
void setup_WiFi(void);

/* Function ------------------------------------------------------------------*/
void setup(void) {
	Serial.begin(115200);
	while (!Serial) { ; }		// wait for serial connection

	setup_WiFi();
}

void loop(void) {
	if (!wifiClient.connected()) {
//		if (wifiClient.connect(MQTT_SERVER, 1883)) {
//			Serial.println("[APP] Connect to MQTT server");

			hmqtt.sendConnect();
//		}
	}
}

void setup_WiFi(void) {
	if (wifiStatus != WL_CONNECTED) {
		Serial.print("[APP] WiFi connect to: ");
		Serial.println(WIFI_SSID);

		wifiStatus = WiFi.begin(WIFI_SSID, WIFI_PWD);

		delay(3000);		// wait for wifi connection
	}
	Serial.println("[APP] WiFi is connected");
	Serial.print("[APP] IP: ");
	Serial.println(IPAddress(WiFi.localIP()));
}

