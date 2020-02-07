#include <iostream>
using namespace std;
class TP
{
 private:      float x,y;
 public:
    TP(float ax,float ay):x(ax),y(ay)
    {   cout<<"Constructor\n";}
    TP()
    {   cout<<"Constructor without parameters\n";}
    TP(TP &p)
    {   cout<<"Copy\n";  x=p.x; y=p.y;   }
    ~TP(){cout<<"Destructor\n";}
    void Out(void)	 
    {   cout<<"\n{"<<x<<","<<y<<"}\n"; }
    TP& operator+=(TP &p)  // a+=b 
    {
        x+=p.x; y+=p.y;  cout<<"operator+=\n";
        return *this;
    }
    TP operator+(TP &p)    // a+b
    {
        TP pp(x,y);  cout<<"operator+\n";
        return pp+=p;
    }
    TP& operator=(TP &p)   // a=b
    {
        x=p.x; y=p.y;    cout<<"operator=\n";
        return *this;
    }
}; 
void main()
{
    TP p(2,3),q(4,5),r(7,8);
    p+=r;    p.Out();
    q=p+r;   q.Out();
    system("pause"); 
}
