#include "Oscillator.h"

Oscillator::Oscillator(float frequency, float amplitude)
{
    _freq = frequency;
    _amp = amplitude;

    _increment = (M_PI * 2 * _freq) / static_cast<float>(_sampleRate);
}

Oscillator::Oscillator(float frequency, float amplitude, int sampleRate)
{
    _freq = frequency;
    _amp = amplitude;
    _sampleRate = sampleRate;

    _increment = (M_PI * 2 * _freq) / static_cast<float>(_sampleRate);
}

void Oscillator::FillBuffer(std::vector<float> &buffer)
{
    for (size_t i = 0; i < buffer.size(); i += 1)
    {
        buffer[i] = NextSample();
    }
}
