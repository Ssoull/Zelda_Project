#include "view/view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    View *view = new View();
    view->show();

    app.exec();

    delete view;

    return 0;
}
