#include "Include.h"

Ball::Ball(string img, int x, int y, int w, int h){
	posX = x;
	posY = y;
	height = h;
	width = w;
	image = al_load_bitmap(img.c_str());
	al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));
}
void Ball::draw(){
	al_draw_bitmap(image, posX, posY, NULL);
}
Ball::~Ball(){
	al_destroy_bitmap(image);
}
int Ball::getX()
{
	return posX;
}
int Ball::getY()
{
	return posY;
}
int Ball::getHeight()
{
	return height;
}
int Ball::getWidth()
{
	return width;
}
void Ball::setX(int x)
{
	posX = x;
}
void Ball::setY(int y)
{
	posY = y;
}
void Ball::setWidth(int w)
{
	width = w;
}
void Ball::setHeight(int h)
{
	height = h;
}
double Ball::getVelocity()
{
	return velocity;
}
void Ball::setVelocity(double v)
{
	velocity = v;
}
double Ball::getAngle()
{
	return angle;
}
void Ball::setAngle(double a)
{
	angle = a;
}
void Ball::move()
{
	int hyp;
	int l1, l2;//leg 1 - x, leg 2 - y
	int newH;//new l2

	if(posX > WIDTH / 2)
	{
		l2 = HEIGHT - posY;
		l1 = l2 / tan(angle);
		hyp = pow(pow(l1, 2) + pow(l2, 2), 0.5);
		newH = (l2 * (hyp- velocity))/(hyp);
		posY = HEIGHT - newH;
		posX = posY / tan(angle);
	}


}