#include "ClearPiece.h"
#include "Map.h"
//statusΪ���ʵ�����״̬��colorΪ�÷�����ɫ
//��ȷ�������map��piece�������
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
					temporary.getMaplists()[i][j].status = 1;
					temporary.getMaplists()[i][j - 1].status = 1;
					temporary.getMaplists()[i][j - 2].status = 1;
				}
				else if (k > 2)//֮���kÿ�ζ���2�󣬴�ʱ��������ض�ͬɫ
				{
					temporary.getMaplists()[i][j].status = 1;
				}
				if (j == 8)//��ֹ��8�͵�9��ͬɫʱ�������Ƚ϶����Խ��
					break;
				if (temporary.getMaplists()[i][j].color == temporary.getMaplists()[i][j + 1].color)//�������j++����jֵ
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
					temporary.getMaplists()[j][i].status = 1;
					temporary.getMaplists()[j - 1][i].status = 1;
					temporary.getMaplists()[j - 2][i].status = 1;
				}
				else if (k > 2)
				{
					temporary.getMaplists()[j][i].status = 1;
				}
				if (j == 8)
					break;
				if (temporary.getMaplists()[j][i].color == temporary.getMaplists()[j + 1][i].color)//color ���жϷ����д�����
					j++;
				else
					break;
			}
		}
	}
	return temporary;
}