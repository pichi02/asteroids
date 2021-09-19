#pragma once
#include"raylib.h"


bool collision(int racketX, int racketY, int racketSizeX, int ballX, int ballY, int ballSizeX, int ballSizeY);
int options(int width, int heigth, Texture2D menuBackground, Vector2 menuBackgroundPosition, Rectangle frameRecMenu, Music& menu, Music& gameplay, float& volume, Sound& ball);
void initMenu();
void updateMenu();
void drawMenu();
void unloadMenu();
void drawGameOverScreen();
void drawVictoryScreen();
void updateGameOverScreen();
void updateVictoryScreen();
void drawCreditsScreen();
void updateCreditsScreen();
void updateMenuMusic();