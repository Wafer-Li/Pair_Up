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
#include"Button.h"
#include "Score.h"
#include "Time.h"

class Animation
{
private:
	 int x[9][9];       //81������ĺ�������������
	 int y[9][9];       //81���������������������
	 int w;             //������
	 int h;             //����߶�
	 int fall[9][9];    //ԭ�������߶�
	 int fall_add[9];    //���䷽��ĵ���߶ȣ����У�
	int appear[9][9];                     //�Ƿ����� 1Ϊ��������
	 PIMAGE PIECE[9][9];                 //����ͼ
	 PIMAGE PIECE_BG[9][9];                //����ͼ
	 PIMAGE BG;                      // ����
	 PIMAGE TYPE[6][6];                 //���з����ز�ͼƬ
	// PIMAGE STYPE[6][4];                //���ⷽ��ͼƬ
	 PIMAGE PIECE_D;                       //����״̬ͼ
	 PIMAGE game_stop;
	 PIMAGE game_start;
	 PIMAGE game_exit;
	 PIMAGE COMBO;
	 MUSIC music_disappear;
	 MUSIC music_combo;
	 MUSIC music_bgm;
	 int lasttime;
	 int lastlevel;
	
	
public:
	Animation();
	Animation(Option opt , Map map);                
	~Animation();
	
	int puanimation(int startx, int starty, int wide, int high, Map&oriMap,Time& time);                        // startx,  starty,  wide,  highִ����Ϸ���ܵķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�
	int animation_change(int i1, int n1, int startx, int starty, int wide, int high, Map&oriMap,Time&time);   //i1 n1Ϊ�����±� i1Ϊ�� n1Ϊ��
	 int animation_restore(int i1, int n1, int i2, int n2);
	 int animation_move(int i1, int n1, int i2, int n2);
	 int animation_disappear(Map&oriMap,Time&time);
	 int animation_fall(Map&oriMap);
	 int animation_add(void);
	 int animation_add(Map&oriMap);
	 int animation_newmap(Map&oriMap);
	 int animation_click(int i1,int n1, Map&oriMap,Time&time);
	 int animation_fall_add(Map&oriMap,Score& score,Time&time,int combo);
	 int animation_stop(void);
	 int animation_combo();
	 void music_stop();
	 void music_start();
};
#endif;