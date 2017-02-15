/*******************************************************************************
 * @file		hMQTT.cpp
 * @brief		This is a source file of MQTT v3.1.1 protocol.
 * @author	llHoYall <hoya@ixys.net>
 * @version	v0.0
 *
 * @revision history
 * 	v0.0 - 2017.02.08 - Start
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
#include <hMQTT.h>

/* hMQTT Class ---------------------------------------------------------------*/
hMQTT::hMQTT(Client& _client) {
	this->client = &_client;
}

void hMQTT::sendConnect(void) {
	byte buffer[20];

	if (client->connect("broker.hivemq.com", 1883)) {
		Serial.println("[DBG] Connect to MQTT Server");
	}
	else {
		return ;
	}

	buffer[0] = 0x10;
	buffer[1] = 0x10;
	buffer[2] = 0x00;
	buffer[3] = 0x04;
	buffer[4] = 'M';
	buffer[5] = 'Q';
	buffer[6] = 'T';
	buffer[7] = 'T';
	buffer[8] = 0x04;
	buffer[9] = 0x02;
	buffer[10] = 0x00;
	buffer[11] = 0x0f;
	buffer[12] = 0x00;
	buffer[13] = 0x04;
	buffer[14] = 'H';
	buffer[15] = 'o';
	buffer[16] = 'Y';
	buffer[17] = 'a';
	client->write(buffer, 18);

//	fixHeader[0] = 0x10;		// CONNECT type
//	fixHeader[1] = 0x0e;
//	payload[0] = 0x00;
//	payload[1] = 0x04;
//	payload[2] = 'M';
//	payload[3] = 'Q';
//	payload[4] = 'T';
//	payload[5] = 'T';
//	payload[6] = 0x04;
//	payload[7] = 0x02;
//	payload[8] = 0x00;
//	payload[9] = 0x0f;
//	client->write(fixHeader, 2);
//	client->write(payload, 14);

	unsigned long startTime = millis();
	while (!client->available()) {
		unsigned long curTime = millis();
		if (curTime - startTime >= 15000) {
			Serial.println("[DBG] Connect Fail");
			client->stop();
			return ;
		}
	}

	unsigned long s = millis();
	while (1) {
		unsigned long e = millis();
		if (e - s >= 1000)
			return ;
		char c = client->read();
		Serial.println(c, HEX);
	}
}

void hMQTT::run(void) {
	if (client->connected()) {
		if (client->available()) {
			Serial.println(client->read());
		}
	}
}

