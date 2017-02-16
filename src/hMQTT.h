/*******************************************************************************
 * @file		hMQTT.h
 * @brief		This is a header file of MQTT v3.1.1 protocol.
 * @author	llHoYall <hoya@ixys.net>
 * @version	v0.0
 *
 * @revision history
 * 	v0.0 - 2017.02.08 - Start
 ******************************************************************************/

#ifndef __HoYa_MQTT_H__
#define __HoYa_MQTT_H__

/* Include Header ------------------------------------------------------------*/
#include <Arduino.h>
#include <Client.h>

/* hMQTT Class ---------------------------------------------------------------*/
class hMQTT {
public:
	hMQTT(Client& _client);

	void setServer(String _domain, uint16_t _port);

	boolean isConnected(void);
	boolean	connect(void);

	void sendConnect(void);
	void run(void);

private:
	byte 	fixHeader[2];
	byte	varHeader[2];
	byte	payload[64];

	String		serverDomain;
	uint16_t	serverPort;
	Client*		client;

	enum STATE {
		INIT,
		CONNECTED,
	};
	STATE	state;
};

#endif

