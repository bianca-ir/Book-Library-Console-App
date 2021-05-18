
#pragma once
#include "Book.h"
#include <string>



class EBook : public Book
{
private:
	std::string m_format;

public:
	/**
	 * Constructors with different signatures.
	 */
	EBook(int id, std::string author, std::string title, std::string publisher, int year, std::string format);
	EBook(std::string author, std::string title, std::string format); 


	/**
	* Display all the attributes of the class using ostream.
	* The method display() from base class is called.
	* \param os: object of type ostream
	*/
	void display(ostream& os) const override;

};

