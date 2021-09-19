
#include <math.h>
#include"Menu.h"
#include <iostream>
#include"Ship.h"
#include"Asteroid.h"
#include"main.h"
#include"Game.h"






const int screenWidth = 800;
const int screenHeight = 450;

bool gameOver = false;
bool victory = false;



Screens currentScreen = MENU;
int main()
{


	InitWindow(screenWidth, screenHeight, "classic game: asteroids");
	SetTargetFPS(60);
	initValeus();
	initMenu();
	while (!WindowShouldClose())
	{

		
		
		switch (currentScreen)
		{
		case MENU:

			updateMenu();

			break;
		case GAMEPLAY:
			
			updateFrame();

			break;
		case GAMEOVER:
			
			updateGameOverScreen();
			break;
		case VICTORY:
			updateVictoryScreen();
		case CREDITS:
			updateCreditsScreen();
			break;
		default:
			break;
		}


		BeginDrawing();
		switch (currentScreen)
		{
		case MENU:


			drawMenu();

			break;
		case GAMEPLAY:

			gameplayDraw();

			break;
		case GAMEOVER:
			drawGameOverScreen();
			break;
		case VICTORY:
			drawVictoryScreen();
			break;
		case CREDITS:
			drawCreditsScreen();
			updateMenuMusic();
			break;
		default:
			break;
		}
		EndDrawing();
	}



	CloseWindow();


	return 0;
}










