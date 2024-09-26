//
// Created by Sara on 24/09/2024.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "string.h"

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

// TEST_CASE("") {
//     CHECK();
// }

//     String null = String();
//     null.append("word");
//     assert(std::strcmp(null.c_str(), "word") == 0);
//
//     String wordCopy = word;
//     assert(std::strcmp(wordCopy.c_str(), word.c_str()) == 0);
//     String copyConstructed = String(word);
//     assert(std::strcmp(copyConstructed.c_str(), word.c_str()) == 0);
//
//
//     // constructor test
//     String str_test = String("Hello");
//     std::cout << str_test.c_str() << std::endl;
//
//     std::cout << std::endl;
//
//     // Conversion & Copy constructor test
//     // copy ctor -> new object created and initialized from other existing object
//     std::cout << "Conversion and copy constructor" << std::endl;
//     String str1 = "Hello";
//     std::cout << str1.c_str() << std::endl;
//     String str2 = str1;
//     std::cout << str2.c_str() << std::endl;
//
//     std::cout << std::endl;
//
//     str2.append(" this is the copied string");
//     std::cout << str1.c_str() << std::endl;
//     std::cout << str2.c_str() <<std::endl;
//
//     std::cout << std::endl;
//
//     // Assignment operator
//     std::cout << "Assigmnet operator" << std::endl;
//     String str3 = String("Hello");
//     String str4 = String("World");
//     std::cout << str3.c_str() << std::endl;
//     str3 = str4;
//     std::cout << str3.c_str() << std::endl;
//
//     std::cout << std::endl;
//
//     // append tests
//     // string literals
//     std::cout << "Append using string literal (char*)" << std::endl;
//     str_test.append(" User!");
//     std::cout << str_test.c_str() << std::endl;
//     str_test.append(" Another one", " and moreee", " and even moooreee");
//     std::cout << str_test.c_str() << std::endl;
//
//     // string objects
//     std::cout << std::endl << "Append using string object (String)" << std::endl;
//     String str_test2 = String(" + Another hello");
//     str_test.append(str_test2);
//     std::cout << str_test.c_str() << std::endl;
//     String str_test3 = String(" + Another one");
//     String str_test4 = String(" + Another another one");
//     str_test.append(str_test3, str_test4);
//     std::cout << str_test.c_str() << std::endl;
//
//     // output via c_str()
//     std::cout << std::endl << str_test.c_str() << std::endl;
//
//     // output length
//     std::cout << "Length of string: " << str_test.length() << std::endl;
//
//     return 0;
// }