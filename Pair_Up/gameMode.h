//this file include function for UI to Datebase

#ifndef GAMEMODE_H
#define GAMEMODE_H
#include"Map.h"
#include"Animation.h"
#include"Global.h"
//gameMode entrance
void g_game(void);

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map);

//judge the Map for clearable(you can use it anywhere but not effecient)
bool g_checkMap(Map & map);

//judge the Map for clearable(more effeciently, but more parameters)
bool g_checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap);

//Binding : Pair up,clear the Map,and replenish it
void g_P_S_R(Map&);

//move the piece
//��LDS�Ĵ��������ٷ�����
inline void g_playerMove(Map& oriMap,Animation*animation )
{
	/*
	1.�û�����ȥ
	2.�϶�-���Ŷ���
	|-���Ϸ�
	|-�Ϸ�-Map ��������(int,int,int,int,Map&)-bool g_checkMap(Map)-
	|-��������-��������-���Ŷ���
	|-������-g-P-S-R-
	*/
	animation->puanimation(0, 0, Global::x_scr, Global::y_scr, oriMap);

}

//create a new map
Map g_makeMap();

//����
void g_PairUp(Map&);

//����deque
void g_replenishMap(Map&);

//ɾ����ͼ
void g_deleteMap(Map& deadMap);

#endif