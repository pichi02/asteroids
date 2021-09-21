
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


	InitWindow(screenWidth, screenHeight, "LUCASTEROIDS");
	SetTargetFPS(60);
	initValeus();
	initMenu();
	while (!WindowShouldClose()&&!getQuit())
	{

		BeginDrawing();
		switch (currentScreen)
		{
		case MENU:

			updateMenu();
			drawMenu();

			break;
		case GAMEPLAY:
			updateFrame();
			gameplayDraw();

			break;
		case GAMEOVER:
			updateGameOverScreen();
			drawGameOverScreen();
			break;
		case VICTORY:
			updateVictoryScreen();
			drawVictoryScreen();
			break;
		case CREDITS:
			updateCreditsScreen();
			updateMenuMusic();
			drawCreditsScreen();
			
			break;
		default:
			break;
		}
		EndDrawing();
	}



	CloseWindow();


	return 0;
}










