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

	void sendConnect(void);
	void run(void);

private:
	byte 	fixHeader[2];
	byte	varHeader[2];
	byte	payload[64];

	Client*	client;
};

#endif

