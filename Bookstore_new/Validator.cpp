#include "Validator.h"
#include <exception>
using namespace std; 

void Validator::validateAuthor(std::string givenAuthor)
{
	if (givenAuthor == "")
		throw exception("Invalid"); 
}

void Validator::validateTitle(std::string givenTitle)
{
	if (givenTitle == "")
		throw exception("Invalid"); 
}

void Validator::validatePublisher(std::string givenPub)
{
	if (givenPub == "") 
		throw exception("Invalid");
}

void Validator::validateYear(int givenYear)
{
	if (givenYear < 0)
		throw exception("Invalid");
}

void Validator::validateId(int id)
{
	if (id < 0 and id > 6)
		throw exception("Invalid"); 

}

void Validator::validateLength(float len)
{
	if (len < 0)
		throw exception("Invalid"); 
}

void Validator::validateFormat(std::string format)
{
	if (format == "")
		throw exception("Invalid");
}



void Validator::validateData(Book* book) {
	std::string exception = "";
	try {
		validateAuthor(book->getAuthor());
	}
	catch (ValidatorException& ve) {
		exception += ve.getMessage();
	}

	try {
		validateTitle(book->getTitle());
	}
	catch (ValidatorException& ve) {
		exception += ve.getMessage();
	}

	try {
		validatePublisher(book->getPublisher());
	}
	catch (ValidatorException& ve) {
		exception += ve.getMessage();
	}

	try {
		validateYear(book->getPublicationYear());
	}
	catch (ValidatorException& ve) {
		exception += ve.getMessage();
	}

	if (exception != "")
		throw ValidatorException(exception);

}
