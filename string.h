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

    static void charCopy(char* destination, const char* toCopy);
    static int charLength(const char* charArray);

    const char* c_str() const;
    int length() const;

    template<typename... Args>
    String& append(const char* first, Args... args);

    template<typename... Args>
    String& append(const String& first, Args... args);

private:
    char* str_; // dynamic size
    int length_ = 0;

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
