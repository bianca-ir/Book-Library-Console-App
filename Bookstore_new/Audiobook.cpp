#include "Audiobook.h"




Audiobook::Audiobook() 
{
	Book::Book(); 
}

Audiobook::Audiobook(int id, std::string author, std::string title, std::string publisher, int year, float len) : Book(id, author, title, publisher, year)
{
	this->m_length = len;
}

Audiobook::Audiobook(std::string author, std::string title, std::string publisher, int year, float len):Book(author, title, publisher, year)
{
	this->m_length = len; 
}


void Audiobook::display(ostream& os) const
{
	os << "Audiobook: ";
	Book::display(os);
	os << " Length (in hours): " << m_length;
}

void Audiobook::setLength(float len)
{
	this->m_length = len; 
}
