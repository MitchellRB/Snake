#pragma once

#include "raylib.h"

#include "Snake.h"

const int BOARD_WIDTH = 40;
const int BOARD_HEIGHT = 40;
const int SQUARE_SIZE = 20;

class GameApp
{
public:
	GameApp();
	~GameApp();

	void Init();

	void Update();

	void Draw();

	void Shutdown();

private:

	int screenHeight;
	int screenWidth;

	Snake* snake;
};

