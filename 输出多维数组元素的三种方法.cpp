#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int ia[3][4] = { 2,4,5,6,8,11,13,14,17,19,22,25 };
	//编写3个不同版本的程序，令其均能输出ia的元素，
	//且不能使用类型别名/auto关键字或decltype关键字。
	//v1:使用范围for语句管理迭代过程；
	//v2:使用普通for语句，用下标运算符；
	//v3:使用普通for语句，使用指针；
	for (int (&a1)[4] : ia) {	//v1
		for (int a2 : a1)
			cout << a2 << " ";
		cout << endl;
	}
	for (int i = 0; i != 3; i++) {	//v2
		for (int j = 0; j != 4; j++)
			cout << ia[i][j] << " ";
		cout << endl;
	}
	for (int(*p)[4] = begin(ia); p != end(ia); p++) {	//v3
		for (int *q = begin(*p); q != end(*p); q++)
			cout << *q << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}

