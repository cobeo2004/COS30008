// COS30008, Final Exam, 2024

#pragma once

#include <optional>
#include <cassert>

#include <iostream>

template <typename T>
class DynamicQueue
{
private:
    T *fElements;
    size_t fFirstIndex;
    size_t fLastIndex;
    size_t fCurrentSize;

    void resize(size_t aNewSize)
    {
        T *lNewElm = new T[aNewSize];
        size_t lNewLastIndex = 0;
        for (size_t i = fFirstIndex; i < fLastIndex; ++i)
        {
            lNewElm[lNewLastIndex++] = fElements[i];
        }

        delete[] fElements;
        fElements = lNewElm;
        fFirstIndex = 0;
        fLastIndex = lNewLastIndex;
        fCurrentSize = aNewSize;
    }
    void ensure_capacity()
    {
        if (fLastIndex == fCurrentSize)
            resize(std::max(size_t(1), fCurrentSize * 2));
    }
    void adjust_capacity()
    {
        if (fLastIndex - fFirstIndex <= fCurrentSize / 4)
            resize(fCurrentSize / 2);
    }

public:
    DynamicQueue() : fElements(nullptr), fFirstIndex(0), fLastIndex(0), fCurrentSize(0) {}
    ~DynamicQueue()
    {
        delete[] fElements;
    }

    DynamicQueue(const DynamicQueue &) = delete;
    DynamicQueue &operator=(const DynamicQueue &) = delete;

    std::optional<T> top() const noexcept
    {
        if (fFirstIndex < fLastIndex)
            return fElements[fFirstIndex];
        return std::nullopt;
    }
    void enqueue(const T &aValue)
    {
        ensure_capacity();
        fElements[fLastIndex++] = aValue;
    }
    void dequeue()
    {
        if (fFirstIndex < fLastIndex)
        {
            fFirstIndex++;
            adjust_capacity();
        }
    }
};
