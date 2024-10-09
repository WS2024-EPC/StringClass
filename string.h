#ifndef STRING_CLASS_STRING_H
#define STRING_CLASS_STRING_H
#endif

#include <iostream>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
namespace mystring{
    class String {
    public:
        String();
        String(const char* str); // not explicit to allow implicit conversion from char* to String
        String(const String& other);
        String(String&& other) noexcept ;
        ~String();

        struct Iterator{
            using iterator_category = std::forward_iterator_tag; //Scan container forward multiple times, read and write value it points to!
            using difference_type = std::ptrdiff_t; //signed int to identify distance between iterator steps
            using value_type = char; //data type of one single thang (what it iterates over, single char in this case)
            using pointer = char*;
            using reference = char&;

            Iterator(pointer ptr) : m_ptr(ptr) {} //initialize m_ptr, points to an element
            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }

            // Prefix increment
            Iterator& operator++() { m_ptr++; return *this; } //Gibt inkrementierten iterator zurück!

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; } //Gibt urpsprüngliches zurück, aber danach is es inkrementiert ( auch bei --)

            // Prefix decrement
            Iterator& operator--() { m_ptr--; return *this; }

            // Postfix decrement
            Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
            //TODO: also implement --, begin, end, stl::find, check if this works ^

        private:
            pointer m_ptr;
        };
        Iterator begin();
        Iterator end();

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
}

