#pragma once
#include "Repository.h"
#include "Controller.h"
class Testing
{
private: 
	void testRepositoryDisplay(); 
	void testRepositoryAdd(); 
	void testRepositoryDelete(); 
	void testRepositoryUpdate(); 

	


public: 
	Testing() {} 
	void testRepository();
	void testController(); 
	void testAll(); 
	~Testing(); 
};

