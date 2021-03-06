// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Sales_item.h"
#include "Sales_data.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using std::cin;  using std::cout; using std::endl;
using std::string;
using std::vector;
using std::begin; using std::end;

extern void statistics_string();
int main()
{
	int grade1[11]{ 4,5,6,7,8,9,18,20,26,28,30};
	int grade2[13]{ 4,5,6,7,8,25,10,11,12,13,30,18,21};
	int length1, length2,lmin,lmax;
	bool g1min;
	length1 = end(grade1) - begin(grade1);
	length2 = end(grade2) - begin(grade2);
	if (length2 > length1) {
		lmin = length1;
		lmax = length2;
		g1min = true;
	}
	else {
		lmin = length2;
		lmax = length1;
		g1min = false;
	}
	for (int i = 0; i != lmin; i++) {
		if (grade1[i] != grade2[i])
			cout << "#" << i << "\t" << grade1[i] <<"\t"<< grade2[i] << endl;
	}
	for (int i = lmin; i != lmax; i++) {
		if (g1min) {
			cout << "#" << i << "\t" << " " << "\t" << grade2[i]<<endl;
		}
		else {
			cout << "#" << i << "\t" << grade1[i] << "\t" <<" "<<endl ;
		}
	}
	cout << endl;
	system("pause");
    return 0;
}

