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
	for (int i=0; i<5; i++)
		mShipHealth[i] = shipLengths[i];
	mRemainingShips = 5;
	playerState = PlayerState::None;
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
		inputValue <= ShipID::Wreck
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
void Player::hitShip(char arri, char shipID)
{	//Jumps to coordX rows along + coordY in the row
	playerState = PlayerState::ShipHit;
	setShips(arri, ShipID::Wreck);
	if (--mShipHealth[shipID] == 0)
	{
		if (--mRemainingShips <= 0)
			playerState = PlayerState::Defeated;
	}
}
void Player::shootEnemy(Player& pEnemy, char arri)
{	char shotOutcome = pEnemy.getShips(arri);
	if (shotOutcome == ShipID::Sea || shotOutcome == ShipID::Wreck)
	{//Miss
		setTargeting(arri, 2);
		pEnemy.playerState = PlayerState::None;
	}
	else if (shotOutcome >= ShipID::Destroyer && shotOutcome <= ShipID::Carrier)
	{//Hit
		pEnemy.hitShip(arri, shotOutcome);
		setTargeting(arri, TargetingID::Hit);
	}
	else;
}

bool Player::insertShip(char shipID, char coordX, char coordY, bool isHorizontal)
{	char shipLength = shipLengths[shipID-1];
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










