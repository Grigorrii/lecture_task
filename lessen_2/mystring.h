#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;
class MyString
{
    size_t size;
    char * buffer;
public:
    MyString();
    MyString(const MyString& s);//1
    MyString(const char * cs);//2
    ~MyString();

    size_t length() const;//3
    int compare(const char* cs) const;//4
    int compare(const MyString& s) const;//5

    MyString& add(const MyString& s);//6
    MyString& add(const char* cs);//6

    MyString& operator=(const MyString& s);
    MyString& operator=(const char* cs);
    MyString& operator=(const char& c);

    MyString& operator+=(const MyString& s);
    MyString& operator+=(const char* cs);
    MyString& operator+=(const char& c);

    friend ostream& operator<<(ostream&, const MyString&);
    friend istream& operator>>(istream&, MyString&);
    friend istream& getline(istream& is, MyString& s);

    void clear();
    void push_back(const char& c);
    void expandMem(const size_t& n);


};

#endif // MYSTRING_H
