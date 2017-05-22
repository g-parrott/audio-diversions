#ifndef SAW_UP_OSC_H_
#define SAW_UP_OSC_H_

#include "Oscillator.h"

class SawUpOscillator : Oscillator
{
    public:
        SawUpOscillator(float frequency, float amplitude);
        SawUpOscillator(float frequency, float amplitude, int sampleRate);

        virtual float NextSample();

        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude);
        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate);
};

#endif // SAW_UP_OSC_H_
