#include <raylib.h>
#include "Ball.h"
#include "Paddle.h"
#include "Colors.h"


Ball ball;
Paddle player;
CpuPaddle cpu;

int player_score = 0;
int cpu_score = 0;

int main(void)
{
	const int screen_width = 1280;
	const int screen_height = 800;

	InitWindow(screen_width, screen_height, "My Pong Game!");
	SetTargetFPS(120);

	ball.radius = 20;
	ball.x = screen_width / 2;
	ball.y = screen_height / 2;
	ball.speed_X = 5;
	ball.speed_Y = 5;


	player.width = 25;
	player.height = 120;
	player.x = screen_width - player.width - 10;
	player.y = screen_height / 2 - player.height / 2;
	player.speed = 6;

	cpu.height = 120;
	cpu.width = 25;
	cpu.x = 10;
	cpu.y = screen_height / 2 - cpu.height / 2;
	cpu.speed = 6;

	Rectangle rect = { 400, 300, 160, 80 };
	Vector2 origin = { rect.width / 2.0f, rect.height / 2.0f };
	float rotation = 5.0f;

	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		// Updating
		ball.Update(player_score, cpu_score);
		player.Update();
		cpu.Update(ball.y);

		//Checking for collisions
		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ player.x, player.y, player.width, player.height }))
		{
			ball.speed_X *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ ball.x,ball.y }, ball.radius, Rectangle{ cpu.x, cpu.y, cpu.width, cpu.height }))
		{
			ball.speed_X *= -1;
		}
		//rotation++;
		DrawRectanglePro(
			rect,
			origin,
			rotation,
			BLUE
		);
		ClearBackground(BLACK);
		//DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		//DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
		//DrawCircleGradient(screen_width / 2, screen_height / 2, 150, Light_Green, Yellow);
		DrawCircleLines(screen_width / 2, screen_height / 2, 150, Light_Green);
		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
		ball.Draw();
		cpu.Draw();
		player.Draw();
		DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);


		EndDrawing();
	}

	CloseWindow();
	return 0;
}