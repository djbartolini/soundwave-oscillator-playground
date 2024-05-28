//
// Created by Daniel Bartolini on 5/25/24.
//

#include "waveform.h"
#include "synth.h"
#include <cmath>
#include <algorithm>
#include <iostream>


// Constructor
Synth::Synth() :
    currentSample(0),
    frequency(440.0),
    octave(0),
    waveType(WaveType::SINE)
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

std::string Synth::getWaveType()
{
    switch (waveType) {
        case WaveType::SINE:
            return "SINE";
        case WaveType::SQUARE:
            return "SQUARE";
        case WaveType::TRIANGLE:
            return "TRIANGLE";
        case WaveType::SAWTOOTH:
            return "SAWTOOTH";
        default:
            return "UNKNOWN";
    }
}

// Go up an octave
void Synth::octaveUp()
{
    if (octave < 4) {
        octave++;
    }
}

// Go down an octave
void Synth::octaveDown()
{
    if (octave > -3) {
        octave--;
    }
}

// Turn on a note (add a voice)
// This allows for polyphony
void Synth::noteOn(double freq)
{
    double adjustedFreq = freq * std::pow(2.0, octave);
    if (activeVoices.find(adjustedFreq) == activeVoices.end())
    {
        activeVoices[adjustedFreq] = {adjustedFreq, waveType, 0.0};
    }
}

// Turn off the note (remove a voice)
void Synth::noteOff(double freq)
{
    double adjustedFreq = freq * std::pow(2.0, octave);
    activeVoices.erase(adjustedFreq);
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

// Load sample for voice
double Synth::generateSample(Voice &voice, double time)
{
    double sampleValue = 0.0;

    switch (voice.waveType)
    {
        case WaveType::SINE:
            sampleValue = sineWave(time, voice.frequency);
            break;
        case WaveType::SQUARE:
            sampleValue = squareWave(time, voice.frequency);
            break;
        case WaveType::SAWTOOTH:
            sampleValue = sawtoothWave(time, voice.frequency);
            break;
        case WaveType::TRIANGLE:
            sampleValue = triangleWave(time, voice.frequency);
            break;
    }

    return sampleValue;
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
        double sampleValue = 0.0;

        for (auto& [freq, voice] : activeVoices)
        {
            sampleValue += generateSample(voice, time);
        }

        samples[i] = static_cast<sf::Int16>(sampleValue / activeVoices.size());

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
