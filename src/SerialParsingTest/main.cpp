#include <Arduino.h>
#include "aJSON.h"

aJsonStream serial_stream(&Serial);

void setup() {
	Serial.begin(115200);
}

void loop() {
	if(serial_stream.available()) {
		/* First, skip any accidental whitespace like newlines. */
		serial_stream.skip();
	}

	if(serial_stream.available()) {
		aJsonObject *root    = aJson.parse(&serial_stream);

		aJsonObject *name    = aJson.getObjectItem(root, "name");

		aJsonObject *address = aJson.getObjectItem(root, "address");
		aJsonObject *country = aJson.getObjectItem(address, "country");
		aJsonObject *street  = aJson.getObjectItem(address, "street");
		aJsonObject *number  = aJson.getObjectItem(address, "number");
		aJsonObject *ZIP     = aJson.getObjectItem(address, "ZIP");

		aJsonObject *alive   = aJson.getObjectItem(root, "alive");

		Serial.print("My name is ");
		Serial.print(name->valuestring);
		Serial.print(" and I live in ");
		Serial.print(number->valueint);
		Serial.print(" ");
		Serial.print(street->valuestring);
		Serial.print(" street in ");
		Serial.print(country->valuestring);
		Serial.print(" ");
		Serial.print(ZIP->valueint);
		Serial.print(" and I am ");
		Serial.print((alive->valuebool)? "" : "not ");
		Serial.print("alive.");

		aJson.deleteItem(root);
	}
}
