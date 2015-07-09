#include "gameMode.h"

//swap two Piece

void swapPiece(int x1, int y1, int x2, int y2, Map& map)
{
	map.Swap(x1, y1, x2, y2);
}

//judeg the Map for clearable
//this function is not efficient, it would be more quickly if I can get the changed Pieces' index
bool checkMap(Map & map)
{
	//�м��
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)//k = 2��ζ�ų�������һ��
				{
					return true;
				}
				if (j == 8)//��ֹ��8�͵�9��ͬɫʱ�������Ƚ϶����Խ��
					break;
				if (map.getMaplists()[i][j].getType() == map.getMaplists()[i][j + 1].getType())//�������j++����jֵ
					j++;
				else
					break;//��������ɫ���ԣ���ô������������״̬��������
			}
		}
	}
	//�м�飺��ʽ��ͬ
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)
				{
					return true;
				}
				if (j == 8)
					break;
				if (map.getMaplists()[j][i].getType() == map.getMaplists()[j + 1][i].getType())
					j++;
				else
					break;
			}
		}
	}
	return false;
}

//judege the Map for clearable(more effeciently but you need to tell me the Pieces' index which are changed)
bool checkMap(int index_x1, int index_y1, int index_x2, int index_y2, Map & theMap)
{
	return (theMap.isPieceClearable(index_x1, index_y1) && theMap.isPieceClearable(index_x2, index_y2));
}
