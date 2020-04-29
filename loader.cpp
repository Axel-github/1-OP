#include "loader.h"
#include <iostream>
#include "store.h"
#include <iomanip>
Loader::Loader(std::string filename)
{
	fp.open(filename);
	if (fp.is_open())
	{
		std::cout << "Файл открыт" << std::endl;
	}
	else
	{
		Loader::~Loader();
	}
}

Loader::~Loader()
{
	fp.close();
	std::cout << "Открыть файл не удалось" << std::endl;
}

void Loader::Save(Store nm)
{
	fp << nm.getAllByStr();
}

Store Loader::Load()
{
	int id;
	std::string name;
	int type;
	float price;
	
	Store *tempStore = new Store("Магнит",1987);
	/*
	while (std::getline(fp, line))
	{
		if (i == 0)id = stoi(line);
		else if (i == 1)name = line;
		else if (i == 2) 
		{
			type = stoi(line);
			std::cout << line << std::endl;
			std::cin >> anus;
			tempStore->AddItem(id, name, type);
		}

	}
	*/
	while (fp >> id >> name >> type >> std::fixed >> std::setprecision(2) >> price)
	{
		tempStore->AddItem(type,name,id,price);
	}
	
	return *tempStore;
}



