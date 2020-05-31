
#include "common.hpp"
#include "Player.cpp"
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitPhysics();
    InitWindow(screenWidth, screenHeight, "Hopper");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Vector2 ground_pos = {0 , screenHeight-40};
    auto ground = CreatePhysicsBodyRectangle(ground_pos,1920,40,20);
    ground->enabled = false;
    Player *p = new Player({100,100});
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        RunPhysicsStep();
        p->Update(deltaTime);
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(ground_pos.x , ground_pos.y , 1920 , 40 , BLACK);

        DrawText("Hello World!", screenWidth/2-100, screenHeight/2, 28, BLACK);

        p->Draw();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    DestroyPhysicsBody(ground);
    ClosePhysics();
    delete p;
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}