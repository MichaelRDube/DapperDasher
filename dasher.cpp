#include "raylib.h"

int main() {
    const int screenWidth = 512;
    const int screenHeight = 380;


    InitWindow(screenWidth, screenHeight, "Dapper Dasher");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
}