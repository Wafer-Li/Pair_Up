#include"button.h"
int Button::x[10] = {0};
int Button::y[10] = { 0 };
int Button::w[10] = { 0 };
int Button::h[10] = { 0 };
int Button::R[10] = { 0 };
int Button:: i = 0;
PIMAGE Button::P[10] = { NULL }; 
PIMAGE Button::P2[10] = { NULL};
PIMAGE Button::P3[10] = { NULL };
Button::Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3) //��ʼ��ĺ����� ������ ��� �߶� ��̬ͼ ѡ��ͼ ���ͼ
{
	x[i] = startx;
	y[i] = starty;
	R[i] = Return;
	w[i] = wide;
	h[i] = high;
	P[i] = p;
	P2[i] = p2;
	P3[i] = p3;
	i++;
	//putimage_transparent(NULL, p, startx, starty, BLACK);


}
Button::~Button()
{
	i--;
	
}
int Button::pubutton(int aa,int bb,int cc,int dd,PIMAGE BK)//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�ִ��ǰ�Ľ�ͼ
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg a;
	PIMAGE q = BK;
	
	PIMAGE dd_ = newimage();
	getimage(dd_, "resource\\init.png", 0, 0);
	PIMAGE M_[4];
	PIMAGE O_[4];
	
	putimage(0, 0, BK);
	for (nn = 0; nn <i; nn++)
	{
		M_[nn] = newimage();
		O_[nn] = newimage();
		getimage(M_[nn],0,0,1476,1016);
		getimage(O_[nn], 0, 0, 1476, 1016);
		
		for (uu = 0; uu <i; uu++){
			if (uu != nn){
				putimage_transparent(M_[nn], P[uu], x[uu], y[uu], BLACK);
				putimage_transparent(O_[nn], P[uu], x[uu], y[uu], BLACK);
			}
			
		}
		putimage_transparent(M_[nn], P2[nn], x[nn], y[nn], BLACK);
		putimage_transparent(O_[nn], P3[nn], x[nn], y[nn], BLACK);

	}

	for (nn = 0; nn < i; nn++)
	{
		putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);
	}

	getimage(dd_, 0,0,1476,1016);
	
	for (;;)
	
	{

		a = getmouse();
		putimage(0, 0, dd_);
		
		if (!(a.x <= cc&&a.x >= aa&&a.y <= dd&&a.y >= bb))break;//��귶Χ�ж�
		for (nn = 0; nn < 10&&(k==0); nn++){

			if (a.x <= x[nn] + w[nn] && a.x >= x[nn] && a.y <= y[nn] + h[nn] && a.y >= y[nn]){
				
				putimage(0, 0, M_[nn]);
				
			//��ťѡ��״̬
				//playmusic(A);   ѡ��Ч����
			}
		}

		if (a.is_left())k++;
		for ( nn = 0; nn< 10 &&( k == 1); nn++){
			if (a.x <= x[nn] + w[nn] && a.x >= x[nn] && a.y <= y[nn] + h[nn] && a.y >= y[nn]){
				putimage(0, 0, O_[nn]);
				//��ť����״̬
				
			}
		}
		if (k==2){
			for ( nn = 0; nn < 10; nn++){
				
				if (a.x <= x[nn] + w[nn] && a.x >= x[nn] && a.y <= y[nn] + h[nn] && a.y >= y[nn])
				{// playmusic(B); ����Ч����
					for (uu = 0; uu < i; uu++)
					{
						delimage(M_[uu]);
						delimage(O_[uu]);

					}
					delimage(dd_);
					

					return R[nn];//�ɿ���ť�󷵻�ֵ
				}
			}
			return 0;
			k = 0;
		}
		
	}
	
	return 0;
}