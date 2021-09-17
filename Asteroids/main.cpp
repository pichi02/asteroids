#include "raylib.h"
#include <math.h>
#include"Menu.h"
#include <iostream>
#include"Ship.h"
#include"Asteroid.h"

const int bigAsteroidsAmount = 4;
const int mediumAsteroidsAmount = 8;
const int smallAsteroidsAmount = 16;


struct Shoot {
    Vector2 position;
    Vector2 speed;
    float radius;
    float rotation;
    int lifeSpawn;
    bool active;
    Color color;
};




const int screenWidth = 800;
const int screenHeight = 450;

bool gameOver = false;
bool pause = false;
bool victory = false;

Ship* ship = new Ship;
Asteroid* bigAsteroids[bigAsteroidsAmount];
Asteroid* mediumAsteroids[mediumAsteroidsAmount];
Asteroid* smallAsteroids[smallAsteroidsAmount];


float shipHeight = 0.0f;


Shoot shoot[10] = { 0 };


int midMeteorsCount = 0;
int smallMeteorsCount = 0;
int destroyedMeteorsCount = 0;


void InitGame();         
void UpdateGame();       
void DrawGame();         
void UnloadGame();      
void UpdateDrawFrame();  
void updatePlayer();
void shootUpdate();
void asteroidsUpdate();


int main() 
{
   
    
    InitWindow(screenWidth, screenHeight, "classic game: asteroids");
    InitGame();
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        int menuOpt = menu(screenWidth, screenHeight);
      

        if (menuOpt == 1)
        {
            while (!WindowShouldClose())    
            {
              
                UpdateDrawFrame();
               
            }
        }
    }
    
    UnloadGame();        

    CloseWindow();        
   

    return 0;
}  





void InitGame() 
{
    for (int i = 0; i < bigAsteroidsAmount; i++)
    {
        bigAsteroids[i] = new Asteroid;
    }
    for (int i = 0; i < mediumAsteroidsAmount; i++)
    {
        mediumAsteroids[i] = new Asteroid;
    }
    for (int i = 0; i < smallAsteroidsAmount; i++)
    {
        smallAsteroids[i] = new Asteroid;
    }

    float posx, posy;
    float velx, vely;
    bool correctRange = false;
    victory = false;
    pause = false;

    shipHeight = (20.0f / 2) / tanf(20 * DEG2RAD);

 
    ship->setPos({ screenWidth / 2, screenHeight / 2 });

    destroyedMeteorsCount = 0;

    // Initialization shoot
    for (int i = 0; i < 10; i++) 
    {
        shoot[i].position = { 0, 0 };
        shoot[i].speed = { 0, 0 };
        shoot[i].radius = 2;
        shoot[i].active = false;
        shoot[i].color = WHITE;
    }

    // Initialization asteroid
    for (int i = 0; i < 4; i++) {
        posx = GetRandomValue(0, screenWidth);
        posy = GetRandomValue(0, screenHeight);

       

        bigAsteroids[i]->setPos({ posx,posy });

        velx = GetRandomValue(-2, 2);
        vely = GetRandomValue(-2, 2);

      
        if (velx == 0 && vely == 0) 
        {
            velx = GetRandomValue(-2, 2);
            vely = GetRandomValue(-2, 2);
        }
        bigAsteroids[i]->setSpeed({ velx,vely });
        bigAsteroids[i]->setRadius(40.0f);
        bigAsteroids[i]->setActivity(true);
       
    }

    for (int i = 0; i < mediumAsteroidsAmount; i++) 
    {
        mediumAsteroids[i]->setPos({ -100, -100 });
        mediumAsteroids[i]->setSpeed({ 0,0 });
        mediumAsteroids[i]->setRadius(20);
        mediumAsteroids[i]->setActivity(false);
    }

    for (int i = 0; i < smallAsteroidsAmount; i++) 
    {
        smallAsteroids[i]->setPos({ -100, -100 });
        smallAsteroids[i]->setSpeed({ 0,0 });
        smallAsteroids[i]->setRadius(10);
        smallAsteroids[i]->setActivity(false);
    }

    midMeteorsCount = 0;
    smallMeteorsCount = 0;
}

// Update game (one frame)
void UpdateGame() {
    if (!gameOver) {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause) 
        {
            
            
            updatePlayer();
            shootUpdate();
            asteroidsUpdate();
          
            for (int i = 0; i < 4; i++) {
                if (CheckCollisionCircles({ ship->getCollider().x,ship->getCollider().y }, ship->getCollider().z, bigAsteroids[i]->getPos(), bigAsteroids[i]->getRadius()) && bigAsteroids[i]->isActive()) gameOver = true;
            }

            for (int i = 0; i < 8; i++) {
                if (CheckCollisionCircles({ ship->getCollider().x, ship->getCollider().y }, ship->getCollider().z, mediumAsteroids[i]->getPos(), mediumAsteroids[i]->getRadius()) && mediumAsteroids[i]->isActive()) gameOver = true;
            }

            for (int i = 0; i < 16; i++) {
                if (CheckCollisionCircles({ ship->getCollider().x, ship->getCollider().y }, ship->getCollider().z, smallAsteroids[i]->getPos(), smallAsteroids[i]->getRadius()) && smallAsteroids[i]->isActive()) gameOver = true;
            }

          

            // Collision logic: player-shoots vs meteors
            for (int i = 0; i < 10; i++) 
            {
                if ((shoot[i].active)) 
                {
                    for (int a = 0; a < bigAsteroidsAmount; a++) 
                    {
                        if (bigAsteroids[a]->isActive() && CheckCollisionCircles(shoot[i].position, shoot[i].radius, bigAsteroids[a]->getPos(), bigAsteroids[a]->getRadius())) 
                        {
                            bigAsteroids[a]->setActivity(false);
                            shoot[i].active = false;
               
                            destroyedMeteorsCount++;

                            for (int j = 0; j < 2; j++) 
                            {
                                if (midMeteorsCount % 2 == 0) {
                                    mediumAsteroids[midMeteorsCount]->setPos({ bigAsteroids[a]->getPos() });
                                    mediumAsteroids[midMeteorsCount]->setSpeed({ (bigAsteroids[a]->getSpeed().x * 1.5f) * -1,(bigAsteroids[a]->getSpeed().y * 1.5f) * -1 });
                                }
                                else {
                                    mediumAsteroids[midMeteorsCount]->setPos({ bigAsteroids[a]->getPos() });
                                    mediumAsteroids[midMeteorsCount]->setSpeed({ (bigAsteroids[a]->getSpeed().x * 1.5f ,bigAsteroids[a]->getSpeed().y * 1.5f )});
                                    if (mediumAsteroids[midMeteorsCount]->getSpeed().x == 0 && mediumAsteroids[midMeteorsCount]->getSpeed().y == 0)
                                    {
                                        mediumAsteroids[midMeteorsCount]->setSpeed({ 1.0f, 1.0f });
                                    }
                                }


                                mediumAsteroids[midMeteorsCount]->setActivity (true);
                                midMeteorsCount++;
                            }
                            
                            
                            a = bigAsteroidsAmount;
                        }
                    }

                    for (int b = 0; b < mediumAsteroidsAmount; b++) 
                    {
                        if (mediumAsteroids[b]->isActive() && CheckCollisionCircles(shoot[i].position, shoot[i].radius, mediumAsteroids[b]->getPos(), mediumAsteroids[b]->getRadius())) 
                        {
                            shoot[i].active = false;
                            
                            mediumAsteroids[b]->setActivity(false);
                            destroyedMeteorsCount++;

                            for (int j = 0; j < 2; j++) 
                            {
                                if (smallMeteorsCount % 2 == 0) 
                                {
                                    smallAsteroids[smallMeteorsCount]->setPos({ mediumAsteroids[b]->getPos() });
                                    smallAsteroids[smallMeteorsCount]->setSpeed({ (mediumAsteroids[b]->getSpeed().x * 1.5f) * -1,(mediumAsteroids[b]->getSpeed().y * 1.5f) * -1 });
                                }
                                else {
                                    smallAsteroids[smallMeteorsCount]->setPos({ mediumAsteroids[b]->getPos() });
                                    smallAsteroids[smallMeteorsCount]->setSpeed({ mediumAsteroids[b]->getSpeed().x * 1.5f,mediumAsteroids[b]->getSpeed().y * 1.5f});
                                }

                                smallAsteroids[smallMeteorsCount]->setActivity(true);
                                smallMeteorsCount++;
                            }
                            
                          
                            b = mediumAsteroidsAmount;
                        }
                    }

                    for (int c = 0; c < smallAsteroidsAmount; c++)
                    {
                        if (smallAsteroids[c]->isActive() && CheckCollisionCircles(shoot[i].position, shoot[i].radius, smallAsteroids[c]->getPos(), smallAsteroids[c]->getRadius())) 
                        {
                            shoot[i].active = false;
                           
                            smallAsteroids[c]->setActivity(false);
                            destroyedMeteorsCount++;
                            
                            
                            c = smallAsteroidsAmount;
                        }
                    }
                }
            }
        }

        if (destroyedMeteorsCount == 4 + 8 + 16) victory = true;
    }
    else {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            InitGame();
            gameOver = false;
        }
    }
}

// Draw game (one frame)
void DrawGame() {
    BeginDrawing();

    ClearBackground(BLACK);

    if (!gameOver) 
    {
        // Draw spaceship
        Vector2 v1 = { ship->getPos().x + sinf(ship->getRotation() * DEG2RAD) * (shipHeight), ship->getPos().y - cosf(ship->getRotation() * DEG2RAD) * (shipHeight) };
        Vector2 v2 = { ship->getPos().x - cosf(ship->getRotation() * DEG2RAD) * (20.0f / 2),  ship->getPos().y - sinf(ship->getRotation() * DEG2RAD) * (20.0f / 2) };
        Vector2 v3 = { ship->getPos().x + cosf(ship->getRotation() * DEG2RAD) * (20.0f / 2),  ship->getPos().y + sinf(ship->getRotation() * DEG2RAD) * (20.0f / 2) };
        DrawTriangle(v1, v2, v3, MAROON);

        // Draw meteors
        for (int i = 0; i < bigAsteroidsAmount; i++) 
        {
            if (bigAsteroids[i]->isActive()) DrawCircleV(bigAsteroids[i]->getPos(), bigAsteroids[i]->getRadius(), DARKGRAY);
         
        }

        for (int i = 0; i < mediumAsteroidsAmount; i++) 
        {
            if (mediumAsteroids[i]->isActive()) DrawCircleV(mediumAsteroids[i]->getPos(), mediumAsteroids[i]->getRadius(), GRAY);
           
        }

        for (int i = 0; i < smallAsteroidsAmount; i++)
        {
            if (smallAsteroids[i]->isActive()) DrawCircleV(smallAsteroids[i]->getPos(), smallAsteroids[i]->getRadius(), WHITE);
           
        }

        // Draw shoot
        for (int i = 0; i < 10; i++) 
        {
            if (shoot[i].active) DrawCircleV(shoot[i].position, shoot[i].radius, WHITE);
        }

        if (victory) DrawText("VICTORY", screenWidth / 2 - MeasureText("VICTORY", 20) / 2, screenHeight / 2, 20, LIGHTGRAY);

        if (pause) DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 - 40, 40, GRAY);
    }
    else DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 - 50, 20, GRAY);

    EndDrawing();
}

// Unload game variables
void UnloadGame() 
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
   /* delete[] bigAsteroids;
    delete ship;*/
}

// Update and Draw (one frame)
void UpdateDrawFrame() 
{
    UpdateGame();
    DrawGame();
}
void updatePlayer()
{
    ship->updateRotation();
    ship->updateSpeed();
    ship->updateAcceleration();
    ship->move();
    ship->checkWallCollision();
    ship->updateCollider();
}
void shootUpdate()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
    {
        for (int i = 0; i < 10; i++) 
        {
            if (!shoot[i].active) 
            {
                shoot[i].position = { ship->getPos().x + (float)sin(ship->getRotation() * DEG2RAD) * (shipHeight), ship->getPos().y - (float)cos(ship->getRotation() * DEG2RAD) * (shipHeight) };
                shoot[i].active = true;
                shoot[i].speed.x = 1.5 * sin(ship->getRotation() * DEG2RAD) * 6.0f;
                shoot[i].speed.y = 1.5 * cos(ship->getRotation() * DEG2RAD) * 6.0f;
                shoot[i].rotation = ship->getRotation();
                break;
            }
        }
    }

    // Shot logic
    for (int i = 0; i < 10; i++) {
        if (shoot[i].active) {
            // Movement
            shoot[i].position.x += shoot[i].speed.x;
            shoot[i].position.y -= shoot[i].speed.y;

            // Collision logic: shoot vs walls
            if (shoot[i].position.x > screenWidth + shoot[i].radius) 
            {
                shoot[i].active = false;
            }
            else if (shoot[i].position.x < 0 - shoot[i].radius)
            {
                shoot[i].active = false;
            }
            if (shoot[i].position.y > screenHeight + shoot[i].radius) 
            {
                shoot[i].active = false;
            }
            else if (shoot[i].position.y < 0 - shoot[i].radius)
            {
                shoot[i].active = false;
            }


        }
    }

}
void asteroidsUpdate()
{
    // Meteors logic: big meteors
    for (int i = 0; i < bigAsteroidsAmount; i++) 
    {
        if (bigAsteroids[i]->isActive())
        {
            bigAsteroids[i]->move();
            bigAsteroids[i]->checkWallCollision();
        }
    }

    // Meteors logic: medium meteors
    for (int i = 0; i < mediumAsteroidsAmount; i++) 
    {
        if (mediumAsteroids[i]->isActive())
        {
            mediumAsteroids[i]->move();
            mediumAsteroids[i]->checkWallCollision();
        }
    }

    // Meteors logic: small meteors
    for (int i = 0; i < 16; i++) 
    {
        if (smallAsteroids[i]->isActive())
        {
            smallAsteroids[i]->move();
            smallAsteroids[i]->checkWallCollision();
        }
    }
}


