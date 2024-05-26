//
// Created by Daniel Bartolini on 5/25/24.
//

#include "waveform.h"
#include "synth.h"
#include <cmath>

// Constructor
Synth::Synth() : currentSample(0), frequency(0.0), waveType(WaveType::SINE)
{
    initialize(1, SAMPLE_RATE); // Mono sound
}

// Destructor
Synth::~Synth()
{

}

// Gets frequency in input.cpp
void Synth::setFrequency(double freq)
{
    frequency = freq;
}

// Gets waveform type in input.cpp
void Synth::setWaveType(WaveType type)
{
    waveType = type;
}

// Load out sample buffers
bool Synth::onGetData(Chunk& data)
{
    samples.resize(SAMPLE_RATE / 10);

    for (unsigned i = 0; i < samples.size(); i++)
    {
        // Sample rate = 44100 hz
        double time = currentSample / static_cast<double>(SAMPLE_RATE);

        // push waveform buffer to sample
        switch (waveType) {
            case WaveType::SINE:
                samples[i] = sineWave(time, frequency);
                break;
            case WaveType::SQUARE:
                samples[i] = squareWave(time, frequency);
                break;
            case WaveType::SAWTOOTH:
                samples[i] = sawtoothWave(time, frequency);
                break;
            case WaveType::TRIANGLE:
                samples[i] = triangleWave(time, frequency);
        }

        currentSample++;
    }

    data.samples = samples.data();
    data.sampleCount = samples.size();

    return true;
}

void Synth::onSeek(sf::Time timeOffset)
{
    currentSample = timeOffset.asSeconds() * SAMPLE_RATE;
}
