//
// Created by Sara on 24/09/2024.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "string.h"

TEST_CASE("Check += operator overload") {
    String str1 = "Hello";
    String str2 = " World";
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    str1 += str2;
    CHECK(std::strcmp(str1.c_str(), "Hello World") == 0);
}

TEST_CASE("Check empty string length") {
    String empty = String("");
    CHECK(empty.length() == 0);
}

TEST_CASE("Check string length") {
    String str = "Hello World";
    CHECK(str.length() == 11);
}

TEST_CASE("Check compare c string with string literal") {
    String str = "Pineapple";
    CHECK(std::strcmp(str.c_str(), "Pineapple") == 0);
}

TEST_CASE("Check (single) append with string literal") {
    String str = "Hello";
    str.append(" World!");
    CHECK(std::strcmp(str.c_str(), "Hello World!") == 0);
}

TEST_CASE("Check (single) appended length with string literal") {
    String str = "Hello";
    CHECK(str.length() == 5);
    str.append(" World!");
    CHECK(str.length() == 12);
}

TEST_CASE("Check (single) append with String instance") {
    String str1 = "Hello";
    String str2 = " World";
    str1.append(str2);
    CHECK(std::strcmp(str1.c_str(), "Hello World") == 0);
}

TEST_CASE("Check (single) appended length with String instance") {
    String str1 = "Hello";
    CHECK(str1.length() == 5);
    String str2 = " World";
    str1.append(str2);
    CHECK(str1.length() == 11);
}

TEST_CASE("Check (multiple) append with string literal") {
    String str = "Hello";
    str.append(" World", ",", " and", " good", " morning", "!");
    CHECK(std::strcmp(str.c_str(), "Hello World, and good morning!") == 0);
}

TEST_CASE("Check (multiple) appended length with string literal") {
    String str = "Hello";
    CHECK(str.length() == 5);
    str.append(" World", ", ", " and", " good", " morning", "!");
    CHECK(str.length() == 31);
}

TEST_CASE("Check (multiple) append with String instance") {
    String str1 = "Hello";
    String str2 = " World";
    String str3 = " again";
    String str4 = " (I'm";
    String str5 = " very";
    String str6 = String(" creative)");
    str1.append(str2, str3, str4, str5, str6);
    CHECK(std::strcmp(str1.c_str(), "Hello World again (I'm very creative)") == 0);
}

TEST_CASE("Check (multiple) appended length with String instance") {
    String str1 = "Hello";
    CHECK(str1.length() == 5);
    String str2 = " World";
    String str3 = " again";
    String str4 = " (I'm";
    String str5 = " very";
    String str6 = String(" creative)");
    str1.append(str2, str3, str4, str5, str6);
    CHECK(str1.length() == 37);
}

TEST_CASE("Check chain append with string literal") {
    String str = "Hello";
    str.append(" to").append(" any").append("one").append(" reading").append(" this").append(" :D");
    CHECK(std::strcmp(str.c_str(), "Hello to anyone reading this :D") == 0);
}

TEST_CASE("Check chain append with String instances") {
    String str1 = "Hello";
    String str2 = " World";
    String str3 = " again";
    String str4 = " (I'm";
    String str5 = " still";
    String str6 = " super";
    String str7 = String(" creative)");
    str1.append(str2).append(str3).append(str4).append(str5).append(str6).append(str7);
    CHECK(std::strcmp(str1.c_str(), "Hello World again (I'm still super creative)") == 0);
}

TEST_CASE("Check move constructor"){
    String str = "Hello";
    String otherStr = std::move(str);
    CHECK(str.c_str() == nullptr);
    CHECK(str.length() == 0);
    CHECK(std::strcmp(otherStr.c_str(), "Hello") == 0);
    CHECK(otherStr.length() == 5);
}

TEST_CASE("Check move assignment operator"){
    String str = "Hello";
    String otherStr;
    otherStr = std::move(str);
    CHECK(str.c_str() == nullptr);
    CHECK(str.length() == 0);
    CHECK(std::strcmp(otherStr.c_str(), "Hello") == 0);
    CHECK(otherStr.length() == 5);
}

TEST_CASE("Check move constructor with empty string") {
    String emptyStr;
    String movedStr = std::move(emptyStr);
    CHECK(emptyStr.c_str() == nullptr);
    CHECK(emptyStr.length() == 0);
    CHECK(movedStr.c_str() == nullptr);
    CHECK(movedStr.length() == 0);
}

TEST_CASE("Check move assignment with empty string") {
    String emptyStr;
    String otherStr;
    otherStr = std::move(emptyStr);
    CHECK(emptyStr.c_str() == nullptr);
    CHECK(emptyStr.length() == 0);
    CHECK(otherStr.c_str() == nullptr);
    CHECK(otherStr.length() == 0);
}

TEST_CASE("Check move assignment self-assignment") {
    String str = "Hello";
    str = std::move(str);
    CHECK(std::strcmp(str.c_str(), "Hello") == 0);  // Original String bleibt gleich
    CHECK(str.length() == 5);
}

TEST_CASE("Check initialisation with nullptr") {
    String str = String(nullptr);
    CHECK(str.length() == 0);
    CHECK(str.c_str() == nullptr);
}

TEST_CASE("Check append with nullptr (nullptr -> string)") {
    String str1 = String(nullptr);
    String str2 = String("Hello");
    str1.append(str2);
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check append with nullptr (string -> nullptr)") {
    String str1 = String("Hello");
    String str2 = String(nullptr);
    str1.append(str2);
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check append with nullptr (nullptr -> nullptr)") {
    String str1 = String(nullptr);
    String str2 = String(nullptr);
    str1.append(str2);
    CHECK(str1.c_str() == nullptr);
}

TEST_CASE("Check constructor with nullptr") {
    String str1(nullptr);
    CHECK(str1.c_str() == nullptr);
    CHECK(str1.length() == 0);

    String str2 = String("Hello");
    CHECK(std::strcmp(str2.c_str(), "Hello") == 0);
    CHECK(str2.length() == 5);
}

TEST_CASE("Check copy constructor with nullptr") {
    String str1(nullptr);
    String str2 = str1;
    CHECK(str2.c_str() == nullptr);
    CHECK(str2.length() == 0);
}

TEST_CASE("Check assignment operator with nullptr") {
    String str1 = String("Hello");
    String str2 = String(nullptr);
    str1 = str2;
    CHECK(str1.c_str() == nullptr);
    CHECK(str1.length() == 0);
}

TEST_CASE("Check move constructor and move assignment operator with nullptr") {
    String str1 = String("Hello");
    String str2 = std::move(str1);
    CHECK(str2.c_str() != nullptr);
    CHECK(std::strcmp(str2.c_str(), "Hello") == 0);
    CHECK(str1.c_str() == nullptr); // str1 should be null after move
    CHECK(str2.length() == 5);
    CHECK(str1.length() == 0);

    String str3 = String("World");
    str3 = std::move(str2);
    CHECK(str3.c_str() != nullptr);
    CHECK(std::strcmp(str3.c_str(), "Hello") == 0);
    CHECK(str2.c_str() == nullptr); // str2 should be null after move
    CHECK(str2.length() == 0);
}

TEST_CASE("Check multiple append with nullptr and non-null strings") {
    String str1 = String(nullptr);
    str1.append("Hello", " ", "World", nullptr);
    CHECK(std::strcmp(str1.c_str(), "Hello World") == 0); // Appended strings
    CHECK(str1.length() == 11);

    String str2 = String("Initial");
    str2.append(nullptr, "String");
    CHECK(std::strcmp(str2.c_str(), "InitialString") == 0); // Appends only the valid string
    CHECK(str2.length() == 13);
}

TEST_CASE("Check assignment operator with self-assignment") {
    String str1 = String("Hello");
    str1 = str1; // Self-assignment should do nothing
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check default constructor for empty string") {
    String str;
    CHECK(str.c_str() == nullptr);
    CHECK(str.length() == 0);
}

TEST_CASE("Check append with empty string") {
    String str1 = "Hello";
    String emptyStr = "";
    str1.append(emptyStr);
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check multiple append with empty and valid strings") {
    String str1 = "Hello";
    str1.append(" World", "", "!");
    CHECK(std::strcmp(str1.c_str(), "Hello World!") == 0);
    CHECK(str1.length() == 12);
}

TEST_CASE("Check append with empty char array") {
    String str1 = "Hello";
    str1.append("");
    CHECK(std::strcmp(str1.c_str(), "Hello") == 0);
    CHECK(str1.length() == 5);
}

TEST_CASE("Check self append") {
    String str1 = "Hello";
    str1.append(str1);
    CHECK(std::strcmp(str1.c_str(), "HelloHello") == 0);
    CHECK(str1.length() == 10);
}

TEST_CASE("Check move constructor with nullptr string") {
    String str1 = nullptr;
    String movedStr = std::move(str1);
    CHECK(movedStr.c_str() == nullptr);
    CHECK(movedStr.length() == 0);
}

TEST_CASE("Check move assignment operator with nullptr string") {
    String str1 = nullptr;
    String movedStr;
    movedStr = std::move(str1);
    CHECK(movedStr.c_str() == nullptr);
    CHECK(movedStr.length() == 0);
}

TEST_CASE("Check copy assignment operator and copy constructor") {
    String word = "Hello";
    String wordCopy = "other";
    wordCopy = word; //Nur Zuweisung --> DANN copy assignment
    //String wordCopy = word --> wär copy constructor, weil wordcopy erst constructed wird
    CHECK(std::strcmp(wordCopy.c_str(), word.c_str()) == 0);
    String copyConstructed = String(word);
    CHECK(std::strcmp(copyConstructed.c_str(), word.c_str()) == 0);
}

// TEST_CASE("") {
//     CHECK();
// }
