#ifndef SAW_DOWN_OSC_H_
#define SAW_DOWN_OSC_H_

#include "Oscillator.h"

class SawDownOscillator : public Oscillator
{
    public:
        SawDownOscillator(float frequency, float amplitude);
        SawDownOscillator(float frequency, float amplitude, int sampleRate);

        virtual float NextSample();

        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude);
        virtual std::shared_ptr<Oscillator> Clone(float frequency, float amplitude, int sampleRate);
};

#endif // SAW_DOWN_OSC_H_
