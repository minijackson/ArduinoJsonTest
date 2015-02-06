#include <Arduino.h>
#include "aJSON.h"

aJsonStream serial_stream(&Serial);

void setup() {
	Serial.begin(115200);
	pinMode(13, OUTPUT);
}

void loop() {
	if(serial_stream.available()) {
		/* First, skip any accidental whitespace like newlines. */
		serial_stream.skip();
	}

	if(serial_stream.available()) {
		aJsonObject *root    = aJson.parse(&serial_stream);
		aJsonObject *led   = aJson.getObjectItem(root, "led");

		digitalWrite(13, (alive->valuebool)? HIGH : LOW);

		aJson.deleteItem(root);
	}
}
