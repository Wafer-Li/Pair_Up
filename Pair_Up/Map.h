#include <list>

class Map{
private:
	std::list <Piece> maplists[9];	//Use list
	//Piece[9][9] piece;	//����list ������ݽṹLHT����������
	bool isPass; //��ǰ��Ϸ�Ƿ����
	bool isDeadMap;
	int passScore;
protected:
public:
	Map() :piece{};
	//-----bool isPass-----
	getIsPass();
	setIsPass();
	//-----int passScore----
	getPassScore();
	setPassScore();

	fillMap();
};


