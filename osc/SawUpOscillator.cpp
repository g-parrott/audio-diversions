#include "SawUpOscillator.h"

SawUpOscillator::SawUpOscillator(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
}

SawUpOscillator::SawUpOscillator(float frequency, float amplitude, int sampleRate) : Oscillator(frequency, amplitude, sampleRate)
{
}

float SawUpOscillator::NextSample()
{
    float sample = (_amp / (M_PI * 2)) * _phase;

    IncrementPhase();

    return sample;
}

std::shared_ptr<Oscillator> Clone(float frequency, float amplitude)
{
    return std::shared_ptr<Oscillator>(new SawUpOscillator(frequency, amplitude));
}

std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate)
{
    return std::shared_ptr<Oscillator>(new SawUpOscillator(frequency, amplitude, sampleRate));
}
