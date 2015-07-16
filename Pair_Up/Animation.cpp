#include"Animation.h"
#include"gameMode.h"
#include<string>
#include<sstream>
Animation::Animation(void)  //������
{


}
Animation::Animation(Option opt, Map map)
{
	int j_ = 0, i_ = 0, n_ = 0;
	
	std::stringstream ss;
	std::string temp;

	/////////////////////////////��ʼ�����������ز�ͼƬ////////////////////////////////
	

	BG = newimage();
	PIECE_D = newimage();
	for ( i_ = 0; i_ != 6; ++i_){
		for (j_ = 0; j_ != 6; ++j_)
		{
			TYPE[i_][j_] = newimage();
			ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_" << i_ + 1 << "_" << j_ << ".png";
			ss >> temp;
			getimage(TYPE[i_][j_], temp.c_str(), 0, 0);
			ss.clear();
		}
	}
	ss << "resource\\skin" << opt.getSkin() << "\\Skin" << opt.getSkin() << "_Piece_Clear.png";
	ss >> temp;
	getimage(PIECE_D, temp.c_str(), 0, 0);
	ss.clear();
	ss << "resource\\BackGround\\GameBk" << opt.getBackground() << ".png";
	ss >> temp;
	getimage(BG, temp.c_str(), 0, 0);
	ss.clear();
	///////////��Ч/////////////////////////
	ss << "resource\\skin" << opt.getSkin() << "\\bgm.mp3";
	ss >> temp;
	music_bgm.OpenFile(temp.c_str());
	ss.clear();
	ss << "resource\\skin" << opt.getSkin() << "\\disappear.wav";
	ss >> temp;
	music_disappear.OpenFile(temp.c_str());
	ss.clear();

	ss << "resource\\skin" << opt.getSkin() << "\\combo.wav";
	ss >> temp;
	music_combo.OpenFile(temp.c_str());
	ss.clear();



	//////////////////////////////////////////������ͣͼƬ////////////////////////////
	game_exit = newimage();
	game_start = newimage();
	game_stop = newimage();
	COMBO = newimage();
	getimage(game_stop, "resource\\BK.png", 0, 0);
	getimage(game_start, "resource\\g_ctn.png", 0, 0);
	getimage(game_exit, "resource\\g_Exit.png", 0, 0);
	getimage(COMBO, "resource\\combo.png", 0, 0 );
	//����6*5=30��Ƥ�� (6�ַ���ÿ����5�����ⷽ�飩

	//////////////////////////////ȷ��ÿ������Ĳ���//////////////////////////////
	w = Global::x_piece;
	h = Global::y_piece;
	for (i_ = 0; i_ < 9; i_++)
		for (n_ = 0; n_ < 9; n_++)
		{
			if (map.getMaplists()[n_][8 - i_].getSpecType() != 0)
			{
				//P[i_][n_] = STYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1][(map.getMaplists()[n_][8 - i_].getSpecType())-1 ];
				PIECE[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1][(map.getMaplists()[n_][8 - i_].getSpecType())];
			}
			else {
				//P[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1];
				PIECE[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1][0];
			}
			x[i_][n_] = Global::x_map_LT + w*n_;
			y[i_][n_] = Global::y_map_LT + h*i_;
			appear[i_][n_] = 1;
			fall[i_][n_] = 0;
		}
	//////////////////////////////��������������//////////////////////////////
	putimage(0, 0, BG);
	
	for (i_ = 0; i_ < 9; i_++)
		for (n_ = 0; n_ < 9; n_++)
		{
			PIECE_BG[i_][n_] = newimage();
			getimage(PIECE_BG[i_][n_], x[i_][n_], y[i_][n_], w, h);
		}
	//////////////////////////////�������//////////////////////////////////////
	for (i_ = 0; i_ < 9; i_++)
		for (n_ = 0; n_ < 9; n_++)
		{

			putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[i_][n_], BLACK);
		}



}
Animation::~Animation()
{
	music_bgm.Close();
	music_combo.Close();
	music_disappear.Close();
}
int Animation::puanimation(int startx, int starty, int wide, int high, Map&oriMap,Time& time)
{

	setcolor(WHITE);
	
	int n_ = 0, i_ = 0;  //n_��i_Ϊ�����±����ڷ�Χ�ж�
	int disappear = 0;    //r�����Ƿ���������ж�
	mouse_msg _a;   //�����Ϣ������
	int left = 0;     //�洢��������Ϣ��
	int buttonr = 0;
	PIMAGE BK_ = newimage();
	getimage(BK_, x[0][0], y[0][0], Global::x_piece * 9, Global::y_piece*9);//��������û�����ǰ����Ϸ״̬ͼƬ
	int clock;
	if (music_bgm.GetPlayStatus() == MUSIC_MODE_STOP)music_bgm.Play(0);
	flushmouse();
	for (;;)
	{

		if ((disappear == 1) || (disappear == 3)){
			putimage(x[0][0],y[0][0], BK_);           //����������������ʱ�����������������������������
			
			break;

		}
		if ((disappear == 4) || (disappear == 5)){
			putimage(x[0][0], y[0][0], BK_);  //������������������ʱ�û������������ҽ�disappear����
			
			disappear = 0;
			
		}
		for (; !mousemsg();)
		{
			putimage(0, 200, 450, 100, BG, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d",clock);       //��겻��ʱʱ��䶯
			if (clock <= 0){
				flushmouse();
				return 1;
			}
		}
		_a = getmouse();
		if (mousemsg()){
			putimage(0, 200, 450, 100, BG, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d", clock);          //��궯ʱʱ��䶯һ��
		}
	
		putimage(x[0][0], y[0][0], BK_);                //�����ʼͼƬ���л�ͼ����Ҫʵ�ַ����ܣ�
		
		
		
		if (!((_a.x <= (startx + wide)) && (_a.x >= startx)&&(_a.y <= (starty + high)) && (_a.y >= starty)))
		{
			
			buttonr = Button::pubutton(0, 650, 520, 200,time,BG);
			if (buttonr == 2)
			{
				time.pauseTime();
				buttonr=this->animation_stop();
				time.resumeTime();
		
			}
				if (buttonr == 1)return buttonr;
			                               //����Ƴ���Ϸ�����밴����
		}
		if (_a.is_left())left++;                           // ��������Ϣ��
		
		 ////////////////////////////////////////////�����ϢΪż��ʱ�������//////////////
		for (i_ = 0; i_ < 9 && (left % 2 == 0); i_++)
			for (n_ = 0; n_ < 9 && (left % 2 == 0); n_++)
		{
			
			setcolor(WHITE);
			
			if (_a.x <= x[i_][n_] + w && _a.x >= x[i_][n_] && _a.y <= y[i_][n_] + h && _a.y >= y[i_][n_])  //�ж���굱ǰ���ڷ���
			{
				
				rectangle(x[i_][n_], y[i_][n_], x[i_][n_] + w, y[i_][n_] + h);
				
				
			}
		}
		///////////////////////////////////////////�����ϢΪż��ʱ���������������ҽ��뽻������///////////////////////
		for (i_ = 0; i_ < 9 && (left % 2 == 1); i_++)
		{
			for (n_ = 0; n_ < 9 && (left % 2 == 1); n_++)
			{
				setcolor(WHITE);

				if (_a.x <= x[i_][n_] + w && _a.x >= x[i_][n_] && _a.y <= y[i_][n_] + h && _a.y >= y[i_][n_])
				{
					rectangle(x[i_][n_], y[i_][n_], x[i_][n_] + w, y[i_][n_] + h);
					disappear = (this->animation_change(i_, n_, startx,starty, wide, high, oriMap,time));         ////����������r=1��������r=4
					delimage(BK_);
					BK_ = newimage();
					getimage(BK_, x[0][0], y[0][0], Global::x_piece * 9, Global::y_piece * 9);

					left = 0;                                               //���������Ϣ

				}

			}
		}

		//////////////////////////////////////////
		
	}
	
	delimage(BK_);
	return 0;
}
int Animation::animation_change(int i1, int n1, int startx, int starty, int wide, int high, Map&oriMap,Time& time)
{
	mouse_msg _a;
	int k = 0;
	int i_ = 0, n_ = 0;  //����ѡ���±��ж�
	int i2=i1, n2=n1;     //i2,n2���ڴ��汻ѡ�еĵڶ���piece���±�
	int disappear = 0;
	int clock;
	PIMAGE BK_ = newimage();
	getimage(BK_, x[0][0], y[0][0], Global::x_piece * 9, Global::y_piece * 9);
	
	for (;;)
	{
		for (; !mousemsg();)
		{
			putimage(0, 200, 450, 100, BG, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d", clock);      //��겻��ʱʱ��䶯
			if (clock <= 0){
				flushmouse();
				return 1;
			}
		}
		_a = getmouse();
		if (mousemsg()){
			putimage(0, 200, 450, 100, BG, 0, 200); 
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d", clock);          //��궯ʱʱ��䶯һ��
		}
		if (!((_a.x <= (startx + wide)) && (_a.x >= startx) && (_a.y <= (starty + high)) && (_a.y >= starty)))  //����Ƿ�����Ϸ����Χ
		{
			break;
		}
		if (_a.is_left())                      //������ɿ�
		{
			
				/*if (!(_a.x <= x[i2][n2] + w && _a.x >= x[i2][n2] && _a.y <= y[i2][n2] + h && _a.y >= y[i2][n2]) && !(i1 != i2&&n1 != n2))          //�϶�����������ɿ�ʱ�뿪��ȷ������Ӻ��Ƿ�ȡ������
				{

					this->animation_restore(i1, n1, i2, n2);
					k = 0;
				
				}*/       
				if ((i1 == i2) && (n1 == n2))          //�������ԭ������ķ������ɿ�ʱ������ʽ��������
				{
					disappear=(this->animation_click(i1, n1, oriMap,time));
					k = 0;                              
					
				}
		
			//////////////�������ݽ������ж��Ƿ��ܲ��������Ľ���/////////////////////////////////////////
				if (k==1){
				disappear = 1;
				if (!g_checkMap(n1, 8 - i1, n2, 8 - i2,oriMap)){
					this->animation_restore(i1, n1, i2, n2);
					disappear = 0;
				}
			}
			/////////////////////////////////////////////////////////////////////
			putimage(x[i1][n1], y[i1][n1], PIECE_BG[i1][n1]);
			putimage(x[i2][n2], y[i2][n2], PIECE_BG[i2][n2]);
			putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1], BLACK);
			putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2], BLACK);
			delay_ms(0);
			break;
		}
		
		/////////////////////////////////////���û�ɿ����뿪��ԭ���ĸ��� �����϶�����//////////////////////////
		for (i_ = 0; i_ < 9 && (k == 0); i_++)
		for (n_ = 0; n_ < 9 &&( k == 0); n_++)
		{
			
			
			if (_a.x <= x[i_][n_] + w && _a.x >= x[i_][n_] && _a.y <= y[i_][n_] + h && _a.y >= y[i_][n_] && ((i_ <= i1 + 1 && i_ >= i1 - 1 && n_ == n1) || (n_ >= n1 - 1 && n_ <= n1 + 1 && i_ == i1)) /*&& (_a.x <= startx&&_a.x >= aa&&_a.y <= dd&&_a.y >= bb)*/)
			{
				putimage(x[0][0],y[0][0], BK_);
				delay_ms(0);
				i2 = i_;
				n2 = n_;
				if (i2!=i1||n2!=n1){
					putimage(x[0][0],y[0][0], BK_);
					delay_ms(0);
					this->animation_move(i1, n1, i2, n2);
				
					k = 1; 
				}			
			}
		}
		
		
	}
	delimage(BK_);
	return disappear;
}
int Animation::animation_restore(int i1, int n1, int i2, int n2)   //�����طţ�����Ϊ����������±�
{
	
	
	int k = 0;
	int d = 0;
	PIMAGE A = newimage();
	putimage(x[i1][n1], y[i1][n1], PIECE_BG[i1][n1]);
	putimage(x[i2][n2], y[i2][n2], PIECE_BG[i2][n2]);
	setcolor(WHITE);
	rectangle(x[i1][n1], y[i1][n1], x[i1][n1] + w, y[i1][n1] + h);
	rectangle(x[i2][n2], y[i2][n2], x[i2][n2] + w, y[i2][n2] + h);
	PIMAGE BK_ = newimage();
	getimage(BK_, x[0][0], y[0][0], Global::x_piece * 9, Global::y_piece * 9);
	/////////////////�������///////////////////////////////////////////
	if (i1 == i2&&n1<n2)
		for (int k = 0; k <= w; k += Global::speed, delay_fps(Global::delay_change))
	{
		for (; keystate(VK_LBUTTON););
		putimage(x[0][0], y[0][0], BK_);
	
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1] + k, y[i1][n1], BLACK);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2] - k, y[i2][n2], BLACK);
	}
	if (i1 == i2&&n1>n2)
		for (int k = 0; k <= w; k += Global::speed, delay_fps(Global::delay_change))
	{
		for (; keystate(VK_LBUTTON););
		putimage(x[0][0],y[0][0], BK_);
		
		
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1] - k, y[i1][n1], BLACK);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2] + k, y[i2][n2], BLACK);
	}
	if (n1 == n2&&i1>i2)
		for (int k = 0; k <= h; k += Global::speed, delay_fps(Global::delay_change))
	{
		for (; keystate(VK_LBUTTON););
	
		putimage(x[0][0], y[0][0], BK_);
		
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1] - k, BLACK);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2] + k, BLACK);

	}
	if (n1 == n2&&i1<i2)
		for (int k = 0; k <= h; k += Global::speed, delay_fps(Global::delay_change))
	{
		for (; keystate(VK_LBUTTON););
	
		putimage(x[0][0], y[0][0], BK_);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2] - k, BLACK);
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1] + k, BLACK);
	
	}
	A = PIECE[i1][n1];
	PIECE[i1][n1] = PIECE[i2][n2];
	PIECE[i2][n2] = A;
	putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1] , BLACK);
	putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2] , BLACK);

	flushmouse();
	
	
	delimage(BK_);
	
	
	return 0;
}
int Animation::animation_move(int i1, int n1, int i2, int n2)          //��������,����Ϊ����������±�
{
	
	int d = 0;

	putimage(x[i1][n1], y[i1][n1], PIECE_BG[i1][n1]);
	putimage(x[i2][n2], y[i2][n2], PIECE_BG[i2][n2]);
	setcolor(WHITE);
	rectangle(x[i1][n1], y[i1][n1], x[i1][n1] + w, y[i1][n1] + h);
	rectangle(x[i2][n2], y[i2][n2], x[i2][n2] + w, y[i2][n2] + h);
	PIMAGE BK_ = newimage();
	getimage(BK_, x[0][0], y[0][0], Global::x_piece * 9, Global::y_piece * 9);
	PIMAGE A = newimage();//���ڽ���
	if (i1 == i2&&n1<n2)
	for (int k = 0; k <= w; k+=Global::speed, delay_fps(Global::delay_change))
	{
		
		putimage(x[0][0], y[0][0], BK_);
	
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1] + k, y[i1][n1], BLACK);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2] - k, y[i2][n2], BLACK);

	}
	if (i1 == i2&&n1>n2)
		for (int k = 0; k <= w; k += Global::speed, delay_fps(Global::delay_change))
	{
		putimage(x[0][0], y[0][0], BK_);
		
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1] - k, y[i1][n1], BLACK);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2] + k, y[i2][n2], BLACK);

	}
	if (n1 == n2&&i1>i2)
		for (int k = 0; k <= h; k += Global::speed, delay_fps(Global::delay_change))
	{
		putimage(x[0][0], y[0][0], BK_);
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1] - k, BLACK);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2] + k, BLACK);
	

	}
	if (n1 == n2&&i1<i2)
		for (int k = 0; k <= h; k += Global::speed, delay_fps(Global::delay_change))
	{
		putimage(x[0][0], y[0][0], BK_);
		putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2] - k, BLACK);
		putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1] + k, BLACK);
	

	}
	A = PIECE[i1][n1];
	PIECE[i1][n1] = PIECE[i2][n2];
	PIECE[i2][n2] = A;
	putimage_transparent(NULL, PIECE[i1][n1], x[i1][n1], y[i1][n1], BLACK);
	putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2], BLACK);
	
	delimage(BK_);
	//delete(A);
	return 0;
}
int Animation::animation_disappear(Map&oriMap)   //��ʧ����
{

	int i_ = 0, n_ = 0;
	delay_ms(Global::delay_disappear);
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		appear[i_][n_] = (oriMap.getMaplists()[n_][8 - i_].getIsClear());
		if (appear[i_][n_] == 1)
		{
			
			putimage_transparent(NULL, PIECE_D, x[i_][n_], y[i_][n_], BLACK);
		}

	}
	music_disappear.Play(0);
	delay_ms(Global::delay_disappear);

	for (i_=0; i_ < 9; i_++)
	for (n_=0; n_ < 9; n_++)
		{
		if (appear[i_][n_] == 1)putimage_transparent(NULL,PIECE_BG[i_][n_],x[i_][n_], y[i_][n_],BLACK);

		}
	
	////////////////////////////���ݴ���//////////////////
	for (n_ = 0; n_ < 9; n_++)           //��ʼ����ͼ����߶�
	{
		fall_add[n_] = 0;
	}


	for (i_ = 8; i_ >=0; i_--)              //ȷ������߶�
	for (n_ = 8; n_ >= 0; n_--)
	{
		
		if (i_ != 8){
			if (appear[i_][n_] == 1)fall[i_][n_] = fall[i_ + 1][n_] + 1;
			if (appear[i_][n_] == 0)fall [i_][n_] = fall[i_ + 1][n_];
		}
		if (i_ == 8){
			if (appear[i_][n_] == 1)fall[i_][n_] = 1;
			if (appear[i_][n_] == 0)fall[i_][n_] = 0;
		}


	}
	 
	for (i_ = 0; i_ <8; i_++)              //Ϊ����߶ȸ��Ӳ�ͼ�ӳ�
	for (n_ = 0; n_ < 9; n_++)
	{
		if ((appear[i_][n_] == 1) && (appear[i_ + 1][n_] == 1))
		{
			fall_add[n_]++;
			fall[i_ + 1][n_] += fall_add[n_];
		}
	}
	
	/*for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (m[i_][n_] == 1)d[i_][n_] = 0;

	}
	*/
	
	return 0;
}





int Animation::animation_add(void)        //�µ�ͼ����ʱ���õĵ��䶯��
{
	int i_ = 0, n_ = 0, d_ = 0, c_ = 0;       //c_���ڼ�ʱ�˳���������ѭ��
	int cc[9] = { 9, 9, 9, 9, 9, 9, 9, 9, 9 };


	for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_ += Global::speed, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_add))
	{

		for (; keystate(VK_LBUTTON););
		putimage(x[0][0], y[0][0], Global::x_map, Global::y_map, BG,x[0][0], y[0][0]);
		for (i_ = 0; i_ < 9; i_++)
		for (n_ = 0; n_ < 9; n_++)
		{

			if (i_ <= (cc[n_] - 1) && (cc[n_] * h>d_))
			{
				if (((y[i_][n_] - (cc[n_]) * h + d_) <= y[0][0]) && ((y[i_][n_] - (cc[n_]) * h + d_) >= (y[0][0] - h)))putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[0][0], BLACK, 0, (y[0][0] - (y[i_][n_] - (cc[n_]) * h + d_)), w, (h - (y[0][0] - (y[i_][n_] - (cc[n_]) * h + d_))));
				if ((y[i_][n_] - (cc[n_]) * h + d_)>y[0][0])putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[i_][n_] - (cc[n_]) * h + d_, BLACK);
				c_++;        
			}
			else putimage_transparent(NULL,PIECE[i_][n_], x[i_][n_], y[i_][n_], BLACK);

		}
		if (c_ == 0)break; //��c_��Ϊ0���˳�����ѭ��
	}
	
	flushmouse();

	return 0;
}
int Animation::animation_newmap(Map&oriMap)     //�µ�ͼ����
{
	int i_ = 0, n_ = 0;
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (oriMap.getMaplists()[n_][8 - i_].getSpecType() != 0)
		{
			//P[i_][n_] = STYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1][(map.getMaplists()[n_][8 - i_].getSpecType())-1 ];
			PIECE[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())];
		}
		else {
			//P[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1];
			PIECE[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][0];
		}		
	}
	
	this->animation_add();
	return 0;
}
int Animation::animation_click(int i1, int n1, Map&oriMap,Time&time)            //�������ģʽ
{
	int i_ = 0, n_ = 0, left = 0;
	int i2 = 0, n2 = 0;
	mouse_msg a_;
	PIMAGE BK_ = newimage();
	int clock;
	getimage(BK_, x[0][0], y[0][0], Global::x_piece * 9, Global::y_piece * 9);
	setcolor(WHITE);
	for (;left<3;)
	{
		for (; !mousemsg();)
		{
			putimage(0, 200, 450, 100, BG, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d", clock); //��겻��ʱ��䶯
			if (clock <= 0){
				flushmouse();
				return 1;
			}
		}
		a_ = getmouse();
		if (mousemsg()){
			putimage(0, 200, 450, 100, BG, 0, 200);        //��궯ʱʱ��䶯һ��
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d", clock);
		}
		if (mousemsg()){
			putimage(0, 200, 450, 100, BG, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:%d", clock);
		}
		if (a_.is_left())left++;

		for (i_ = 0; i_ < 9 && (left == 0);i_++)      //���û���ʱ����
		for (n_ = 0; n_ < 9 && (left == 0); n_++)
		{
			if (a_.x <= x[i_][n_] + w && a_.x >= x[i_][n_] && a_.y <= y[i_][n_] + h && a_.y >= y[i_][n_])
			{

				putimage(x[0][0],y[0][0], BK_);
				rectangle(x[i_][n_], y[i_][n_], x[i_][n_] + w, y[i_][n_] + h);
			}
		}
		
			for (i_ = 0; i_ < 9 && (left == 1); i_++)       //��갴�¼�������
			for (n_ = 0; n_ < 9 && (left == 1); n_++)
			{
				if (a_.x <= x[i_][n_] + w && a_.x >= x[i_][n_] && a_.y <= y[i_][n_] + h && a_.y >= y[i_][n_])
				{

					putimage(x[0][0], y[0][0], BK_);
					rectangle(x[i_][n_], y[i_][n_], x[i_][n_] + w, y[i_][n_] + h);
				
				}
			}
		
		
			for (i_ = 0; i_ < 9 && (left == 2); i_++)      //����ɿ������������Ż����˳�����������
			for (n_ = 0; n_ < 9 &&( left == 2); n_++)
			{
				if (a_.x <= x[i_][n_] + w && a_.x >= x[i_][n_] && a_.y <= y[i_][n_] + h && a_.y >= y[i_][n_])
				{

					if ((i_ == i1 && ((n_ == n1 + 1) || (n_ == n1 - 1))) || (n_ == n1 && ((i_ == i1 + 1) || (i_ == i1 - 1))))
					{
						this->animation_move(i1, n1, i_, n_);
						i2 = i_;
						n2 = n_;
						left= 3;                     //�ܽ�����left��Ϊ3����ط��ж�
						
					}
					else{
						putimage_transparent(NULL,PIECE_BG[i_][n_], x[i_][n_], y[i_][n_], BLACK);
						putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[i_][n_], BLACK);
						left = 5;                     //���ܽ�����left��Ϊ5�˳���������������
					}
				}
			}

			if (left == 3){                                          //����ɿ���ȷ���Ƿ���лط�
				if (!g_checkMap(n2, 8 - i2, n1, 8 - i1, oriMap)){
					this->animation_restore(i1,n1,i2,n2);
					left = 4;                                      //�ܽ����򷵻�3���򷵻�4
					putimage(x[0][0],y[0][0], BK_);
					
				}
				else{
					putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2], BLACK);
					putimage_transparent(NULL, PIECE[i2][n2], x[i2][n2], y[i2][n2], BLACK);
				}
				
			}

	}
	delimage(BK_);

	return left;
}
int Animation::animation_fall_add(Map&oriMap,Score& score, int combo)
{
	int i_ = 0, n_ = 0, d_ = 0, c_ = 0;//c_�����ж϶����Ƿ����
	////////////////////��������////////////////////////////////
	for (i_ = 0; i_ < 9; i_++)
	for (n_ = 0; n_ < 9; n_++)
	{
		if (oriMap.getMaplists()[n_][8 - i_].getSpecType() != 0)
		{
			//P[i_][n_] = STYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1][(map.getMaplists()[n_][8 - i_].getSpecType())-1 ];
			PIECE[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][(oriMap.getMaplists()[n_][8 - i_].getSpecType())];
		}
		else {
			//P[i_][n_] = TYPE[(map.getMaplists()[n_][8 - i_].getType()) - 1];
			PIECE[i_][n_] = TYPE[(oriMap.getMaplists()[n_][8 - i_].getType()) - 1][0];
		}



	}
	//////////////////////////�����ı�//////////////////////////////
	putimage(0, 400, 450, 300, BG, 0, 400);
	xyprintf(70, 400, "%d/%d", score.getScore(), score.getPassScore());
	xyprintf(70, 450, "level %d", score.getLevel());

	/////////////////////////////���Ŷ���///////////////////////////

	for (i_ = 0, n_ = 0, d_ = 0; d_ <= h * 9; d_ += Global::speed, i_ = 0, n_ = 0, c_ = 0, delay_fps(Global::delay_add))
	{

		for (; keystate(VK_LBUTTON););
		putimage(x[0][0], y[0][0], Global::x_map, Global::y_map, BG, x[0][0], y[0][0]);
		for (i_ = 0; i_ < 9; i_++)
		{

			for (n_ = 0; n_ < 9; n_++)
			{

				if ((fall[i_][n_] * h>d_)&&(fall[i_][n_]!=0))
				{
					
					if (((y[i_][n_] - (fall[i_][n_]) * h + d_) <= y[0][0]) && ((y[i_][n_] - (fall[i_][n_]) * h + d_) >= (y[0][0] - h)))
						putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[0][0], BLACK, 0, (y[0][0] - (y[i_][n_] - (fall[i_][n_]) * h + d_)),w ,(h - (y[0][0] - (y[i_][n_] - (fall[i_][n_]) * h + d_))));

					if ((y[i_][n_] - (fall[i_][n_]) * h + d_)>y[0][0])
						putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[i_][n_] - (fall[i_][n_]) * h + d_, BLACK);
					c_++;
				}
				else { 
					putimage_transparent(NULL, PIECE[i_][n_], x[i_][n_], y[i_][n_], BLACK); 
				}

			}
		}
		if (c_ == 0)break;

	}
	//////////////////////////////////////////////////
	if (combo > 1)this->animation_combo();
	flushmouse();
	return 0;
}
int Animation::animation_stop()
{
	PIMAGE source = newimage();
	getimage(source, 0, 0, Global::x_scr, Global::y_scr);    //������ͣǰ����;
	cleardevice();
	putimage(0, 0, game_stop);

	putimage_transparent(NULL, game_start,(Global::x_scr/2)-400, (Global::y_scr/2), BLACK);
	putimage_transparent(NULL, game_exit,(Global::x_scr / 2 ), (Global::y_scr / 2), BLACK);
	mouse_msg _a;
	int left = 0;
	PIMAGE BK_ = newimage();
	getimage(BK_,0, 0, Global::x_scr, Global::y_scr);
	for (;;)
	{

		_a = getmouse();
		putimage(0, 0, BK_);                //�����ʼͼƬ���л�ͼ����Ҫʵ�ַ����ܣ�



		if (_a.is_left())left++;                           // ��������Ϣ��

		////////////////////////////////////////////�����ϢΪż��ʱ�������//////////////


		setcolor(WHITE);

		if (_a.x <= (Global::x_scr / 2) - 300 && _a.x >= (Global::x_scr / 2) - 400 && _a.y <= (Global::y_scr / 2)+100 && _a.y >= (Global::y_scr / 2))  //�ж���굱ǰ���ڷ���
		{

			rectangle((Global::x_scr / 2) - 400, (Global::y_scr / 2), (Global::x_scr / 2) - 300, (Global::y_scr / 2)+100);


		}
		if (_a.x <= (Global::x_scr / 2) +100 && _a.x >= (Global::x_scr / 2)  && _a.y <= (Global::y_scr / 2) + 100 && _a.y >= (Global::y_scr / 2))  //�ж���굱ǰ���ڷ���
		{

			rectangle((Global::x_scr / 2), (Global::y_scr / 2), (Global::x_scr / 2)+100, (Global::y_scr / 2) + 100);


		}

		///////////////////////////////////////////�����ϢΪż��ʱ���������������ҽ��뽻������///////////////////////

			{
				setcolor(WHITE);
				if (left == 2)
				{
					if (_a.x <= (Global::x_scr / 2) - 300 && _a.x >= (Global::x_scr / 2) - 400 && _a.y <= (Global::y_scr / 2) + 100 && _a.y >= (Global::y_scr / 2))  //�ж���굱ǰ���ڷ���
					{

						left = 1;

						

						break;
					}
					if (_a.x <= (Global::x_scr / 2) + 100 && _a.x >= (Global::x_scr / 2) && _a.y <= (Global::y_scr / 2) + 100 && _a.y >= (Global::y_scr / 2))  //�ж���굱ǰ���ڷ���
					{

						left = 0;


				
						break;
					}


					left = 0;//���������Ϣ
				}


				//////////////////////////////////////////

			}
	}
			putimage(0, 0, source);
	return left;
}
int Animation::animation_combo()
{
	PIMAGE RE = newimage();
	getimage(RE, 0, 0, 1476, 1016);
	putimage_transparent(NULL, COMBO, Global::x_map_LT, Global::y_map_LT, BLACK);
	music_combo.Play(0);
	delay_ms(300);
	putimage(0, 0, RE);
	delimage(RE);
	return 0;
}
void Animation::music_stop()
{
	this->music_bgm.Stop();
}
void Animation::music_start()
{
	this->music_bgm.Play(0);
}
