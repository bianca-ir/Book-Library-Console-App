#include "UI.h"
#include "Validator.h"

void UI::menu()
{
	cout << endl; 
	cout << "Options: " << endl; 
	cout << "\t1. Add book" << endl; 
	cout << "\t2. Remove book by id" << endl; 
	cout << "\t3. Update book by id" << endl; 
	cout << "\t4. List books published before a certain year" << endl; 
	cout << "\t5. List books from a certain author" << endl; 
	cout << "\t6. Print all books" << endl; 
	cout << "\t0. Exit"; 
}

int UI::command()
{
	int command;
	cout << endl; 
	cout << "Choose an option: "; 
	cin >> command; 
	while (command < 0 && command > 6) {
		cout << "Not a valid option."; 
		cin >> command; 
	}
	return command;
}

void UI::run()
{
	int command; 

	while (true) {
		this->menu(); 
		command = this->command(); 
		switch (command) {
		case 1: 
			this->addBook();
			cout << "The book was added." << endl; 
			break; 
		case 2: 
			this->removeBook(); 
			cout << "Book was deleted" << endl; 
			break; 
		case 3: 
			this->updateBook(); 
			cout << "Book was updated." << endl; 
			break; 
		case 4: 
			this->listBooksLessThanYear(); 
			cout << endl; 
			break; 
		case 5: 
			this->listBooksFromAuthor(); 
			cout << endl; 
			break; 
		case 6: 
			cout << "The available books are: "; 
			cout << endl; 
			this->printAll(); 
			break; 
	
		case 0: 
			break; 
		default:
			break; 

			
		}
	}
}

void UI::addBook() { 
	cout << "What type of book do you want to add?" << endl; 
	cout << "\t1. Audiobook"; 
	cout << "\t2. eBook"; 
	cout << endl; 
	int type; 
	cin >> type; 
	while (type != AUDIOBOOK and type != EBOOK) {
		cout << "Not a valid option."; 
		cin >> type; 
	}

	this->convertAdd(type); 
	
}

void UI::convertAdd(int type) {
	int id;
	std::string author; 
	std::string title; 
	std::string publisher; 
	int year; 
	float len; 
	std::string format; 


	switch (type) {
	case AUDIOBOOK:
	{
		// check if it already exists 
		cout << "Enter ID: ";
		cin >> id;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			this->validator.validateId(id);
			while (this->ctrl.CTRLSearchBook(id) != -1) {
				cout << "It already exists.";
				cin >> id;
			}

		cout << "Enter author: ";
	
		
		getline(cin, author); 
		this->validator.validateAuthor(author);

		cout << "Enter title: ";
		getline(cin, title); 
		this->validator.validateTitle(title);

		cout << "Enter publisher: ";
		getline(cin, publisher); 
		this->validator.validatePublisher(publisher);

		cout << "Enter year: ";
		cin >> year;
		this->validator.validateYear(year);

		cout << "Enter length (in hours): ";
		cin >> len;
		this->validator.validateLength(len); 
		Book* audiobook = new Audiobook(id, author, title, publisher, year, len);
		this->ctrl.CTRLAddBook(audiobook);
		break;
	}
	case EBOOK: 
	{
		// check if it already exists 
		cout << "Enter ID: ";
		cin >> id;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->validator.validateId(id);
		while (this->ctrl.CTRLSearchBook(id) != -1) {
			cout << "It already exists.";
			cin >> id;
		}
		cout << "Enter author: ";
		getline(cin, author); 
		this->validator.validateAuthor(author);

		cout << "Enter title: ";
		getline(cin, title); 
		this->validator.validateTitle(title);

		cout << "Enter publisher: ";
		getline(cin, publisher); 
		this->validator.validatePublisher(publisher);

		cout << "Enter year: ";
		cin >> year;
		this->validator.validateYear(year);

		cout << "Enter format (PDF, EPUB, MOBI): ";
		cin >> format;
		this->validator.validateFormat(format);
		Book* ebook = new EBook(id, author, title, publisher, year, format);
		this->ctrl.CTRLAddBook(ebook);
		break;
	}
	default:
		break; 

	}
}

void UI::convertUpdate(int type) {
	int id; 
	std::string author;
	std::string title;
	std::string publisher;
	int year;
	float len;
	std::string format;
	switch (type) {
	case AUDIOBOOK: 
		cout << "Enter id of the audiobook to be updated: "; 
		cin >> id; 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->validator.validateId(id); 
		while (this->ctrl.CTRLSearchBook(id) == -1) {
			cout << "It does not exist.";
			cin >> id;
		}
		cout << "Enter new author: ";
		getline(cin, author); 
		this->validator.validateAuthor(author);

		cout << "Enter new title: ";
		getline(cin, title); 
		this->validator.validateTitle(title);

		cout << "Enter new publisher: ";
		getline(cin, publisher); 
		this->validator.validatePublisher(publisher);

		cout << "Enter new year: ";
		cin >> year; 
		this->validator.validateYear(year);

		cout << "Enter new length (in hours): ";
		cin >> len;
		this->validator.validateLength(len);

		this->ctrl.CTRLUpdateAudiobook(id, author, title, publisher, year, len); 
		break; 
	case EBOOK: 
		// check if it already exists 
		cout << "Enter ID: ";
		cin >> id;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		this->validator.validateId(id);
		while (this->ctrl.CTRLSearchBook(id) == -1) {
			cout << "It does not exist.";
			cin >> id;
		}
		cout << "Enter new author: ";
		getline(cin, author); 
		this->validator.validateAuthor(author);

		cout << "Enter new title: ";
		getline(cin, title); 
		this->validator.validateTitle(title);

		cout << "Enter new publisher: ";
		getline(cin, publisher); 
		this->validator.validatePublisher(publisher);

		cout << "Enter new year: ";
		cin >> year;
		this->validator.validateYear(year);

		cout << "Enter new format (PDF, EPUB, MOBI): ";
		cin >> format;
		this->validator.validateFormat(format);

		this->ctrl.CTRLUpdateEbook(id, author, title, publisher, year, format); 
		break; 

	}

}


void UI::removeBook() {
	cout << "What book do you want to remove? Enter id: " << endl; 
	int id; 
	cin >> id; 
	while (id < 1) {
		cout << "Not a valid option."; 
		cin >> id; 
	}

	this->validator.validateId(id); 
	this->ctrl.CTRLRemoveBook(id); 
	
}

void UI::updateBook() {
	cout << "What type of book do you want to update?" << endl;
	cout << "\t1. Audiobook";
	cout << "\t2. eBook";
	cout << endl; 
	int type;
	cin >> type;
	while (type != AUDIOBOOK and type != EBOOK) {
		cout << "Not a valid option.";
		cin >> type;
	}

	this->convertUpdate(type); 
}

void UI::printAll() { 
	std::vector<Book*> allBooks = this->ctrl.getAll(); 
	for (size_t i = 0; i < allBooks.size(); i++) {
		std::cout << allBooks[i]->bookString(); 
	}
}


void UI::listBooksLessThanYear() {
	cout << "What is your year of choice? Enter year: " << endl; 
	int year; 
	cin >> year; 
	std::vector<Book*> allBooksFiltered = this->ctrl.CTRLFilterByYear(year); 
	for (size_t i = 0; i < allBooksFiltered.size(); i++) {
		std::cout << allBooksFiltered[i]->bookString();
	}
}

void UI::listBooksFromAuthor() {
	cout << "What is your author of choice? Enter author: " << endl; 
	std::string author; 
	getline(cin, author); 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::vector<Book*> allBooksFiltered = this->ctrl.CTRLFilterByAuthor(author);
	for (size_t i = 0; i < allBooksFiltered.size(); i++) {
		std::cout << allBooksFiltered[i]->bookString();
	}
}


