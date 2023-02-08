#include "string.h"

String() {
    length = 0;
    data = new char[length + 1];
    data[length] = '\0';
}

String(const char* str) {
    length = strlen(str);
    data = new char[length + 1];
    strcpy(data, str);
}

~String() {
    delete[] data;
}

void print() const {
    std::cout << data << std::endl;
}

int length() const {
    return length;
}

char* get() const {
    return data;
}

char& operator[](int index) {
    return data[index];
}

String& operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

String& operator=(const char* other) {
    delete[] data;
    length = strlen(other);
    data = new char[length + 1];
    strcpy(data, other);
    return *this;
}

String& operator+=(const String& other) {
    int newLength = length + other.length;
    char* newData = new char[newLength + 1];
    strcpy(newData, data);
    strcat(newData, other.data);
    delete[] data;
    length = newLength;
    data = newData;
    return *this;
}
