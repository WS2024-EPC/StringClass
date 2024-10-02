#include <iostream>

int main() {
    // Speicherlecks erzeugen
    int* leak1 = new int[10];   // 10 ints werden allokiert, aber nicht freigegeben
    char* leak2 = new char[20]; // 20 chars werden allokiert, aber nicht freigegeben

    std::cout << "Programm läuft..." << std::endl;

    // Optional: Freigeben (zum Testen, ob VLD dies als kein Leak erkennt)
    // delete[] leak1;
    // delete[] leak2;

    return 0; // VLD sollte hier die nicht freigegebenen Speicherblöcke erkennen
}