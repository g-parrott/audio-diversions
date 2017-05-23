#ifndef SINE_OSC_H_
#define SINE_OSC_H_

#include "Oscillator.h"

class SineOscillator : public Oscillator
{
    public:
        SineOscillator(float frequency, float amplitude);
        SineOscillator(float frequency, float amplitude, float sampleRate);

        virtual float NextSample();

        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude);
        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate);
};

#endif // SINE_OSC_H_
