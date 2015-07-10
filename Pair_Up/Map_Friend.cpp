//The FRIEND function of Map
#include "Map.h"

//clearPiece
void clearPiece(Map & map){
	//�м��
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)//k = 2��ζ���״γ�������һ��
				{
					map.maplists[i][j].setIsClear(1);
					map.maplists[i][j - 1].setIsClear(1);
					map.maplists[i][j - 2].setIsClear(1);
				}
				else if (k > 2)//֮���kÿ�ζ���2�󣬴�ʱ��������ض�ͬɫ
				{
					map.maplists[i][j].setIsClear(1);
				}
				if (j == 8)//��ֹ��8�͵�9��ͬɫʱ�������Ƚ϶����Խ��
					break;
				if (map.maplists[i][j].getType() == map.maplists[i][j + 1].getType())//�������j++����jֵ
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
					map.maplists[j][i].setIsClear(1);
					map.maplists[j - 1][i].setIsClear(1);
					map.maplists[j - 2][i].setIsClear(1);
				}
				else if (k > 2)
				{
					map.maplists[j][i].setIsClear(1);
				}
				if (j == 8)
					break;
				if (map.maplists[j][i].getType() == map.maplists[j + 1][i].getType())//color ���жϷ����д�����
					j++;
				else
					break;
			}
		}
	}
}

//NEED TO FIX: ERASE SINGLE ITEM IN ON TURN, CAUSE THE **OUT OF RANGE** EXCEPTION
//may be fixed
//RemovePiece
int removePiece(Map & map)
{
	int count = 0;

	for (int i = 0; i < map.MAX_SIZE; i++)
	{
		for (int j = 0; j < map.maplists[i].size(); j++)
		{
			std::deque<Piece>::iterator p = map.maplists[i].begin();

			for (int k = 0; k < j; k++)
			{
				p++;
			}

			if (map.maplists[i][j].getIsClear())
			{
				p = map.maplists[i].erase(p);
				count++;
			}
		}
	}
	return count;
}

//RepairPiece
void repairPiece(Map & map)
{
	for (int i = 0; i < map.MAX_SIZE; i++)
	{
		while (map.maplists[i].size() < map.MAX_SIZE)
		{
			Piece piece = Piece();
			map.maplists[i].push_back(piece);
		}
	}
}