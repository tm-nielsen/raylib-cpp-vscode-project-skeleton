#include <iostream>
#include <raylib.h>
#include <raymath.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

Vector2 ballPosition;
float ballRadius = 12;
float ballSpeed = 300;


static void Initialize();
static void LoadContent();
static void UpdateDraw();
static void Update(float delta);
static void Draw(float delta);

int main()
{
    Initialize();
    LoadContent();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDraw, 60, 1);
#else
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDraw();
    }
#endif

    CloseWindow();
    return 0;
}

static void Initialize()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    ballPosition = { screenWidth / 2.0, screenHeight / 2.0 };

    InitWindow(screenWidth, screenHeight, "raylib example project");
}

static void LoadContent() {}

static void UpdateDraw()
{
    float delta = GetFrameTime();

    Update(delta);

    BeginDrawing();
    Draw(delta);
    EndDrawing();
}

static void Update(float delta)
{
    Vector2 inputDirection = { 0.0f, 0.0f };

    if(IsKeyDown(KEY_D)) inputDirection.x += 1;
    if(IsKeyDown(KEY_A)) inputDirection.x -= 1;
    if(IsKeyDown(KEY_W)) inputDirection.y -= 1;
    if(IsKeyDown(KEY_S)) inputDirection.y += 1;

    inputDirection = Vector2Normalize(inputDirection);

    if(inputDirection.x != 0)
        std::cout << inputDirection.x << std::endl;

    ballPosition.x += inputDirection.x * ballSpeed * delta;
    ballPosition.y += inputDirection.y * ballSpeed * delta;
}

static void Draw(float delta)
{
    ClearBackground(BLACK);

    DrawCircleV(ballPosition, ballRadius, GREEN);

    DrawText("This is a raylib example", 10, 40, 20, DARKGRAY);
    DrawFPS(10, 10);
}
