#include "guitar.h"

#include <iostream>
#include <sstream>
#include <iomanip>

const std::vector<std::string> Guitar::forType = { "Классическая","Акустическая","Электрическая", "Электроакуст.","Другое"};

void Guitar::printOnceInfo()
{
	std::cout << "id:" << _id << " \tНаименование: " << _name << " \tТип: " << forType[_type] << " \tЦена: " << std::fixed << std::setprecision(2) <<_price << std::endl;
}
Guitar::Guitar(int id, std::string name, int type, float price)
{
	this->_id = id;
	this->_name = name;
	this->_price = price;
	this->_type = type;
	
	if (type >= 0 && type < Guitar::forType.size())this->_type = type;
	else this->_type = forType.size()-1;
	
}

/*Guitar::Guitar(int id, std::string name)
{
	this->_id = id;
	this->_name = name;
	this->_type = 0;
}*/

int Guitar::getId()
{
	return this->_id;
}

std::string Guitar::getGuitarSuchStr()
{
	std::stringstream ss;
	std::string str;
	ss << std::fixed << std::setprecision(2) << _price;
	ss >> str;
	return std::to_string(_id) + " " + _name + " " + std::to_string(_type) + " " + str;
}
