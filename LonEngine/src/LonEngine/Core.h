#pragma once
#ifdef LE_Platform_Windows
    #ifdef LE_BUILD_DLL
        #define LONENGINE_API __declspec(dllexport)
    #else
        #define LONENGINE_API __declspec(dllimport)
    #endif
#else
    #error LonEngine Only Support Windows!
#endif