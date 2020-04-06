#include "figures.h"
using namespace std;

void CFigure::sett(int a1, int a2, int a3){
	xc = a1;
	yc = a2;
	t = 0;
	dt = a3;
}
CFigure::CFigure(){
	xc = 300;
	yc = 300;
	t = 0;
	dt = 0;
}

void CFigure::tick(){
	t += dt;
}

void CFigure::redraw(QPainter *qpp){

}

void CCircle::redraw(QPainter *qpp){
 QRectF rect(xc - 110, yc - 110, xc + 110, yc + 110);
 qpp->eraseRect(rect);
 qpp->drawPie(rect, t*16 , 270 *16);
 tick();
}

void CSquare::redraw(QPainter *qpp){
int x1, y1, x2, y2, x3, y3, x4, y4;
 QRectF rect(xc - 125, yc - 125, xc + 125, yc + 125);
qpp->eraseRect(rect);
  x1 = xc - int(90 * cos(t));
  y1 = yc - int(90 * sin(t));
  x2 = xc - int(90 * cos(t + 3.14 / 2));
  y2 = yc - int(90 * sin(t + 3.14 / 2));
  x3 = xc - int(90 * cos(t + 3.14));
  y3 = yc - int(90 * sin(t + 3.14));
  x4 = xc - int(90 * cos(t + 3 * 3.14 / 2));
  y4 = yc - int(90 * sin(t + 3 * 3.14 / 2));
  qpp->drawLine(x1, y1, x2, y2);
  qpp->drawLine(x2, y2, x3, y3);
  qpp->drawLine(x3, y3, x4, y4);
  qpp->drawLine(x4, y4, x1, y1);
  tick();
}

void CEllipse::redraw(QPainter *qpp){
 int x1, y1, x2, y2, x3, y3, x4, y4, xc1, yc1, xc2, yc2;
  QRectF rect(xc - 125, yc - 125, xc + 125, yc + 125);
  qpp->eraseRect(rect);
  x1 = xc - int(60 * cos(t));
  y1 = yc - int(60 * sin(t));
  x2 = xc - int(60 * cos(t + 3.14 / 2));
  y2 = yc - int(60 * sin(t + 3.14 / 2));
  x3 = xc - int(60 * cos(t + 3.14));
  y3 = yc - int(60 * sin(t + 3.14));
  x4 = xc - int(60 * cos(t + 3 * 3.14 / 2));
  y4 = yc - int(60 * sin(t + 3 * 3.14 / 2));
  xc1 = int((x2 + x3) / 2);
  yc1 = int((y2 + y3) / 2);
  xc2 = int((x4 + x1) / 2);
  yc2 = int((y4 + y1) / 2);

  //Self.canv.canvas.line(xc1, yc1, xc2, yc2);
  qpp->drawLine(x1, y1, x2, y2);
  //Self.canv.canvas.line(x2, y2, x3, y3);
  qpp->drawLine(x3, y3, x4, y4);
  //Self.canv.canvas.line(x4, y4, x1, y1);

  qpp->drawArc(xc1 - 40, yc1 - 40, 80, 80, (-t*180*16)/3.14 - 45*16, +180*16);
  qpp->drawArc(xc2 - 40, yc2 - 40, 80, 80, (-t*180*16)/3.14- 45*16, -180*16);
  tick();
}

void CCircle::sett(int a1, int a2, int a3){
	xc = a1;
	yc = a2;
	t = 0;
	dt = a3;
}
void CSquare::sett(int a1, int a2, int a3){
	xc = a1;
	yc = a2;
	t = 0;
	dt = a3;
}
void CEllipse::sett(int a1, int a2, int a3){
	xc = a1;
	yc = a2;
	t = 0;
	dt = a3;
}