#pragma once
#include"raylib.h"
class Asteroid
{
private: 
    Vector2 position;
    Vector2 speed;
    float radius;
    bool active;
    

public:
	Asteroid();
	~Asteroid();
    void move();
    void checkWallCollision();
    void setPos(Vector2 pos);
    void setSpeed(Vector2 speed);
    void setRadius(float radius);
    void setActivity(bool active);
    Vector2 getPos();
    Vector2 getSpeed();
    float getRadius();
    bool isActive();

};

