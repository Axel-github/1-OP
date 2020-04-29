#pragma once
#include <fstream>
#include <string>
#include "store.h"

class Loader
{
private:
	std::fstream fp;
public:
	Loader(std::string filename);
	~Loader();
	void Save(Store nm);
	Store Load();
};

