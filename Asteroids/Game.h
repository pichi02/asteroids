#pragma once
#include"raylib.h"
#include"Asteroid.h"
#include"main.h"

struct Shoot
{
	Vector2 position;
	Vector2 speed;
	float radius;
	float rotation;
	int lifeSpawn;
	bool active;
	Color color;
};

extern bool victory;
extern bool gameOver;


void initValeus();
void gameplayUpdate();
void gameplayDraw();
void resetValeus();
void unloadGameplay();
void updateFrame();
void updatePlayer();
void shootUpdate();
void asteroidsUpdate();
void collisionAndSplitAsteroids
(
	Asteroid biggerSizeAsteroids[],
	Asteroid smallerSizeAsteroids[],
	int biggerSizeAmount,
	int& smallerSizeCount,
	Shoot shoot[], bool isSmall,
	float biggerAsteroidSpeed,
	float smallerAsteroidsspeed
);

