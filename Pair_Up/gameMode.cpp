#include "gameMode.h"

//swap two Piece

Map swapPiece(int x1, int y1, int x2, int y2, Map& temp)
{
	temp.Swap(x1, y1, x2, y2);
	return temp;
}

//judeg the Map for clearable
//this function is not efficient, it would be more quickly if I can get the changed Pieces' index
bool checkMap(Map temporary)
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
				if (temporary.getMaplists()[i][j].getType() == temporary.getMaplists()[i][j + 1].getType())//�������j++����jֵ
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
				if (temporary.getMaplists()[j][i].getType() == temporary.getMaplists()[j + 1][i].getType())
					j++;
				else
					break;
			}
		}
	}
	return false;
}

