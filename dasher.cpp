#include "raylib.h"

int main() {
    //window dimensions
    const int screenWidth = 512;
    const int screenHeight = 380;

    //rectangle dimensions
    const int fps = 60;
    const int width = 50;
    const int height = 80;
    float posY = screenHeight - height;
    double velocity = 0;
    const double gravity = 26.0/fps;
    bool doubleJump = true;


    InitWindow(screenWidth, screenHeight, "Dapper Dasher");
    SetTargetFPS(fps);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if(IsKeyPressed(KEY_SPACE) && (posY == screenHeight-height || doubleJump)) {
            if(posY != screenHeight-height) {
                doubleJump = false;
            }
            velocity = -10;
        }

        posY += velocity;
        velocity += gravity;

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