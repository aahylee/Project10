#include "Genre.h"
const int Genre::max_book = 100;
Genre::Genre(int gnum, string name) :gnum(gnum)
{
	//this->gnum = gnum;
	this->name = name;
	books.resize(max_book, 0); //  ��� �߰��ϰ� �ʱ�ȭ
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
	cout << "No." << gnum << ", �帣 �̸�:" << name << '\n';

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
	cout << "�帣 �� ���� ������(1~100)";
	int bnum = ehglobal::getnum();
	if ((bnum < 1) || (bnum > 100))
	{
		cout << "���� ��� ���� ������" << '\n';
		return 0;
	}
	cout << "���� ����:";
	string title = ehglobal::getstr();
	//books[bnum - 1] = new Book(isbn, bnum, title);
	return books[bnum - 1];
}
string Genre::RemoveBook()
{
	int bnum = ehglobal::getnum();
	if ((bnum < 1) || (bnum > 100))
	{
		cout << "������ ��� ���� �������Դϴ�." << endl;
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
		cout << "���� ����" << '\n';
		return "";
	}
}
int Genre::GetGNum() const
{
	return this->gnum;
}

void Genre::FindBook() const
{
	cout << "�帣 �� ���� ������(1~100):";
	int bnum = ehglobal::getnum();
	if ((bnum < 1) || (bnum > 100))
	{
		cout << "���� ��� ���� ������" << '\n';
		return;
	}
	if (books[bnum - 1])
	{
		books[bnum - 1]->View();
	}
	else
		cout << "���� �����Դϴ�" << '\n';
}