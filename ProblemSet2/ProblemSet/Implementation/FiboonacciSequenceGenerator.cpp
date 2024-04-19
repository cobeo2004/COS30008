#include "FibonacciSequenceGenerator.h"
#include <stdexcept>
#include <climits>
FibonacciSequenceGenerator::FibonacciSequenceGenerator(const std::string& aID) noexcept : fID(aID), fPrevious(0), fCurrent(1) {

}

const std::string& FibonacciSequenceGenerator::id() const noexcept {
	return this->fID;
}

const long long& FibonacciSequenceGenerator::operator*() const noexcept {
	return this->fCurrent;
}

FibonacciSequenceGenerator::operator bool() const noexcept {
	return this->hasNext();
}

void FibonacciSequenceGenerator::reset() noexcept {
	this->fPrevious = 0;
	this->fCurrent = 1;
}

bool FibonacciSequenceGenerator::hasNext() const noexcept {
	return this->fCurrent >= 0 && this->fCurrent + this->fPrevious < LLONG_MAX ;
}

void FibonacciSequenceGenerator::next() noexcept {
	if (!this->hasNext())
		throw std::overflow_error("Fibonacci sequence overflow");
	long long next = this->fCurrent + this->fPrevious;
	this->fPrevious = fCurrent;
	this->fCurrent = next;

}