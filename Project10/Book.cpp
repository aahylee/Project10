//Book.cpp
#include "Book.h"

Book::Book(string isbn, int bnum, string title):isbn(isbn)
{
	this->bnum = bnum;
	this->title = title;
}

Book::~Book(void)
{
}

void Book::View() const
{
	cout << isbn << ",No." << bnum << ",????:" << title << '\n';
}

string Book::GetISBN() const
{
	return isbn;
}