#include <Arduino.h>
#include "aJSON.h"

void setup() {
	Serial.begin(115200);
}

void loop() {
	aJsonObject* jsonObject = aJson.parse(
		"{"
		"	\"name\"    : \"Jack\","
		"	\"country\" : \"Freedonia\""
		"}"
	);

	aJsonObject* name    = aJson.getObjectItem(jsonObject, "name");
	aJsonObject* country = aJson.getObjectItem(jsonObject, "country");

	Serial.print("My name is ");
	Serial.print(name->valuestring);
	Serial.print(" and I live in ");
	Serial.println(country->valuestring);

	delay(1000);
}
