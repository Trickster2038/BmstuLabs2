#ifndef bookFile_h
#define bookFile_h
#include <QFile>

struct recType   // ��������� ������ ��� ������ ��������
{	QString fam,name,nom;   };

class bookFile 
{	
	bool k1,k2,k3,k4,ff; // ����� ������
public:
	QFile * f;    // ��������� �� ������ ������ QFile
	recType r;  // ����� �����-������
	bookFile();  // �����������
	~bookFile(); // ����������
	bool addRec(recType r); // ���������� ������ � ����
	bool readRec();	    // ������ ������ �� �����
	bool findFirst(const recType r1); // ����� ������ 
                                                         // ������, ��������������� �������
	bool findNext(const recType r1);
                       // ����� ��������� ������
};
#endif
