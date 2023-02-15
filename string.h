

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

class String
{
private:
    char *str;
    int length;
public:
    String();
    String(const char *s);
    String(const String &s);
    ~String();
    String &operator=(const String &s);
    String &operator=(const char *s);
    String operator+(const String &s);
    String operator+(const char *s);
    String &operator+=(const String &s);
    String &operator+=(const char *s);
    bool operator==(const String &s);
    bool operator==(const char *s);
    bool operator!=(const String &s);
    bool operator!=(const char *s);
    char &operator[](int index);
    friend ostream &operator<<(ostream &os, const String &s);
    friend istream &operator>>(istream &is, String &s);
    int getLength();
    char *getStr();
    int stringtoint();
    int Getline(istream &is, String var);
    int Getline(istream &is, String var, char delim);

};

String::String()
{
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

String::String(const char *s)
{
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

String::String(const String &s)
{
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
}

String::~String()
{
    delete[] str;
}

String &String::operator=(const String &s)
{
    if (this == &s)
        return *this;
    delete[] str;
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
    return *this;
}

String &String::operator=(const char *s)
{
    delete[] str;
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
    return *this;
}

String String::operator+(const String &s)
{
    String temp;
    temp.length = length + s.length;
    delete[] temp.str;
    temp.str = new char[temp.length + 1];
    strcpy(temp.str, str);
    strcat(temp.str, s.str);
    return temp;
}

String String::operator+(const char *s)
{
    String temp;
    temp.length = length + strlen(s);
    delete[] temp.str;
    temp.str = new char[temp.length + 1];
    strcpy(temp.str, str);
    strcat(temp.str, s);
    return temp;
}

String &String::operator+=(const String &s)
{
    length += s.length;
    char *temp = new char[length + 1];
    strcpy(temp, str);
    strcat(temp, s.str);
    delete[] str;
    str = temp;
    return *this;
}

String &String::operator+=(const char *s)
{
    length += strlen(s);
    char *temp = new char[length + 1];
    strcpy(temp, str);
    strcat(temp, s);
    delete[] str;
    str = temp;
    return *this;
}

bool String::operator==(const String &s)
{
    return strcmp(str, s.str) == 0;
}

bool String::operator==(const char *s)
{
    return strcmp(str, s) == 0;
}

bool String::operator!=(const String &s)
{
    return strcmp(str, s.str) != 0;
}

bool String::operator!=(const char *s)
{
    return strcmp(str, s) != 0;
}

char &String::operator[](int index)
{
    return str[index];
}

ostream &operator<<(ostream &os, const String &s)
{
    os << s.str;
    return os;
}

istream &operator>>(istream &is, String &s)
{
    char temp[1000];
    is >> temp;
    s = temp;
    return is;
}

int String::getLength()
{
    return length;
}

char *String::getStr()
{
    return str;
}

int String::stringtoint()
{
    int i = 0;
    int num = 0;
    while (str[i] != '\0')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

int String::Getline(istream &is, String &var)
{
    char c;
    int count = 0;
    var = "";
    while (is.get(c))
    {
        if (c == '\n')
            break;
        var += c;
        count++;
    }
    return count;
}

int String::Getline(istream &is, String &var, char delim)
{
    char c;
    int count = 0;
    var = "";
    while (is.get(c))
    {
        if (c == delim)
            break;
        var += c;
        count++;
    }
    return count;
}



