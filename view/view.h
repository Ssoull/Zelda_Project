#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

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

    GraphicPlayer *m_graphicPlayer;

    void checkMoveInput(QKeyEvent *event);

    void updateTilemap();

public:
    explicit View(Model *model, Controller *controller, QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent *event) override;

    ~View() override;
};

#endif // VIEW_H
