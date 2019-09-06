#include "view/view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Model *model = new Model();
    Controller *controller = new Controller(model);
    View *view = new View(model, controller);

    view->show();

    app.exec();

    delete model;
    delete controller;
    delete view;

    return 0;
}
