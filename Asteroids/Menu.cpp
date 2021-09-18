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
	
	titleX = (GetScreenWidth() / 100) * 25;
	titleY = (GetScreenHeight() / 10) * 3;
	playButtonSizeX = 180;
	optionsButtonSizeX = 230;
	buttonSizeY = 45;
	rectangleMouseSize = 1;
	mouseX = GetMouseX();
	mouseY = GetMouseY();
	playButtonX = GetScreenWidth() / 2 - playButtonSizeX / 2;
	playButtonY = GetScreenHeight() * 5 / 10;
	optionsButtonX = playButtonX - 20;
	optionsButtonY = GetScreenHeight() * 6 / 10;
	quitButtonX = playButtonX + 10;
	quitButtonY = GetScreenHeight() * 7 / 10;
	quitButtonWidth = playButtonSizeX - 20;
}
void updateMenu()
{

	if (collision(mouseX, mouseY, rectangleMouseSize, playButtonX, playButtonY, playButtonSizeX, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = GAMEPLAY;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = OPTIONS;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{

		WindowShouldClose();
	}

}
void drawMenu()
{
	ClearBackground(BLACK);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	/*DrawTextureRec(menuBackground, frameRecMenu, menuBackgroundPosition, RAYWHITE);*/
	DrawRectangle(optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY, RED);
	DrawRectangle(playButtonX, playButtonY, playButtonSizeX, buttonSizeY, RED);
	DrawRectangle(quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY, RED);
	DrawText(TextFormat("ASTEROIDS"), titleX, titleY, 50, WHITE);
	DrawText(TextFormat("START"), playButtonX, playButtonY, 50, WHITE);
	DrawText(TextFormat("OPTIONS"), optionsButtonX, optionsButtonY, 50, WHITE);
	DrawText(TextFormat("Created by Lucas Pich"), 490, 910, 30, WHITE);
	DrawText(TextFormat("QUIT"), quitButtonX + 18, quitButtonY, 50, WHITE);
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