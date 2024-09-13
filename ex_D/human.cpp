#include "human.h"

Human::Human(const char *nam = "", double x = 0, double y = 0) : name(new char[strlen(nam) + 1])
{
    strcpy(this->name, nam);
    location.set_x(x);
    location.set_y(y);
}

void Human::set_name(char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Human::display()
{
    cout << "Human Name: " << name << "\nHuman Location: "
         << location.get_x() << " ,"
         << location.get_y() << ".\n"
         << endl;
}