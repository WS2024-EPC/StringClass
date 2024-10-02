//
// Created by Sara on 24/09/2024.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "string.h"
#include "vld.h"

TEST_CASE("Check operator+= with String") {
    mystring::String str1("Hello");
    mystring::String str2(" World");

    str1 += str2;
    CHECK(std::strcmp(str1, "Hello World") == 0);
    CHECK(str1.length() == 11);
}

TEST_CASE("Check operator+= with const char*") {
    mystring::String str1("Hello");

    str1 += " World";
    CHECK(std::strcmp(str1, "Hello World") == 0);
    CHECK(str1.length() == 11);
}

TEST_CASE("Check operator+ with String") {
    mystring::String str1("Hello");
    mystring::String str2(" World");

    mystring::String result = str1 + str2;
    CHECK(std::strcmp(result, "Hello World") == 0);
    CHECK(result.length() == 11);
}

TEST_CASE("Check operator+ with const char*") {
    mystring::String str1("Hello");

    mystring::String result = str1 + " World";
    CHECK(std::strcmp(result, "Hello World") == 0);
    CHECK(result.length() == 11);
}

TEST_CASE("Check operator+ with const char* as first argument") {
    mystring::String str1("World");

    mystring::String result = mystring::String("Hello") + str1;
    CHECK(std::strcmp(result, "HelloWorld") == 0);
    CHECK(result.length() == 10);
}

TEST_CASE("Check implicit conversion to const char*") {
    mystring::String str1("Hello World");

    CHECK(std::strcmp(str1, "Hello World") == 0);

    puts(str1);
}

TEST_CASE("Check += operator overload") {
    mystring::String str1 = "Hello";
    mystring::String str2 = " World";
    CHECK(std::strcmp(str1, "Hello") == 0);
    str1 += str2;
    CHECK(std::strcmp(str1.c_str(), "Hello World") == 0);
}

TEST_CASE("Check empty string length") {
    mystring::String empty = mystring::String("");
    CHECK(empty.length() == 0);
}

TEST_CASE("Check string length") {
    mystring::String str = "Hello World";
    CHECK(str.length() == 11);
}

TEST_CASE("Check compare c string with string literal") {
    mystring::String str = "Pineapple";
    CHECK(std::strcmp(str.c_str(), "Pineapple") == 0);
}

TEST_CASE("Check (single) append with string literal") {
    mystring::String str = "Hello";
    str.append(" World!");
    CHECK(std::strcmp(str.c_str(), "Hello World!") == 0);
}

TEST_CASE("Check (single) appended length with string literal") {
    mystring::String str = "Hello";
    CHECK(str.length() == 5);
    str.append(" World!");
    CHECK(str.length() == 12);
}

TEST_CASE("Check (single) append with mystring::String instance") {
    mystring::String str1 = "Hello";
    mystring::String str2 = " World";
    str1.append(str2);
    CHECK(std::strcmp(str1.c_str(), "Hello World") == 0);
}

TEST_CASE("Check (single) appended length with mystring::String instance") {
    mystring::String str1 = "Hello";
    CHECK(str1.length() == 5);
    mystring::String str2 = " World";
    str1.append(str2);
    CHECK(str1.length() == 11);
}

TEST_CASE("Check (multiple) append with string literal") {
    mystring::String str = "Hello";
    str.append(" World", ",", " and", " good", " morning", "!");
    CHECK(std::strcmp(str.c_str(), "Hello World, and good morning!") == 0);
}

TEST_CASE("Check (multiple) appended length with string literal") {
    mystring::String str = "Hello";
    CHECK(str.length() == 5);
    str.append(" World", ", ", " and", " good", " morning", "!");
    CHECK(str.length() == 31);
}

TEST_CASE("Check (multiple) append with mystring::String instance") {
    mystring::String str1 = "Hello";
    mystring::String str2 = " World";
    mystring::String str3 = " again";
    mystring::String str4 = " (I'm";
    mystring::String str5 = " very";
    mystring::String str6 = mystring::String(" creative)");
    str1.append(str2, str3, str4, str5, str6);
    CHECK(std::strcmp(str1.c_str(), "Hello World again (I'm very creative)") == 0);
}

TEST_CASE("Check (multiple) appended length with mystring::String instance") {
    mystring::String str1 = "Hello";
    CHECK(str1.length() == 5);
    mystring::String str2 = " World";
    mystring::String str3 = " again";
    mystring::String str4 = " (I'm";
    mystring::String str5 = " very";
    mystring::String str6 = mystring::String(" creative)");
    str1.append(str2, str3, str4, str5, str6);
    CHECK(str1.length() == 37);
}

TEST_CASE("Check chain append with string literal") {
    mystring::String str = "Hello";
    str.append(" to").append(" any").append("one").append(" reading").append(" this").append(" :D");
    CHECK(std::strcmp(str.c_str(), "Hello to anyone reading this :D") == 0);
}

TEST_CASE("Check chain append with mystring::String instances") {
    mystring::String str1 = "Hello";
    mystring::String str2 = " World";
    mystring::String str3 = " again";
    mystring::String str4 = " (I'm";
    mystring::String str5 = " still";
    mystring::String str6 = " super";
    mystring::String str7 = mystring::String(" creative)");
    str1.append(str2).append(str3).append(str4).append(str5).append(str6).append(str7);
    CHECK(std::strcmp(str1.c_str(), "Hello World again (I'm still super creative)") == 0);
}

TEST_CASE("Check move constructor"){
    mystring::String str = "Hello";
    mystring::String otherStr = std::move(str);
    CHECK(str.c_str() == nullptr);
    CHECK(str.length() == 0);
    CHECK(std::strcmp(otherStr.c_str(), "Hello") == 0);
    CHECK(otherStr.length() == 5);
}

TEST_CASE("Check move assignment operator"){
    mystring::String str = "Hello";
    mystring::String otherStr;
    otherStr = std::move(str);
    CHECK(str.c_str() == nullptr);
    CHECK(str.length() == 0);
    CHECK(std::strcmp(otherStr.c_str(), "Hello") == 0);
    CHECK(otherStr.length() == 5);
}

TEST_CASE("Check move constructor with empty string") {
    mystring::String emptyStr;
    mystring::String movedStr = std::move(emptyStr);
    CHECK(emptyStr.c_str() == nullptr);
    CHECK(emptyStr.length() == 0);
    CHECK(movedStr.c_str() == nullptr);
    CHECK(movedStr.length() == 0);
}

TEST_CASE("Check move assignment with empty string") {
    mystring::String emptyStr;
    mystring::String otherStr;
    otherStr = std::move(emptyStr);
    CHECK(emptyStr.c_str() == nullptr);
    CHECK(emptyStr.length() == 0);
    CHECK(otherStr.c_str() == nullptr);
    CHECK(otherStr.length() == 0);
}

TEST_CASE("Check move assignment self-assignment") {
    mystring::String str = "Hello";
    str = std::move(str);
    CHECK(std::strcmp(str.c_str(), "Hello") == 0);  // Original mystring::String bleibt gleich
    CHECK(str.length() == 5);
}

TEST_CASE("Check initialisation with nullptr") {
    mystring::String str = mystring::String(nullptr);
    CHECK(str.length() == 0);
    CHECK(str.c_str() == nullptr);
}

TEST_CASE("Check append with nullptr (nullptr -> string)") {
    mystring::String str1 = mystring::String(nullptr);
    mystring::String str2 = mystring::String("Hello");
    str1.append(str2);
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check append with nullptr (string -> nullptr)") {
    mystring::String str1 = mystring::String("Hello");
    mystring::String str2 = mystring::String(nullptr);
    str1.append(str2);
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check append with nullptr (nullptr -> nullptr)") {
    mystring::String str1 = mystring::String(nullptr);
    mystring::String str2 = mystring::String(nullptr);
    str1.append(str2);
    CHECK(str1.c_str() == nullptr);
}

TEST_CASE("Check constructor with nullptr") {
    mystring::String str1(nullptr);
    CHECK(str1.c_str() == nullptr);
    CHECK(str1.length() == 0);

    mystring::String str2 = mystring::String("Hello");
    CHECK(std::strcmp(str2.c_str(), "Hello") == 0);
    CHECK(str2.length() == 5);
}

TEST_CASE("Check copy constructor with nullptr") {
    mystring::String str1(nullptr);
    mystring::String str2 = str1;
    CHECK(str2.c_str() == nullptr);
    CHECK(str2.length() == 0);
}

TEST_CASE("Check assignment operator with nullptr") {
    mystring::String str1 = mystring::String("Hello");
    mystring::String str2 = mystring::String(nullptr);
    str1 = str2;
    CHECK(str1.c_str() == nullptr);
    CHECK(str1.length() == 0);
}

TEST_CASE("Check move constructor and move assignment operator with nullptr") {
    mystring::String str1 = mystring::String("Hello");
    mystring::String str2 = std::move(str1);
    CHECK(str2.c_str() != nullptr);
    CHECK(std::strcmp(str2.c_str(), "Hello") == 0);
    CHECK(str1.c_str() == nullptr); // str1 should be null after move
    CHECK(str2.length() == 5);
    CHECK(str1.length() == 0);

    mystring::String str3 = mystring::String("World");
    str3 = std::move(str2);
    CHECK(str3.c_str() != nullptr);
    CHECK(std::strcmp(str3.c_str(), "Hello") == 0);
    CHECK(str2.c_str() == nullptr); // str2 should be null after move
    CHECK(str2.length() == 0);
}

TEST_CASE("Check multiple append with nullptr and non-null strings") {
    mystring::String str1 = mystring::String(nullptr);
    str1.append("Hello", " ", "World", nullptr);
    CHECK(std::strcmp(str1.c_str(), "Hello World") == 0); // Appended strings
    CHECK(str1.length() == 11);

    mystring::String str2 = mystring::String("Initial");
    str2.append(nullptr, "String");
    CHECK(std::strcmp(str2.c_str(), "InitialString") == 0); // Appends only the valid string
    CHECK(str2.length() == 13);
}

TEST_CASE("Check assignment operator with self-assignment") {
    mystring::String str1 = mystring::String("Hello");
    str1 = str1; // Self-assignment should do nothing
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check default constructor for empty string") {
    mystring::String str;
    CHECK(str.c_str() == nullptr);
    CHECK(str.length() == 0);
}

TEST_CASE("Check append with empty string") {
    mystring::String str1 = "Hello";
    mystring::String emptyStr = "";
    str1.append(emptyStr);
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check multiple append with empty and valid strings") {
    mystring::String str1 = "Hello";
    str1.append(" World", "", "!");
    CHECK(std::strcmp(str1.c_str(), "Hello World!") == 0);
    CHECK(str1.length() == 12);
}

TEST_CASE("Check append with empty char array") {
    mystring::String str1 = "Hello";
    str1.append("");
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check self append") {
    mystring::String str1 = "Hello";
    str1.append(str1);
    CHECK(std::strcmp(str1.c_str(), "HelloHello") == 0);
    CHECK(str1.length() == 10);
}

TEST_CASE("Check move constructor with nullptr string") {
    mystring::String str1 = nullptr;
    mystring::String movedStr = std::move(str1);
    CHECK(movedStr.c_str() == nullptr);
    CHECK(movedStr.length() == 0);
}

TEST_CASE("Check move assignment operator with nullptr string") {
    mystring::String str1 = nullptr;
    mystring::String movedStr;
    movedStr = std::move(str1);
    CHECK(movedStr.c_str() == nullptr);
    CHECK(movedStr.length() == 0);
}

TEST_CASE("Check copy assignment operator and copy constructor") {
    mystring::String word = "Hello";
    mystring::String wordCopy = "other";
    wordCopy = word; //Nur Zuweisung --> DANN copy assignment
    //mystring::String wordCopy = word --> wär copy constructor, weil wordcopy erst constructed wird
    CHECK(std::strcmp(wordCopy.c_str(), word.c_str()) == 0);
    mystring::String copyConstructed = mystring::String(word);
    CHECK(std::strcmp(copyConstructed.c_str(), word.c_str()) == 0);
}

TEST_CASE("MAKE IT LEAK") {
    int* leak1 = new int[10];   // 10 ints werden allokiert, aber nicht freigegeben
    char* leak2 = new char[20]; // 20 chars werden allokiert, aber nicht freigegeben

    std::cout << "Programm läuft..." << std::endl;
}
