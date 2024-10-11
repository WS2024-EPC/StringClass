#ifndef STRING_CLASS_STRING_H
#define STRING_CLASS_STRING_H
#endif

#include <iostream>
#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

namespace mystring {
    class String {
    public:
        String();
        String(const char* str); // not explicit to allow implicit conversion from char* to String
        String(const String& other);
        String(String&& other) noexcept ;
        ~String();

        struct Iterator {
            using iterator_category = std::forward_iterator_tag; // scan container forward multiple times, read and write value it points to!
            using difference_type = std::ptrdiff_t; // signed int to identify distance between iterator steps
            using value_type = char; // data type of one single thang (what it iterates over, single char in this case)
            using pointer = char*;
            using reference = char&;

            Iterator(pointer ptr) : m_ptr(ptr) {} // initialize m_ptr, points to an element
            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }

            // Prefix increment; returns incremented iterator
            Iterator& operator++() {
                ++m_ptr;
                return *this;
            }

            // Postfix increment; returns original value, but still increments
            Iterator operator++(int) {
                Iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            // Prefix decrement
            Iterator& operator--() {
                --m_ptr;
                return *this;
            }

            // Postfix decrement
            Iterator operator--(int) {
                Iterator tmp = *this;
                --(*this);
                return tmp;
            }

            bool operator==(const Iterator& other) const { return m_ptr == other.m_ptr; }
            bool operator!=(const Iterator& other) const { return m_ptr != other.m_ptr; }

        private:
            pointer m_ptr;
        };

        Iterator begin() const;
        Iterator end() const;

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

