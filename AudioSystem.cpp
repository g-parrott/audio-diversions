#include "AudioSystem.h"

// for printf on errors
#include <cstdio>

AudioSystem::AudioSystem(int sampleRate, Uint8 channels, Uint16 sampleSize)
{
    SDL_Init(SDL_INIT_AUDIO);

    _deviceName = SDL_GetAudioDeviceName(0, 0);

    _sampleRate = sampleRate;
    _channels = channels;
    _sampleSize = sampleSize;

    SDL_AudioSpec want, have;
    SDL_zero(want);

    want.freq = sampleRate;
    want.format = format;
    want.channels = channels;
    want.samples = sampleSize;

    _deviceId = SDL_OpenAudioDevice(_deviceName.c_str(), 0, &want, &have, 0);

    if (_deviceId == 0)
    {
        fprintf(stderr, "AudioSystemError: Could not open device %s\n", _deviceName.c_str());
    }
}

AudioSystem::AudioSystem()
{
    AudioSystem(_sampleRate, _channels, _sampleSize);
}

AudioSystem::~AudioSystem()
{
    SDL_CloseAudioDevice(_deviceId);
    SDL_Quit();
}

void AudioSystem::Start()
{
    SDL_PauseAudioDevice(_deviceId, 0);
}

void AudioSystem::Stop()
{
    SDL_PauseAudioDevice(_deviceId, 1);
}

void AudioSystem::TogglePause()
{
    _paused = (_paused == 0) ? 1 : 0;
    SDL_PauseAudioDevice(_deviceId, _paused);
}

void AudioSystem::QueueSamples(std::vector<float> &samples)
{
    SDL_QueueAudio(_deviceId, &samples, sizeof(float) * samples.size());
}
