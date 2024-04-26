//Neccessary libraries, where cassert for assert() and cctype for isalpha() and toupper()
#include "KeyProvider.h"
#include <cctype> 
#include <cassert>

/*
* The function preprocessString will take in a string and returns a new string
* (Exceptions for Non-alphabetic characters) that contains the word in uppercase
* @param aString (const std::string&): The given string
* @return std::string: New string in uppercase and no non-alphabetic characters
*/
std::string KeyProvider::preprocessString(const std::string& aString) noexcept
{
    //Declare a string for storing characters
    std::string result;
    //Loop through each characters on the given string
    for (const char c : aString)
    {
        if (std::isalpha(c))
            //If that character is alphabetic -> push_back that characters
            //(In uppercase) to the result string
            result.push_back(std::toupper(c));
    }
    //Return the string
    return result;
}

/*
* Constructor of KeyProvider class, which will also be used for comptuing keyword sequnce
* based on the input text. In addition, this function must guarantee that the size of fKeys
* must match with the inputted phrase
* @param aKeyword (const std::string&): The keyword
* @param aSource (const std::string&): The source phrase
* @return void
*/
KeyProvider::KeyProvider(const std::string& aKeyword, const std::string& aSource) noexcept
    : fIndex(0)
{
    //Uppercase the keyword and the source phrase
    std::string processedKeyword = preprocessString(aKeyword);
    std::string processedSource = preprocessString(aSource);
    //Allocate more spaces in fKeys based on the size of processed source phrase
    fKeys.reserve(processedSource.size());
    
    //Get the size of processed keyword and source phrase
    size_t keywordLength = processedKeyword.size();
    size_t sourceLength = processedSource.size();
    
    //Here, 'i' will be the iterator for the source phrase
    //While 'j' will be the iterator for the keyword phrase
    size_t j = 0;
    for (size_t i = 0; i < sourceLength; i++)
    {
        //Loop through sourceLength.size() - 1 times, append the keyword in the length
        //of source phrase. For example, source: Me is Simon, keyword: abc -> fKeys: ABCABCABC
        if (j >= keywordLength)
            j = 0;
        fKeys.push_back(processedKeyword[j]);
        j++;
    }
    
    // Ensures fKeys is properly sized
    assert(fKeys.size() == sourceLength); 
}

/*
* Get the keyword character where the iterator is pointed on
* @param None
* @return char: The keyword character where the iterator is pointed on
*/
char KeyProvider::operator*() const noexcept
{
    assert(fIndex < fKeys.size()); // Prevent out-of-bounds access
    // The character at the fIndex
    return fKeys.at(fIndex);
}

/*
* Advance the iterator to one index and return the updated iterator
* @param None
* @return KeyProvider&: the updated iterator
*/
KeyProvider& KeyProvider::operator++() noexcept
{
    //Advance one index
    ++fIndex;
    //Return the updated iterator
    return *this;
}

/*
* Advance the iterator to one index and return the old iterator
* @param None
* @return KeyProvider&: the updated iterator
*/
KeyProvider KeyProvider::operator++(int) noexcept
{
    //Make a copy of old iterator
    KeyProvider temp = *this;
    //Using operator++() and return the old iterator
    ++(*this);
    return temp;
}

/*
* Return the equality of the underlying collection and the position of this
* object and other KeyProvider object
* @param aOther (const KeyProvider&): Other KeyProvider object
* @return bool: The equality between objects
*/
bool KeyProvider::operator==(const KeyProvider& aOther) const noexcept
{
    return fIndex == aOther.fIndex && fKeys == aOther.fKeys;
}

/*
* Return the in-equality of the underlying collection and the position of this
* object and other KeyProvider object
* @param aOther (const KeyProvider&): Other KeyProvider object
* @return bool: The in-equality between objects
*/
bool KeyProvider::operator!=(const KeyProvider& aOther) const noexcept
{
    return !(*this == aOther);
}

/*
* Return a copy of 'this' iterator object positioned in the first index of the string
* @param None
* @return KeyProvider: A copy of 'this' iterator at the first index
*/
KeyProvider KeyProvider::begin() const noexcept
{
    //Get a copy and set the index as 0
    KeyProvider temp = *this;
    temp.fIndex = 0;
    //Return the copy
    return temp;
}

/*
* Return a copy of 'this' iterator object positioned in the last index of the string
* @param None
* @return KeyProvider: A copy of 'this' iterator at the last index
*/
KeyProvider KeyProvider::end() const noexcept
{
    //Get a copy and set the index as the size of the keyword
    KeyProvider temp = *this;
    temp.fIndex = fKeys.size();
    //Return the copy
    return temp;
}
