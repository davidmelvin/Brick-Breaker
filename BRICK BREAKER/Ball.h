#include "Include.h"

class Ball
{
private:
	ALLEGRO_BITMAP *image;
	int posX, posY, height, width;
public:
	Ball(string, int, int, int, int);
	~Ball();
	void draw();
	void getX();
	void getY();
};