#include "SimpleSynth.h"

SimpleSynth::SimpleSynth()
{
    SimpleSynth(_sampleRate);
}

SimpleSynth::SimpleSynth(int sampleRate) : _audioSystem(sampleRate, _channels, _sampleCount)
{
    SimpleSynth(sampleRate, _channels, _sampleCount);
}

SimpleSynth::SimpleSynth(int sampleRate, Uint8 channels) : _audioSystem(sampleRate, channels, _sampleCount)
{
    SimpleSynth(sampleRate, channels, _sampleCount);
}

SimpleSynth::SimpleSynth(int sampleRate, Uint8 channels, Uint16 sampleCount) : _audioSystem(sampleRate, channels, sampleCount)
{
    _sampleRate = sampleRate;
    _channels = channels;
    _sampleCount = sampleCount;

    _oscillatorFactory.insert({OscType::Sine,
                               std::unique_ptr<Oscillator>(new SineOscillator(0, 0))});

    _oscillatorFactory.insert({OscType::Square,
                               std::unique_ptr<Oscillator>(new SquareOscillator(0, 0))});

    _oscillatorFactory.insert({OscType::Triangle,
                               std::unique_ptr<Oscillator>(new TriangleOscillator(0, 0))});

    _oscillatorFactory.insert({OscType::SawUp,
                               std::unique_ptr<Oscillator>(new SawUpOscillator(0, 0))});

    _oscillatorFactory.insert({OscType::SawDown,
                               std::unique_ptr<Oscillator>(new SawDownOscillator(0, 0))});

    _oscs.reserve(64);
}

int SimpleSynth::AddOscillator(OscType type)
{
    _oscs.push_back(_oscillatorFactory[type]->Clone(0, 0));
    return _oscs.size() - 1;
}

void SimpleSynth::SetFrequency(int oscId, float frequency)
{
    _oscs[oscId]->SetFrequency(frequency);
}

void SimpleSynth::SetFrequencyAll(float frequency)
{
    for (auto o : _oscs)
    {
        o->SetFrequency(frequency);
    }
}

void SimpleSynth::SetAmplitude(int oscId, float amplitude)
{
    _oscs[oscId]->SetAmplitude(amplitude);
}

void SimpleSynth::SetAmplitudeAll(float amplitude)
{
    float amp = amplitude;
    for (auto o : _oscs)
    {
        o->SetAmplitude(amp);
        amp /= 2;
    }
}

std::vector<float> SimpleSynth::GetSamples(float secs, float frequency, float amplitude)
{
    size_t numSamples = static_cast<size_t>(secs * _sampleRate);
    std::vector<float> samples;
    samples.reserve(numSamples);

    SetFrequencyAll(frequency);
    SetAmplitudeAll(amplitude);

    float sample = 0;
    for (size_t i = 0; i < numSamples; i += 1)
    {
        for (auto o : _oscs)
        {
            sample += o->NextSample();
        }
        samples.push_back(sample);
        sample = 0;
    }

    return samples;
}

std::vector<float> SimpleSynth::GetSamples(float secs)
{
    size_t numSamples = static_cast<size_t>(secs * _sampleRate);
    std::vector<float> samples;

    float sample = 0;
    for (size_t i = 0; i < numSamples; i += 1)
    {
        for (auto o : _oscs)
        {
            sample += o->NextSample();
        }
        samples.push_back(sample);
        sample = 0;
    }

    return samples;
}

void SimpleSynth::GetSamples(float secs, float frequency, float amplitude, std::vector<float> &out)
{
    size_t numSamples = static_cast<size_t>(secs * _sampleRate);
    if (out.size() < numSamples)
    {
        out.resize(numSamples);
    }

    SetFrequencyAll(frequency);
    SetAmplitudeAll(amplitude);

    float sample = 0;
    for (size_t i = 0; i < numSamples; i += 1)
    {
        for (auto o : _oscs)
        {
            sample += o->NextSample();
        }
        out[i] = sample;
        sample = 0;
    }
}

void SimpleSynth::GetSamples(float secs, std::vector<float> &out)
{
    size_t numSamples = static_cast<size_t>(secs * _sampleRate);
    if (out.size() < numSamples)
    {
        out.resize(numSamples);
    }

    float sample = 0;
    for (size_t i = 0; i < numSamples; i += 1)
    {
        for (auto o : _oscs)
        {
            sample += o->NextSample();
        }
        out[i] = sample;
        sample = 0;
    }
}
