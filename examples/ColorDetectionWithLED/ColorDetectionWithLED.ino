/*
 * Copyright 2020 VIA Technologies, Inc. All Rights Reserved.
 *
 * This PROPRIETARY SOFTWARE is the property of WonderMedia Technologies, Inc.
 * and may contain trade secrets and/or other confidential information of
 * WonderMedia Technologies, Inc. This file shall not be disclosed to any third
 * party, in whole or in part, without prior written consent of WonderMedia.
 *
 * THIS PROPRIETARY SOFTWARE AND ANY RELATED DOCUMENTATION ARE PROVIDED AS IS,
 * WITH ALL FAULTS, AND WITHOUT WARRANTY OF ANY KIND EITHER EXPRESS OR IMPLIED,
 * AND WonderMedia TECHNOLOGIES, INC. DISCLAIMS ALL EXPRESS OR IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
*/

#include <Pixetto.h>

// HardwareSerial pins
#define rxPin 0
#define txPin 1

// SoftwareSerial pins
//#define rxPin A5
//#define txPin A4

Pixetto ss(rxPin, txPin);

void setup()
{
	ss.begin();

	pinMode(13, OUTPUT);
	pinMode(11, OUTPUT);
}


void loop()
{
	if (ss.isDetected()) {
		if (ss.getFuncID() == Pixetto::FUNC_COLOR_DETECTION) {
			if (ss.getTypeID() == Pixetto::COLOR_RED){
				digitalWrite(13, HIGH);
				digitalWrite(11, LOW);
			} else if (ss.getTypeID() == Pixetto::COLOR_BLUE){
				digitalWrite(11, HIGH);
				digitalWrite(13, LOW);
			}
		}
	}
	delay(20);

}
