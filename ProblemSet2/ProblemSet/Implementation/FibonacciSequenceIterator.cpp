#include "FibonacciSequenceIterator.h"


FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequenceGenerator& aSequenceObject, long long aStart) noexcept : fSequenceObject(aSequenceObject), fIndex(aStart) {
	fSequenceObject.reset();
	for (int i = 0; i <= aStart; i++)
		fSequenceObject.next();
}

const long long& FibonacciSequenceIterator::operator*() const noexcept {
	return *fSequenceObject;
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept {
	++fIndex;
	fSequenceObject.next();
	return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept {
	FibonacciSequenceIterator temp = *this;
	++(*this);
	return temp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept {
	return fIndex == aOther.fIndex && fSequenceObject.id() == aOther.fSequenceObject.id();
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const noexcept {
	return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept {
	FibonacciSequenceIterator temp = *this;
	temp.fIndex = 0;
	temp.fSequenceObject.reset();
	return temp;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept {
	FibonacciSequenceIterator temp = *this;
	temp.fIndex = 92;
	return temp;
}
