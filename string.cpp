#include "String.h"

// constructor without parameter
String::String() {
    str_ = nullptr;
}

// constructor with char* parameter
String::String(const char* str) {
    int length = charLength(str);
    str_ = new char[length + 1];
    charCopy(str_, str);  // copy new string into member
    length_ = length;
}

// constructor with String object parameter
String::String(const String& other) {
    length_ = other.length_;
    str_ = new char[length_ + 1]; // +1 for \0
    charCopy(str_, other.c_str()); // copy new string into member
}

// destructor
String::~String() {
    delete[] str_;
}

// assignment operator
String& String::operator=(const String& other) {
    if (this == &other) {
        return *this; // same object: dont do anything
    }

    delete[] str_; //free old space
    length_ = other.length_;
    str_ = new char[length_ + 1];
    charCopy(str_, other.str_);

    return *this;
}

// move constructor
String::String(String&& other) noexcept
{
    str_ = other.str_;
    other.str_ = nullptr; // nullify the other object resource
}

// move assignment operator
String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str_; // free existing resource
        str_ = other.str_; // transfer ownership
        other.str_ = nullptr; // nullify source
    }
    return *this;
}

// overwrite destination with toCopy
// copy toCopy into destination
// add null termination character at the end of toCopy in destination
void String::charCopy(char* destination, const char* toCopy) {
    int i = 0;
    while(toCopy[i] != '\0') {
        destination[i] = toCopy[i];
        ++i;
    }
    destination[i] = 0;
}

// m_str getter
const char* String::c_str() const {
    return str_;
}

// m_length getter
int String::length() const {
    return length_;
}

// iterate through passed char* to determine length
int String::charLength(const char* charArray) {
    int i = 0;
    while(charArray[i] != '\0') {
        ++i;
    }
    return i;
}

// append function with one argument
// used in append template functions
void String::append_single(const char* stringToAppend) {
    if(stringToAppend == nullptr){
        return;
    }
    if(str_ == nullptr){
        str_ = new char[1];
        charCopy(str_, stringToAppend);
        return;
    }
    // determine how long newStr has to be
    int appendLength = charLength(stringToAppend);
    char* newStr = new char[length_ + appendLength + 1];  // +1 for \0 string termination

    // copy old string into new
    charCopy(newStr, str_);

    // append new string to it
    charCopy(newStr + length_, stringToAppend);

    // free old space to set to new string
    delete[] str_;
    str_ = newStr;
    length_ += appendLength;
}

// append using String object
void String::append_single(const String& stringToAppend) {
    append_single(stringToAppend.c_str());
}
