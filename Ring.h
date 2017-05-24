#ifndef RING_H_
#define RING_H_

#include <array>
#include <cassert>

template <class T, int size>
class Ring
{
    private:
        std::array<T, size> _ring;

        int _current;

    public:
        Ring(std::initializer_list<T> &&elements);

        void RotateDown();

        void RotateUp();

        T Get();

        void Set(T elem);

        void Set(int index, T elem);
};

#endif // RING_H_
