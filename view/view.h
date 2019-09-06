#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "model/model.h"
#include "controller/controller.h"
#include "graphicplayer.h"

class View : public QGraphicsView
{
    Q_OBJECT
private:
    Model *m_model;
    Controller *m_controller;

    QGraphicsScene *m_scene;

    GraphicPlayer *m_graphicalPlayer;

public:
    explicit View(Model *model, Controller *controller, QWidget *parent = nullptr);

    ~View();
};

#endif // VIEW_H
