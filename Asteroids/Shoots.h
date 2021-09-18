
#pragma once
#include"raylib.h"
class Shoots
{
private:

    Vector2 position;
    Vector2 speed;
    float radius;
    float rotation;
    int lifeSpawn;
    bool active;
    Color color;
    
public:
	Shoots();
	~Shoots();

};


