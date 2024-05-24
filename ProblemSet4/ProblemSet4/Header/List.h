
// COS30008, Problem Set 4, 2024

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include <cstddef> // for size_t
#include <iostream>

template <typename T>
class List
{
private:
    using Node = typename DoublyLinkedList<T>::Node;

    Node fHead;   // first element
    Node fTail;   // last element
    size_t fSize; // number of elements

public:
    using Iterator = DoublyLinkedListIterator<T>;

    List() noexcept : fHead(nullptr), fTail(nullptr), fSize(0) {} // default constructor

    // copy constructor
    List(const List &aOther) : fHead(nullptr), fTail(nullptr), fSize(0)
    {
        for (Node nodeIndex = aOther.fHead; nodeIndex; nodeIndex = nodeIndex->fNext)
        {
            push_back(nodeIndex->fData);
        }
    }

    // copy assignment
    List &operator=(const List &aOther)
    {
        if (this != &aOther)
        {
            List temp(aOther);
            swap(temp);
        }
        return *this;
    }

    // move constructor
    List(List &&aOther) noexcept : fHead(std::move(aOther.fHead)), fTail(std::move(aOther.fTail)), fSize(aOther.fSize)
    {
        aOther.fSize = 0;
        aOther.fHead = nullptr;
        aOther.fTail = nullptr;
    }

    // move assignment
    List &operator=(List &&aOther) noexcept
    {
        if (this != &aOther)
        {
            fHead = std::move(aOther.fHead);
            fTail = std::move(aOther.fTail);
            fSize = aOther.fSize;
            aOther.fSize = 0;
            aOther.fHead = nullptr;
            aOther.fTail = nullptr;
        }
        return *this;
    }

    void swap(List &aOther) noexcept
    {
        std::swap(fHead, aOther.fHead);
        std::swap(fTail, aOther.fTail);
        std::swap(fSize, aOther.fSize);
    }

    size_t size() const noexcept
    {
        return fSize;
    }

    template <typename U>
    void push_front(U &&aData)
    {
        Node tempNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        if (fHead)
        {
            tempNode->fNext = fHead;
            fHead->fPrevious = tempNode;
        }
        else
        {
            fTail = tempNode;
        }
        fHead = tempNode;
        ++fSize;
    }

    template <typename U>
    void push_back(U &&aData)
    {
        Node tempNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));
        if (fTail)
        {
            tempNode->fPrevious = fTail;
            fTail->fNext = tempNode;
        }
        else
        {
            fHead = tempNode;
        }
        fTail = tempNode;
        ++fSize;
    }

    void remove(const T &aElement) noexcept
    {
        for (Node nodeIndex = fHead; nodeIndex; nodeIndex = nodeIndex->fNext)
        {
            if (nodeIndex->fData == aElement)
            {
                if (nodeIndex == fHead)
                {
                    fHead = nodeIndex->fNext;
                    if (fHead)
                    {
                        fHead->fPrevious.reset();
                    }
                    else
                    {
                        fTail.reset();
                    }
                }
                else if (nodeIndex == fTail)
                {
                    fTail = nodeIndex->fPrevious.lock();
                    if (fTail)
                    {
                        fTail->fNext.reset();
                    }
                    else
                    {
                        fHead.reset();
                    }
                }
                else
                {
                    nodeIndex->isolate();
                }
                --fSize;
                return;
            }
        }
    }

    const T &operator[](size_t aIndex) const
    {
        Node tempNode = fHead;
        for (size_t i = 0; i < aIndex; ++i)
        {
            tempNode = tempNode->fNext;
        }
        return tempNode->fData;
    }

    Iterator begin() const noexcept
    {
        return Iterator(fHead, fTail).begin();
    }

    Iterator end() const noexcept
    {
        return Iterator(fHead, fTail).end();
    }

    Iterator rbegin() const noexcept
    {
        return Iterator(fHead, fTail).rbegin();
    }

    Iterator rend() const noexcept
    {
        return Iterator(fHead, fTail).rend();
    }
};
