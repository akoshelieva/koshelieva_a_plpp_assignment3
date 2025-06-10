#include <iostream>
#include <cstring>
#include "ceasar.h"


int main() {
    char rawText[] = "Hello World!";
    int key = 3;

    char* encrypted = encrypt(rawText, key);
    if (encrypted) {
        std::cout << "Encrypted: " << encrypted << std::endl;
        char* decrypted = decrypt(encrypted, key);
        if (decrypted) {
            std::cout << "Decrypted: " << decrypted << std::endl;
            delete[] decrypted;
        }
        delete[] encrypted;
    }

    return 0;
}