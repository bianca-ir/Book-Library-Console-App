#include "Book.h"
// Bookstore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 

int Book::contor = 0; 

Book::Book()
{
    m_id = 0;
    m_title = "";
    m_author = "";
    m_publisher = "";
    m_publicationYear = 0;
}

int Book::getContor() {
    return this->contor; 
}

Book::Book(int id, std::string author, std::string title, std::string publisher, int year)
{
    this->m_id = id;
    this->m_title = title;
    this->m_author = author;
    this->m_publisher = publisher;
    this->m_publicationYear = year;
}

Book::Book(std::string author, std::string title, std::string publisher, int year)
{
    this->m_title = title;
    this->m_author = author;
    this->m_publisher = publisher;
    this->m_publicationYear = year;
}

Book::Book(std::string author, std::string title)
{
    this->m_author = author; 
    this->m_title = title; 
}

std::string Book::getTitle()
{
    return m_title;
}

std::string Book::getAuthor()
{
    return m_author;
}

int Book::getId()
{
    return m_id;
}

void Book::setTitle(std::string title)
{
    this->m_title = title;
}

void Book::setAuthor(std::string author)
{
    this->m_author = author;
}

void Book::setId(int id)
{
    this->m_id = id;
}

void Book::setPublicationYear(int year)
{
    this->m_publicationYear = year;
}

int Book::getPublicationYear()
{
    return m_publicationYear;
}

void Book::setPublisher(std::string publisher)
{
    this->m_publisher = publisher;
}

std::string Book::getPublisher()
{
    return m_publisher;
}

Book::~Book()
{

}

std::string Book::bookString()
{
    return std::to_string(this->m_id) + " " + this->m_author + " " + this->m_title + " " + this->m_publisher + " " + std::to_string(this->m_publicationYear);
}

void Book::display(ostream& os) const
{
    os << m_id << " " << m_title << " " << m_author << " " << m_publisher << " " << m_publicationYear;

}

bool Book::operator==(const Book& otherBook) {
    if (this->m_title.compare(otherBook.m_title)==0)
        return true; 
    else return false; 
}

ostream& operator<<(ostream& os, const Book& b)
{
    b.display(os);
    return os;
}

ifstream& operator>>(ifstream& in, Book& b) {
    in >> b.m_id;
    in >> b.m_author; 
    in >> b.m_title; 
    in >> b.m_publisher; 
    in >> b.m_publicationYear; 

    return in; 
     
}
