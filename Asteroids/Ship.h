#pragma once
#include"raylib.h"
#include"Rotation.h"
class Ship
{
private:
	int width;
	int height;
	Vector2 position;
	float acceleration;
	float rotation;
	Vector3 collider;
	Vector2 speed;
	float shipHeight = (20.0f / 2) / tanf(20 * DEG2RAD);
	const float minimalAcceleration = 0.2f;
	
public:
	Ship();
	~Ship();
	int getWidth();
	int getHeight();
	Vector2 getPos();
	Vector3 getCollider();
	float getRotation();

	float getAcceleration();
	void setPos(Vector2 pos);
	void updateAcceleration();
	void updateRotation();
	void updateCollider();
	void updateSpeed();
	void checkWallCollision();
	void move();

	
};

