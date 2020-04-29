#pragma once

#include <string>
#include "guitar.h"
#include <vector>


class Store
{
private:
	std::string _name;
	int _year;
	std::vector<Guitar> _items;
public:
	Store(std::string name, int year);
	void PrintItemsInfo();
	void AddItem(int id, std::string name, int type, float price);
	void EditItem(int id);
	std::string getAllByStr();
	void RemoveItemById(int id);
	//void PrintStat();


};