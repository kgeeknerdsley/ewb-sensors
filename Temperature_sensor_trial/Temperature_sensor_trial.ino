const int temperaturePin = 0;
int i;
bool avgCollected;
// hello

float averages[20];

float avgTemp;

void setup() {
 Serial.begin(9600);

 avgCollected = false;
 avgTemp = 0;
}

void loop() {
 float voltage, degreesC, degreesF;
  voltage = getVoltage(temperaturePin);
   degreesC = (voltage - 0.5) * 100.0;
   degreesF = degreesC * (9.0/5.0) + 32.0;

   averages[i] = degreesF;
   Serial.println(averages[i]);

   i++;

   if(i > 19) {
     i = 0;
     avgCollected = true;
   }

   

  if(avgCollected) {
    for(int x = 0; x < 19; x++) {
      avgTemp = avgTemp + averages[x];
    }

    avgTemp = avgTemp / 20;

    Serial.print("Average temperature: ");
    Serial.print(avgTemp);
    Serial.print(" F");
  }

  delay(1000);
}

float getVoltage(int pin)
{
    return (analogRead(pin) * 0.004882814);
}
