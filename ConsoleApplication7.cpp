#include <iostream>
#include <vector>
#include "store.h"      
#include <iterator>   
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "loader.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    
    Loader* ld = new Loader("db.txt");
    Store magaz = ld->Load();
    Menu menu = Menu(magaz);
    menu.Run();
    
    return 0;
}
