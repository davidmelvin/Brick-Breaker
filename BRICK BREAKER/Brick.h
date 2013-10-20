#ifndef BRICK_H //Wrapper
#define BRICK_H
#include "Include.h"
using namespace std;

class Brick
{
protected:
	int width;
	int height;
	int posX;
	int posY;
	ALLEGRO_BITMAP *brickImage;
public:
	Brick(int x, int y, string imgName);
	Brick(int x, int y, int w, int h, string imgName);
	~Brick();
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	void setWidth(int w);
	void setHeight(int h);
	void setX(int x);
	void setY(int y);
	void setImage(ALLEGRO_BITMAP *bi);
	void draw(int x, int y);
	void draw();
};

#endif