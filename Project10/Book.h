#pragma once
#include "ehglobal.h"
class Book
{
    const string isbn;
    int bnum;
    string title;
public:
    Book(string isbn, int bnum, string title);
    ~Book(void);
    string GetISBN() const;
    void View() const;
};