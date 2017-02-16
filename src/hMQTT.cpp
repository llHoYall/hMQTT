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
	this->serverDomain = "";
	this->serverPort = 0;
	this->state = hMQTT::INIT;
}

void hMQTT::setServer(String _domain, uint16_t _port) {
	serverDomain = _domain;
	serverPort = _port;
}

boolean hMQTT::isConnected(void) {
	if (client == NULL) {
		return false;
	}
	else {
		if (!client->connected()) {
			if (state == hMQTT::CONNECTED) {
				state = hMQTT::INIT;
				client->flush();
				client->stop();
			}
			return false;
		}
	}
	return true;
}

boolean hMQTT::connect(void) {
	if (client->connect((const char*)serverDomain.c_str(), serverPort)) {
		sendConnect();

		return true;
	}
	return false;
}

void hMQTT::sendConnect(void) {
	fixHeader[0] = 0x10;		// CONNECT type
	fixHeader[1] = 0x0e;
	payload[0] = 0x00;
	payload[1] = 0x04;
	payload[2] = 'M';
	payload[3] = 'Q';
	payload[4] = 'T';
	payload[5] = 'T';
	payload[6] = 0x04;
	payload[7] = 0x02;
	payload[8] = 0x00;
	payload[9] = 0x0f;
	client->write(fixHeader, 2);
	client->write(payload, 14);

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
		if (e - s >= 10)
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

