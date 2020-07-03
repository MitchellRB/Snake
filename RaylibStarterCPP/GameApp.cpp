#include "GameApp.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

GameApp::GameApp()
{
	screenWidth = BOARD_WIDTH * SQUARE_SIZE;
	screenHeight = BOARD_HEIGHT * SQUARE_SIZE;

	InitWindow(screenWidth, screenHeight, "Snake");

	snake = nullptr;

	SetTargetFPS(60);
}

GameApp::~GameApp()
{

}

void GameApp::Init()
{
	snake = new Snake();
}

void GameApp::Update()
{
	if (snake->GetAlive())
	{
		snake->Update({ BOARD_WIDTH - 1,BOARD_HEIGHT - 1 });
	}
	else if (IsKeyPressed(KEY_ENTER))
	{
		delete snake;
		snake = new Snake();
	}
}

void GameApp::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	snake->Draw(SQUARE_SIZE);

	for (size_t i = 0; i < BOARD_WIDTH; i++)
	{
		for (size_t j = 0; j < BOARD_HEIGHT; j++)
		{
			DrawRectangleLines(i * SQUARE_SIZE, j * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, LIGHTGRAY);
		}
	}

	if (!snake->GetAlive())
	{
		DrawText("GAME OVER", screenWidth / 2 - MeasureText("GAME OVER", 32) / 2, 32, 32, RED);
		DrawText("Press ENTER to play again", screenWidth / 2 - MeasureText("Press ENTER to play again", 22) / 2, 60, 22, GRAY);
	}

	EndDrawing();
}

void GameApp::Shutdown()
{
	delete snake;
}