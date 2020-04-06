#ifndef drawer_h
#define drawer_h
#include <QWidget>
#include "figures.h"
#include <QPainter>
class CDrawer : public QWidget {
 
  public:
    CDrawer(QWidget *parent = 0);
 
  protected:
    void paintEvent(QPaintEvent *event);
    void drawFigure(QPainter *qp, int id);
    CCircle *f1;
    CSquare *f2;
    CEllipse *f3;
};

#endif