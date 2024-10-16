
#ifndef STRINGCLASS_UNIQUEPOINTER_H
#define STRINGCLASS_UNIQUEPOINTER_H
#include <iostream>
// für std::swap
#include <utility>
// für std::function
#include <functional>

// Template-Klasse für UniquePtr
template<typename T>
class UniquePtr {
private:
    // Der Pointer
    T* ptr;
    // optionaler Custom Deleter
    std::function<void(T*)> deleter;

public:
    // Konstruktoren (Standard -> mit nullptr initialisiert und Pointer wird deleted) *explicit damit keine ungewollten konvertierungen passieren
    explicit UniquePtr(T* p = nullptr, std::function<void(T*)> d = nullptr)
            : ptr(p), deleter(d) {} //Initialisierungsliste weil ~ effizient ~

    // Move-Konstruktor, noexcept garantiert keine exceptions werden gethrowed
    UniquePtr(UniquePtr&& other) noexcept
            : ptr(other.ptr), deleter(std::move(other.deleter)) {
        other.ptr = nullptr;
    } //Bei zB UniquePtr<int> ptr(std::move(otherptr));

    // Move-Assignment-Operator
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            Reset(); // Altes Objekt freigeben
            ptr = other.ptr;
            deleter = std::move(other.deleter);
            other.ptr = nullptr;
        }
        return *this;
    } // Bei ptr1; otherptr; --> otherptr = std::move(ptr1);

    // Destruktor
    ~UniquePtr() {
        Reset(); // Das verwaltete Objekt freigeben (wenn deleter gesetzt, wird der custom verwendet dafür)
    }

    // Dereferenzierungsoperator (*)
    T& operator*() const {
        return *ptr;
    }

    // Member-Zugriffsoperator (->)
    T* operator->() const {
        return ptr;
    }

    // Bool-Operator: gibt true zurück, wenn der Pointer gültig ist
    explicit operator bool() const {
        return ptr != nullptr;
    }

    // Release-Funktion: gibt die Kontrolle über das Objekt frei und gibt den Pointer zurück
    T* Release() {
        T* oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }

    // Reset-Funktion: Setzt den Pointer auf ein neues Objekt oder auf nullptr
    void Reset(T* newPtr = nullptr) {
        if (ptr) {
            if (deleter) {
                deleter(ptr); // Custom Deleter aufrufen, falls vorhanden
            } else {
                delete ptr; // Standardmäßige Zerstörung
            }
        }
        ptr = newPtr;
    }

    // Swap-Funktion: Tauscht den verwalteten Pointer mit einem anderen UniquePtr
    void Swap(UniquePtr& other) {
        std::swap(ptr, other.ptr);
        std::swap(deleter, other.deleter);
    }

    // Verbietet Kopieren
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
};

#endif //STRINGCLASS_UNIQUEPOINTER_H
