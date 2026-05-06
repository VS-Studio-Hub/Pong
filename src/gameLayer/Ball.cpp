#include "Ball.h"
#include <raylib.h>
#include "Colors.h"


void Ball::Draw() {
	DrawCircle(x, y, radius, Yellow);
}

void Ball::Update(int& player_score, int& cpu_score) {
	x += speed_X;
	y += speed_Y;

	if (y + radius >= GetScreenHeight() || y - radius <= 0) {
		speed_Y *= -1;
	}
	if (x + radius >= GetScreenWidth())
	{
		cpu_score++;
		ResetBall();
	}
	if (x - radius <= 0)
	{
		player_score++;
		ResetBall();
	}
}

void Ball::ResetBall()
{
	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;

	int speed_choices[2] = { -1,1 };
	speed_X *= speed_choices[GetRandomValue(0, 1)];
	speed_Y *= speed_choices[GetRandomValue(0, 1)];
}