#include <iostream>
#include <vector>
#include "que.h"
using namespace std;



void CQueue::add(char arg) {
	queuef.push_back(arg);
}
void CQueue::rm() {
	queuef.pop_back();
}
// void CQueue::setlng() {
// 	lng = 0;
// 	for (vector<char>::iterator i = queuef.begin(); i != queuef.end(); ++i) {
// 		lng++;
// 	}
// }
int CQueue::getlng() {
	lng = 0;
	for (vector<char>::iterator i = queuef.begin(); i != queuef.end(); ++i) {
		lng++;
	}
	return lng;
}
void CQueue::reset() {
	p = -1;
}
char CQueue::gett() {
	p++;
	return queuef[p];
}


void CSmartQ::sort() {
	bool sorted = false;
	while (!(sorted)) {
		sorted = true;
		for (vector<char>::iterator i = queuef.begin(); i != (queuef.end()-1); ++i) {
			if ((*i) > * (i + 1)) {
				char buf;
				buf = *i;
				*i = *(i + 1);
				*(i + 1) = buf;
				sorted = false;
			}
		}
	}
}