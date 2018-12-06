#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Book
{
	string bookName;
	string authorSurname;
	string authorName;
	string genre;
	string year;
	int price;
	int id;
};

mstring *bookReport(string report);
Book loadBook(string *reportBook);
void checkNovels(Book *books, int n);
void checkCheapBooks(Book *books, int n);
void checkAuthors(Book *books, int n);

int main(void)
{
	Book *books = new Book[5];
	string report;
	for (int i = 0; i < 5; i++)
	{
		cout << "Zadej nazev knihy, prijmeni autora, jmeno autora, zanr knihy, rok vydani, cenu a id:" << endl;

		getline(cin, report);

		string *reportBook = bookReport(report);

		books[i] = loadBook(reportBook);

	}

	checkNovels(books, 5);
	checkCheapBooks(books, 5);
	checkAuthors(books, 5);

	delete[] books;
	books = nullptr;

	return 0;
}

/// <summary>
/// Returns an array of the book report.
/// </summary>
/// <param name="report">Input of the report</param>
/// <returns>String array to be used to create struct Book</returns>
string *bookReport(string report)
{
	stringstream ss("");
	string *reportBook = new string[7];
	int index = 0;
	bool bookAccounted = false;

	for (unsigned int i = 0; i < report.length(); i++)
	{
		if (report.at(i) == ' ')
		{
			if (!bookAccounted)
			{
				bookAccounted = true;
				reportBook[index] = ss.str();
				ss.clear();
				ss.str("");
				index++;
				continue;
			}
			else
			{
				continue;
			}
		}

		else
		{
			ss << report.at(i);
			bookAccounted = false;
		}
	}

	reportBook[index] = ss.str();

	return reportBook;
}

Book loadBook(string *reportBook)
{
	Book book;

	book.bookName = reportBook[0];
	book.authorSurname = reportBook[1];
	book.authorName = reportBook[2];
	book.genre = reportBook[3];
	book.year = reportBook[4];
	book.price = stoi(reportBook[5]);
	book.id = stoi(reportBook[6]);

	return book;
}

void checkNovels(Book *books, int n)
{
	cout << "Romany jsou:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (books[i].genre == "roman")
		{
			cout << books[i].bookName << endl;
		}
	}

	cout << endl;
}

void checkCheapBooks(Book *books, int n)
{
	cout << "Knihy s cenou mensi nez 300,- Kc jsou:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (books[i].price < 300)
		{
			cout << books[i].bookName << endl;
		}
	}

	cout << endl;
}

void checkAuthors(Book *books, int n)
{
	bool authorDuplicate = false;
	cout << "Prijmeni vsech autoru jsou:" << endl;
	cout << books[0].authorSurname << endl;
	for (int i = 1; i < n; i++)
	{
		authorDuplicate = false;
		for (int j = 0; j < i; j++)
		{
			if (books[j].authorSurname == books[i].authorSurname)
			{
				authorDuplicate = true;
			}
		}
		if (!authorDuplicate)
		{
			cout << books[i].authorSurname << endl;
		}
	}
}