#include "String.h"

// constructor without parameter
String::String() {
    m_str = nullptr;
}

// constructor with char* parameter
String::String(const char* str) {
    int length = charLength(str);
    m_str = new char[length + 1];
    charCopy(m_str, str);  // copy new string into member
    m_length = length;
}

// constructor with String object parameter
String::String(const String& other) {
    m_length = other.m_length;
    m_str = new char[m_length + 1]; // +1 for \0
    charCopy(m_str, other.c_str()); // copy new string into member
}

// destructor
String::~String() {
    delete[] m_str;
}

// assignment operator
String& String::operator=(const String& other) {
    if (this == &other) {
        return *this; // same object: dont do anything
    }

    delete[] m_str; //free old space
    m_length = other.m_length;
    m_str = new char[m_length + 1];
    charCopy(m_str, other.m_str);

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
    return m_str;
}

// m_length getter
int String::length() const {
    return m_length;
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
    if(m_str == nullptr){
        m_str = new char[1];
        charCopy(m_str, stringToAppend);
        return;
    }
    // determine how long newStr has to be
    int appendLength = charLength(stringToAppend);
    char* newStr = new char[m_length + appendLength + 1];  // +1 for \0 string termination

    // copy old string into new
    charCopy(newStr, m_str);

    // append new string to it
    charCopy(newStr + m_length, stringToAppend);

    // free old space to set to new string
    delete[] m_str;
    m_str = newStr;
    m_length += appendLength;
}

// append using String object
void String::append_single(const String& stringToAppend) {
    append_single(stringToAppend.c_str());
}