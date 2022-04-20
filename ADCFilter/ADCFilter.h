#ifndef ADCFilter_h
#define ADCFilter_h

#include <Arduino.h>

#define CHANNELS 16
#define SAMPLES 6

class ADCFilter
{
    public:
        void update(int channel, float newRaw);
        float get(int channel);
        void setAlpha(float alpha);
    private:
        float Raw[CHANNELS][SAMPLES];
        float RawAveraged[CHANNELS];
        float RawSum[CHANNELS];
        float OldSmoothed[CHANNELS];
        float Smoothed[CHANNELS];
        int Index[CHANNELS];
        float Alpha = 0.1f;
};

#endif