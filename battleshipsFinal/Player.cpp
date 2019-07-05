#include <ctime>
#include "mallib.h"
#include "Player.h"
//Sets default member values
Player::Player()
{
}
//Sets default member values
void Player::reset()
{
	for (int i=0; i<100; i++)
	{	mShips[i] = ShipID::Sea;
		mTargeting[i] = TargetingID::Sea;
	}
	for (int i : mShipHealth)
		mShipHealth[i] = ShipID::SHIP_LENGTHS[i];
	mRemainingShips = 5;
}

std::string Player::intToCoord(char coordX, char coordY)
{	std::string foo;
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
	if (arri >= 0 && 
		arri < 100 &&
		inputValue >= ShipID::Error &&
		inputValue <= ShipID::Carrier
	)
		mShips[arri] = inputValue;
	else;
}
void Player::setTargeting(char arri, char inputValue)
{	//Jumps to coordX rows along + coordY in the row
	if (arri >= 0 && 
		arri < 100 && 
		inputValue >= TargetingID::Error && 
		inputValue <= TargetingID::Miss
	)
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
bool Player::hitShip(char arri, char shipID)
{	//Jumps to coordX rows along + coordY in the row
	setShips(arri, 6);
	if (--mShipHealth[shipID] == 0)
		mRemainingShips--
}
char Player::shootEnemy(Player& pEnemy, char arri)
{	char shotOutcome = pEnemy.getShips(arri);
	if (shotOutcome == ShipID::Sea || shotOutcome == ShipID::Wreck)
	{//Miss
		setTargeting(arri, 2);
		return 0;
	}
	else if (shotOutcome >= ShipID::Submarine && shotOutcome<= ShipID::Battleship)
	{//Hit
		pEnemy.hitShip(arri, ShipID::Wreck);
		setTargeting(arri, TargetingID::Hit);
		hitShip(arri, shotOutcome);
		return shotOutcome;
	}
	else
		return ShipID::Error;
}

bool Player::insertShip(char shipID, char coordX, char coordY, bool isHorizontal)
{	char shipLength = ShipID::SHIP_LENGTHS[shipID-1];
	char foo;
	if (isHorizontal)
	{//Location Validation	
		if (coordX < 0 || coordX+shipLength > 9)
		//Ship is out of bounds
			return false;
		for (int i=0; i<shipLength; i++)
		{	foo = mrd::arric(coordX+i, coordY, 10);
			if (getShips(foo) > ShipID::Sea)
			//Ship is in the way
				return false;
		}//Valid
		for (int i=0; i<shipLength; i++)
		{//Ship Placement
			foo = mrd::arric(coordX+i, coordY, 10);
			setShips(foo, shipID);
		}
		return true;
	}//Vertical
	else
	{//Location Validation	
		if (coordY < 0 || coordY+shipLength > 9)
			return false;
		for (int i=0; i<shipLength; i++)
		{//Ship placement
			foo = mrd::arric(coordX, coordY+i, 10);
			if (getShips(foo) > ShipID::Sea)
			//Ship is in the way
				return false;
		}
		for (int i = 0; i<shipLength; i++)
		{//Ship Placement
			foo = mrd::arric(coordX, coordY+i, 10);
			setShips(foo, shipID);
		}
		return true;
	}
}