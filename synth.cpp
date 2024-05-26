//
// Created by Daniel Bartolini on 5/25/24.
//

#include "waveform.h"
#include "synth.h"
#include <cmath>

// Constructor
Synth::Synth() : currentSample(0), frequency(440.0), octave(0), waveType(WaveType::SINE)
{
    initialize(1, SAMPLE_RATE); // Mono sound
}

// Destructor
Synth::~Synth() {}

// Get octave
int Synth::getOctave()
{
    return octave;
}

// Go up an octave
void Synth::octaveUp()
{
    octave++;
}

// Go down an octave
void Synth::octaveDown()
{
    octave--;
}

// Sets frequency in input.cpp
void Synth::setFrequency(double freq)
{
    frequency = freq;
}

// Sets waveform type in input.cpp
void Synth::setWaveType(WaveType type)
{
    waveType = type;
}

// Load out sample buffers
bool Synth::onGetData(Chunk& data)
{
    samples.resize(SAMPLE_RATE / 10);

    double adjustedFreq = frequency * std::pow(2.0, octave);

    for (unsigned i = 0; i < samples.size(); i++)
    {
        // Sample rate = 44100 hz
        double time = currentSample / static_cast<double>(SAMPLE_RATE);

        // Generate waveform based on the wave type and adjusted frequency
        switch (waveType) {
            case WaveType::SINE:
                samples[i] = sineWave(time, adjustedFreq);
                break;
            case WaveType::SQUARE:
                samples[i] = squareWave(time, adjustedFreq);
                break;
            case WaveType::SAWTOOTH:
                samples[i] = sawtoothWave(time, adjustedFreq);
                break;
            case WaveType::TRIANGLE:
                samples[i] = triangleWave(time, adjustedFreq);
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
