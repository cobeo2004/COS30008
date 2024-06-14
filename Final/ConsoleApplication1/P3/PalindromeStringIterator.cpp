
// COS30008, Final Exam, 2024

#include "PalindromeStringIterator.h"

void PalindromeStringIterator::moveToNextIndex()
{
	// 3a
	while (fIndex < fString.length() && !std::isalpha(fString[fIndex]))
	{
		++fIndex;
	}
}

void PalindromeStringIterator::moveToPreviousIndex()
{
	while (fIndex != std::string::npos && !std::isalpha(fString[fIndex]))
	{
		if (fIndex == 0)
			fIndex == std::string::npos;
		else
			--fIndex;
	}
}

PalindromeStringIterator::PalindromeStringIterator(const std::string &aString) : fString(aString), fIndex(0)
{
	moveToNextIndex();
}

char PalindromeStringIterator::operator*() const noexcept
{
	return std::toupper(fString[fIndex]);
}

PalindromeStringIterator &PalindromeStringIterator::operator++() noexcept
{
	++fIndex;
	moveToNextIndex();
	return *this;
}

PalindromeStringIterator PalindromeStringIterator::operator++(int) noexcept
{
	PalindromeStringIterator old = *this;

	++(*this);

	return old;
}

PalindromeStringIterator &PalindromeStringIterator::operator--() noexcept
{
	if (fIndex == 0)
		fIndex = std::string::npos;
	else
	{
		--fIndex;
		moveToPreviousIndex();
	}
	return *this;
}

PalindromeStringIterator PalindromeStringIterator::operator--(int) noexcept
{
	PalindromeStringIterator old = *this;

	--(*this);

	return old;
}

bool PalindromeStringIterator::operator==(const PalindromeStringIterator &aOther) const noexcept
{
	return fIndex == aOther.fIndex;
}

bool PalindromeStringIterator::operator!=(const PalindromeStringIterator &aOther) const noexcept
{
	return !(*this == aOther);
}

PalindromeStringIterator PalindromeStringIterator::begin() const noexcept
{
	PalindromeStringIterator lIter(fString);
	lIter.fIndex = 0;
	lIter.moveToNextIndex();
	return lIter;
}

PalindromeStringIterator PalindromeStringIterator::end() const noexcept
{
	PalindromeStringIterator lIter(fString);
	lIter.fIndex = fString.length();
	return lIter;
}

PalindromeStringIterator PalindromeStringIterator::rbegin() const noexcept
{
	PalindromeStringIterator lIter(fString);
	lIter.fIndex = fString.length() - 1;
	lIter.moveToPreviousIndex();
	return lIter;
}

PalindromeStringIterator PalindromeStringIterator::rend() const noexcept
{
	PalindromeStringIterator lIter(fString);
	lIter.fIndex = std::string::npos;
	return lIter;
}
