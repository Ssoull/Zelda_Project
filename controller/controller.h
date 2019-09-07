#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"

class Controller
{
private:
    Model *m_model;

public:
    Controller(Model *model);

    bool manageInput(char input);

    void checkCollision();
};

#endif // CONTROLLER_H
