#include <ctime>
#include "mallib.h"
#include "Player.h"
//Sets default member values
Player::Player()
{
	for (int i=0; i<100; i++)
	{	mShips[i] = 0;
		mTargeting[i] = 0;
	}
	for (int i : mShipHealth)
		mShipHealth[i] = DEFAULT_HEALTH[i];
	mRemainingShips = 5;
}
//Sets default member values
void Player::reset()
{
	for (int i=0; i<100; i++)
	{	mShips[i] = ShipsID::Sea;
		mTargeting[i] = TargetingID::Sea;
	}
	for (int i : mShipHealth)
		mShipHealth[i] = DEFAULT_HEALTH[i];
	mRemainingShips = 5;
}
bool Player::coordToInt(char& arri, char* coords)
{	char foo = 0;
	if (*coords >= 'a' && *coords <= 'j')
		foo = *coords - 'a';
	else if (*coords >= 'A' && *coords <= 'J')
		foo= *coords - 'A';
	else
	//Invalid coordinate
		return false;
	if (coords[1] >= '1' && coords[1] <= '9')
	{	if (coords[1] == '1' && coords[2] == '0')
		//coords ends with 10
			arri = arric(foo, 9, 10);
		else
			arri = arric(foo, coords[1] - '1', 10);
		return true;
	}//Invalid coordinate
	else
		return false;
}
String Player::intToCoord(char coordX, char coordY)
{	String foo;
	if (coordX >= 0 && coordX <= 9)
		foo[0] = (coordX + 'A');
	else
	//Invalid location
		return "-1";
	if (coordY >= 0 && coordY <= 8)
		foo[1] = coordY + '1';
	else if (coordY == 9)
	{	foo[1] = '1';
		foo[2] = '0';
	}
	else
		return foo;
}
void Player::setShips(char arri, char inputValue)
{	//Jumps to coordX rows along + coordY in the row
	if (arri >= 0 && arri < 100)
	mShips[arri] = inputValue;
	else;
}
void Player::setTargeting(char arri, char inputValue)
{	//Jumps to coordX rows along + coordY in the row
	if (arri >= 0 && arri < 100)
		mTargeting[arri] = inputValue;
	else;
}
char Player::getShips(char arri)
{	if (arri >= 0 && arri < 100)
		return mShips[arri];
	else
		return -1;
}
char Player::getTargeting(char arri)
{	//Jumps to coordX rows along + coordY in the row
	if (arri >= 0 && arri < 100)
		return mTargeting[arri];
	else
		return -1;
}
void Player::hitShip(char arri, char shipID)
{	//Jumps to coordX rows along + coordY in the row
	setShips(arri, 6);
	if (--mShipHealth[shipID] == 0)
		mRemainingShips--;
}
char Player::shootEnemy(Player& pEnemy, char arri)
{	char shotOutcome = pEnemy.getShips(arri);
	if (shotOutcome == ShipsID::Sea || shotOutcome == ShipsID::Wreck)
	{//Miss
		setTargeting(arri, 2);
		return 0;
	}
	else if (shotOutcome >= ShipsID::Submarine && shotOutcome<= ShipsID::Battleship)
	{//Hit
		pEnemy.hitShip(arri, 6);
		setTargeting(arri, 1);
		hitShip(arri, shotOutcome);
		return shotOutcome;
	}
	else
		return ShipsID::Error;
}
bool Player::insertShip(char shipID, char coordX, char coordY, bool isHorizontal)
{	char shipLength;
	char foo;
	shipID == 1 ? 
		shipLength = 2: 
		shipLength = shipID;
	if (isHorizontal)
	{//Location Validation	
		if (coordX+shipLength > 9 || coordX < 0)
		//Ship is out of bounds
			return false;
		for (int i=0; i<shipID; i++)
		{	foo = arric(coordX+i, coordY, 10);
			if (getShips(foo))
			//Another ship is in the way
				return false;
		}//Valid
		for (int i = 0; i<shipLength; i++)
		{//Ship Placement
			foo = arric(coordX + i, coordY, 10);
			setShips(foo, shipID);
		}
		return true;
	}//Vertical
	else
	{//Location Validation	
		if (coordY+shipLength > 9 || coordY < 0)
			return false;
		for (int i=0; i<shipID; i++)
		{//Ship placement
			foo = arric(coordX, coordY+i, 10);
			if (getShips(coordY+i))
				return false;
		}
	}
}
