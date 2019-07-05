#ifndef PLAYER_H
#define PLAYER_H
#include <string>

namespace ShipID
{
	enum ShipID : char
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
	const char SHIP_LENGTHS[5] = { 2, 3, 3, 4, 5 };
	const std::string SHIP_NAMES[5] =
	{
		"Destroyer", 
		"Submarine",
		"Cruiser",
		"Battleship",
		"Aircraft Carrier"
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
namespace PlayerState
{
	enum State
	{	None,
		ShipHit,
		ShipDestroyed,
		Defeated
	};
}

class Player
{	
	char mShips[100];
	char mTargeting[100];
	char mShipHealth[5];
	char playerState;
public:
	Player();
	char mRemainingShips;
	void reset();
	std::string intToCoord(char coordX, char coordY);
	void setShips(char arri, char inputValue);
	void setTargeting(char arri, char inputValue);
	char getShips(char arri);
	char getTargeting(char arri);
	void hitShip(char arri, char shipID);
	bool insertShip(char shipID, char corodX, char coordX, bool isHorizontal);
	char shootEnemy(Player& pEnemy, char arri);
	char getPlayerState();

};

#endif