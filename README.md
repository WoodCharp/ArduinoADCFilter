# Arduino ADC Filter
 Method to smooth ADC readings.

## How it works ?

This filter has running averaging for raw values from ADC and exponential smoothing to averaged sum of raw values.

## Visualized values from filter

Few images to see how filter performs. 

I have linear hall-effect A1324 with 4.7uF bypass capacitor on arduino nano board for this test.
There is no magnet near the sensor. New value is printed every 10ms (115200 baud rate). Blue line is highest value and red is lowest value got from arduino.

Remember, your results may vary.

### Raw

Here filter is not being used. Value fluctuates around range of 2.

![Raw](https://user-images.githubusercontent.com/51534125/164296573-c35a46e8-85f6-46b3-9a05-52e11e11a6bf.jpg)

### Exponential smoothing alpha = 0.9

Value fluctuates around range of ~1 - 0.7.

![FILTERED_0_9](https://user-images.githubusercontent.com/51534125/164297247-c4e46a1e-8a32-435a-b264-8f857e286c87.jpg)


### Exponential smoothing aplha = 0.1

Value fluctuates around range of ~0.6 - 0.45.

![FILTERED_0_1](https://user-images.githubusercontent.com/51534125/164297336-100642cb-9e7a-45a1-8e9a-e30b0c28debe.jpg)

## How to use

See the example file at ADCFilter\examples\FilterExample\FilterExample.ino
