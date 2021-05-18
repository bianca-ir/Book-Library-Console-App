#include "Repository.h"
#include "Book.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ostream>




Repository::~Repository()
{
}

int Repository::searchForBook(int id) {
	std::vector<Book*> data = this->data; 
	for (int i = 0; i < this->data.size(); i++)
		if (data[i]->getId() == id)
			return i; 
	return -1; 
}

void Repository::addBook(Book* bookToAdd) { 

	this->validator.validateData(bookToAdd); 
	this->data.push_back(bookToAdd); 
	//this->repositoryFile.writeToFile("MyFile.csv", data); 
	cout << "Name of file where you want to save the data (format filename.csv): "; 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string path; 
	getline(cin, path); 
	this->repositoryFile.writeToFile(path, data);

}


void Repository::removeBook(int id) {

	int index = searchForBook(id);
	if (index == -1)
		throw exception("Book does not exist.");
	this->data.erase(this->data.begin() + index); 
	//this->repositoryFile.writeToFile("MyFile.csv", data); // se va rescrie 
}


void Repository::updateBook(int id, Book* bookToUpdate) {
	int index = this->searchForBook(id);
	if (index == -1)
		throw exception("Does not exist");
	this->data[index] = bookToUpdate; 
//	this->repositoryFile.writeToFile("NyFile.csv", data);


}

std::vector<Book*> Repository::getAllBooks() {
	return this->data; 
//	this->repositoryFile.readFromFile("MyFile.csv");
}


std::vector<Book*> Repository::listBooksLessThanYear(int year)
{
	vector<Book*> result; 
	std::copy_if(this->data.begin(), this->data.end(), back_inserter(result), [year](Book* book)
		{return book->getPublicationYear() < year; });
	return result; 
}

std::vector<Book*> Repository::listBooksFromAuthor(std::string author)
{

	vector<Book*> result;
	std::copy_if(this->data.begin(), this->data.end(), back_inserter(result), [author](Book* book)
		{return book->getAuthor() == author; });
	return result;
}


