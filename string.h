//define string without standard library

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "string.cpp"

using namespace std;

class String {
public:
    String(const char* str);
    ~String();
    void print() const;
    int length() const;
    char* get() const;
    char& operator[](int index);
    String& operator=(const String& other);
    String& operator=(const char* other);
    String& operator+=(const String& other);
private:
    int length;
    char* data;
};



