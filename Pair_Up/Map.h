#ifndef MAP_HEADER_FILE 
#define MAP_HEADER_FILE 

//include parts
#include <deque>
#include "Piece.h"
#include "Global.h"

//Class
class Map{
private:
	static const int MAX_SIZE = 9;
	std::deque<Piece> maplists[MAX_SIZE];//Use deque instead of list

protected:
public:
	/* Ctor & Dtor */
	Map();
	~Map();

	/* MENBER */

	//Funciton: initial & fill the map
	//Update: Remove for unnecessary

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

	//Maplists
	std::deque<Piece> * getMaplists();

	/*FRIEND*/
	friend void clearPiece(Map& map);
	friend int removePiece(Map & map);
	friend void repairPiece(Map & map);
	//add the function for more conviently
	friend void deal_SpecPiece(int x, int y, Map& map);//this function is used by clearPiece for check special Piece and deal with them
	//caculate the movePoint for each Piece after clearPiece function
	friend void movePoint(Map& map);
	//initialize the movePoint
	friend void init_movePoint(Map& map);
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

/*
Friend function Deal_SpecialPiece
As to the different SpecialType, it have different way
Help ClearPiece function to change the Pieces' isClear
*/
void deal_SpecPiece(int x, int y, Map& map);

#endif // !MAP_HEADER_FILE 