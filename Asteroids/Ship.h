#pragma once
#include"raylib.h"
#include"Rotation.h"
class Ship
{
private:
	int width;
	int height;

	float rotation;
	Vector2 position;
	Vector3 collider;
	Vector2 speed;
	Vector2 acceleration;
	Vector2 direction;
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
	float getShipHeight();

	float getAcceleration();
	void setPos(Vector2 pos);
	void setRotation(float rot);
	void resetAcceleration();
	void updateAcceleration();
	void updateRotation();
	void updateCollider();
	void updateSpeed();
	void checkWallCollision();
	void move();
	void setAcceleration(Vector2 acc);
	void setDirection(Vector2 dir);

	
};

