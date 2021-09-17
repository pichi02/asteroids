#include"Asteroid.h"

Asteroid::Asteroid() 
{
	position = { 0,0 };
	speed = { 0,0 };
}

Asteroid::~Asteroid()
{
}

void Asteroid::move()
{
	position.x += speed.x;
	position.y += speed.y;
	
}

void Asteroid::checkWallCollision()
{
	if (position.x > GetScreenWidth() + radius) position.x = -(radius);
	else if (position.x < 0 - radius) position.x = GetScreenWidth() + radius;
	if (position.y > GetScreenHeight() + radius) position.y = -(radius);
	else if (position.y < 0 - radius) position.y = GetScreenHeight() + radius;
}

void Asteroid::setPos(Vector2 pos)
{
	position = pos;
}

void Asteroid::setSpeed(Vector2 speed)
{
	this->speed = speed;
}

void Asteroid::setRadius(float radius)
{
	this->radius = radius;
}

void Asteroid::setActivity(bool active)
{
	this->active = active;
}

Vector2 Asteroid::getPos()
{
	return position;
}

Vector2 Asteroid::getSpeed()
{
	return speed;
}

float Asteroid::getRadius()
{
	return radius;
}

bool Asteroid::isActive()
{
	return active;
}
