#include "SineOscillator.h"

SineOscillator::SineOscillator(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
}

SineOscillator::SineOscillator(float frequency, float amplitude, float sampleRate) : Oscillator(frequency, amplitude, sampleRate)
{
}

float SineOscillator::NextSample()
{
    float sample = _amp * std::sin(_phase);

    IncrementPhase();

    return sample;
}

std::shared_ptr<Oscillator> SineOscillator::Clone(float frequency, float amplitude)
{
    return std::shared_ptr<Oscillator>(new SineOscillator(frequency, amplitude));
}

std::shared_ptr<Oscillator> SineOscillator::Clone(float frequency, float amplitude, int sampleRate)
{
    return std::shared_ptr<Oscillator>(new SineOscillator(frequency, amplitude, sampleRate));
}
