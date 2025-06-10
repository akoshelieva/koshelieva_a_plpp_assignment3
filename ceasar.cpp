#include <iostream>
#include <cstring>
#include "ceasar.h"

char* encrypt(char* rawText, int key) {
    if (rawText == nullptr) {
        std::cout << "String is empty" << std::endl;
        return nullptr;
    }

    int text_len = strlen(rawText);
    char* encryptedText = new char[text_len + 1];

    for (int i = 0; i < text_len; i++) {
        if (rawText[i] >= 'A' && rawText[i] <= 'Z') {
            encryptedText[i] = 'A' + ((rawText[i] - 'A' + key) % 26 + 26) % 26;
        } else if (rawText[i] >= 'a' && rawText[i] <= 'z') {
            encryptedText[i] = 'a' + ((rawText[i] - 'a' + key) % 26 + 26) % 26;
        } else {
            encryptedText[i] = rawText[i];
        }
    }
    encryptedText[text_len] = '\0';
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    if (encryptedText == nullptr) {
        std::cerr << "String is empty" << std::endl;
        return nullptr;
    }

    int text_len = strlen(encryptedText);
    char* rawText = new char[text_len + 1];

    for (int i = 0; i < text_len; i++) {
        if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
            rawText[i] = 'A' + ((encryptedText[i] - 'A' - key) % 26 + 26) % 26;
        } else if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z') {
            rawText[i] = 'a' + ((encryptedText[i] - 'a' - key) % 26 + 26) % 26;
        } else {
            rawText[i] = encryptedText[i];
        }
    }
    rawText[text_len] = '\0';
    return rawText;
}


