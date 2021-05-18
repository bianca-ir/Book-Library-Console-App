#pragma once
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
private:
	int m_id; 
protected:
	std::string m_title;
	std::string m_author;
	std::string m_publisher;
	int m_publicationYear;
	
public:
	static int contor; 
	int getContor(); 

	/**
	 * Constructors with different number of parameters.
	 */
	Book();
	Book(int id, std::string author, std::string title, std::string publisher, int year);
	Book(std::string author, std::string title, std::string publisher, int year);
	Book(std::string author, std::string title); 

	/**
	 * Getter functions.
	 * \return the specific attribute
	 */
	std::string getTitle();
	std::string getAuthor();
	int getId();
	int getPublicationYear();
	std::string getPublisher();

	/**
	 * Setter functions.
	 * \param: specific attributes
	 */
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setId(int id);
	void setPublicationYear(int year);
	void setPublisher(std::string publisher);
	
	/**
	 * toString function. Function will display all the attributes using to_string method. 
	 * \return attributes in a string form
	 */
	std::string bookString();

	/**
	 * Overloading ostream and ifstream, so that we can read from and write to file. 
	 */
	friend ostream& operator <<(ostream& os, const Book& a);
	friend ifstream& operator >> (ifstream& in, Book& b);

	/**
	 * Display all the attributes using ostream.
	 */
	virtual void display(ostream& os) const;

	/**
	 * Overloading == operator. Will compare an attribute of an object with an attribute of another object.
	 * \param otherBook: the object with whom we compare the first one. 
	 * \return true if the comparison is true, false if otherwise 
	 */
	bool operator==(const Book& otherBook);

	/**
	 * Destructor.
	 */
	~Book();
};

