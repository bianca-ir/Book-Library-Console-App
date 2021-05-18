#pragma once
#include "Book.h"
#include "Validator.h"
#include "FileRepository.h"
#include "Validator.h"
#include <string>

#include <vector>
using namespace std;

class Repository
{
private: 
	vector<Book*> data; 
	FileRepository repositoryFile; 
	Validator validator; 
public: 
	/**
	 * Constructor which receives a vector of objects as parameter. 
	 */
	Repository(vector<Book*> d) : data(d) {}; 

	/**
	 * Default constructor.
	 */
	Repository() {};

	/**
	 * Destructor.
	 */
	~Repository(); 

	/**
	 * Add an object to the vector. The object will also be added to the csv file. 
	 * @param bookToAdd: object to be added
	 */	
	void addBook(Book* bookToAdd); 

	/**
	 * Search throughout the storing vector for a specific id given as parameter.
	 * @return the index of the object which has this id
	 */
	int searchForBook(int id); 

	/**
	 * Remove the object which has a specific id given as parameter. 
	 * The object will also be removed from the csv file.
	 */
	void removeBook(int id); 

	//void updateBook(Book* bookToUpdate, Book* bookTobeUpdated); 
//	void updateBook(int id, std::string author, std::string title, std::string publisher, int year); 

	/**
	 * Update an object by id.
	 * @param id: id of the object which will be updated 
	 * @param bookToUpdate: the object which will be the new element in the storing vector
	 */
	void updateBook(int id, Book* bookToUpdate); 

	/**
	 * Return all the elements from the storing vector.
	 * \return a vector storing the current elements
	 */
	std::vector<Book*> getAllBooks();
	
	 
	/**
	 * List the books which were published earlier than a specific year given as parameter
	 * @return a vector containing the filtered elements.
	 */
	std::vector<Book*> listBooksLessThanYear(int year); 

	/**
	 * List the books which are written by a certain author whose name is given as parameter.
	 * @return a vector containing the filtered elements. 
	 */
	std::vector<Book*> listBooksFromAuthor(std::string author); 

	/**
	 * Overloading << operator.
	 */
	friend ostream& operator<<(ostream& os, const Repository& b); 


};

