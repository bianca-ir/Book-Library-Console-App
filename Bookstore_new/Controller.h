#pragma once
#include "Repository.h"
#include "Book.h"
#include "Audiobook.h"
#include "eBook.h"
class Controller
{
private: 
//	Repository* repo; 
	Repository repo; 
//	FileRepository repoFile; 
public: 
	/**
	 * Constructors with different signatures. 
	 * @param repository: object of type Repository received by the controller
	 */
	Controller(); 
	Controller(Repository repository) : repo(repository) {}; 
	
	/**
	 * Destructor.
	 */
	~Controller(); 

	/**
	 * Return all the elements from the storing vector.
	 * \return a vector storing the current elements
	 */
	std::vector<Book*> getAll(); 

	/**
	* Add an object to the vector. The object will also be added to the csv file.
	* @param b: object to be added
	*/
	void CTRLAddBook(Book* b); 


	void CTRLAddAudiobook(int id, std::string author, std::string title, std::string publisher, int year, float len); 
	void CTRLAddEbook(int id, std::string author, std::string title, std::string publisher, int year, std::string format); 


	/**
	 * Search throughout the storing vector for a specific id given as parameter.
	 * @return the index of the object which has this id
	 */
	int CTRLSearchBook(int id); 

	/**
	 * Remove the object which has a specific id given as parameter.
	 * The object will also be removed from the csv file.
	 */
	void CTRLRemoveBook(int id);

	/**
	 * Update an object by id.
	 * @param id: id of the object which will be updated
	 * @param bookToUpdate: the object which will be the new element in the storing vector
	 */
	void CTRLUpdateBook(int id, Book* b); 
	//void CTRLUpdateBook(int id, std::string author, std::string title, std::string publisher, int year); 
	void CTRLUpdateEbook(int id, std::string author, std::string title, std::string publisher, int year, std::string format); 
	void CTRLUpdateAudiobook(int id, std::string author, std::string title, std::string publisher, int year, float length); 


	/**
	 * List the books which were published earlier than a specific year given as parameter.
	 * @return a vector containing the filtered elements.
	 */
	vector<Book*> CTRLFilterByYear(int year);

	 /**
	  * List the books which are written by a certain author whose name is given as parameter.
	  * @return a vector containing the filtered elements.
	  */
	vector <Book*> CTRLFilterByAuthor(std::string author); 

};

