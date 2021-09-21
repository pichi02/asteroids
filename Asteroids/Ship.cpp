#include"Ship.h"



Ship::Ship()
{
	position = {(float) GetScreenWidth() / 2 , (float)(GetScreenHeight() / 2 - shipHeight / 2 )};
	rotation = 0;
	
	/*acceleration = minimalAcceleration;*/
	
	
}

Ship::~Ship()
{

}

int Ship::getWidth()
{
	return width;
}

int Ship::getHeight()
{
	return height;
}

Vector2 Ship::getPos()
{
	return position;
}

Vector3 Ship::getCollider()
{
	return collider;
}

float Ship::getRotation()
{
	return rotation;
}

float Ship::getShipHeight()
{
	return shipHeight;
}



float Ship::getAcceleration()
{
	return 0.0f;
}

void Ship::move()
{
	/*position.x += (speed.x * acceleration.x);
	position.y -= (speed.y * acceleration.y);*/
	direction.x = GetMousePosition().x - position.x;
	direction.y = GetMousePosition().y - position.y;

	if (Vector2Length(Vector2Subtract(GetMousePosition(), position)) > 60.0f) {
		rotation = Vector2Angle(position, GetMousePosition()) + 90;
	}



	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
		acceleration.x += direction.x / (sqrt((direction.x * direction.x) + direction.y * direction.y));
		acceleration.y += direction.y / (sqrt((direction.x * direction.x) + direction.y * direction.y));
	}

	position.x += acceleration.x * GetFrameTime() * 5;
	position.y += acceleration.y * GetFrameTime() * 5;
}

void Ship::setAcceleration(Vector2 acc)
{
	acceleration = acc;
}

void Ship::setDirection(Vector2 dir)
{
	direction = dir;
}


void Ship::setPos(Vector2 pos)
{
	position = pos;
}

void Ship::setRotation(float rot)
{
	rotation = rot;
}

void Ship::resetAcceleration()
{
	/*acceleration = minimalAcceleration;*/
}


void Ship::updateAcceleration()
{
	/*if (GetMouseX() - position.x > 40 && IsMouseButtonDown(1)) 
	{
		if (acceleration < 1) acceleration += 0.04f;
	}
	if (position.x - GetMouseX() > 40 && IsMouseButtonDown(1)) 
	{
		if (acceleration < 1) acceleration += 0.04f;
	}
	if (GetMouseY() - position.y > 40 && IsMouseButtonDown(1)) 
	{
		if (acceleration < 1) acceleration += 0.04f;
	}
	if (position.y - GetMouseY() > 40 && IsMouseButtonDown(1)) 
	{
		if (acceleration < 1) acceleration += 0.04f;
	}*/
	
}

void Ship::updateRotation()
{
	/*if (IsMouseButtonDown(1))
	{
		if (Vector2Length(Vector2Subtract(GetMousePosition(), position)) > 40)
		{
			rotation = Vector2Angle(position, GetMousePosition()) + 90;
		}
	}*/
}

void Ship::updateCollider()
{
	collider = { position.x + (float)sin(rotation * DEG2RAD) * (shipHeight / 2.5f), position.y - (float)cos(rotation * DEG2RAD) * (shipHeight / 2.5f), 12 };
}

void Ship::updateSpeed()
{
	/*speed.x = (sin(rotation * DEG2RAD) * 250.0f)*GetFrameTime();
	speed.y = (cos(rotation * DEG2RAD) * 250.0f)*GetFrameTime();*/
}

void Ship::checkWallCollision()
{
	if (position.x > GetScreenWidth() + shipHeight) position.x = -(shipHeight);
	else if (position.x < -(shipHeight)) position.x = GetScreenWidth() + shipHeight;
	if (position.y > (GetScreenHeight() + shipHeight)) position.y = -(shipHeight);
	else if (position.y < -(shipHeight))position.y = GetScreenHeight() + shipHeight;
}
