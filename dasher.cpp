#include "raylib.h"

int main() {
    //window dimensions
    const int screenWidth = 512;
    const int screenHeight = 380;

    //rectangle stats
    /*
    const int width = 50;
    const int height = 80;
    float posY = screenHeight - height;
    */
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
    
    //Scarfy texture
    Texture2D scarfy = LoadTexture("./textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = screenWidth/2 - scarfyRec.width/2;
    scarfyPos.y = screenHeight - scarfyRec.height;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        //check for ability to jump
        //either on ground, or in air with double jump enabled
        if(IsKeyPressed(KEY_SPACE) && (scarfyPos.y == screenHeight-scarfyRec.height || doubleJump)) {
            if(scarfyPos.y != screenHeight-scarfyRec.height) {
                doubleJump = false;
            }
            velocity = -jumpHeight;
        }

        //update position and velocity of rectangle
        scarfyPos.y += velocity;
        velocity += gravity;

        //ground check
        //stops rectangle on ground and restores double jump
        if(scarfyPos.y > screenHeight-scarfyRec.height) {
            velocity = 0;
            scarfyPos.y = screenHeight-scarfyRec.height;
            doubleJump = true;
        }
        //DrawRectangle(screenWidth/2, posY, width, height, BLUE);
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        EndDrawing();
    }

    CloseWindow();
}