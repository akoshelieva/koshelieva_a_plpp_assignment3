#include <iostream>
#include <cstring>
// #include "ceasar.h"
#include <windows.h>

using encrypt_ = char* (__cdecl*)(char*, int);
using decrypt_ = char* (__cdecl*)(char*, int);

int main() {
    HMODULE hLib = LoadLibraryA("libMyDll.dll");

    if (!hLib) {
        std::cout << "Not found libMyDll.dll\n";
        return 1;
    }

    auto encrypt = reinterpret_cast<encrypt_>(GetProcAddress(hLib, "encrypt"));
    auto decrypt = reinterpret_cast<decrypt_>(GetProcAddress(hLib, "decrypt"));
    if (!encrypt || !decrypt) {
        std::cerr << "Not foud DLL\n";
        FreeLibrary(hLib);
        return 1;
    }

    const char* rawText[3] = {"Hello World!", "", "Some kind of text ()}{+-"};

    for (int key = 0; key < 3; key++) {

        char* encrypted = encrypt((char*)rawText[key], key);
        if (encrypted) {
            std::cout << "Encrypted: " << encrypted << std::endl;
            char* decrypted = decrypt(encrypted, key);
            if (decrypted) {
                std::cout << "Decrypted: " << decrypted << std::endl;
                delete[] decrypted;
            }
            delete[] encrypted;
        }
        std::cout << std::endl;
    }
    return 0;
}