
#pragma once
#include "Book.h"



class Audiobook : public Book
{
private:
	float m_length;
public:
	/**
	 * Constructors with different signature.
	 */
	Audiobook(); 
	Audiobook(int id, std::string author, std::string title, std::string publisher, int year, float len);
	Audiobook(std::string author, std::string title, std::string publisher, int year, float len); 

	/**
	 * Display all the attributes of the class using ostream.
	 * The method display() from base class is called. 
	 * \param os: object of type ostream
	 */
	void display(ostream& os) const override;

	/**
	 * Setter for length.
	 */
	void setLength(float len); 

};

