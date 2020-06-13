#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
	
	string name;
	int score;
	
	// < 运算符重载，类似于Java中重写equals方法 
	bool operator<(const Student &otherStudent) {
		
		return score < otherStudent.score;
	}
	
	// << 运算符重载，类似于Java中重写toString方法 
	friend ostream& operator<<(ostream &os, const Student &student) {
		
		os<<"Student: "<<student.name<<" "<<student.score<<endl;
		return os;
	}
};
#endif //SELECTIONSORT_STUDENT_H
