#include "SquareOscillator.h"

SquareOscillator::SquareOscillator(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
}

SquareOscillator::SquareOscillator(float frequency, float amplitude, int sampleRate) : Oscillator(frequency, amplitude, sampleRate)
{
}

float SquareOscillator::NextSample()
{
    float sample = 0;
    if (_phase <= M_PI)
    {
        sample = _amp;
    }

    else if (_phase > M_PI)
    {
        sample = -_amp;
    }

    IncrementPhase();

    return sample;
}

std::shared_ptr<Oscillator> SquareOscillator::Clone(float frequency, float amplitude)
{
    return std::shared_ptr<Oscillator>(new SquareOscillator(frequency, amplitude));
}

std::shared_ptr<Oscillator> SquareOscillator::Clone(float frequency, float amplitude, int sampleRate)
{
    return std::shared_ptr<Oscillator>(new SquareOscillator(frequency, amplitude, sampleRate));
}
