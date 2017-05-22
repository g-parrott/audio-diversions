#ifndef SQR_OSC_H_
#define SQR_OSC_H_

#include "Oscillator.h"

class SquareOscillator : Oscillator
{
    public:
        SquareOscillator(float frequency, float amplitude);
        SquareOscillator(float frequency, float amplitude, int sampleRate);

        virtual float NextSample();

        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude);
        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate);
};

#endif // SQR_OSC_H_
