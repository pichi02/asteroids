#include"raylib.h"
#include"Menu.h"
#include"main.h"


int titleX;
int titleY;
int playButtonSizeX;
int optionsButto;
int rectangleMouseSize;
int mouseX;
int mouseY;
int optionsButtonSizeX;
int buttonSizeY;
int playButtonX;
int playButtonY;
int optionsButtonX;
int optionsButtonY;
int quitButtonX;
int quitButtonY;
int quitButtonWidth;
int playAgainButtonX;
int victoryBackButtonX;
int backMenuButtonWidth;
bool quit;
static Music menuMusic;
Texture2D menuBackgroundTexture;
Image menuImage;





//int options(int width, int heigth, Texture2D menuBackground, Vector2 menuBackgroundPosition, Rectangle frameRecMenu, Music& menu, Music& gameplay, float& volume, Sound& ball)
//{
//	int rectangleMouseSize = 1;
//	int mouseX = GetMouseX();
//	int mouseY = GetMouseY();
//	int volumeButtonSizeX = 45;
//	int volumeButtomSizeY = 45;
//	int decreaseVolumeButtonX = ((width / 10) * 7) - volumeButtonSizeX - 10;
//	int increaseVolumeButtonX = (width / 10) * 7;
//	int volumeButtonY = heigth / 4;
//	int screenVolume = volume * 10;
//	int backButtonWidth = 180;
//	int backButtonHeigth = 60;
//	int backButtonX = width / 2 - backButtonWidth / 2;
//	int backButtonY = (heigth / 10) * 8;
//
//	BeginDrawing();
//	ClearBackground(BLACK);
//	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
//	DrawTextureRec(menuBackground, frameRecMenu, menuBackgroundPosition, RAYWHITE);
//	DrawRectangle(backButtonX, backButtonY, backButtonWidth, backButtonHeigth, RED);
//	DrawText(TextFormat("BACK"), backButtonX + 5, backButtonY, 60, WHITE);
//	DrawRectangle(increaseVolumeButtonX, volumeButtonY, volumeButtonSizeX, volumeButtomSizeY, RED);
//	DrawRectangle(decreaseVolumeButtonX, volumeButtonY, volumeButtonSizeX, volumeButtomSizeY, RED);
//	DrawText(TextFormat("+"), increaseVolumeButtonX + 2, volumeButtonY - 13, 80, WHITE);//el +2 y el -13 para que quede centrado el texto con respecto al cuadrado
//	DrawText(TextFormat("-"), decreaseVolumeButtonX + 6, volumeButtonY - 13, 80, WHITE);//lo mismo que en la anterior linea
//	DrawText(TextFormat(" % 01i", screenVolume), increaseVolumeButtonX + volumeButtonSizeX, volumeButtonY, 30, WHITE);
//	DrawText(TextFormat("MUSIC..............."), width / 4, volumeButtonY - 13, 70, WHITE);
//	EndDrawing();
//	if (volume < 10.0f)
//	{
//		if (collision(mouseX, mouseY, rectangleMouseSize, increaseVolumeButtonX, volumeButtonY, volumeButtonSizeX, volumeButtomSizeY) && IsMouseButtonPressed(0))
//		{
//			volume += 0.1f;
//		}
//	}
//	if (volume > 0.1f)
//	{
//		if (collision(mouseX, mouseY, rectangleMouseSize, decreaseVolumeButtonX, volumeButtonY, volumeButtonSizeX, volumeButtomSizeY) && IsMouseButtonPressed(0))
//		{
//			volume -= 0.1f;
//		}
//	}
//	if (collision(mouseX, mouseY, rectangleMouseSize, backButtonX, backButtonY, backButtonWidth, backButtonHeigth) && IsMouseButtonPressed(0))
//	{
//		return 1;
//	}
//	SetMusicVolume(menu, volume);
//	SetMusicVolume(gameplay, volume);
//	SetSoundVolume(ball, volume);
//}
//bool returnToMenu()
//{
//	if (IsKeyPressed(KEY_M))
//	{
//		return true;
//	}
//}
void initMenu()
{
	quit = false;
	titleX = (GetScreenWidth() / 100) * 25;
	titleY = (GetScreenHeight() / 10) * 3;
	playButtonSizeX = 135;
	optionsButtonSizeX = 180;
	buttonSizeY = 45;
	rectangleMouseSize = 1;
	playButtonX = (GetScreenWidth() / 100) *42;
	playButtonY = GetScreenHeight() * 4 / 10;
	optionsButtonX = playButtonX - 20;
	optionsButtonY = GetScreenHeight() * 6 / 10;
	quitButtonX = (GetScreenWidth()/100)*45;
	quitButtonY = GetScreenHeight() * 8 / 10;
	quitButtonWidth = 90;
	backMenuButtonWidth = 115;
	playAgainButtonX = (GetScreenWidth() / 100) * 70;
	victoryBackButtonX = (GetScreenWidth() / 100) * 30 - quitButtonWidth;
	menuMusic = LoadMusicStream("resources/menu.ogg");
	menuImage = LoadImage("resources/background.png");
	menuBackgroundTexture = LoadTextureFromImage(menuImage);
	
}

void updateMenu()
{
	PlayMusicStream(menuMusic);
	UpdateMusicStream(menuMusic);
	mouseX = GetMouseX();
	mouseY = GetMouseY();

	if (collision(mouseX, mouseY, rectangleMouseSize, playButtonX, playButtonY, playButtonSizeX, buttonSizeY) && IsMouseButtonPressed(0))
	{
		StopMusicStream(menuMusic);
		currentScreen = GAMEPLAY;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = CREDITS;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		UnloadImage(menuImage);
		UnloadMusicStream(menuMusic);
		
		quit = true;
	}

}
void drawMenu()
{
	
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	///*DrawTextureRec(menuBackground, frameRecMenu, menuBackgroundPosition, RAYWHITE);*/
	//DrawRectangle(optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY, BLUE);
	//DrawRectangle(playButtonX, playButtonY, playButtonSizeX, buttonSizeY, BLUE);
	//DrawRectangle(quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY, BLUE);
	
	DrawText(TextFormat("LUCASTEROIDS"), (GetScreenWidth()/100)*21, (GetScreenHeight()/100)*20, 60, BLUE);
	if (collision(mouseX, mouseY, rectangleMouseSize, playButtonX, playButtonY, playButtonSizeX, buttonSizeY))
	{
		DrawText(TextFormat("start"), playButtonX, playButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("start"), playButtonX, playButtonY, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY))
	{
		DrawText(TextFormat("credits"), optionsButtonX, optionsButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("credits"), optionsButtonX, optionsButtonY, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("quit"), quitButtonX , quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("quit"), quitButtonX , quitButtonY, 50, WHITE);
	}

	DrawText(TextFormat("Created by Lucas Pich"), 490, 910, 30, WHITE);

}

void drawGameOverScreen()
{
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	DrawText(TextFormat("YOU LOSE"), (GetScreenWidth() / 100) * 33, titleY, 50, WHITE);
	/*DrawRectangle(playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY, BLUE);
	DrawRectangle(victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY, BLUE);*/
	
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, WHITE);
	}
}
void updateGameOverScreen()

{
	mouseX = GetMouseX();
	mouseY = GetMouseY();
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = GAMEPLAY;
	}
	else if(collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = MENU;
	}

}

void drawVictoryScreen()
{
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	DrawText(TextFormat("YOU WIN :D"), (GetScreenWidth() / 100) * 33, titleY, 50, WHITE);
	/*DrawRectangle(playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY, BLUE);
	DrawRectangle(victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY, BLUE);*/
	
	
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, WHITE);
	}
}
void updateVictoryScreen()

{
	mouseX = GetMouseX();
	mouseY = GetMouseY();
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = GAMEPLAY;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = MENU;
	}

}
void drawCreditsScreen()
{
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	DrawText(TextFormat("CREDITS"), (GetScreenWidth() / 100) * 35, (GetScreenHeight()/100)*15, 50, WHITE);
	DrawText(TextFormat("background by Calinou (https://opengameart.org/content/space-skybox-1)"), (GetScreenWidth() / 100) * 6, (GetScreenHeight() / 100) * 35, 19, WHITE);
	DrawText(TextFormat("UI Audio by CodeManu (https://opengameart.org/content/magic-space)"), (GetScreenWidth() / 100) * 8, (GetScreenHeight() / 100) * 42, 19, WHITE);
	DrawText(TextFormat("Gameplay Audio by maxstack (https://opengameart.org/content/through-space)"), (GetScreenWidth() / 100) * 5, (GetScreenHeight() / 100) * 49, 19, WHITE);
	DrawText(TextFormat("Shoot sound by Kenney (https://www.kenney.nl/assets/sci-fi-sounds)"), (GetScreenWidth() / 100) * 8, (GetScreenHeight() / 100) * 56, 19, WHITE);
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, WHITE);
	}
	
}
void updateCreditsScreen()

{
	mouseX = GetMouseX();
	mouseY = GetMouseY();
	
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = MENU;
	}

}

bool collision(int mouseX, int mouseY, int mouseCollider, int ballX, int ballY, int ballSizeX, int ballSizeY)
{
	if (mouseX <= ballX + ballSizeX && ballX <= mouseX + mouseCollider && mouseY <= ballY + ballSizeY && ballY <= mouseY + mouseCollider)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void updateMenuMusic()
{
	UpdateMusicStream(menuMusic);
}
bool getQuit() 
{
	return quit;
}