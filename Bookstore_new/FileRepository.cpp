#include "FileRepository.h"
#include <fstream> 
#include "Exception.h" 



void FileRepository::writeToFile(string path, vector<Book*> data) {
	std::ofstream FileOut(path, ios::out); 

	if (!FileOut.is_open())
		throw FileException("Unable to open file."); 

	for (auto data : data) {
		FileOut << *data;
		FileOut << endl; 
	}

	FileOut.close(); 
}

vector<Book*> FileRepository::readFromFile(string path)
{
	ifstream FileIn(path); 
	vector<Book*> data; 
	Book* bookRead = new Book(); 
	if (!FileIn.is_open())ofstream FileIn(path, ios::out); 
	while (FileIn >> *bookRead) {
		data.push_back(bookRead); 
	}

	FileIn.close(); 
	return data; 
}

void FileRepository::setPath(string path) {
	this->path = path; 
}

bool FileRepository::exists(Book* bookSearched) {
	vector<Book*> books = this->readFromFile(this->path); 
	int ok = 0; 
	for (auto data : books) {
		if (data == bookSearched) {
			ok = 1; 
		}
	}

	if (ok == 1) return true;
	else return false; 
}
