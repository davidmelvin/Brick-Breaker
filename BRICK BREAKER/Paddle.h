#ifndef PADDLE_H
#define PADDLE_H

#include "Include.h"

using namespace std;

class Paddle
{
private:
	ALLEGRO_BITMAP *image;
	int posX, posY, height, width;
public:
	void move(int,int);
	void collision();
	void draw();
	Paddle(string, int, int, int, int);
	~Paddle();
};

#endif

