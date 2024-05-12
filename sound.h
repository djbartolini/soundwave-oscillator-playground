#ifndef SOUND_H
#define SOUND_H

#include <math.h>

namespace sound
{
    #define TWO_PI 6.283185307

    short SineWave(double time, double freq, double amp);
    short SquareWave(double time, double freq, double amp);
    short SawtoothWave(double time, double freq, double amp);
    short TriangleWave(double time, double freq, double amp);

    short Noise(double amp);
}

#endif