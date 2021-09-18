#include"Game.h"

#include"Ship.h"
#include"Shoots.h"


const int bigAsteroidsAmount = 4;
const int mediumAsteroidsAmount = 8;
const int smallAsteroidsAmount = 16;
const float bigAsteroidSpeed = 150;
const float mediumAsteroidSpeed = 250;
const float smallAsteroidSpeed=450;
int destroyedMeteorsCount = 0;
int midMeteorsCount = 0;
int smallMeteorsCount = 0;

bool pause = false;

Ship* ship = new Ship;
Asteroid bigAsteroids[bigAsteroidsAmount];
Asteroid mediumAsteroids[mediumAsteroidsAmount];
Asteroid smallAsteroids[smallAsteroidsAmount];
Shoot shoot[10] = { 0 };


void initValeus()
{
	for (int i = 0; i < bigAsteroidsAmount; i++)
	{
		bigAsteroids[i] = Asteroid();
	}
	for (int i = 0; i < mediumAsteroidsAmount; i++)
	{
		mediumAsteroids[i] = Asteroid();
	}
	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		smallAsteroids[i] = Asteroid();
	}

	float posx, posy;
	float velx, vely;
	bool correctRange = false;
	victory = false;
	pause = false;




	ship->setPos({ (float)GetScreenWidth ()/ 2, (float)GetScreenHeight() / 2 });

	destroyedMeteorsCount = 0;

	// Initialization shoot
	for (int i = 0; i < 10; i++)
	{
		shoot[i].position = { 0, 0 };
		shoot[i].speed = { 0, 0 };
		shoot[i].radius = 2;
		shoot[i].active = false;
		shoot[i].color = WHITE;
	}

	// Initialization asteroid
	for (int i = 0; i < 4; i++) {
		posx = GetRandomValue(0, GetScreenWidth());
		posy = GetRandomValue(0, GetScreenHeight());



		bigAsteroids[i].setPos({ posx,posy });

		velx = GetRandomValue(-bigAsteroidSpeed, bigAsteroidSpeed);
		vely = GetRandomValue(-bigAsteroidSpeed, bigAsteroidSpeed);


		if (velx == 0 && vely == 0)
		{
			velx = GetRandomValue(-bigAsteroidSpeed, bigAsteroidSpeed);
			vely = GetRandomValue(-bigAsteroidSpeed, bigAsteroidSpeed);
		}
		bigAsteroids[i].setSpeed({ velx,vely });
		bigAsteroids[i].setRadius(40.0f);
		bigAsteroids[i].setActivity(true);

	}

	for (int i = 0; i < mediumAsteroidsAmount; i++)
	{
		mediumAsteroids[i].setPos({ -100, -100 });
		mediumAsteroids[i].setSpeed({ 0,0 });
		mediumAsteroids[i].setRadius(20);
		mediumAsteroids[i].setActivity(false);
	}

	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		smallAsteroids[i].setPos({ -100, -100 });
		smallAsteroids[i].setSpeed({ 0,0 });
		smallAsteroids[i].setRadius(10);
		smallAsteroids[i].setActivity(false);
	}

	midMeteorsCount = 0;
	smallMeteorsCount = 0;
}

static void gameplayUpdate()
{
	
	/*if (!pause)
	{*/


		updatePlayer();
		shootUpdate();
		asteroidsUpdate();

		for (int i = 0; i < bigAsteroidsAmount; i++) {
			if (CheckCollisionCircles({ ship->getCollider().x,ship->getCollider().y }, ship->getCollider().z, bigAsteroids[i].getPos(), bigAsteroids[i].getRadius()) && bigAsteroids[i].isActive())
				gameOver = true;
		}

		for (int i = 0; i < mediumAsteroidsAmount; i++) {
			if (CheckCollisionCircles({ ship->getCollider().x, ship->getCollider().y }, ship->getCollider().z, mediumAsteroids[i].getPos(), mediumAsteroids[i].getRadius()) && mediumAsteroids[i].isActive()) 
				gameOver = true;
		}

		for (int i = 0; i < smallAsteroidsAmount; i++) {
			if (CheckCollisionCircles({ ship->getCollider().x, ship->getCollider().y }, ship->getCollider().z, smallAsteroids[i].getPos(), smallAsteroids[i].getRadius()) && smallAsteroids[i].isActive()) 
				gameOver = true;
		}


		collisionAndSplitAsteroids(bigAsteroids, mediumAsteroids, bigAsteroidsAmount, midMeteorsCount, shoot, false,bigAsteroidSpeed, mediumAsteroidSpeed);
		collisionAndSplitAsteroids(mediumAsteroids, smallAsteroids, mediumAsteroidsAmount, smallMeteorsCount, shoot, false,mediumAsteroidSpeed, smallAsteroidSpeed);
		collisionAndSplitAsteroids(smallAsteroids, smallAsteroids, smallAsteroidsAmount, smallMeteorsCount, shoot, true,smallAsteroidSpeed,mediumAsteroidSpeed);


	/*}*/

	if (destroyedMeteorsCount == smallAsteroidsAmount+mediumAsteroidsAmount+bigAsteroidsAmount)
	{
		victory = true;
		currentScreen = MENU;
	}
}
//else {
//    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//    {
//        InitGame();
//        gameOver = false;
//    }


void gameplayDraw()
{


	ClearBackground(BLACK);


	// Draw spaceship
	Vector2 v1 = { ship->getPos().x + sinf(ship->getRotation() * DEG2RAD) * (ship->getShipHeight()), ship->getPos().y - cosf(ship->getRotation() * DEG2RAD) * (ship->getShipHeight()) };
	Vector2 v2 = { ship->getPos().x - cosf(ship->getRotation() * DEG2RAD) * (20.0f / 2),  ship->getPos().y - sinf(ship->getRotation() * DEG2RAD) * (20.0f / 2) };
	Vector2 v3 = { ship->getPos().x + cosf(ship->getRotation() * DEG2RAD) * (20.0f / 2),  ship->getPos().y + sinf(ship->getRotation() * DEG2RAD) * (20.0f / 2) };
	DrawTriangle(v1, v2, v3, MAROON);

	// Draw meteors
	for (int i = 0; i < bigAsteroidsAmount; i++)
	{
		if (bigAsteroids[i].isActive()) DrawCircleV(bigAsteroids[i].getPos(), bigAsteroids[i].getRadius(), DARKGRAY);

	}

	for (int i = 0; i < mediumAsteroidsAmount; i++)
	{
		if (mediumAsteroids[i].isActive()) DrawCircleV(mediumAsteroids[i].getPos(), mediumAsteroids[i].getRadius(), GRAY);

	}

	for (int i = 0; i < smallAsteroidsAmount; i++)
	{
		if (smallAsteroids[i].isActive()) DrawCircleV(smallAsteroids[i].getPos(), smallAsteroids[i].getRadius(), WHITE);

	}

	// Draw shoot
	for (int i = 0; i < 10; i++)
	{
		if (shoot[i].active) DrawCircleV(shoot[i].position, shoot[i].radius, WHITE);
	}



	if (pause) DrawText("GAME PAUSED", GetScreenWidth() / 2 - MeasureText("GAME PAUSED", 40) / 2, GetScreenHeight() / 2 - 40, 40, GRAY);

	/*else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);*/


}

void resetValeus()
{

	initValeus();
	gameOver = false;

}

void unloadGameplay()
{

}

void updatePlayer()
{
	ship->updateRotation();
	ship->updateSpeed();
	ship->updateAcceleration();
	ship->move();
	ship->checkWallCollision();
	ship->updateCollider();
}
void shootUpdate()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		for (int i = 0; i < 10; i++)
		{
			if (!shoot[i].active)
			{
				shoot[i].position = { ship->getPos().x + (float)sin(ship->getRotation() * DEG2RAD) * (ship->getShipHeight()), ship->getPos().y - (float)cos(ship->getRotation() * DEG2RAD) * (ship->getShipHeight()) };
				shoot[i].active = true;
				shoot[i].speed.x = 1.5 * sin(ship->getRotation() * DEG2RAD) * 6.0f;
				shoot[i].speed.y = 1.5 * cos(ship->getRotation() * DEG2RAD) * 6.0f;
				shoot[i].rotation = ship->getRotation();
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (shoot[i].active) {
			
			shoot[i].position.x += shoot[i].speed.x;
			shoot[i].position.y -= shoot[i].speed.y;

			if (shoot[i].position.x > GetScreenWidth() + shoot[i].radius)
			{
				shoot[i].active = false;
			}
			else if (shoot[i].position.x < 0 - shoot[i].radius)
			{
				shoot[i].active = false;
			}
			if (shoot[i].position.y > GetScreenHeight() + shoot[i].radius)
			{
				shoot[i].active = false;
			}
			else if (shoot[i].position.y < 0 - shoot[i].radius)
			{
				shoot[i].active = false;
			}


		}
	}

}
void asteroidsUpdate()
{

	for (int i = 0; i < bigAsteroidsAmount; i++)
	{
		if (bigAsteroids[i].isActive())
		{
			bigAsteroids[i].move();
			bigAsteroids[i].checkWallCollision();
		}
	}

	
	for (int i = 0; i < mediumAsteroidsAmount; i++)
	{
		if (mediumAsteroids[i].isActive())
		{
			mediumAsteroids[i].move();
			mediumAsteroids[i].checkWallCollision();
		}
	}

	
	for (int i = 0; i < 16; i++)
	{
		if (smallAsteroids[i].isActive())
		{
			smallAsteroids[i].move();
			smallAsteroids[i].checkWallCollision();
		}
	}
}
void collisionAndSplitAsteroids(Asteroid biggerSizeAsteroids[], Asteroid smallerSizeAsteroids[], int biggerSizeAmount, int& smallerSizeCount, Shoot shoot[], bool isSmall,float biggerAsteroidSpeed, float smallerAsteroidSpeed)
{
	for (int i = 0; i < 10; i++)
	{
		if ((shoot[i].active))
		{
			for (int a = 0; a < biggerSizeAmount; a++)
			{
				if (biggerSizeAsteroids[a].isActive() && CheckCollisionCircles(shoot[i].position, shoot[i].radius, biggerSizeAsteroids[a].getPos(), biggerSizeAsteroids[a].getRadius()))
				{
					biggerSizeAsteroids[a].setActivity(false);
					shoot[i].active = false;

					destroyedMeteorsCount++;

					if (!isSmall)
					{

						for (int j = 0; j < 2; j++)
						{
							if (smallerSizeCount % 2 == 0) {
								smallerSizeAsteroids[smallerSizeCount].setPos({ biggerSizeAsteroids[a].getPos() });
								smallerSizeAsteroids[smallerSizeCount].setSpeed({ (biggerSizeAsteroids[a].getSpeed().x * 1.5f) * -1,(biggerSizeAsteroids[a].getSpeed().y * 1.5f) * -1 });
							}
							else {
								smallerSizeAsteroids[smallerSizeCount].setPos({ biggerSizeAsteroids[a].getPos() });
								smallerSizeAsteroids[smallerSizeCount].setSpeed({ (biggerSizeAsteroids[a].getSpeed().x * 1.5f ,biggerSizeAsteroids[a].getSpeed().y * 1.5f) });
								if (smallerSizeAsteroids[smallerSizeCount].getSpeed().x <biggerAsteroidSpeed && smallerSizeAsteroids[smallerSizeCount].getSpeed().y<biggerAsteroidSpeed )
								{
									smallerSizeAsteroids[smallerSizeCount].setSpeed({ smallerAsteroidSpeed, smallerAsteroidSpeed });
								}
							}


							smallerSizeAsteroids[smallerSizeCount].setActivity(true);
							smallerSizeCount++;
						}
					}

					a = biggerSizeAmount;
				}
			}
		}
	}
}
void updateFrame()
{
	if (IsKeyPressed('P')) pause = !pause;
		gameplayUpdate();
		if (gameOver)
		{
			currentScreen = MENU;
			resetValeus();
		}

}
