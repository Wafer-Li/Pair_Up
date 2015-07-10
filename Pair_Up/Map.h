#ifndef MAP_HEADER_FILE 
#define MAP_HEADER_FILE 

//include parts
#include <deque>
#include "Piece.h"

//Class
class Map{
private:
	static const int MAX_SIZE = 9;
	std::deque<Piece> maplists[MAX_SIZE];//Use deque instead of list
	bool isPass; //��ǰ��Ϸ�Ƿ����
	int passScore;
	//add the function for more conviently
	void deal_SpecPiece(int x, int y);//this function is used by clearPiece for check special Piece and deal with them
protected:
public:
	/* Ctor & Dtor */
	Map();
	~Map();

	/* MENBER */

	//initial & fill the map
	void initMap();

	//Swap
	bool swap(int x1, int y1, int x2, int y2);

	//g_isDeadMap
	bool g_isDeadMap();
	
	//another way to judge the DeadMap
	bool g_isDeadMap_();

	//isDead
	bool isDead(int x, int y);

	//isPieceClearale
	//NOTICE:
	//Only judge the single piece
	//Do NOT change the Piece.isClear
	bool isPieceClearable(int x, int y);

	//-----bool isPass-----
	bool getIsPass();
	void setIsPass(bool flag);

	//-----int passScore----
	int getPassScore();
	void setPassScore(int score);

	//Maplists
	std::deque<Piece> * getMaplists();

	/*FRIEND*/
	friend void clearPiece(Map& map);
	friend int removePiece(Map & map);
	friend void repairPiece(Map & map);
};

//FRIEND function

/*Friend function ClearPiece
* Judge the whole map
* Change the Piece.isClear
*/
void clearPiece(Map & map);

/*Friend function RemovePiece
* Ergodic the whole map
* Count the number of removing-items
* Remove Piece
* Return the number of removing-items
*/
int removePiece(Map & map);

/*Friend function RepairPiece
* Ergodic the deque
* If the deque are not full
* Fill it
*/
void repairPiece(Map & map);



#endif // !MAP_HEADER_FILE 