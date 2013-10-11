/*
 * Brick Class Implementation
 */
#include "Include.h"
using namespace std;

Brick::Brick(int x, int y, string imgName)
{
	posX = x;
	posY = y;
	width = 60;
	height = 30;
	brickImage = al_load_bitmap(imgName.c_str());
}
Brick::Brick(int x, int y, int w, int h, string imgName)
{
	posX = x;
	posY = y;
	width = w;
	height = h;
	brickImage = al_load_bitmap(imgName.c_str());
}
Brick::~Brick()
{
	al_destroy_bitmap(brickImage);
}
int Brick::getWidth()
{
	return width;
}
int Brick::getHeight()
{
	return height;
}
int Brick::getX()
{
	return posX;
}
int Brick::getY()
{
	return posY;
}
void Brick::setWidth(int w)
{
	width = w;
}
void Brick::setHeight(int h)
{
	height = h;
}
void Brick::setX(int x)
{
	posX = x;
}
void Brick::setY(int y)
{
	posY = y;
}
void Brick::setImage(ALLEGRO_BITMAP *bi)
{
	brickImage = bi;
}
void Brick::draw(int x, int y)
{
	posX = x;
	posY = y;
	al_draw_bitmap(brickImage, posX, posY, NULL);
}
void Brick::draw()
{
	al_draw_bitmap(brickImage, posX, posY, NULL);
}