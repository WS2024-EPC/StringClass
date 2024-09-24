// #include <iostream>
// #include <cassert>
// #include <cstring>
// #include "string.h"
//
// int main() {
//     //Asserts
//     String emptyStr = String("");
//     assert(emptyStr.c_str()[0] == '\0');
//     assert(emptyStr.length() == 0);
//
//     String word = String("pineapple");
//     assert(std::strcmp(word.c_str(), "pineapple") == 0);
//     assert(word.length() == 9);
//     word.append(" and").append(" apple");
//     assert(std::strcmp(word.c_str(), "pineapple and apple") == 0);
//     assert(word.length() == 19);
//
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