#include "Ring.h"

template <class T, int size>
Ring<T, size>::Ring(std::initializer_list<T> &&elements)
{
    assert(elements.size() == size);

    int i = 0;
    for (auto e : elements)
    {
        _ring[i] = e;
        i += 1;
    }
}

template <class T, int size>
void Ring<T, size>::RotateDown()
{
    _current = (_current == 0) ? size - 1 : _current - 1;
}

template <class T, int size>
void Ring<T, size>::RotateUp()
{
    _current = (_current == size - 1) ? 0 : _current + 1;
}

template <class T, int size>
T Ring<T, size>::Get()
{
    return _ring[_current];
}

template <class T, int size>
void Ring<T, size>::Set(T elem)
{
    _ring[_current] = elem;
}

template <class T, int size>
void Ring<T, size>::Set(int index, T elem)
{
    assert(index >= 0 && index < size);
    _ring[index] = elem;
}
