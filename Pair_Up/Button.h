#ifndef __BUTTON__
#define __BUTTON__
#include"graphics13.h"
#include<iostream>
class Button
{
private:
	static int x[10];
	static int y[10];
	static int R[10];
	static int w[10];
	static int h[10];
	static int i;
	static PIMAGE P[10];
	static PIMAGE P2[10];
	static PIMAGE P3[10];
public:
	
	Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3);//��ť��ʼ��ĺ����� ������ ��� �߶� ��̬ͼ ѡ��ͼ ���ͼ
	~Button(void);
	
	static int pubutton(int aa, int bb, int cc, int dd,PIMAGE BK);//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�ִ��ǰ�Ľ�ͼ

		
};
#endif;