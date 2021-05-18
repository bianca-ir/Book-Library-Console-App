#pragma once
#include "Book.h"
#include <fstream>
#include <vector> 
class FileRepository 
{
protected:
	std::string path; 
public: 

	/**
	 * Add a vector to a csv file. If the file does not exist, an exception will be raised. 
	 * @param path: name of the file where the information will be stored 
	 * @param data: vector storing the information to be written to the file 
	 */
	void writeToFile(string path, vector<Book*> data); 

	/**
	 * Reading information from a file whose name is given as parameter.
	 * @param path: name of the file where the information is stored
	 * @return a vector containig the read data
	 */
	vector<Book*> readFromFile(string path); 

	/**
	 * Setter for path (filename).
	 */	
	void setPath(string path); 

	/**
	 * Check if a certain object is present in the file, using the overloaded ==. 
	 * @param book: element to be searched for 
	 * @return true if we found the object, false otherwise
	 */
	bool exists(Book* book); 

};

