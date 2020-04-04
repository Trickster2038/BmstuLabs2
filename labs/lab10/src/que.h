#include <iostream>
#include <vector>
using namespace std;

class CQueue {
protected:
	vector<char> queuef;
	int lng;
	int p;
public:
	void add(char arg);
	void rm();
	//void setlng(); 
	int getlng();
	void reset();
	char gett();
};

class CSmartQ : public CQueue {
public:
	void sort();
};