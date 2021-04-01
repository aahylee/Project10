
#pragma once
#include "Book.h"
#include <vector>
#include <algorithm>
using namespace std;

//using Books = vector<Book*>;
//using BIter = Books::iterator;
//using CBIter = Books::const_iterator;

typedef vector<Book*> Books;
typedef Books::iterator BIter;
typedef Books::const_iterator CBIter;

class Genre
{
    const int gnum;
    string name;
    static const int max_book;
    Books books;
public:
    Genre(int gnum, string name);
    ~Genre(void);
    Book* AddBook(string isbn);
    string RemoveBook();

    int GetGNum() const;
    void FindBook() const;
    void View() const;
    void ViewAll() const;
  
};