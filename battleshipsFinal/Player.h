#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
typedef std::string String;
namespace ShipsID
{
	enum ShipsID : char
	{
		Sea,
		Destroyer,
		Submarine,
		Cruiser,
		Battleship,
		Carrier,
		Wreck,
		Error = -1

	};
}
namespace TargetingID
{
	enum TargetingID : char
	{
		Sea,
		Hit,
		Miss,
		Error = -1
	};
}
class Player
{	const char DEFAULT_HEALTH[5] = { 2, 2, 3, 4, 5 };
	char mShips[100];
	char mTargeting[100];
	char mShipHealth[5];
	Player();
public:

	char mRemainingShips;
	void reset();
	bool coordToInt(char& arri, char* coords);
	String intToCoord(char coordX, char coordY);
	void setShips(char arri, char inputValue);
	void setTargeting(char arri, char inputValue);
	char getShips(char arri);
	char getTargeting(char arri);
	void hitShip(char arri, char shipID);
	bool insertShip(char shipID, char corodX, char coordX, bool isHorizontal);
	char shootEnemy(Player& pEnemy, char arri);
	

};

#endif