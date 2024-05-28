//
// Created by Daniel Bartolini on 5/25/24.
//

#ifndef SINE_WAVE_OSCILLATOR_SYNTH_H
#define SINE_WAVE_OSCILLATOR_SYNTH_H

#include <SFML/Audio.hpp>
#include <vector>
#include <map>

enum class WaveType { SINE, SQUARE, TRIANGLE, SAWTOOTH };

struct Voice
{
    double frequency;
    WaveType waveType;
    double currentPhase;
};

class Synth : public sf::SoundStream
{
public:
    Synth();
    ~Synth();

    int octave;

    // Octave shifting functions
    void octaveUp();
    void octaveDown();

    // Waveform Selector function
    void setWaveType(WaveType type);

    // Polyphonic (multiple-note) handling
    void noteOn(double freq);
    void noteOff(double freq);

    void setFrequency(double freq);

    // Getter functions
    int getOctave();
    std::string getWaveType();


protected:
    virtual bool onGetData(Chunk& data) override;
    virtual void onSeek(sf::Time timeOffset) override;

private:
    double generateSample(Voice& voice, double time);

    std::vector<sf::Int16> samples;

    unsigned int currentSample;
    WaveType waveType;

    double frequency; // Lose this?

    std::map<double, Voice> activeVoices;
};

#endif //SINE_WAVE_OSCILLATOR_SYNTH_H
