#ifndef GLOBAL_H
#define GLOBAL_H

//never instantiation the class
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