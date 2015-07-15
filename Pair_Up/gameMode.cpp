#include "gameMode.h"

//gameMode entrance
void g_game()
{
	//partial variable
	//Piece.type means basic elements of piece
	//Piece.specType means special piece 
	int restOfLive = 6; //��ʼ����ֵ
	int score = 0;
	int exit_sign = 0;
	bool isDeadMap = false;
	bool isExpMax = false;
	bool pauseGame = false;
	Option option;
	Map & newMap = g_makeMap();
	isDeadMap = newMap.g_isDeadMap();
	Animation* newAnimation = new Animation(option, newMap);
	
	newAnimation->animation_add();
	while (restOfLive){
		//+if(button.exit_inGame())
		isDeadMap = newMap.g_isDeadMap();
		if (pauseGame){}
		else{
			if (isDeadMap)
			{
				restOfLive--;
				g_deleteMap(newMap);
				Map newmap = g_makeMap();
				newAnimation->animation_newmap(newMap);
			}
			else
			{
				/*
					1.�û�����ȥ
					2.�϶�-���Ŷ���
					|-���Ϸ�
					|-�Ϸ�-Map ��������(int,int,int,int,Map&)-bool g_checkMap(Map)-
					|-��������-��������-���Ŷ���
					|-������-g-P-S-R-
					*/

				
				for (; g_checkMap(newMap) == 1;)
				{

					clearPiece(newMap);

					newAnimation->animation_disappear(newMap);


					g_P_S_R(newMap);
					newAnimation->animation_fall_add(newMap);
				}

				isDeadMap = newMap.g_isDeadMap();
				if (!isDeadMap)
				{
					exit_sign = newAnimation->puanimation(0, 0, Global::x_scr, Global::y_scr, newMap);

				}

				//+isExpMax();
			}
		}
	}
	l_inRanking(score);//Record score, disaplay in leaderboard if the top five
}

//swap two Piece
void swapPiece(int x1, int y1, int x2, int y2, Map& map)
{
	map.swap(x1, y1, x2, y2);
}

//Judge the Map for clearable
//Judge the whole map
//Do NOT change the Piece.isClearable

//bool g_checkMap(Map & map)
//{
//	//�м��
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			for (int k = 0;; k++)
//			{
//				if (k == 2)//k = 2��ζ�ų�������һ��
//				{
//					return true;
//				}
//				if (j == 8)//��ֹ��8�͵�9��ͬɫʱ�������Ƚ϶����Խ��
//					break;
//				if (map.getMaplists()[i][j].getType() == map.getMaplists()[i][j + 1].getType())//�������j++����jֵ
//				{
//					j++;
//					if (map.getMaplists()[i][j].getSpecType() == 5)//����Ҳ���������ⷽ����
//					{
//						break;
//					}
//				}
//				else
//					break;//��������ɫ���ԣ���ô������������״̬��������
//			}
//		}
//	}
//	//�м�飺��ʽ��ͬ
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			for (int k = 0;; k++)
//			{
//				if (k == 2)
//				{
//					return true;
//				}
//				if (j == 8)
//					break;
//				if (map.getMaplists()[j][i].getType() == map.getMaplists()[j + 1][i].getType())
//				{
//					j++;
//					if (map.getMaplists()[i][j].getSpecType() == 5)//����Ҳ���������ⷽ����
//					{
//						break;
//					}
//				}
//				else
//					break;
//			}
//		}
//	}
//	return false;
//}

//GMT+9 2015/7/13 14:30
//Rewrite by Wafer
bool g_checkMap(Map & map)
{
	for (int i = 0; i < Global::MAX_SIZE; i++)
	{
		for (int j = 0; j < Global::MAX_SIZE; j++)
		{
			if (map.isPieceClearable(i, j))
			{
				return true;
			}
		}
	}
	return false;
}

//Judgee the Map for clearable(more effeciently but you need to tell me the Pieces' index which are changed)
//GMT+9 2015/7/13 12:04, Update by Wafer
//Swap the two Piece, judge isClearable
//TRUE for Something Clearable, and do NOT Swap back
//FALSE for Something Unclearable, and Swap back
bool g_checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap)
{
	theMap.swap(index_x1, index_y1, index_x2, index_y2);
	if (theMap.isPieceClearable(index_x1, index_y1) || theMap.isPieceClearable(index_x2, index_y2))
	{
		return true;
	}
	else
	{
		theMap.swap(index_x1, index_y1, index_x2, index_y2);
		return false;
	}
}

void g_P_S_R(Map& oriMap)
{
	//newMap[g_game] -> oriMap[g_P_S_R]

	g_PairUp(oriMap);
	//g_setMap();

	g_replenishMap(oriMap);//Push_back//Tgf//book
}
Map & g_makeMap()
{	
	Map *myMap = new Map();
	Map &newMap = *myMap;
	//Map newmap;
	return newMap;
}
void g_PairUp(Map& oriMap)
{
	removePiece(oriMap);
}

void g_replenishMap(Map& oriMap)
{
	repairPiece(oriMap);
}

void g_deleteMap(Map& deadMap)
{
	delete &deadMap;
}

//return the score by the cleared number and the combo number
int g_score(int num, int com)
{
	if (num >= 3)
	{
		return int(30.0 * pow(1.5, num - 3) * com);
	}
	else
		//it is possible that just clear 2 Piece even 1 piece
		return 30;
}
