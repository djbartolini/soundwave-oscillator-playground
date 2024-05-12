
#include "sound.h"
#include <math.h>

#define TWO_PI 6.283185307

namespace sound
{

    short SineWave(double time, double freq, double amp)
    {
        short result;

        double tpc = 44100 / freq;     // ticks per cycle
        double cycles = time / tpc;
        double rad = TWO_PI * cycles;
        short amplitude = 32767 * amp;

        result = amplitude * sin(rad);  // double converts to 16-bit int

        return result;
    }

    short SquareWave(double time, double freq, double amp)
    {
        short result = 0;

        int tpc = 44100 / freq;      // ticks per cycle
        int cyclepart = int(time) % tpc;
        int halfcycle = tpc / 2;
        short amplitude = 32767 * amp;

        if (cyclepart < halfcycle) {
            result = amplitude;
        }

        return result;
    }

    short SawtoothWave(double time, double freq, double amp)
    {
        short result = 0;

        int tpc = 44100 / freq;     // ticks per cycle
        int cyclepart = int(time) % tpc;
        short amplitude = 32767 * amp;

        result = (short)((amplitude * 2 * cyclepart) / tpc - amplitude);

        return result;
    }

    short Noise(double amp)
    {
        short result = 0;

        short amplitude = 32767 * amp;

        result = rand() % amplitude;

        return result;
    }
}
