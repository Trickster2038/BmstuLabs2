//#include <QPainter>
#include "drawer.h"
#include "figures.h"
#include <QPainter>

CDrawer::CDrawer(QWidget *parent): QWidget(parent)
{ 
setFixedSize(QSize(800,300));
f1 = new CCircle();
f2 = new CSquare();
f3 = new CEllipse();
f1->sett(125,125,1);
f2->sett(375,125,3);
f3->sett(625,125,1);
}
 
void CDrawer::paintEvent(QPaintEvent *e) {
    
  Q_UNUSED(e);
  
  QPainter qp(this);
  drawFigure(&qp,0);
  drawFigure(&qp,1);
  drawFigure(&qp,2);
}
 
void CDrawer::drawFigure(QPainter *qp, int id) {
  
  QPen pen(Qt::black, 2, Qt::SolidLine);  
  qp->setPen(pen);
  // CCircle f1(125,125,1);
  // CSquare f2(375,125,5);
  // CEllipse f3(625,125,9);
  switch(id){
    case 0:
      f1->redraw(qp);
    break;
    case 1:
      f2->redraw(qp);
    break;
    case 2:
      f3->redraw(qp);
    break;
  }
}