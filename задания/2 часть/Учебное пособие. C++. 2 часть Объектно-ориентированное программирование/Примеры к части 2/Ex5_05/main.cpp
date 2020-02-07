#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
class String
{
 private:     char *str,name;       int  len;
 public:  String(int Len,char Name); // ������ ������ � ������� 
     String(char *vs,char Name);  // ������������������ ������
     String(String &S);           // ����� ������
	~String();                   // ������������ ������
     int Length(){return len;}    // ����������� �����
     char operator[](int n)       // ������ ������� �� ������
     {   return ((n>=0)&&(n<len))?str[n]:'\0';  }
     void print()                 // ����� ������ � �� �����
     {   
         cout<<"Str: "<<name<<":";
         cout<<str<<" Length: "<<len<<endl; 
     }
     String  operator+(String &A);  // ������� �����
     String  operator+(char c);     // ���������� �������
     String& operator=(String &S);  // ������������ ����� 
};
String::String(int Len,char Name)
{ 
    len=Len; str=new char[len+1]; 
    str[0]='\0'; name=Name;
    cout<<"Constructor length "<<name<<"\n";
}
String::String(char *vs,char Name) 
{   
    len=strlen(vs); str=new char[len+1]; 
    strcpy(str,vs);  name=Name;
    cout<<"Constructor "<<name<<"\n";
}
String::String(String &S) 
{ 			
    len=S.Length(); str=new char[len+1]; 
    strcpy(str,S.str); name='K';
    cout<<"Copy from "<<S.name<<" to "<<name<<"\n";
}
String::~String() 
{ 
    delete [] str; 	cout<<"Destructor "<<name<<"\n"; 
}
String  String::operator+(String &A)
{ 
    cout<<"Operation +"<<"\n";  int j=len+A.Length();
    String S(j,'S');       strcpy(S.str,str);
    strcat(S.str,A.str);   cout<<"Operation +"<<"\n";
    return S;  
}
String  String::operator+(char c)
{
    cout<<"Operation +c"<<"\n";  int j=len+1;
    String S(j,'Q');       strcpy(S.str,str);
    S.str[len]=c;          S.str[len+1]='\0';
    cout<<"Operation +c"<<"\n";  
    return S;  
}
String& String::operator=(String &S) 
{ 
    cout<<"Operation ="<<"\n";  len=S.Length();
    if (str!=NULL) delete[]str; 
    str=new char[len+1];         
    strcpy(str,S.str);
    cout<<"Operation ="<<"\n";   
    return *this;
} 
void main()
{
    String A("ABC",'A'),B("DEF",'B'),C(6,'C');
    C.print();
    C=A+B;
    C.print();
    C=C+'a';
    C.print();
    system("pause"); 
}
