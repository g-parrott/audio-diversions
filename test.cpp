#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

int main() {
  SDL_Init(SDL_INIT_AUDIO);

  // get the first non-capture audio device
  auto devName = SDL_GetAudioDeviceName(0, 0);

  SDL_AudioSpec want, have;
  SDL_AudioDeviceID dev;
  SDL_zero(want);

  want.freq = 48000;
  want.format = AUDIO_F32;
  want.channels = 1;
  want.samples = 4096;
  want.callback = NULL;

  dev = SDL_OpenAudioDevice(devName, 0, &want, &have, 0);

  if (dev == 0) {
    cout << "Could not open device" << std::endl;
  }

  const int sr = 48000;
  float data[sr];
  float waveFreq = 440.f;
  float phase = 0.f;
  float increment = waveFreq * M_PI * 2 / static_cast<float>(sr);
  float amp = 0.3f;

  for (int i = 0; i < sr; i += 1) {
    data[i] = amp * std::sin(phase);

    if (phase >= M_PI * 2) {
      phase -= M_PI * 2;
    }

    if (phase < 0 ) {
      phase += M_PI * 2;
    }

    phase += increment;
  }

  phase = 0.f;

  amp = 0.1f;
  waveFreq = 440.f*1.5f;

  increment = (waveFreq * M_PI * 2) / static_cast<float>(sr);

  for (int i = 0; i < sr; i += 1) {
    if (phase >= 0 && phase < M_PI) {
      data[i] += amp;
    }

    else if (phase >= M_PI && phase < M_PI * 2) {
      data[i] += -amp;
    }

    if (phase >= M_PI * 2) {
      phase -= M_PI * 2;
    }

    if (phase < 0) {
      phase += M_PI * 2;
    }
    phase += increment;
  }

  waveFreq = 440.f / 1.5f;
  increment = (waveFreq * M_PI * 2) / static_cast<float>(sr);
  phase = 0.0f;
  amp = 0.3f;

  for (int i = 0; i < sr; i += 1) {
    data[i] *= amp * std::cos(phase);

    if (phase >= M_PI * 2) {
      phase -= M_PI * 2;
    }

    if (phase < 0) {
      phase += M_PI * 2;
    }

    phase += increment;
  }

  SDL_QueueAudio(dev, data, sizeof(float) * sr);

  SDL_PauseAudioDevice(dev, 0);

  SDL_Delay(5000);

  SDL_CloseAudioDevice(dev);

  SDL_Quit();

  return 0;
}
