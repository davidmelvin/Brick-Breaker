#include "Include.h"

Ball::Ball(string img, int x, int y, int w, int h){
	posX = x;
	posY = y;
	height = h;
	width = w;
	image = al_load_bitmap(img.c_str());
}
void Ball::draw(){
	al_draw_bitmap(image, posX, posY, NULL);
}