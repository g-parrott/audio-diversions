#ifndef AUDIO_SYSTEM_H_
#define AUDIO_SYSTEM_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include <string>
using std::string;

#include <vector>
using std::vector;

// encapsulation of SDL audio system using the SDL_QueueAudio method
class AudioSystem
{
    private:
        SDL_AudioDeviceID _deviceId;

        string _deviceName;

        int _sampleRate {44100};
        SDL_AudioFormat _format {AUDIO_F32};
        Uint8 _channels {1};
        Uint16 _sampleSize {1024};

        int _paused {1};
    public:
        AudioSystem(int sampleRate, Uint8 channels, Uint16 sampleSize);

        AudioSystem();

        ~AudioSystem();

        void Start();

        void Stop();

        void TogglePause();

        void QueueSamples(std::vector<float> &samples);
};

#endif // AUDIO_SYSTEM_H_
