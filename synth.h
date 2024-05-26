//
// Created by Daniel Bartolini on 5/25/24.
//

#ifndef SINE_WAVE_OSCILLATOR_SYNTH_H
#define SINE_WAVE_OSCILLATOR_SYNTH_H

#include <SFML/Audio.hpp>
#include <vector>

enum class WaveType { SINE, SQUARE, TRIANGLE, SAWTOOTH };

class Synth : public sf::SoundStream
{
public:
    Synth();
    ~Synth();
    void setFrequency(double freq);
    void setWaveType(WaveType type);

private:
    virtual bool onGetData(Chunk& data) override;
    virtual void onSeek(sf::Time timeOffset) override;

    std::vector<sf::Int16> samples;
    unsigned currentSample;
    double frequency;
    WaveType waveType;

};

#endif //SINE_WAVE_OSCILLATOR_SYNTH_H
