#include "eBook.h"
#include "Book.h"
#include "Book.h"


EBook::EBook(int id, std::string author, std::string title, std::string publisher, int year, std::string format) :Book(id, author, title, publisher, year)
{
	this->m_format = format;
}

EBook::EBook(std::string author, std::string title, std::string format):Book(author, title)
{
	this->m_format = format; 
}

void EBook::display(ostream& os) const
{
	os << "Ebook: ";
	Book::display(os);
	os << " Format (PDF, EPUB, MOBI): " << m_format;
}