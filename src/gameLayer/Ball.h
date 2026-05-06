#pragma

class Ball {
public:
	float x, y;
	int speed_X, speed_Y;
	int radius;

	void Draw();
	void Update(int& player_score, int& cpu_score);
	void ResetBall();
};