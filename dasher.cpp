#include "raylib.h"

int main() {
    //window dimensions
    const int screenWidth = 512;
    const int screenHeight = 380;

    //rectangle stats
    const int width = 50;
    const int height = 80;
    float posY = screenHeight - height;
    const int jumpHeight = 10;
    double velocity = 0;
    bool doubleJump = true;

    //frames per second
    const int fps = 60;
    
    //gravity value
    const double gravity = 23.0/fps;

    //initiate window
    InitWindow(screenWidth, screenHeight, "Dapper Dasher");
    SetTargetFPS(fps);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        //check for ability to jump
        //either on ground, or in air with double jump enabled
        if(IsKeyPressed(KEY_SPACE) && (posY == screenHeight-height || doubleJump)) {
            if(posY != screenHeight-height) {
                doubleJump = false;
            }
            velocity = -jumpHeight;
        }

        //update position and velocity of rectangle
        posY += velocity;
        velocity += gravity;

        //ground check
        //stops rectangle on ground and restores double jump
        if(posY > screenHeight-height) {
            velocity = 0;
            posY = screenHeight-height;
            doubleJump = true;
        }

        DrawRectangle(screenWidth/2, posY, width, height, BLUE);

        EndDrawing();
    }

    CloseWindow();
}