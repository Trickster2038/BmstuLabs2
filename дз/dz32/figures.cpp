#include "figures.h"

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

void CFigure::tick(int dt){
	t += dt;
}

void CFigure::redraw(QPainter *qpp){

}

void CCircle::redraw(QPainter *qpp){
 QRectF rect(xc - 125, yc - 125, xc + 125, yc + 125);
 qpp->drawPie(rect, t * 16, t + 90*16);
 tick(1);
}

void CSquare::redraw(QPainter *qpp){

}

void CEllipse::redraw(QPainter *qpp){

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