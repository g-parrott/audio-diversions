#ifndef OSC_H_
#define OSC_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include <cmath>

#include <vector>

#define _USE_MATH_DEFINES

class Oscillator {
  private:
    float _phase {0.f};
    float _increment {0.f};
    float _freq {0.f};
    float _amp {0.f};

    int _sampleRate {44100};

  public:
    Oscillator(float frequency, float amplitude);
    Oscillator(float frequency, float amplitude, int sampleRate);

    void FillBuffer(std::vector<float> &buffer);

    virtual float NextSample() = 0;
};

#endif // OSC_H_
