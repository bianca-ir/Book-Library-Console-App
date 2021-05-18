#pragma once
#include <iostream>
#include "Controller.h"
#include <string> 
using namespace std; 

enum type {
	AUDIOBOOK = 1,
	EBOOK = 2
};

class UI
{
private: 
	Controller ctrl; 
	Validator validator; 

	/**
	 * Print the available options to choose from.
	 */
	void menu(); 

	/**
	 * Return the number of the command that the user chose.
	 */
	int command(); 

	/**
	 * Call specific commands.
	 */
	void addBook(); 
	void removeBook(); 
	void updateBook(); 
	void listBooksLessThanYear(); 
	void listBooksFromAuthor(); 
	void printAll(); 
	
	/**
	 * Either adds an object of type AUDIOBOOK or EBOOK, depending on the case. 
	 * Given the fact that user can add two different types of objects, the function will prompt them
	 * to enter the values of attributes for each type. The attributes must be valid. 
	 * The object will be added to our vector of Book objects using upcasting. 
	 */
	void convertAdd(int type); 

	/**
	 * Either updates an object of type AUDIOBOOK or EBOOK, depending on the case.
	 * Given the fact that user can update two different types of objects, the function will prompt them
	 * to enter the values of attributes for each type. The attributes must be valid. 
	 * The object will be updated in our vector of Book objects using upcasting.
	 */
	void convertUpdate(int type); 
public:

	UI(Controller c) : ctrl(c) {};
	void run(); 
	
};

