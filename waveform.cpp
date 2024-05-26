
#include <cmath>
#include "waveform.h"

double sineWave(double time, double freq)
{
    return AMPLITUDE * sin(TWO_PI * freq * time);
}

double squareWave(double time, double freq)
{
    short result = 0;

    int tpc = 44100 / freq;      // ticks per cycle
    int cyclepart = int(time) % tpc;
    int halfcycle = tpc / 2;

    if (cyclepart < halfcycle) {
        result = AMPLITUDE;
    }

    return result;
}

double sawtoothWave(double time, double freq)
{
    short result = 0;

    int tpc = 44100 / freq;     // ticks per cycle
    int cyclepart = int(time) % tpc;

    result = (short)((AMPLITUDE * 2 * cyclepart) / tpc - AMPLITUDE);

    return result;
}

double triangleWave(double time, double freq)
{
    short result = 0;

    int tpc = 44100 / freq;
    int cyclepart = int(time) % tpc;
    int halfcycle = tpc / 2;

    if (cyclepart < halfcycle) {
        result = (short)((AMPLITUDE * 2 * cyclepart) / halfcycle - AMPLITUDE);
    } else {
        result = (short)(AMPLITUDE - (AMPLITUDE * 2 * (cyclepart - halfcycle)) / halfcycle);
    }

    return result;
}

double noise(double amp)
{
    short result = 0;

    result = rand() % AMPLITUDE;

    return result;
}
