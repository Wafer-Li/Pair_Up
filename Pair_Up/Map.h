#ifndef MAP_HEADER_FILE 
#define MAP_HEADER_FILE 

//include parts
#include <list>


class Map{
private:
	static const int MAX_SIZE = 9;
	std::list<Piece> maplists[MAX_SIZE];	//Use list 9*9 map
	//Piece[9][9] piece;	//����list ������ݽṹLHT����������
	bool isPass; //��ǰ��Ϸ�Ƿ����
	int passScore;
protected:
public:
	Map();
	~Map();

	//initial & fill the map
	void initMap();

	//isDeadMap
	bool isDeadMap();


	//-----bool isPass-----
	bool getIsPass();
	void setIsPass(int flag);
	//-----int passScore----
	int getPassScore();
	void setPassScore(int score);
};


#endif // !MAP_HEADER_FILE 