#pragma once
#include<vector>
#include <string>
#include "store.h"
#include "loader.h"

using namespace std;

class Menu
{
private:
	vector<string> nameItemMenu;
	int choice;
	Store *magaz;
	Loader *ld;
	

	void getChoice();
	void printMenu();
	
public:
	Menu(Store &name);
	


	void Run();
};

