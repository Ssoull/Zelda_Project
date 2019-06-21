#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

class View : public QMainWindow
{
    Q_OBJECT
public:
    explicit View(QWidget *parent = nullptr);

    ~View();
};

#endif // VIEW_H
