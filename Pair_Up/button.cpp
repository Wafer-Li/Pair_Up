#include"button.h";
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
	mouse_msg a;
	PIMAGE q = BK;
	
	for (;;)
	{
		
		a = getmouse();
		putimage(0, 0, q);
		for ( nn = 0; nn < i; nn++)
		{
			putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);//��ť��̬
		}
		if (!(a.x <= cc&&a.x >= aa&&a.y <= dd&&a.y >= bb))break;//��귶Χ�ж�
		for (int n = 0; n < 10&&k==0; n++){

			if (a.x <= x[n] + w[n] && a.x >= x[n] && a.y <= y[n] + h[n] && a.y >= y[n]){
				putimage(0, 0, q);
				for ( nn = 0; nn < i; nn++)
				{
					if (nn != n)putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);
				}
				putimage_transparent(NULL, P2[n], x[n], y[n], BLACK);//��ťѡ��״̬
				//playmusic(A);   ѡ��Ч����
			}
		}

		if (a.is_left())k++;
		for (int n = 0; n < 10 && k == 1; n++){
			if (a.x <= x[n] + w[n] && a.x >= x[n] && a.y <= y[n] + h[n] && a.y >= y[n]){
				putimage(0, 0, q);
				for (nn = 0; nn < i; nn++)
				{
					if (nn != n)putimage_transparent(NULL, P[nn], x[nn], y[nn], BLACK);
				}
				putimage_transparent(NULL, P3[n], x[n], y[n], BLACK);//��ť����״̬
				
			}
		}
		if (k==2){
			for (int n = 0; n < 10; n++){
				
				if (a.x <= x[n] + w[n] && a.x >= x[n] && a.y <= y[n] + h[n] && a.y >= y[n])
				{// playmusic(B); ����Ч����
					
					return R[n];//�ɿ���ť�󷵻�ֵ
				}
			}
			return 0;
			k = 0;
		}
		
	}
	return 0;
}