#include "Controller.h"



Controller::~Controller()
{
}

std::vector<Book*> Controller::getAll()
{
	return this->repo.getAllBooks(); 
}


void Controller::CTRLAddBook(Book* b)
{
	this->repo.addBook(b); 
}

void Controller::CTRLAddAudiobook(int id, std::string author, std::string title, std::string publisher, int year, float len)
{
	 
	Book* audiobook = new Audiobook(); 
	audiobook->setId(id); 
	audiobook->setAuthor(author); 
	audiobook->setTitle(title); 
	audiobook->setPublisher(publisher);


	this->repo.addBook(audiobook); 
}


void Controller::CTRLAddEbook(int id, std::string author, std::string title, std::string publisher, int year, std::string format)
{
	Book* eBook = new EBook(id, author, title, publisher, year, format);


	this->repo.addBook(eBook); 
}

int Controller::CTRLSearchBook(int id)
{
	return this->repo.searchForBook(id); 
}

void Controller::CTRLRemoveBook(int id)
{
	 this->repo.removeBook(id); 
	 Book::contor -= 1; 
}




void Controller::CTRLUpdateBook(int id, Book* b) {
	this->repo.updateBook(id, b); 
}

void Controller::CTRLUpdateEbook(int id, std::string author, std::string title, std::string publisher, int year, std::string format)
{
	Book* ebook = new EBook(id, author, title, publisher, year, format);
	this->repo.updateBook(id, ebook);
}

void Controller::CTRLUpdateAudiobook(int id, std::string author, std::string title, std::string publisher, int year, float len) {
	Book* audiobook = new Audiobook(id, author, title, publisher, year, len); 
	this->repo.updateBook(id, audiobook); 
}



vector<Book*> Controller::CTRLFilterByYear(int year)
{
	return this->repo.listBooksLessThanYear(year); 
}

vector<Book*> Controller::CTRLFilterByAuthor(std::string author)
{
	return this->repo.listBooksFromAuthor(author);
}




