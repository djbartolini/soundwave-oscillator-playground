
#include <cmath>
#include "waveform.h"

// Sine (wave) is build into math.h
double sineWave(double time, double freq)
{
    return AMPLITUDE * sin(TWO_PI * freq * time);
}

// Square wave:
// We want AMPLITUDE to be zero when time
// gets halfway through each `tick`
// And then AMPLITUDE to be 1.0 when time
// gets to the first half of the `tick`
double squareWave(double time, double freq)
{
    double period = 1.0 / freq; // Period of one cycle in seconds
    double cyclepart = fmod(time, period);

    if (cyclepart < period / 2.0) {
        return AMPLITUDE;
    } else {
        return -AMPLITUDE;
    }
}

// Sawtooth:
// Waveform must rise steadily throughout
// each `tick`
// Then AMPLITUDE must jump back to 0
// to begin the next `tick`
double sawtoothWave(double time, double freq)
{
    double period = 1.0 / freq; // Period of one cycle in seconds
    double cyclepart = fmod(time, period);

    return (2.0 * AMPLITUDE * cyclepart / period) - AMPLITUDE;
}

// Triangle:
// Go up halfway
// Go down the other half
double triangleWave(double time, double freq)
{
    double period = 1.0 / freq; // Period of one cycle in seconds
    double cyclepart = fmod(time, period);
    double halfperiod = period / 2.0;

    if (cyclepart < halfperiod) {
        return (2.0 * AMPLITUDE * cyclepart / halfperiod) - AMPLITUDE;
    } else {
        return (2.0 * AMPLITUDE * (halfperiod - cyclepart + halfperiod) / halfperiod) - AMPLITUDE;
    }
}

// White noise
double noise(double amp)
{
    short result = 0;

    result = AMPLITUDE * (2.0 * rand() / RAND_MAX - 1.0);

    return result;
}
