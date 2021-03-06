// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h> 
#include <graphics.h>
#include <string>
#include <Windows.h>
#include <fstream>
#include <deque>
#include <array>
#include <list>
#include <iterator>

using namespace std;
extern void chose2go();
extern void chose1back();
extern void outGo();
extern void calNew(deque<int> &a1);	//根据go中每组队列计算一次结果，结合for(auto &a1:go)使用
extern void calFree();				//初始化桥两侧人员
extern void calResult();
extern void eject();
deque<int > l0 = { 1, 2, 5, 10,12,16,20,26 },l=l0, r;
deque<deque<int>> go,gotmp;
int ejTimes = 1;
int main() {
	time_t t1 = clock();
	for (int i = 0; i != l0.size() - 2; ++i) {
		chose2go();
		eject();
		cout << go.size() << "个###times:" << clock() - t1 << endl;
		chose1back();
		eject();
		cout << go.size() << "个###times:" << clock() - t1 << endl;
	}
	chose2go();
	eject();
//	outGo();
	calResult();
	cout <<go.size()<<"个###times:"<< clock() - t1<<endl;
	system("pause"); 
    return 0;
}
void chose2go() 
{
	if (go.empty()) {	//如果go为空则是第一次执行，初始化
		deque<int> tmp;
		for (int i1 = 0; i1 != l.size() - 1; ++i1)
		{
			for (int i2 = i1 + 1; i2 != l.size(); ++i2) {
				tmp = { *(l.begin() + i1),*(l.begin() + i2) };
				gotmp.push_back(tmp);
			}
		}
		//将此次计算结果导入go中
		swap(go, gotmp);
		gotmp.clear();
	}
	else {
		for (auto &a1 : go) {
			calNew(a1);
			//从左侧选两个人去桥右侧
			deque<int> tmp;
			for (int i1 = 0; i1 != l.size() - 1; ++i1)
			{
				for (int i2 = i1 + 1; i2 != l.size(); ++i2) {
					tmp = a1;
					tmp.push_back(*(l.begin() + i1));
					tmp.push_back(*(l.begin() + i2));
					//tmp = { *(l.begin() + i1),*(l.begin() + i2) };
					gotmp.push_back(tmp);
				}
			}
			calFree();
		}
		//将此次计算结果导入go中
		swap(go, gotmp);
		gotmp.clear();
	}
}
void chose1back() {
	//根据go中的队列计算当前桥两侧人员情况
	for (auto &a1 :go)
	{
		calNew(a1);
		for (auto &a : r) {
			deque<int> dtmp(a1);
			dtmp.push_back(a);
			gotmp.push_back(dtmp);
		}
		calFree();
	}
	//将此次计算结果导入go中
	swap(go, gotmp);	
	gotmp.clear();
}
void calNew(deque<int> &a1) {	
	unsigned u = 0;
	for (auto &a2 : a1) {
		if (u != 2) {	//通过u来判断此人是去程还是回程。每当去两个人必定回一个人送手电筒
						//去两个人
			++u;
			int j = 0;
			while (*(l.begin() + j) != a2)++j;//找到这个人并退出循环
											  //将这个人从桥左侧移动到右侧
			l.erase(l.begin() + j);
			r.push_back(a2);
		}
		else {
			//回一个人
			u = 0;
			int j = 0;
			while (*(r.begin() + j) != a2)++j;//找到这个人并退出循环
											  //将这个人从桥左侧移动到右侧
			r.erase(r.begin() + j);
			l.push_back(a2);
		}
	}
}
void calFree() {
	l = l0;
	r.clear();
}
void outGo() {
	int i = 0;
	for (auto &a1 : go) {
		++i;
		cout << i << ": ";
		for (auto &a2 : a1) {
			cout << a2 << ",";
		}
		cout << endl;
	}
}
void calResult() {
	unsigned num = 0,minNum=0,sum = 0,min=0;
	for (auto &a1 : go) {
		sum = 0;
		unsigned u = 0;
		int ii = 0;
		for (auto &a2 : a1) {
			switch (u) {
			case 0:
				ii = a2;
				u = 1;
				break;
			case 1:
				if (a2 > ii)ii = a2;
				sum += ii;
				ii = 0;
				u = 2;
				break;
			case 2:
				sum += a2;
				u = 0;
				ii = 0;
				break;
			}
		}
		if (num == 0) 
		{ 
			min = sum;
		}
		else {
			if (sum < min) {
				min = sum;
				minNum = num;
			}
		}
		++num;
	}
	cout <<"用时最快的是第"<< minNum+1<<"组方案，共用时" << min << endl;
	cout << "左侧:";
	for (auto aleft : l)cout << aleft<<",";
	cout << "    右侧:";
	for (auto aright : r)cout << aright <<",";
	cout << endl;
	cout << "----------------------" << endl;
	unsigned u = 0;
	for (auto afast : go[minNum]) {
		if (u != 2) {
			unsigned j = 0;
			while (l[j] != afast)j++;
			l.erase(l.begin() + j);
			r.push_back(afast);
			++u;

			cout << afast << ">>";
		}
		else {
			unsigned j = 0;
			while (r[j] != afast)j++;
			r.erase(r.begin() + j);
			l.push_back(afast);
			u = 0;

			cout << "    <<" << afast << endl;
			cout << "左侧:";
			for (auto aleft : l)cout << aleft << ",";
			cout << "    右侧:";
			for (auto aright : r)cout << aright << ",";
			cout << endl;
			cout << "----------------------" << endl;
		}
	}
	cout << endl;
	cout << "左侧:";
	for (auto aleft : l)cout << aleft << ",";
	cout << "    右侧:";
	for (auto aright : r)cout << aright << ",";
	cout << endl;
	cout << "----------------------" << endl;
}
void eject() {
	unsigned amount = 1000;
	auto b = go.begin();
	auto sz = go.size();
	if (ejTimes > 4) amount = 2000;
	if (ejTimes > 6) amount = 8000;
	if (ejTimes > 8) amount = 16000;
	if (ejTimes > 10) amount = 64000;
	if (sz > amount) {
		go.erase(b + amount, b + sz);
		cout << "eject:" << sz - amount  << endl;
	}
	if (ejTimes > 6 && go.size()>amount) {
		go.erase(b, b + amount / 2);
		cout << "*eject:" << amount /2  << endl;
	}
	++ejTimes;
}