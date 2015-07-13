#ifndef __ANIMATION__
#define __ANIMATION__
#include"graphics15.h"
#include "Option.h"
#include"Global.h"
#include"Map.h"
#include"gameMode.h"
#include<string>
#include<sstream>
#include<iostream>
class Animation
{
private:
	 int x[9][9];
	 int y[9][9];
	//static int R[10];
	 int w;
	 int h;
	 int d[9][9];     //����߶�
	 int d_add[9];
	int m[9][9];                     //�Ƿ�����
	int k[9][9];
	 PIMAGE P[9][9];                 //����ͼ
	 PIMAGE BP[9][9];                //����ͼ
	 PIMAGE BG;                      // ����
	 PIMAGE TYPE[6];                 //������ͨ�����ز�ͼƬ
	 PIMAGE STYPE[6][5];                //���ⷽ��ͼƬ
	 PIMAGE DP;                       //����״̬ͼ
	
public:
	Animation();
	Animation(Option,Map map);                      //��Ϸ������ʼ��ĺ����� ������ �زĿ�� �߶� Map
	~Animation();
	
	int puanimation(int aa, int bb, int cc, int dd, Map&oriMap);                        //ִ����Ϸ���ܵķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�
	int animation_change(int i_, int n, int aa, int bb, int cc, int dd, Map&oriMap);
	  int animation_restore(int i1, int n1, int i2, int n2);
	 int animation_move(int i1, int n1, int i2, int n2);
	 int animation_disappear(Map&oriMap);
	 int animation_fall(Map&oriMap);
	 int animation_add(void);
	 int animation_add(Map&oriMap);
	 int animation_newmap(Map&oriMap);
	 int animation_click(int i1,int n1, Map&oriMap);
	 int animation_fall_add(Map&oriMap);
};
#endif;