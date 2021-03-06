#ifndef figures_h
#define figures_h
#include <QPainter>
#include <QRectF>
#include <QWidget>
#include <cmath> 
 
class CFigure{
  protected:
  	int xc, yc, t, dt;
    void tick();
 
  public:
    void sett(int a1, int a2, int a3);
    CFigure();
    void redraw(QPainter *qpp);
};

class CCircle: public CFigure{
 
  public:
    void sett(int a1, int a2, int a3);
    void redraw(QPainter *qpp);
};

class CSquare: public CFigure{
 
  public:
    void sett(int a1, int a2, int a3);
    void redraw(QPainter *qpp);
};

class CEllipse: public CFigure{
 
  public:
    void sett(int a1, int a2, int a3);
    void redraw(QPainter *qpp);
};

#endif