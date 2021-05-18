#pragma once
#include <string>
#include "Exception.h"
#include "Book.h"
class Validator
{
public: 
	void validateAuthor(std::string givenAuthor); 
	void validateTitle(std::string givenTitle); 
	void validatePublisher(std::string givenPub); 
	void validateYear(int givenYear); 
	void validateId(int id); 
	void validateLength(float len); 
	void validateFormat(std::string format); 

	//void validateData(std::string givenAuthor, std::string givenTitle, std::string givenPub, int givenYear); 
	void validateData(Book* element); 
};

