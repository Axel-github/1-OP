#include "store.h"
#include "checker.h"

Store::Store(std::string name, int year)
{
	this->_name = name;
	this->_year = year;
}

void Store::PrintItemsInfo()
{
	for (auto it : _items)
	{
		it.printOnceInfo();
	}
}

void Store::AddItem(int id, std::string name, int type, float price)
{
	_items.push_back(Guitar(type, name, id,  price));
}
void Store::EditItem(int id)
{	
	int temp;
	for (int i = 0; i < _items.size(); i++)
	{
		if (_items.at(i).getId() == id)
		{
			temp = id;
			_items.erase(_items.begin() + i);
			AddItem(Checker::getValue("тип"), Checker::getStrValue("имя"), temp, Checker::getFLValue("цена"));
			break;
		}
	}

}
std::string Store::getAllByStr()
{
	std::string buf;
	for (auto it : _items)
	{
		buf += it.getGuitarSuchStr() + "\n";
	}
	return buf;
}
void Store::RemoveItemById(int id)
{
	for (int i = 0; i < _items.size(); i++)
	{
		if (_items.at(i).getId() == id) 
		{
			_items.erase(_items.begin()+i);
			break;
		}
	}
}

/*void Store::AddItem(int type, std::string name, int id)
{
	_items.push_back(Guitar(id, name, type));
}*/
