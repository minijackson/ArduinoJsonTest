#include <Arduino.h>

#include "aJSON.h"

void setup() {
	Serial.begin(115200);
}

void loop() {
	aJsonObject *address,
				*root = aJson.createObject();

	aJson.addStringToObject(root    , "name"    , "Jack");
	aJson.addItemToObject  (root    , "address" , address = aJson.createObject());

	aJson.addStringToObject(address , "country" , "Freedonia");
	aJson.addStringToObject(address , "street"  , "Albert Einstein");
	aJson.addNumberToObject   (address , "number"  , 42);
	aJson.addNumberToObject   (address , "ZIP"     , 1337);

	aJson.addBooleanToObject  (root    , "alive"   , true);

	Serial.println(aJson.print(root));
	delay(1000);
}
