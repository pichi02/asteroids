
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












void UnloadGame();

Screens currentScreen = MENU;
int main()
{


	InitWindow(screenWidth, screenHeight, "classic game: asteroids");

	SetTargetFPS(60);
	initValeus();
	initMenu();
	while (!WindowShouldClose())
	{

		
		/* if (currentScreen==GAMEPLAY)
		 {

			 do
			 {
				 UpdateDrawFrame();
			 } while (!gameOver && !victory);


		 }
		 else if (currentScreen==GAMEOVER)
		 {
			 do
			 {
				 BeginDrawing();
				 ClearBackground(BLACK);
				 DrawText("VICTORY", screenWidth / 2 - MeasureText("VICTORY", 20) / 2, screenHeight / 2, 20, LIGHTGRAY);

			 } while (true);
			 EndDrawing();
		 }*/

		switch (currentScreen)
		{
		case MENU:

			updateMenu();

			break;
		case GAMEPLAY:
			
			updateFrame();

			break;
		case GAMEOVER:
			break;
		case OPTIONS:
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
			break;
		case OPTIONS:
			break;
		default:
			break;
		}
		EndDrawing();
	}

	UnloadGame();

	CloseWindow();


	return 0;
}







// Unload game variables
void UnloadGame()
{
	// TODO: Unload all dynamic loaded data (textures, sounds, models...)
   /* delete[] bigAsteroids;
	delete ship;*/
}



