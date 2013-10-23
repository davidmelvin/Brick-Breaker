#include "Include.h"

class Ball
{
private:
	ALLEGRO_BITMAP *image;
	int posX, posY, height, width;
	double angle;//from 0 to 2pi, CCW, starting from pointing right parallel to bottom of screen
	double velocity;//velocity = distance / time

public:
	Ball(string, int, int, int, int);
	~Ball();
	void draw();
	int getX();
	int getY();
	int getHeight();
	int getWidth();
	void setX(int x);
	void setY(int y);
	void setWidth(int w);
	void setHeight(int h);
	double getVelocity();
	void setVelocity(double v);
	double getAngle();
	void setAngle(double a);
	void move();
};