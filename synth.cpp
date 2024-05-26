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

void Synth::setFrequency(double freq)
{
    frequency = freq;
}

void Synth::setWaveType(WaveType type)
{
    waveType = type;
}

bool Synth::onGetData(Chunk& data)
{
    samples.resize(SAMPLE_RATE / 10);

    for (unsigned i = 0; i < samples.size(); i++)
    {
        double time = currentSample / static_cast<double>(SAMPLE_RATE);

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
