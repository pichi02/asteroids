#pragma once
#include"raylib.h"
int menu(int width, int heigth/*, Texture2D menuBackground, Vector2 menuBackgroundPosition, Rectangle frameRecMenu*/);
bool returnToMenu();
bool collision(int racketX, int racketY, int racketSizeX, int ballX, int ballY, int ballSizeX, int ballSizeY);
int options(int width, int heigth, Texture2D menuBackground, Vector2 menuBackgroundPosition, Rectangle frameRecMenu, Music& menu, Music& gameplay, float& volume, Sound& ball);