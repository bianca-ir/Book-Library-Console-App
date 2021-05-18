#pragma once

#include <iostream>
#include <string>
#include "Repository.h"
#include "FileRepository.h"
#include "Controller.h"
#include "Book.h"
#include "Testing.h"
#include "UI.h"
#include <ostream>

int main()
{
	Testing tests{}; 
//	tests.testAll(); 
	


	vector<Book*> vect; 
	
	Repository repo{ vect }; 
	Controller controller{repo};

	UI ui{controller}; 
	ui.run(); 

	



	return 0;
}
