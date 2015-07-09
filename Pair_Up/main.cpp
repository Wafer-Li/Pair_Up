//------------READ-ME--------------------------------------------
//���nedOPT�ĵط���ζ����Ҫ�Ż�
//���+�ĵط���ζ����Ҫ���
//Update7-7: ����ȷ������������� Piece.type		(0��6]    match to six different piece basic type
//			 ���ⷽ�飺			Piece.specType	[0��6]	  match to seven different piece addition type
//			specType:			0.ori-ԭʼ����-ʲô������		1.line-������	2.row-������		3.box-����3*3	4.same_color-����ͬɫ	5.unclear-��������	6.death-ֱ������
//Update7-7:Please add getter and setter for your class :D
//Update7-7:Please change your function name to match main function as possible~ 
//Update7-8:��Map����������һ���������ȡ�������������
//Update7-8:Map���м�ɾ��Ԫ�غ� ���еĵ�������ʧЧ����ע����ѭ�����ؽ��µ�����
//Update7-8:-��Ч��Ϣ-Map����ʹ�����Ͻ�Ϊ����ԭ��
//Update7-8:Map���и���Ϊʹ�����½�Ϊ����ԭ��
//Update7-8:��Ϸ���ڴ�СΪ1476*1016
//Update7-9:ÿ��Piece��С:100*100����Ч����:98*98��Map�����С:900*900������ԭ��λ��:(x_map_LT,y_map_LT)������ԭ��λ��:(x_map_LB,y_map_LB)		
//			ÿ��[x][y]piece�����λ�ã�
//Update7-9:ͬ������ ͳһ�������� ����Ƿ�-is ���-pair ����-clear �Ƿְ壨���а�-leaderboard ��-piece ͼ-map ����-score ����-make �ж�����-flag
//			�ɵģ�ԭʼ��-ori �µ�-new
//			gameMode�µĺ������ "g_" ǰ׺��learboardMode�µĺ������ "l_" ǰ׺
//Update7-9:����ȫ��ʹ�ô��δ���
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include "yage.h"
#include "Map.h"
#include "Piece.h"
#include "Button.h"
//�ӿں����б�
//g_makeMap();
//g_isDead();
//g_playerMove();			
//g_checkPair(oriMap);
//g_pairUp();
//g_setMap();
//g_replenishMap();
//Update7-7������д�����Ҿ�д����ĺ���..
const static int x_scr = 1476;
const static int y_scr = 1016;
const static int x_map = 900;
const static int y_map = 900;
const static int x_piece = 100;
const static int y_piece = 100;
const static int x_map_LT = 519;
const static int x_map_LB = 519;
const static int y_map_LT = 52;
const static int y_map_LB = 952;
static int glo_score = 0;
void resource(Option)
{	
	struct yage_canvas *Background = yage_canvas_load_image("Bk.png");
	resourceSkin(o_skin);
}
void resourceSkin(int skin)
{
	std::vector<struct yage_canvas *> pieceSkin;
	std::string temp;
	std::stringstream ss;
	for (int i = 1; i != 7; ++i)
	for (int j = 1; j != 7; ++j)
	{
		ss << "Skin" << skin << "_Piece_" << i << "_" << j << ".png";
		ss >> temp;
		ss.clear();
		std::cout << temp << std::endl;
		pieceSkin.push_back(yage_canvas_load_image(temp.c_str()));
	}
	system("PAUSE");
}

int main(int argc, char*argv[]
{

	init();
	meun(start());
	yage_quit();
	return 0;
}

int init(void)
{
	srand((unsigned)time(0));
	yage_init(x_scr, y_scr);
	return 0;

}

void meun(int playerChoose)
{
	int condition = 1;

	while (condition)
		switch (playerChoose)
	{
		case 1:
			condition = gameMode();
			//start game
			break;
		case 2:
			//open record mode
			condition = leaderboardMode();
			break;
		case 3:
			//option
			condition = optionMode();
			break;
		case 4:
			//exit program
			condition = exitMode();
			break;
		default:
	}
}

int gameMode()
{
	g_game();
	return 1;
}

int leaderboardMode()
{
	return 1;
}

int optionMode()
{
	return 1;
}

int exitMode()
{

	return 0;
}

void g_game()
{
	//partial variable
	//Piece.type means basic elements of piece
	//Piece.specType means special piece 
	int restOfLive = 6; //��ʼ����ֵ
	bool isMapDead = false;
	bool isExpMax = false;
	bool g_payeseGame = true;

	Map newmap = g_makeMap();//Lht+Tgf+Hjy
	isMapDead = g_isDead();//Lht
	while (restOfLive){
		//if(pair_Up)
		//+if(button.exit_inGame())
		if (g_pauseGame()){
		}
		else{
			newMap = g_checkPair();
			if (removePiece == 0)
			{
				if (isMapDead)
				{
					g_deleteMap(newMap);
					Map newmap = g_makeMap();
				}
				else
				{

					newMap = g_playerMove();//g_playerMove()->Lds -> Lc //"="need of operator overlording
					/*
					1.�û�����ȥ
					2.�϶�-���Ŷ���
					|-���Ϸ�
					|-�Ϸ�-Map ��������(int,int,int,int,Map&)-bool checkMap(Map)-
					|-��������-��������-���Ŷ���
					|-������-g-P-S-R-
					*/

					g_checkMap(oriMap);//Lc

					g_P_S_R(newMap);
					//+isExpMax();
					//nedOPT:in loops,this function"isMapDead"will carry out twice with one loop
					//Update7-7:slove
					isMapDead = g_isDead();
					if (isMapDead)
					{
						--restOfLive;
					}
				}
			}
			else
			{
				g_P_S_R(newMap);
				//+isExpMax();
			}
		}
	}
	l_scoreUpdate();//record Game score,if the score is at the top 10 of leaderboard, congratulations and refresh the learboard
}

void g_P_S_R(Map& oriMap)
{
	//newMap[g_game] -> oriMap[g_C_P_S_R]

	g_pairUp();//����//Lc + Lds

	//g_setMap();//����//Lht+Lds+Hjy+Tgf

	g_replenishMap();//Push_back//Tgf//book
}

void g_playerMove(Map& oriMap)
{

	/*
	1.�û�����ȥ
	2.�϶�-���Ŷ���
	|-���Ϸ�
	|-�Ϸ�-Map ��������(int,int,int,int,Map&)-bool checkMap(Map)-
	|-��������-��������-���Ŷ���
	|-������-g-P-S-R-
	*/
}

Map g_makeMap()
{
	//Map *newMap = new Map();
	Map newmap;
	return newmap;
}

void g_deleteMap(Map& deadMap)