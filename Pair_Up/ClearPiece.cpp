#include "ClearPiece.h"
#include "Map.h"
//statusΪ���ʵ�����״̬��colorΪ�÷�����ɫ
Map clearPiece(Map temporary){
	//�м��
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0;; k++)
			{
				if (k == 2)//k = 2��ζ���״γ�������һ��
				{
					temporary.maplists[i][j].status = 1;
					temporary.maplists[i][j - 1].status = 1;
					temporary.maplists[i][j - 2].status = 1;
				}
				else if (k > 2)//֮���kÿ�ζ���2�󣬴�ʱ��������ض�ͬɫ
				{
					temporary.maplists[i][j].status = 1;
				}
				if (j == 8)//��ֹ��8�͵�9��ͬɫʱ�������Ƚ϶����Խ��
					break;
				if (temporary.maplists[i][j].color == temporary.maplists[i][j + 1].color)//�������j++����jֵ
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
					temporary.maplists[j][i].status = 1;
					temporary.maplists[j - 1][i].status = 1;
					temporary.maplists[j - 2][i].status = 1;
				}
				else if (k > 2)
				{
					temporary.maplists[j][i].status = 1;
				}
				if (j == 8)
					break;
				if (temporary.maplists[j][i].color == temporary.maplists[j + 1][i].color)//color ���жϷ����д�����
					j++;
				else
					break;
			}
		}
	}
}