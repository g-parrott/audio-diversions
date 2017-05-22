#include "SawDownOscillator.h"

SawDownOscillator::SawDownOscillator(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
}

SawDownOscillator::SawDownOscillator(float frequency, float amplitude, int sampleRate) : Oscillator(frequency, amplitude, sampleRate)
{
}

float SawDownOscillator::NextSample()
{
    float sample = (-(_amp / (M_PI * 2)) * _phase) + _amp;

    IncrementPhase();

    return sample;
}

std::shared_ptr<Oscillator> Clone(float frequency, float amplitude)
{
    return std::shared_ptr<Oscillator>(new SawDownOscillator(frequency, amplitude));
}

std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate)
{
    return std::shared_ptr<Oscillator>(new SawDownOscillator(frequency, amplitude, sampleRate));
}
