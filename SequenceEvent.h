#ifndef SEQ_EVENT_H_
#define SEQ_EVENT_H_

#include <memory>
#include <array>

class SequenceEvent
{
    private:
        float _frequency;

        float _amplitude;

        float _secs;

        std::array<int, 3> _tag;
    public:
        SequenceEvent(float frequency, float amplitude, float secs, std::array<int, 3> &tag);

        SequenceEvent(float frequency, float amplitude, float secs, int t1, int t2, int t3);

        float Frequency();

        float Amplitude();

        float Seconds();

        const std::array<int, 3> &Tag();
};

#endif // SEQ_EVENT_H_
