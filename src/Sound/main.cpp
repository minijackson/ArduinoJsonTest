void setup() {
	Serial.begin(9600);
}

void loop() {
	int base = 880;
	float delta = 1.12246;               // 2^(1/6) (demi-octave)
	float variation = 1.003616666; // 2^(1/192)

        // iterate over the notes of the melody:
	for (int thisNote = base ; thisNote < base*delta ; thisNote *= variation) {
		//Serial.println(thisNote);
		tone(8, thisNote, 10);
		delay(10);
	}

	for (int thisNote = base*delta ; thisNote > base ; thisNote /= variation) {
		//Serial.println(thisNote);
		tone(8, thisNote, 10);
		delay(10);
	}
}
