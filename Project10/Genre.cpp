#include "Genre.h"
const int Genre::max_book = 100;
Genre::Genre(int gnum, string name) :gnum(gnum)
{
	//this->gnum = gnum;
	this->name = name;
	books.resize(max_book, 0); //  요소 추가하고 초기화
}

Genre::~Genre(void)
{
	for (int index = 0; index < max_book; ++index)
	{
		if (books[index])
			delete books[index];
	}
}

void Genre::View(void) const
{
	cout << "No." << gnum << ", 장르 이름:" << name << '\n';

}
void Genre::ViewAll(void) const
{
	View();
	for (int index = 0; index < max_book; ++index)
	{
		if (books[index])
			books[index]->View();
	}
}
Book* Genre::AddBook(string name)
{
	cout << "장르 내 도서 구분자(1~100)";
	int bnum = ehglobal::getnum();
	if ((bnum < 1) || (bnum > 100))
	{
		cout << "범위 벗어난 도서 구분자" << '\n';
		return 0;
	}
	cout << "도서 제목:";
	string title = ehglobal::getstr();
	//books[bnum - 1] = new Book(isbn, bnum, title);
	return books[bnum - 1];
}
string Genre::RemoveBook()
{
	int bnum = ehglobal::getnum();
	if ((bnum < 1) || (bnum > 100))
	{
		cout << "범위를 벗어난 도서 구분자입니다." << endl;
		return "";
	}
	if (books[bnum - 1])
	{
		string isbn = books[bnum - 1]->GetISBN();
		delete books[bnum - 1];
		books[bnum - 1] = 0;
		return isbn;
	}
	else
	{
		cout << "없는 도서" << '\n';
		return "";
	}
}
int Genre::GetGNum() const
{
	return this->gnum;
}

void Genre::FindBook() const
{
	cout << "장르 내 도서 구분자(1~100):";
	int bnum = ehglobal::getnum();
	if ((bnum < 1) || (bnum > 100))
	{
		cout << "범위 벗어난 도서 구분자" << '\n';
		return;
	}
	if (books[bnum - 1])
	{
		books[bnum - 1]->View();
	}
	else
		cout << "없는 도서입니다" << '\n';
}