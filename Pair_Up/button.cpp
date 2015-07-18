#include"button.h"
int Button::button_x[20] = {0};
int Button::button_y[20] = { 0 };
int Button::button_w[20] = { 0 };
int Button::button_h[20] = { 0 };
int Button::button_R[20] = { 0 };
int Button:: button_i = 0;
PIMAGE Button::button_P[20] = { NULL }; 
PIMAGE Button::button_P2[20] = { NULL};
PIMAGE Button::button_P3[20] = { NULL };
PIMAGE Button::button_RP =  NULL ;
PIMAGE Button::button_allP = { NULL };
PIMAGE Button::button_M[20] = { NULL };
PIMAGE Button::button_O[20] = { NULL };
PIMAGE Button::chose = NULL;
int Button::cho = 0;
MUSIC Button::music_button_o;
MUSIC Button::music_button_m;
Button::Button(int startx, int starty, int wide, int high, int Return, PIMAGE p, PIMAGE p2, PIMAGE p3) //��ʼ��ĺ����� ������ ��� �߶� ��̬ͼ ѡ��ͼ ���ͼ
{
	button_x[button_i] = startx;
	button_y[button_i] = starty;
	button_R[button_i] = Return;
	button_w[button_i] = wide;
	button_h[button_i] = high;
	button_P[button_i] = p;
	button_P2[button_i] = p2;
	button_P3[button_i] = p3;
	music_button_m.OpenFile("resource//button_m.wav");
	music_button_o.OpenFile("resource//button_o.mp3");
	if (button_i == 0)
	{
		button_RP = newimage();
		getimage(button_RP, Global::x_0, Global::y_0, Global::x_scr, Global::y_scr);
	}
	button_i++;
	//putimage_transparent(NULL, p, startx, starty, BLACK);


}
Button::Button(int startx, int starty, int wide, int high, int Return, PIMAGE p) //��ʼ��ĺ����� ������ ��� �߶� ��̬ͼ ѡ��ͼ ���ͼ
{
	button_x[button_i] = startx;
	button_y[button_i] = starty;
	button_R[button_i] = Return;
	button_w[button_i] = wide;
	button_h[button_i] = high;
	button_P[button_i] = p;
	button_P2[button_i] = p;
	button_P3[button_i] = p;
	if (button_i == 0)
	{
		button_RP = newimage();
		getimage(button_RP, Global::x_0, Global::y_0, Global::x_scr, Global::y_scr);
	}
	button_i++;
	//putimage_transparent(NULL, p, startx, starty, BLACK);


}
Button::~Button()
{
	int j = 0;
	for (j = 0; j < 20; j++)
	{
		button_x[j] = 0;
		button_y[j] = 0;
		button_w[j] = 0;
		button_h[j] = 0;
		button_R[j] = 0;
	}
	cho = 0;
	button_i--;
	delimage(button_M[button_i]);
	delimage(button_O[button_i]);

	if (button_i == 0)
	{
		delimage(button_allP);
		delimage(button_RP);


	}
	
}
int Button::setbutton(int startx, int starty, int wide, int high)//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶�,     /*����������ť��̬ͼ���ϵ������ϲ����±���ͼƬ�Լ������ͼƬ�Ĵ���*/
{
	int k = 0;
	int nn = 0;
	int uu = 0;

	putimage(startx, starty, wide, high, button_RP, startx,starty);      //�����ťִ������ԭͼ
	 button_allP = newimage();



	for (nn = 0; nn <button_i; nn++)                          //��ѡ��̬�Ͱ���̬���ϵ�ԭͼ�����±���
	{
		button_M[nn] = newimage();
		button_O[nn] = newimage();
		getimage(button_M[nn], startx, starty, wide, high);
		getimage(button_O[nn], startx, starty, wide, high);

		for (uu = 0; uu <button_i; uu++){
			if (uu != nn){
				putimage_transparent(button_M[nn], button_P[uu], button_x[uu], button_y[uu], BLACK);
				putimage_transparent(button_O[nn], button_P[uu], button_x[uu], button_y[uu], BLACK);
			}

		}
		putimage_transparent(button_M[nn], button_P2[nn], button_x[nn], button_y[nn], BLACK);
		putimage_transparent(button_O[nn], button_P3[nn], button_x[nn], button_y[nn], BLACK);


	}

	for (nn = 0; nn < button_i; nn++)
	{ 
		putimage_transparent(NULL, button_P[nn], button_x[nn], button_y[nn], BLACK);           //����̬�����������
	}

	getimage(button_allP, startx, starty, wide, high);                   //����̬ͼ����

	return 0;
}
int Button::pubutton(int startx, int starty, int wide, int high)//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶�
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg mouse;
	
	flushmouse();
	for (;;)
	
	{

		mouse = getmouse();
		
		putimage(startx, starty, button_allP);
		
		if (!((mouse.x <= (startx + wide)) && (mouse.x >= startx) && (mouse.y <= (starty + high)) && (mouse.y >= starty)))
		{
			putimage(startx, starty, button_allP);
			break;//��귶Χ����ִ������ʱ�˳�
		}
		for (nn = 0; nn < 10&&(k==0); nn++){

			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				
				putimage(startx, starty, button_M[nn]);
				music_button_m.Play(0);
			//��ťѡ��״̬
				//playmusic(A);   ѡ��Ч����
			}
		}

		if (mouse.is_left())k++;
		for ( nn = 0; nn< 10 &&( k == 1); nn++){
			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] &&mouse.y >= button_y[nn]){
				putimage(startx, starty, button_O[nn]);
				//��ť����״̬
				
			}
		}
		if (k==2){
			for ( nn = 0; nn < 10; nn++){
				
				if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn])
				{
					music_button_o.Play(0);
					// playmusic(B); ����Ч����
					return button_R[nn];//�ɿ���ť�󷵻�ֵ
				}
			}
			return 0;
		}
		
	}
	
	return 0;
}
int Button::pubutton(int startx, int starty, int wide, int high,Time&time,PIMAGE bg)//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶�
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg mouse;
	int clock = 0;

	setcolor(WHITE); 
	flushmouse();
	for (;;)

	{
		for (; !mousemsg();)
		{
		
			putimage(0, 200, 510, 100, bg, 0, 200);
			clock = time.getRemainTime();
			xyprintf(70, 200, "Remain Time:");
			xyprintf(70, 250, "%d", clock);      //��겻��ʱʱ��䶯
			if (clock <= 0){
				flushmouse();
				return 1;
			}
		}
		mouse = getmouse();
		putimage(startx, starty, button_allP);

		if (!((mouse.x <= (startx + wide)) && (mouse.x >= startx) && (mouse.y <= (starty + high)) && (mouse.y >= starty)))
		{
			putimage(startx, starty, button_allP);
			break;//��귶Χ����ִ������ʱ�˳�
		}
		for (nn = 0; nn < 20 && (k == 0); nn++){

			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){

				
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
				//��ťѡ��״̬
				//playmusic(A);   ѡ��Ч����
			}
		}

		if (mouse.is_left())k++;
		for (nn = 0; nn< 20 && (k == 1); nn++){
			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
				//��ť����״̬

			}
		}
		if (k == 2){
			for (nn = 0; nn < 10; nn++){

				if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn])
				{// playmusic(B); ����Ч����
					
				


					return button_R[nn];//�ɿ���ť�󷵻�ֵ
				}
			}
			return 0;
		}

	}

	return 0;
}
int Button::pubutton(int startx, int starty, int wide, int high, int rectangle_)//ִ�к����ķ�Χ��ʼ��X,Y,��ȣ��߶ȣ�����ģʽ
{
	int k = 0;
	int nn = 0;
	int uu = 0;
	mouse_msg mouse;

	flushmouse();

	for (;;)

	{

		mouse = getmouse();
		if (cho == 0)putimage(startx, starty, button_allP);
		if (cho == 1)putimage(startx, starty, chose);

		if (!((mouse.x <= (startx + wide)) && (mouse.x >= startx) && (mouse.y <= (starty + high)) && (mouse.y >= starty)))
		{
			if (cho == 0)putimage(startx, starty, button_allP);
			if (cho == 1)putimage(startx, starty, chose);
			break;//��귶Χ����ִ������ʱ�˳�
		}
		for (nn = 0; nn < 20 && (k == 0); nn++){

			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				setcolor(WHITE);
				if (cho == 0)putimage(startx, starty, button_allP);
				if (cho == 1)putimage(startx, starty, chose);
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
				//��ťѡ��״̬
				//playmusic(A);   ѡ��Ч����
			}
		}

		if (mouse.is_left())k++;
		for (nn = 0; nn< 20 && (k == 1); nn++){
			if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn]){
				putimage(startx, starty, button_allP);
				setcolor(RED);
				rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);

				//��ť����״̬

			}
		}
		if (k == 2){
			for (nn = 0; nn < 20; nn++){

				if (mouse.x <= button_x[nn] + button_w[nn] && mouse.x >= button_x[nn] && mouse.y <= button_y[nn] + button_h[nn] && mouse.y >= button_y[nn])
				{// playmusic(B); ����Ч����
					putimage(startx, starty, button_allP);
					setcolor(RED);
					rectangle(button_x[nn], button_y[nn], button_x[nn] + button_w[nn], button_y[nn] + button_h[nn]);
					delimage(chose);
					chose = newimage();
					getimage(chose, startx, starty, wide, high);
					cho = 1;



					return button_R[nn];//�ɿ���ť�󷵻�ֵ
				}
			}
			return 0;
		}

	}

	return 0;
}