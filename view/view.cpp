#include "view.h"
#include <iostream>

View::View(QWidget *parent) : QMainWindow(parent)
{

}


View::~View()
{
    std::cout << "View: Passed in the destructor" << std::endl;
}
