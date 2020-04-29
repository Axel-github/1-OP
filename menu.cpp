#include "menu.h"
#include <iostream>

#include "checker.h"
#include "loader.h"

using namespace std;
Menu::Menu(Store &name)
{
    magaz = &name;
    ld = new Loader("db.txt");

    nameItemMenu.push_back("Вывести элементы");
    nameItemMenu.push_back("Удалить элемент");
    nameItemMenu.push_back("Добавить элемент");
    nameItemMenu.push_back("Изменить элемент");
}

void Menu::getChoice()
{
    do
    {
        choice = Checker::getValue("пункт меню (0-" + to_string(nameItemMenu.size()) + ")");
    } while (choice > nameItemMenu.size());
}

void Menu::printMenu()
{
    int i = 0;
    system("cls");
    for (auto it : nameItemMenu)
    {
        i++;
        cout << i << "." << it << "." << endl;
    }
    cout << "0.Выход." << endl;

}

void Menu::Run()
{
    std::string tmp;
    int i = 0;
    printMenu();
    getChoice();
    for (auto it : Guitar::forType)
    {
        tmp += to_string(i++) + ".";
        tmp += it;
        tmp += "\n";
    }
    switch (choice)
    {
    case 1:
        magaz->PrintItemsInfo();
        break;
    case 2:
        magaz->RemoveItemById(Checker::getValue("id удаляемого элемента"));
        break;
    case 3:
        
        magaz->AddItem (Checker::getValue("тип\n" + tmp), Checker::getStrValue("имя"), (Checker::getValue("id")), Checker::getFLValue("цена"));
        break;
    case 4:
        magaz->EditItem(Checker::getValue("id изменяемого элемента"));
        break;
    case 0 :
        ld->Save(*magaz);
        exit(0);
    default:
        break;
    }
    system("pause");
    Run();


}
