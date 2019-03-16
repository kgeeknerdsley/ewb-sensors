//ResistanceTester.ino
//by Kevin Worsley for EWB R&D

/* WIRING:
	A0 = Water +
	A1 = Water - = Vref +
*/

//ints to hold the adc values from either end
int adc_refp;
int adc_probep;
int adc_proben;

float volt_refp;
float volt_probep;
float volt_proben;

float voltWater;
float voltRef;
float current;
float waterResistance;

#define REF_RESISTANCE 4680

void setup() {
	Serial.begin(9600);
	adc_refp = 0;
	adc_probep = 0;
	adc_proben = 0;

	volt_refp = 0;
	volt_probep = 0;
	volt_proben = 0;

	voltWater = 0;
}

void loop() {
	adc_probep = analogRead(A0); //pull in the voltage values from adc
	adc_proben = analogRead(A1);

	volt_probep = adcToVolt(adc_probep); //convert adc value to voltage number
	volt_proben = adcToVolt(adc_proben);
	volt_refp = volt_proben; //these are attached to the same node

	//Serial.println(volt_probep);
	//Serial.println(volt_proben);

	voltWater = volt_probep - volt_proben; //V+ - V- is voltage on resistor
	voltRef = volt_refp; //negative end of ref resistor is connected to ground, so sub by 0

	current = (voltRef / REF_RESISTANCE); //i = V/r, this current is constant throughout the series circuit
	waterResistance = (voltWater/current);

	Serial.print("Voltage across the water: ");
	Serial.println(voltWater);

	Serial.print("Voltage on ref resistor: ");
	Serial.println(voltRef);

	Serial.print("Current in circuit: ");
	Serial.println(current, 7);

	Serial.print("Resistance of water: ");
	Serial.println(waterResistance,3);

	delay(1000);
}

float adcToVolt(int vin) {
	return vin * (5.0 / 1023);//converts adc value to voltage
}