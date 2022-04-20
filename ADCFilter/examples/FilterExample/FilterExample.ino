#include <ADCFilter.h>

#define ANALOG_PIN A0
#define MS 10

//Filter has 16 channels and 6 samples by default
//To change channel count and sample count edit ADCFilter.h file
ADCFilter filter;

void setup() {
    Serial.begin(9600);

    //Alpha must be 0 < a < 1, default value is 0.1
    //The lower alpha value, the higher smoothing
    //This is not required but, to set new alpha value use:
    filter.setAlpha(0.2f);
}

void loop() {
    //Update channel 0 with new value
    filter.update(0, analogRead(ANALOG_PIN));
    //Get smoothed value from channel 0 and print it
    Serial.println(filter.get(0));

    delay(MS);
}