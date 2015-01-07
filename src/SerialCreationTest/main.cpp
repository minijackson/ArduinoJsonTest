#include <Arduino.h>

#include "aJSON.h"

void setup() {
	Serial.begin(115200);
	Serial.flush();
}

void readLine(char* output, size_t maxSize) {
	size_t readCount(0);
	char byte;

	while(!Serial.available());

	delay(3);
	while(Serial.available() > 0 && readCount < maxSize) {
		output[readCount++] = Serial.read();
	}
	output[readCount] = '\0';
}

void loop() {

	char name[30], country[30], street[30], tempNumber[4], tempZIP[8], tempAlive[2];
	int number, ZIP;
	bool alive;

	Serial.println("Name: ");
	readLine(name, 30);

	Serial.println("Country: ");
	readLine(country, 30);

	Serial.println("Street: ");
	readLine(street, 30);

	Serial.println("Number: ");
	readLine(tempNumber, 30);
	number = atoi(tempNumber);

	Serial.println("ZIP: ");
	readLine(tempZIP, 30);
	ZIP = atoi(tempZIP);

	Serial.println("Alive? (1 = true, 0 = false): ");
	readLine(tempAlive, 30);
	alive = atoi(tempAlive);


	aJsonObject *address,
				*root = aJson.createObject();

	aJson.addStringToObject (root    , "name"    , name);
	aJson.addItemToObject   (root    , "address" , address = aJson.createObject());

	aJson.addStringToObject (address , "country" , country);
	aJson.addStringToObject (address , "street"  , street);
	aJson.addNumberToObject (address , "number"  , number);
	aJson.addNumberToObject (address , "ZIP"     , ZIP);

	aJson.addBooleanToObject(root    , "alive"   , alive);

	Serial.println(aJson.print(root));
	aJson.deleteItem(root);
	delay(1000);
}
