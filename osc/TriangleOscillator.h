#ifndef TRIANGLE_OSC_H_
#define TRIANGLE_OSC_H_

#include "Oscillator.h"

class TriangleOscillator : public Oscillator
{
    public:
        TriangleOscillator(float frequency, float amplitude);
        TriangleOscillator(float frequency, float amplitude, int sampleRate);

        virtual float NextSample();

        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude);
        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate);
};

#endif // TRIANGLE_OSC_H_
