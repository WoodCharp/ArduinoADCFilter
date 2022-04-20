#include "ADCFilter.h"

void ADCFilter::update(int channel, float newRaw) {
  //Remove old raw from sum of raw's
  RawSum[channel] -= Raw[channel][Index[channel]];
  //Add new raw to raw's array
  Raw[channel][Index[channel]] = newRaw;
  //Add new raw to sum of raw's
  RawSum[channel] += newRaw;
  //Increment index
  Index[channel]++;
  //If index is more than SAMPLES count then reset index
  if(Index[channel] >= SAMPLES) Index[channel] = 0;
  //Calculate new average value
  RawAveraged[channel] = RawSum[channel] / SAMPLES;
  //Calculate new smoothed value
  Smoothed[channel] = Alpha * RawAveraged[channel] + (1 - Alpha) * OldSmoothed[channel];
  //Add new smoothed to old smoothed array for the next round's new smoothed value
  OldSmoothed[channel] = Smoothed[channel];
}

float ADCFilter::get(int channel) {
    return Smoothed[channel];
}

void ADCFilter::setAlpha(float alpha) {
    Alpha = alpha;
}