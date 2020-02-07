#include <locale.h>
#include <iostream>
#include <string.h>
using namespace std;
template <class type>    // ���������� ������� � ���������� type
class Tset     
{ 
 private:
    type *contents;   // ��������� �� ������������ ������ ���� type
    int size;         // ������������ ������ ���������
    int SetEl(int ind, type m) // ������� ������ �������� � ������
    {  
        if (ind<size)   
        {   contents[ind]=m; sizetek+=1; return 1;  }
        else 
        {
            cout<<"�������� ������ ��������� "<<endl;
            return 0;
        }  
    }
public:
    int sizetek;      // ������� ������ ���������
    type GetEl(int ind)   // ������� ������ �������� �� �������
    {   return contents[ind];}
    Tset(){  contents=NULL;}
    Tset(Tset &A);        // �������� ����������� ������������
    Tset(int number)      // ����������� ������ Tset
    {   contents = new type [size=number];sizetek=0;}
    ~Tset(){ if (contents!=NULL) delete [] contents; } 
    int Getsize()         // ������������ ������ ��������� 
    {   return size;  }
    void Add(type m);     // ���������� �������� � ���������
    void Del(type m);     // �������� �������� �� ���������
    int  In(type m);  // �������� ��������� �������� �� ���������
    int  InSet(int Nn);    // ���������� ���������
    void  OutSet();        // ����� ��������� ���������
    Tset& CrossSet(Tset &B);   // ����������� ��������
    Tset &operator +(Tset &B); // ����������� ��������
    Tset &operator =(Tset &B); // ������������ ��������
};   
template <class type> Tset<type>::Tset(Tset<type>&A)
{ 
    contents = new type [size=A.Getsize()];
    sizetek=A.sizetek;
    for(int i=0;i<sizetek;i++)   
        contents[i]=A.contents[i];    
}
template <class type> int Tset<type>::InSet(int Nn)
{ 
    type c; int k=0;
    if (Nn>Getsize()) Nn=Getsize();
    cout<<"������� "<<Nn<<" ��������� ���������: "<<endl;
    for (int i=0;i<Nn;i++)
    { 
        cin>>c;  
        if (!In(c))
        {  if(!SetEl(k,c)) return 0;  k+=1;} 
    }
    return 1;  
}
template <class type> void Tset<type>::OutSet()
{   
    if (sizetek!=0)  
    {
        for(int i=0;i<sizetek;i++) 
           cout<<" "<<GetEl(i);
    }
    else cout<<" ������ ���������";
    cout<<endl;     
}
template <class type> int Tset<type>::In(type m)
{  
    for (int i=0;i<sizetek;i++)  
        if (m==GetEl(i)) return 1;
    return 0; 
}
template <class type> void Tset<type>::Add(type m)
{ 
    if (!In(m))   
        if (sizetek<size) SetEl(sizetek,m);   
}
template <class type> void Tset<type>::Del(type m)
{ 
    int h;
    if (In(m))  
    { 
        h=0;
        for(int i=0;i<sizetek;i++)
           if(h) contents[i-1]=contents[i];
           else if (m==GetEl(i)) h=1;
        sizetek-=1; 
     }     
}
template <class type> 
Tset<type>& Tset<type>::operator =(Tset<type> &B)
{ 
    if (this==&B) return *this;
    if (contents!=NULL) delete [] contents;
    contents = new type [size=B.Getsize()];
    sizetek=B.sizetek;
    for(int i=0;i<sizetek;i++)  
    {   contents[i]=B.contents[i];} 
    return *this; }
template <class type> 
Tset<type> & Tset<type>::operator +(Tset<type> &B)
{  
    for(int i=0;i<B.sizetek;i++) 
    Add(B.GetEl(i));   return *this;   
}
template <class type> 
Tset<type> &Tset<type>::CrossSet(Tset<type> &B)
{ 
    int i=0;
    do  
    { 
       if( !B.In(GetEl(i)))  
           Del(GetEl(i)); 
       else i++;
     }  while (i<sizetek);
     return *this;  
}
template <class type> 
Tset<type>& operator -(Tset<type> &A,Tset<type> &B)
{  
    Tset<char> *C=new Tset<char>(A.Getsize());
    for(int i=0;i<A.sizetek;i++)  
       if(!B.In(A.GetEl(i)))  C->Add(A.GetEl(i));
    return *C;      
}
template <class type> 
Tset<type>& operator*(Tset<type>&A,Tset<type> &B)
{  
    int l;
    if(A.Getsize() > B.Getsize()) l=A.Getsize();   
    else l=B.Getsize();
    Tset<char> *C=new Tset<char>(l);
    for(int i=0;i<A.sizetek;i++)
    { 
        if( B.In(A.GetEl(i))) C->Add(A.GetEl(i));
    }
    return *C; 
} 
void main()
{  
    setlocale(0,"russian");   
    int n;   
    Tset<char> aa(15),bb(10),dd(10),cc;
    cout<<"������� �������� ��������� n<= ";
    cout<<aa.Getsize()<<endl;    cin>>n;  
    aa.InSet(n);
    cout<<"������� �������� ��������� n<= ";
    cout<<bb.Getsize()<<endl;    cin>>n; 
    bb.InSet(n);
    cout<<"������� ��������� ��������� n<= ";
    cout<<dd.Getsize()<<endl;    cin>>n;  
    dd.InSet(n);
    cout<<" ��������� aa: ";  aa.OutSet();
    cout<<" ��������� bb: ";  bb.OutSet();
    cout<<" ��������� dd: ";  dd.OutSet();
    Tset<char> ee,pp=aa; // ������������� ����������� ������������
    cout<<" ��������� pp=aa: ";  pp.OutSet();
    ee=aa*bb;
    cout<<"ee=aa*bb="; ee.OutSet();
    aa.CrossSet(bb);
    cout<<"aa.CrossSet(bb)=";  aa.OutSet();
    aa=aa+dd; 
    cout<<"aa=aa+dd=";  aa.OutSet();
    cc=dd-bb; 
    cout<<"cc=dd-bb";   cc.OutSet();
    system("pause"); 
}
