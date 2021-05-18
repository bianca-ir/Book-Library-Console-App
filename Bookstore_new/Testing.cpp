#include "Testing.h"
#include <assert.h>
#include <fstream> 

void Testing::testRepositoryDisplay()
{
	Repository testRepository{}; 
	int id = 1; 
	std::string testAuthor = "A", testTitle = "T", testPublisher = "Publisher"; 
	int testPublicationYear = 1988; 
	Book* testBook = new Book (id, testAuthor, testTitle, testPublisher, testPublicationYear); 
	testRepository.addBook(testBook); 
	std::vector<Book*> testBooksRepo = testRepository.getAllBooks(); 
	
	delete testBook; 
}

void Testing::testAll()
{
	testRepository(); 
	testController(); 
}

Testing::~Testing()
{
}

void Testing::testRepositoryAdd() { 
	Repository repoTest{}; 
	int id = 1; 
	std::string author = "Author", title = "Title", publisher = "Pub";
	int year = 2000; 
	Book* testbook = new Book(author, title, publisher, year);

	repoTest.addBook(testbook); 
	try {
		repoTest.addBook(testbook);
	}
	catch (RepositoryException& re) {
		assert(true); 
	}

	delete testbook; 
}

void Testing::testRepositoryDelete()
{
	Repository testRepository{};
	int id = 1; 
	std::string author = "Author", title = "Title", publisher = "Pub";
	int year = 2000;
	Book* testbook = new Book(author, title, publisher, year);
	(testRepository.addBook(testbook));
	(testRepository.removeBook(testbook->getId()));
	(testRepository.addBook(testbook));

	delete testbook; 
}

void Testing::testRepositoryUpdate()
{
	Repository testRepository{};
	int id = 1; 
	std::string author = "Author", title = "Title", publisher = "Pub";
	int year = 2000;
	Book* testbook = new Book(id, author, title, publisher, year);
	(testRepository.addBook(testbook));
	std::string newAuthorTest = "New"; 
	std::string newTitleTest = "New"; 
	std::string newPublisher = "New"; 
	int newYear = 2009; 
	Book* testbook2 = new Book(2, newAuthorTest, newTitleTest, newPublisher, newYear);
	(testRepository.addBook(testbook2));
	testRepository.updateBook(1, testbook2);

	delete testbook; 
	delete testbook2; 
}

void Testing::testRepository()
{
	testRepositoryAdd();
	testRepositoryDelete();
	testRepositoryUpdate();
	testRepositoryDisplay();
}

void Testing::testController() {
	vector<Book*> data; 
	Repository testRepository{ data }; 
	Controller testController(testRepository);

	// ADD test

	int idTest = 1; 
	std::string authorTest = "abcd", titleTest = "bbb", publisherTest = "publish"; 
	int yearTest = 2000; 
	Book* bookTest = new Book(idTest, authorTest, titleTest, publisherTest, yearTest);
	(testController.CTRLAddBook(bookTest)); 
	data = testController.getAll(); 

	// UPDATE test

	int idTest2 = 2;
	std::string authorTest2 = "abcd2", titleTest2 = "bbb2", publisherTest2 = "publish2";
	int yearTest2 = 1999; 
	Book* bookTest2 = new Book(idTest2, authorTest2, titleTest2, publisherTest2, yearTest2); 
	(testController.CTRLUpdateBook(idTest, bookTest2));


	// REMOVE test
	int idTest3 = 3;
	std::string authorTest3 = "abcd", titleTest3 = "bbb", publisherTest3 = "publish";
	int yearTest3 = 2000;
	Book* bookTest3 = new Book(idTest3, authorTest3, titleTest3, publisherTest3, yearTest3);
	(testController.CTRLAddBook(bookTest3));
	try {
		(testController.CTRLRemoveBook(idTest3)); 
	}
	catch (RepositoryException& re) {
		assert(re.getMessage() == "Tape does not exist.");
	} 

	delete bookTest;
	delete bookTest2; 
	delete bookTest3; 
}
