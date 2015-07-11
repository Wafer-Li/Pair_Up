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
					deal_SpecPiece(i, j, map);
					deal_SpecPiece(i, j - 1, map);
					deal_SpecPiece(i, j - 2, map);
				}
				else if (k > 2)//֮���kÿ�ζ���2�󣬴�ʱ��������ض�ͬɫ
				{
					map.maplists[i][j].setIsClear(1);
					deal_SpecPiece(i, j, map);
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
					deal_SpecPiece(j, i, map);
					deal_SpecPiece(j - 1, i, map);
					deal_SpecPiece(j - 2, i, map);
				}
				else if (k > 2)
				{
					map.maplists[j][i].setIsClear(1);
					deal_SpecPiece(j, i, map);
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

//WARNING:
//Please ensure to DELETE the repairNum in the stage
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

//special Piece
void deal_SpecPiece(int i, int n, Map& map)
{
	if (map.maplists[i][n].getSpecType() == 1)
	{
		for (int m = 0; m < 8; m++)
			map.maplists[m][n].setIsClear(1);
	}
	if (map.maplists[i][n].getSpecType() == 2)
	{
		for (int m = 0; m < 8; m++)
			map.maplists[i][m].setIsClear(1);
	}
	if (map.maplists[i][n].getSpecType() == 3)
	{
		if (i > 0)
			map.maplists[i - 1][n].setIsClear(1);
		if (i < 8)
			map.maplists[i + 1][n].setIsClear(1);
		if (n > 0)
			map.maplists[i][n - 1].setIsClear(1);
		if (n < 8)
			map.maplists[i][n + 1].setIsClear(1);
		if ((i > 0) && (n > 0))
			map.maplists[i - 1][n - 1].setIsClear(1);
		if ((i > 0) && (n < 8))
			map.maplists[i - 1][n + 1].setIsClear(1);
		if ((i < 8) && (n > 0))
			map.maplists[i + 1][n - 1].setIsClear(1);
		if ((i < 8) && (n < 8))
			map.maplists[i + 1][n + 1].setIsClear(1);
	}
	if (map.maplists[i][n].getSpecType() == 4)
	{
		for (int index_x = 0, index_y = 0; (index_x == 8) && (index_y == 8); index_x++, index_y++)
		{
			if (map.maplists[i][n].getType() == map.maplists[index_x][index_y].getType())
			{
				map.maplists[index_x][index_y].setIsClear(1);
			}
		}
	}
	if (map.maplists[i][n].getSpecType() == 5)
	{
		map.maplists[i][n].setIsClear(0);
	}
}

//caculate the movePoint for each Piece
void movePoint(Map& map)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (map.maplists[i][j].getIsClear() == 1)
			{
				for (int n = j - 1; n != 0; n--)
				{
					map.maplists[i][n].setMovePoint(map.maplists[i][n].getMovePoint() + 1);
				}
			}
		}
	}
	return;
}

//initialize the movePoint
void init_movePoint(Map& map)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			map.maplists[i][j].setMovePoint(0);
		}
	}
}