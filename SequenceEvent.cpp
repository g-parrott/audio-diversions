#include "SequenceEvent.h"

SequenceEvent::SequenceEvent(float frequency, float amplitude, float secs, std::array<int, 3> &tag)
{
    _frequency = frequency;
    _amplitude = amplitude;
    _secs = secs;

    _tag[0] = tag[0];
    _tag[1] = tag[1];
    _tag[2] = tag[2];
}

SequenceEvent::SequenceEvent(float frequency, float amplitude, float secs, int t1, int t2, int t3)
{
    _frequency = frequency;
    _amplitude = amplitude;
    _secs = secs;

    _tag[0] = t1;
    _tag[1] = t2;
    _tag[2] = t3;
}

float SequenceEvent::Frequency()
{
    return _frequency;
}

float SequenceEvent::Amplitude()
{
    return _amplitude;
}

float SequenceEvent::Seconds()
{
    return _secs;
}

const std::array<int, 3> &SequenceEvent::Tag()
{
    return _tag;
}
