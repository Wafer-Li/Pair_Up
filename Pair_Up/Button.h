#ifndef __BUTTON__
#define __BUTTON__
#include"graphics15.h"
#include<iostream>
#include"Global.h"
#include"Time.h";
class Button
{
private:
	static int button_x[20];       //��ť��ʼ�������
	static int button_y[20];       //��ť��ʼ��������
	static int button_R[20];       //��ť���º�ķ���ֵ
	static int button_w[20];       //��ť������
	static int button_h[20];       //��ť����߶�
	static int button_i;           //��ť����
	static PIMAGE button_P[20];    //��ť��̬Դͼ   
	static PIMAGE button_P2[20];   //��ťѡ��̬Դͼ
	static PIMAGE button_P3[20];   //��ť����̬Դͼ
	static PIMAGE button_RP;       //��ť���ǰ��ԭͼ
	static PIMAGE button_allP;      //��ťȫ�����ͼ
	static PIMAGE button_M[20];    //ѡ��״̬��ͼ
	static PIMAGE button_O[20];     //����״̬��ͼ
	static PIMAGE chose;           //����ͼ
	static int cho;   //����ѡ���ж�
public:
	
	Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3);//��ť��ʼ��ĺ����� ������ ��� �߶� ��̬ͼ ѡ��ͼ ���ͼ
	Button(int startx, int starty, int wide, int high, int Return, PIMAGE p);//����ģʽ
	~Button(void);
	static int setbutton(int startx, int starty, int wide, int high);//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�ִ��ǰ�Ľ�ͼ ���ú������ͼƬ���������ҽ���ť��̬�������Ļ
	static int pubutton(int startx, int starty, int wide, int high);//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�
	static int pubutton(int startx, int starty, int wide, int high,int rectangle_);  //rectangle_�����ò���ֻ����������̬ģʽ�뷽��ģʽ
	static int pubutton(int startx, int starty, int wide, int high, Time&time, PIMAGE bg);  //rectangle_�����ò���ֻ����������̬ģʽ�뷽��ģʽ(�޺��);
		
};
#endif;