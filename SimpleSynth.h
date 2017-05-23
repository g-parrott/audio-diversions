#ifndef SIMPLE_SYNTH_H_
#define SIMPLE_SYNTH_H_

#include "AudioSystem.h"
#include "OscillatorIncludes.h"
#include "OscType.h"

#include <vector>
#include <map>
#include <memory>

// additive synth
class SimpleSynth
{
    private:
        int _sampleRate {44100};

        int _channels {1};

        int _sampleCount {1024};


        std::map<OscType, std::unique_ptr<Oscillator>> _oscillatorFactory;


        std::vector<std::shared_ptr<Oscillator>> _oscs;

    public:
        SimpleSynth();

        SimpleSynth(int sampleRate);

        SimpleSynth(int sampleRate, Uint8 channels);

        SimpleSynth(int sampleRate, Uint8 channels, Uint16 sampleSize);


        int AddOscillator(OscType type);


        void SetFrequency(int oscId, float frequency);

        void SetFrequencyAll(float frequency);

        void SetAmplitude(int oscId, float amplitude);

        void SetAmplitudeAll(float amplitude);


        std::vector<float> GetSamples(float secs, float frequency, float amplitude);

        std::vector<float> GetSamples(float secs);

        void GetSamples(float secs, float frequency, float amplitude, std::vector<float> &out);

        void GetSamples(float secs, std::vector<float> &out);
};

#endif // SIMPLE_SYNTH_H_
