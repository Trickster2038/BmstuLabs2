#include <iostream>
using namespace std;
class TPoint
{
 private:      float x,y;
 public:
    TPoint(float ax,float ay):x(ax),y(ay){}
    TPoint(){}
    void Out(void)	 
    {   cout<<"\n{"<<x<<","<<y<<"}\n"; }
    TPoint& operator-()            // -a Ц одноместна€ операци€
    {   x=-x;  y=-y;  return *this;  }
    TPoint& operator+=(TPoint &p)  // a+=b Ц двуместна€ операци€ 
    {   x+=p.x; y+=p.y;  return *this;  }
    TPoint operator+(TPoint &p)    // a+b Ц двуместна€ операци€
    {   TPoint pp(x,y);  return pp+=p;  }
}; 
void main()
{
    TPoint p(2,3),q(4,5),r(7,8);
    -q;     q.Out();
    p+=r;   p.Out();
    q=p+r;  q.Out();
    system("pause");
}
