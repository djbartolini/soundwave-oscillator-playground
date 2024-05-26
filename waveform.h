#ifndef SOUND_H
#define SOUND_H

#include <cmath>

const unsigned SAMPLE_RATE = 44100;
const unsigned AMPLITUDE = 30000;
const double TWO_PI = 6.28318;

double sineWave(double time, double frequency);
double squareWave(double time, double frequency);
double sawtoothWave(double time, double frequency);
double triangleWave(double time, double frequency);

#endif