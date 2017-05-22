#include "Oscillator.h"

void Oscillator::IncrementPhase()
{
    _phase += _increment;

    if (_phase >= M_PI * 2)
    {
        _phase -= M_PI * 2;
    }

    else if (_phase < 0)
    {
        _phase += M_PI * 2;
    }
}

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

void Oscillator::SetFrequency(float frequency)
{
    _freq = frequency;
    _increment = (M_PI * 2 * _freq) / static_cast<float>(_sampleRate);
}

void Oscillator::FillBuffer(std::vector<float> &buffer, int channels)
{
    float sample = 0;
    for (size_t i = 0; i < buffer.size(); i += 1)
    {
        if (i % channels == 0)
        {
            sample = NextSample();
        }
        buffer[i] = sample;
    }
}
