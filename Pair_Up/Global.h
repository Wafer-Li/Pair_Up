#ifndef GLOBAL_H
#define GLOBAL_H

//WRANING:DO NOT instantiation the class
class Global
{
public:
	Global();
	~Global();
	const static int x_scr ;
	const static int y_scr ;
	const static int x_map ;
	const static int y_map  ;
	const static int x_piece ;
	const static int y_piece ;
	const static int x_map_LT ;
	const static int x_map_LB ;
	const static int y_map_LT ;
	const static int y_map_LB ;
	const static int delay_fall;               //fps
	const static int delay_add;                //fps
	const static int delay_change;             //fps
	const static int delay_disappear;          //ms
	const static int speed;
	const static int x_0;
	const static int y_0;
	const static int x_g_b_exit;
	const static int y_g_b_exit;
	const static int x_g_b_pause;
	const static int y_g_b_pause;
//specType:	
/*
*0.ori-ԭʼ����-ʲô������
*1.line-������
*2.row-������		
*3.box-����3*3	
*4.same_color-����ͬɫ	
*5.unclear-��������	
*6.death-ֱ������
*/
	enum SpecType
	{
		origin, line,row,box,same_color,unclearable,death
	};
};


#endif