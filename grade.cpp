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
//不使用下标运算符，实现划分分数段。（统计0~9，10~19，20~29……各个分数段的人数）
int main()
{
	vector<int>text{ 3,5,8,12,16,29,32,36,38,39,52,57,58,62,69,72,78,82,83,85,88,92,95,97,99 };
	vector<int> grade( 11,0 );
	auto beg = text.begin(), end = text.end();
	while (beg != end-1) {
		auto a = grade.begin();
		a += *beg / 10;
		*a += 1;
		beg++;
	}
	for (auto a : grade)
		cout << a << " ";
	cout << endl;
	system("pause");
    return 0;
}

