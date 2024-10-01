#ifndef STRING_CLASS_STRING_H
#define STRING_CLASS_STRING_H
#endif

#include <iostream>

class String {
public:
    String();
    String(const char* str); // not explicit to allow implicit conversion from char* to String
    String(const String& other);
    String(String&& other) noexcept ;
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    String operator+(const String& other) const;
    String operator+(const char* other) const;
    String& operator+=(const String& other);
    String& operator+=(const char* other);

    operator const char*() const;

    static void charCopy(char* destination, const char* toCopy);
    static size_t charLength(const char* charArray);

    const char* c_str() const;
    size_t length() const;

    template<typename... Args>
    String& append(const char* first, Args... args);

    template<typename... Args>
    String& append(const String& first, Args... args);

private:
    char* str_; // dynamic size
    size_t length_ = 0;

    void append_single(const char* stringToAppend);
    void append_single(const String& stringToAppend);
};

template<typename... Args>
String& String::append(const char* first, Args... args) {
    append_single(first);
    (append_single(args), ...); // fold expression -> apply append_single to ever argument in args
    return *this;
}

template<typename... Args>
String& String::append(const String& first, Args... args) {
    append_single(first);
    (append_single(args), ...); // fold expression
    return *this;
}
