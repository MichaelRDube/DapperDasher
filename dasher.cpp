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
    const int jumpHeight = 600;
    double velocity = 0;
    bool doubleJump = true;

    //frames per second
    const int fps = 60;
    
    //gravity value
    const double gravity = 1'000.0;

    //initiate window
    InitWindow(screenWidth, screenHeight, "Dapper Dasher");
    SetTargetFPS(fps);

    //nebula texture
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebRec;
    nebRec.width = nebula.width/8;
    nebRec.height = nebula.height/8;
    nebRec.x = 0;
    nebRec.y = 0;
    Vector2 nebPos{screenWidth, screenHeight-nebRec.height};
    int nebVel = -600;
    
    //Scarfy texture
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = screenWidth/2 - scarfyRec.width/2;
    scarfyPos.y = screenHeight - scarfyRec.height;

    //time since last frame
    float dt;

    //sprite animation
    int spriteIndex = 0;
    float spriteTime = 0;
    const float updateTime = 1.0/12.0;

    while(!WindowShouldClose()) {
        dt = GetFrameTime();
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

        //update position and velocity of scarfy
        scarfyPos.y += velocity*dt;
        velocity += gravity*dt;

        //update position of nebula
        nebPos.x += nebVel*dt;

        //ground check
        //stops rectangle on ground and restores double jump
        if(scarfyPos.y > screenHeight-scarfyRec.height) {
            velocity = 0;
            scarfyPos.y = screenHeight-scarfyRec.height;
            doubleJump = true;
        }
        //DrawRectangle(screenWidth/2, posY, width, height, BLUE);
        //draw scarfy
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        
        //draw nebula
        DrawTextureRec(nebula, nebRec, nebPos, WHITE);

        spriteTime += dt;
        if(spriteTime >= updateTime) {
            spriteIndex++;
            spriteIndex %= 6;
            scarfyRec.x = scarfyRec.width*spriteIndex;
            spriteTime = 0;

        }

        EndDrawing();
    }

    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}