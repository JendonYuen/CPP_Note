#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{	//删除无序vector中的相同元素
	vector<int> v= { 0,0,6,2,3,8,4,3,7,5,2,1,9,0,6,2,10,0,0,-12 };
	vector<int> vsign;		//定义一个vsign容器，用于存放标记删除的元素
	for (int i1 = v.size() - 1; i1 != -1; i1--) {	//从容器最后一个元素依次向前循环
		for (int i2 = i1 - 1; i2 != -1; i2--) {
			if(v[i1]==v[i2]){						//比较是否相等，相等则标记该元素
				vsign.push_back(i1);
				i2 = 0;								//直接跳出该循环，避免重复标记，优化计算，并避免重复删除
			}
		}
	}
	for (auto a : vsign) {
//		cout <<"["<< a <<"]"<< " ";
		v.erase(v.begin()+a);		//从后向前删除，不会影响前面元素的下标。
	}
	cout << endl;
	for (auto a : v)
		cout << a << " ";
	cout << endl;
	system("pause");
    return 0;
}