// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <time.h> 
#include <graphics.h>

#define pi 3.1415926535
#define ul 200

using namespace std;

struct Point {
	double x;
	double y;
	bool operator==(const Point &rhs)
	{
		return (this->x == rhs.x && this->y == rhs.y);
	}
};
struct myline {
	Point s;
	Point e;
};

extern void initDraw();
extern void endDraw();
extern void draw1();
extern void drawMyLine(myline l);
extern void cal1(vector <myline> &vml);
extern void initLine(vector <myline> &vml);

int main()
{
	initDraw();
	draw1();
	system("pause");
	endDraw();
	system("pause"); 
    return 0;
}
void draw1() {
	vector <myline> vml;
	initLine(vml);
	cal1(vml);
	cal1(vml);
	cal1(vml);
	cal1(vml);
	for (auto a : vml )
		drawMyLine(a); 
}
void cal1(vector <myline> &vml) {
	vector <myline> vpush;
	Point pt1 = { -ul,0 }, pt2 = { ul,0 };
	myline l1 = { pt1,pt2 };
	for (auto a1 : vml) {
		double dx = (a1.e.x - a1.s.x);
		double dy = (a1.e.y - a1.s.y);
		double s = sqrt(dx * dx + dy * dy);
		double angle = atan2(dy,dx);
		cout << angle<<endl;
		//第一条线
		pt1 = { a1.s.x,a1.s.y };
		pt1 = pt2;
		pt2.x += s / 3 * cos(angle + 0);
		pt2.y += s / 3 * sin(angle + 0);
		l1 = { pt1,pt2 };
		vpush.push_back(l1);
		//第二条线
		pt1 = pt2;
		pt2.x += s / 3 * cos(angle + pi / 3);
		pt2.y += s / 3 * sin(angle + pi / 3);
		l1 = { pt1,pt2 };
		vpush.push_back(l1);
		//第三条线
		pt1 = pt2;
		pt2.x += s / 3 * cos(angle - pi / 3);
		pt2.y += s / 3 * sin(angle - pi / 3); 
		l1 = { pt1,pt2 };
		vpush.push_back(l1);
		//第四条线
		pt1 = pt2;
		pt2.x += s / 3 * cos(angle + 0);
		pt2.y += s / 3 * sin(angle + 0);
		l1 = { pt1,pt2 };
		vpush.push_back(l1);
	}
 	vml.clear();
	vml = vpush;
}
void initLine(vector <myline> &vml) {
	myline l ;
	l.s = { ul,0 };
	l.e = { -ul,0 };
	vml.push_back(l);
	l.s = l.e;
	l.e = { 0,sqrt(3)*ul };
	vml.push_back(l);
	l.s = l.e;
	l.e = { ul,0 };
	vml.push_back(l);
}
void drawMyLine(myline l) {
	line(l.s.x, l.s.y, l.e.x, l.e.y	);
}
void initDraw() {
	initgraph(1200, 600);			// 初始化绘图窗口
	setorigin(300, 400);			//设置坐标原点
	setaspectratio(1, -1);		//设置缩放系数，翻转Y轴方向
	setcolor(RGB(200, 200, 200));		//设置绘图初始颜色
}
void endDraw() {
	closegraph();					// 关闭图形界面 
}
