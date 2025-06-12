// #ifndef CAESAR_H
// #define CAESAR_H

#pragma once

#ifdef _WIN32
  #ifdef BUILD_DLL
    #define CELIB_API __declspec(dllexport)
  #else
    #define CELIB_API __declspec(dllimport)
  #endif
#else
  #define CELIB_API
#endif

#include <string>


// #ifdef __cplusplus
extern "C" {
// #endif

    CELIB_API char* encrypt(char* rawText, int key);
    CELIB_API char* decrypt(char* encryptedText, int key);

// #ifdef __cplusplus
}
// #endif

// #endif // CAESAR_H