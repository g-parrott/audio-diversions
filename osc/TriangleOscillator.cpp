#include "TriangleOscillator.h"

TriangleOscillator::TriangleOscillator(float frequency, float amplitude) : Oscillator(frequency, amplitude)
{
}

TriangleOscillator::TriangleOscillator(float frequency, float amplitude, int sampleRate) : Oscillator(frequency, amplitude, sampleRate)
{
}

float TriangleOscillator::NextSample()
{
    float sample = 0;

    if (_phase < M_PI)
    {
        sample = _amp * (_phase / M_PI);
    }

    else if (_phase >= M_PI)
    {
        sample = (-_amp) * (_phase / M_PI) + (_amp * M_PI);
    }

    IncrementPhase();

    return sample;
}

std::shared_ptr<Oscillator> TriangleOscillator::Clone(float frequency, float amplitude)
{
    return std::shared_ptr<Oscillator>(new TriangleOscillator(frequency, amplitude));
}

std::shared_ptr<Oscillator> TriangleOscillator::Clone(float frequency, float amplitude, int sampleRate)
{
    return std::shared_ptr<Oscillator>(new TriangleOscillator(frequency, amplitude, sampleRate));
}
