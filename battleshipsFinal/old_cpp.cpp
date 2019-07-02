#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <array>
#include <memory>
typedef std::array<short int, 100> Grid;
typedef short int Sint16;//Short Integer
typedef std::string String;
//Global Constants
const std::array<String, 5> SHIP_NAMES = { "Destroyer", "Submarine", "Cruiser", "Battleship", "Airftact Carrier" };
const Sint16 SHIP_HEALTH_RESET[5] = { 2, 3, 3, 4, 5 };
const bool godMode = false;
//Command Line Functions
//Prints out a string in the command line
void print(String message, bool newLine = true)
{
	newLine ? std::cout << message << "\n" : std::cout << message;
}
void print(char* message, bool newLine = true)
{
	newLine ? std::cout << message << "\n" : std::cout << message;
}
void print(int message, bool newLine = true)
{
	newLine ? std::cout << message << "\n" : std::cout << message;
}
void print(short int* grid)
{	std::cout << "  A B C D E F G H I J \n";
	for (int i = 0; i < 10; i++)
	{	std::cout << i+1 << " ";
		for (int j = 0; j < 10; j++)
		{	switch(grid[j + (10 * i)])
			{	case 0:
					std::cout << '-'; break;
				case 1:
					std::cout << 'X'; break;
				case 2:
					std::cout << 'O'; break;
				case 3:
					std::cout << '+'; break;
				case 4:
					std::cout << '@'; break;
				case 5:
					std::cout << '#'; break;
				case 6:
					std::cout << '~'; break;
			}
			if (i != 10)
			{	std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
//Returns user input
String input()
{
	String foo;
	std::cin >> foo;
	return foo;
}
//Flips a coin and takes user input
bool coinToss()
{	String foo;
	Sint16 coinSide;
	coinSide = rand() % 2;
	do
	{//Repeat until a valid answer is given
		if (!godMode) system("CLS");
		print(" Heads or Tails? heads/tails");
		foo = input();
	}	while (foo[0] != 'h' && foo[0] != 't');
	if (foo[0] == 'h' && coinSide == 0)
	{//User got heads correct
		print("heads, you win, you go first");
		return true;
	}
	else if (foo[0] == 't' && coinSide == 1)
	{//User got tails correct
		print("tails, you win, you go first");
		return true;
	}
	else
	{//Computer wins toss
		coinSide ? print("tails, you lost, AI goes first") : print("heads, you lost, AI goes first");
		return false;
	}
}
//Mathmatical Functions
//Squares a number
float sqr(float num)
{
	return num * num;
}
//Functions
void nullGrid(Sint16* pArray, int arraySize = 100)
{	//Nulls out a 1d grid of defined size
	for (int i = 0; i < arraySize; i++)
	{//Go through all rows in the array
		pArray[i] = 0;
	}
}
bool coordToInt(Sint16* coordX, Sint16* coordY, String coords)
{
	if (coords[0] >= 'a' && coords[0] <= 'j')
	{//First char in coordsiantes is from 'a' to 'j'
		*coordX = coords[0] - 'a';
	}
	else if (coords[0] >= 'A' && coords[0] <= 'J')
	{//First char in coords is from 'A' to 'J'
		*coordX = coords[0] - 'A';
	}
	else
	{//coordinate location is invalid
		return false;
	}
	if (coords[1] >= '1' && coords[1] <= '9')
	{//Second char in coords is from '1' to '9'
		if (coords[1] == '1' && coords[2] == '0')
		{//coords ends in a 10
			*coordY = 9;
		}//Coord does not end in 10
		else
		{	*coordY = coords[1] - '1';
		}
		return true;
	}//Invalid final coordiante
	else
	{	return false; 
	}
}
String intToCoord(Sint16 coordX, Sint16 coordY)
{
	String foo;
	foo[0] = coordX + 'A';
	if (coordY == 9)
	{	foo[1] = '1';
		foo[2] = '0';
	}
	else
	{	foo[1] = coordY + '1';
	}
	return foo;
}
void recordGrid(Sint16* pArray, Sint16 coordX, Sint16 coordY, Sint16 inputValue)
{
	pArray[coordX + (10 * coordY)] = inputValue;
}
Sint16 getGridValue(Sint16* pArray, Sint16 coordX, Sint16 coordY)
{
	return pArray[coordX + (10 * coordY)];
}
void shipSetup(Sint16* playerShips, bool rand = false)
{//Sets up the ships int he beginning of a new game
	String foo;
	Sint16 shipX;
	Sint16 shipY;
	std::time_t time = std::time(nullptr);
	bool  isLocationValid;
	for (int i=0; i<5; i++)
	{//Repeat ship setup 5 times
		isLocationValid = false;
		if (!rand)
		{//Ships to be placed manually
			if (!godMode) system("CLS");
			print("This is your grid currently");
			print(playerShips);
			print("Enter the location of your ", false);
			print((SHIP_NAMES[i]), false);
			print(" Length ", false);
			print(SHIP_HEALTH_RESET[i], false);
			print(". A1 to J10");
			foo = input();
			if (coordToInt(&shipX, &shipY, foo))
			{//Coordinates are valid
				print("Would you like the ship to be vertical or horizontal? v/h");
				foo = input();
				switch(foo[0])
				{//Player selects horizontal					
					case 'h':	
					//Horizontal
						if (shipX+SHIP_HEALTH_RESET[i] < 10 )
						{//Ship does not spill to next line
							for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
							{	if (getGridValue(playerShips, shipX + j, shipY))
								{//Invalid ship location
									print("A ship is in the way");
									isLocationValid = false;
									break;
								}//Valid
								else isLocationValid = true;
							}
						}
						break;
					case 'v':
						if (shipY + SHIP_HEALTH_RESET[i] < 10)
						{//Ship doesn't spill to next line	
							for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
							{	if (getGridValue(playerShips, shipX, shipY + j))
								{//Invalid ship location
									print("A ship is in the way");
									isLocationValid = false;
									break;
								}//Valid
								else isLocationValid = true;
							}
						}
						break;
					default:
					//Not vertical or horizontal selection
						print("You didn't select vertical or horizontal v/h");
						isLocationValid = false;
						break;
				}
			}//Invalid coordinate conversion
			else
			{	isLocationValid = false;
			}
			while (!isLocationValid)
			{//Repeats until user complies with constraints or is happy with selection
				if (!godMode) system("CLS");
				print(playerShips);
				print("Please enter a valid location of your " + SHIP_NAMES[i] + " Length ", false);
				print(SHIP_HEALTH_RESET[i], false);
				print(". A1 to J10");
				foo = input();
				if (coordToInt(&shipX, &shipY, foo))
				{//Coordinates are valid
					print("Would you like the ship to be vertical or horizontal? v/h");
					foo = input();
					switch (foo[0])
					{//Player selects horizontal					
					case 'h':
						//Horizontal
						if (shipX + SHIP_HEALTH_RESET[i] < 10)
						{//Ship does not spill to next line
							for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
							{	if (getGridValue(playerShips, shipX + j, shipY))
								{//Invalid ship location
									print("A ship is in the way");
									isLocationValid = false;
									break;
								}//Valid
								else isLocationValid = true;
							}
						}
						break;
					case 'v':
						if (shipY + SHIP_HEALTH_RESET[i] < 10)
						{//Ship doesn't spill to next line	
							for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
							{	if (getGridValue(playerShips, shipX, shipY + j))
								{//Invalid ship location
									print("A ship is in the way");
									isLocationValid = false;
									break;
								}//Valid
								else isLocationValid = true;
							}
						}
						break;
					default:
						//Not vertical or horizontal selection
						print("You didn't select vertical or horizontal v/h");
						isLocationValid = false;
						break;
					}
				}
			}
			if (isLocationValid)
			{	for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
				{//Records the ship into the player's grid
					foo[0] == 'h' ? recordGrid(playerShips, shipX + j, shipY, SHIP_HEALTH_RESET[i]) : recordGrid(playerShips, shipX, shipY + j, SHIP_HEALTH_RESET[i]);
				}
			}
		}//Ships are to be randomised
		else
		{	print("Randomising AI ships");
			while (!isLocationValid)
			{	foo[0] = std::rand() % 2;
				if (foo[0] == 0)
				{//Ship will be horizontal
					shipX = std::rand() % (10-i);
					shipY = std::rand() % 10;
					if (shipX + SHIP_HEALTH_RESET[i] < 10)
					{//Ship doesn't spill to next line	
						for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
						{	if (getGridValue(playerShips, shipX+j, shipY + j))
							{//Invalid ship location
								print("A ship is in the way");
								isLocationValid = false;
								break;
							}//Valid
							else isLocationValid = true;
						}
					}
					if (isLocationValid)
					{	for (int j=0; j<SHIP_HEALTH_RESET[i]; j++)
						{	recordGrid(playerShips, shipX+j, shipY, SHIP_HEALTH_RESET[i]);
						}
					}
				}//Ship will be horizontal
				else
				{	shipX = std::rand() % (10 - i);
					shipY = std::rand() % 10;
					if (shipY + SHIP_HEALTH_RESET[i] < 10)
					{//Ship doesn't spill to next line	
						for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
						{	if (getGridValue(playerShips, shipX, shipY + j))
							{//Invalid ship location
								print("A ship is in the way");
								isLocationValid = false;
								break;
							}//Valid
							else isLocationValid = true;
						}
					}
					if (isLocationValid)
					{	for (int j = 0; j < SHIP_HEALTH_RESET[i]; j++)
						{	recordGrid(playerShips, shipX, shipY + j, SHIP_HEALTH_RESET[i]);
						}
					}
				}
			}
		}
		print(shipX);
		print(shipY);
		print(playerShips);
		std::time(&time);
		srand(time);
	}
	print("Ship setup is done.");
	std::cout << "\n";
}
Sint16 shootGrid(Sint16* pEnemyShips, String coords, Sint16* pPlayerTargeting = nullptr)
{
	Sint16 foo;
	Sint16 coordX;
	Sint16 coordY;
	if (coordToInt(&coordX, &coordY, coords))
	{
		foo = getGridValue(pEnemyShips, coordX, coordY);
		if (foo == 0 || foo == 6)
		{//Targeted grid coordinate is sea or destroyed ship part
			print("You missed...");
			//Records and returns miss
			if (pPlayerTargeting) 
				recordGrid(pPlayerTargeting, coordX, coordY, 2);
			return 0;
		}
		else if (foo > 1 && foo < 6)
		{//Targeted grid coordinate is a ship
			print("You hit the ennemy ship!");
			//Records a hit
			recordGrid(pEnemyShips, coordX, coordY, 6);
			if (pPlayerTargeting) recordGrid(pPlayerTargeting, coordX, coordY, 1);
			return foo;
		}
	}//Invalid coordinate
	else
	{
		return -1;
	}
}
//ENTRY POINT
int main(int argc, char** argv)
{	//Variable Setup
	enum Direction : int {up, down, left, right};
	bool isRunning = true;
	bool isGameOver = false;
	bool isPlayer1First = false;
	bool isPlayer1Turn = false;
	bool isInputInvalid = false;
	bool isComputerHunting = false;
	Sint16 player1Ships[100];
	Sint16 player1Targeting[100];
	Sint16 player2Ships[100];
	Sint16 player2Targeting[100];
	Sint16 player1ShipHealth[5];
	Sint16 player2ShipHealth[5];
	Sint16 player1ShipsRemaining;
	Sint16 player2ShipsRemaining;
	Sint16 turnCount;
	String userInput;
	Sint16 shotOutcome = -1;
	Sint16 shotsTried = 0;
	Sint16 randomX;
	Sint16 randomY;
	Sint16 hitX;
	Sint16 hitY;
	Sint16 shipValue;
	Sint16 currentTry;
	bool isDirectionTarget[4] = { true, true, true, true };
	//Reset Values
	std::time_t time;
	while (isRunning)
	{//New game
		std::time(&time);
		srand(time);
		turnCount = 0;
		for (int i=0; i<100; i++)
		{
			player1Ships[i] = 0;
			player2Ships[i] = 0;
			player1Targeting[i] = 0;
			player2Targeting[i] = 0;
		}
		nullGrid(player1Ships, 100);
		nullGrid(player1Targeting, 100);
		nullGrid(player2Ships, 100);
		nullGrid(player2Targeting, 100);
		player1ShipsRemaining = 5;
		player2ShipsRemaining = 5;
		isInputInvalid = false;
		isComputerHunting = false;
		currentTry = 0;
		for (int i=0; i<5; i++)
		{
			player1ShipHealth[i] = SHIP_HEALTH_RESET[i];
			player2ShipHealth[i] = SHIP_HEALTH_RESET[i];
		}
		if (godMode)
		{	print("Randomize ships?");
			userInput = input();
			if (userInput == "yes") shipSetup(player1Ships, true);
			else shipSetup(player1Ships);
		}
		else
		{	shipSetup(player1Ships);
		}
		shipSetup(player2Ships, true);
		isPlayer1First = coinToss();
		isPlayer1Turn = isPlayer1First;
		isGameOver = false;
		while (!isGameOver)
		{//GAME LOOP
			if (!godMode) std::system("CLS");
			print("Your ships:");
			print(player1Ships);
			print("Your view of enemy's grid:");
			print(player1Targeting);
			if (godMode)
			{	print("Enemiy Ships DEBUG:");  
				print(player2Ships); 
			}
			if (turnCount >= 50)
			{	print("50 turns has passed, the game is a stalemate");
				isGameOver = true;
			}
			else if (isPlayer1Turn || isInputInvalid)
			{//Player 1's turn
				print("Where do you want to shoot? A1 to J10");
				userInput = input();
				shotOutcome = shootGrid(player2Ships, userInput, player1Targeting);
				if (shotOutcome > 0 && shotOutcome < 6)
				{//Hit registered
					player2ShipHealth[shotOutcome-1]--;
					if (player2ShipHealth[shotOutcome-1] <= 0)
					{//0 ship health left on hit ship
						print("The enemy's " + SHIP_NAMES[shotOutcome-1] + " has been destroyed!");
						player2ShipsRemaining--;
						isInputInvalid = false;
						turnCount++;
					}
				}
				else if (shotOutcome == 0)
				{//Missed shot
					print("You missed the enemy...");
					isInputInvalid = false;
					turnCount++;
				}//Off-grid hit
				else
				{	while (shotOutcome == -1)
					{//Shot location is invalid
						print("Please enter a valid grid location. A1 to J10");
						userInput = input();
						shotOutcome = shootGrid(player2Ships, userInput, player1Targeting);
						isInputInvalid = true;
					}
				}
				//Change player turn
				isPlayer1Turn = false;
			}//Player 2 Turn (AI)
			else if (!isPlayer1Turn)
			{	if (isComputerHunting)
				{//AI enabled
					//Up Check
					if (hitY-1 >= 0)
					{	shipValue = getGridValue(player2Targeting, hitX, hitY-1);
						if (shipValue)
						{	isDirectionTarget[Direction::up] = false;
						}
						else
						{	isDirectionTarget[Direction::up] = true;
						}
					}
					else
					{	isDirectionTarget[Direction::up] = false;
					}//Left Check
					if (hitX-1 >= 0)
					{	shipValue = getGridValue(player2Targeting, hitX-1, hitY);
						if (shipValue)
						{	isDirectionTarget[Direction::left] = false;
						}
						else
						{	isDirectionTarget[Direction::left] = true;
						}
					}
					else
					{	isDirectionTarget[Direction::up] = false;
					}//Down Check
					if (hitY+1 <= 10)
					{	shipValue = getGridValue(player2Targeting, hitX, hitY+1);
						if (shipValue)
						{	isDirectionTarget[Direction::down] = false;
						}
						else
						{	isDirectionTarget[Direction::down] = true;
						}
					}
					else
					{	isDirectionTarget[Direction::up] = false;
					}//Right Check
					if (hitX+1 <= 10)
					{	shipValue = getGridValue(player2Targeting, hitX, hitY+1);
						if (shipValue)
						{	isDirectionTarget[Direction::right] = false;
						}
						else
						{	isDirectionTarget[Direction::right] = true;
						}
					}
					else
					{	isDirectionTarget[Direction::up] = false;
					}
					switch (currentTry)
					{	case Direction::up:
							if (isDirectionTarget[Direction::up])
							{	userInput = intToCoord(hitX, hitY-1);
								shotOutcome = shootGrid(player1Ships, userInput);
								print("Computer shot grid ", false);
								print(char( hitX + 'A' ),  char(hitY + '1'-1));
								if (shotOutcome >= 1 && shotOutcome <= 5)
								{	player1ShipHealth[shotOutcome-1]--;
									hitY--;
								}
								currentTry++;
								break;
							}
						case Direction::left:
							if (isDirectionTarget[Direction::left])
							{	userInput = intToCoord(hitX-1, hitY);
								shotOutcome = shootGrid(player1Ships, userInput);
								print(char( hitX + 'A'-1 ),  char(hitY + '1'));
								if (shotOutcome >= 1 && shotOutcome <= 5)
								{	player1ShipHealth[shotOutcome-1]--;
									hitX--;
								}
								currentTry++;
								break;
							}
						case Direction::down:
							if (isDirectionTarget[Direction::down])
							{	userInput = intToCoord(hitX, hitY+1);
								shotOutcome = shootGrid(player1Ships, userInput);
								print( char(hitX + 'A' ),  char(hitY + '1'+1));
								if (shotOutcome >= 1 && shotOutcome <= 5)
								{	player1ShipHealth[shotOutcome-1]--;
									hitY++;
								}
								currentTry++;
								break;
							}

						case Direction::right:
							if (isDirectionTarget[Direction::right])
							{	userInput = intToCoord(hitX+1, hitY);
								shotOutcome = shootGrid(player1Ships, userInput);
								print( char(hitX + 'A'+1) ,  char(hitY + '1'));
								if (shotOutcome >= 1 && shotOutcome <= 5)
								{	player1ShipHealth[shotOutcome-1]--;
									hitX++;
								}
								currentTry++;
								break;
							}
						case 5:
							currentTry = 0;
							isComputerHunting = false;
							break;	
					}
					
				}//Computer has no idea where to shoot
				else
				{	randomX = rand() % 10;
					randomY = rand() % 10;
					userInput[0] = randomX + 'A';
					if (randomY == 9)
					{	userInput[1] = 1;
						userInput[2] = 0;
					}
					else userInput[1] = randomY + '1';
					shotOutcome = shootGrid(player1Ships, userInput, player2Targeting);
					print("Computer shot grid ", false);
					print( char(randomX + 'A') ,  char(randomY + '1'));
					if (shotOutcome >= 1 && shotOutcome <= 5)
					{//Shot was a hit
						hitX = randomX;
						hitY = randomY;
						player1ShipHealth[shotOutcome-1];
						isComputerHunting = true;
					}
				}
				isPlayer1Turn = true;
				turnCount++;
			}
		if (player1ShipsRemaining == 0 || player2ShipsRemaining == 0 || isGameOver)
		{//Player 1 has lost all ships
			player1ShipsRemaining == 0 ? print("You are victorious!") : print("You have lost...");
			print("Play again? y/n");
			userInput = input();
			if (userInput[0] == 'n')
			{//Quit is picked
				print("Are you sure you want to quit? y/n");
				userInput = input();
				while (userInput[0] == 'n')
				{//User is indecisive
					print("Play again? y/n");
					userInput = input();
					if (userInput[0] == 'n')
					{//Quit is picked again
						print("Are you sure you want to quit? y/n");
						userInput = input();
						if (userInput[0] == 'y')
						{//Quit is confirmed
							break;
						}
					}
				}
				if (userInput[0] == 'y')
				{//Quit is confirmed
					isGameOver = true;
					isRunning = false;
					print("Thanks for playing!");
				}
			}
			else
			{	print("Resetting game...");
				isGameOver = true;
			}
			}
		}
	}//CLEANUP
	print("Cleaning up game...");
}