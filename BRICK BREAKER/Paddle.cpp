#include "Include.h"

void Paddle :: move(int dir, int a=5)
{
	if(dir == ALLEGRO_KEY_RIGHT)
	{	
		if(posX >= WIDTH - width)
			return;
		else
			posX += a;
	}
	else if (dir == ALLEGRO_KEY_LEFT)
	{
		if(posX <= 0)
			return;
		else
			posX -= a;
	}
}

void Paddle :: collision()
{
	;
}

void Paddle :: draw()
{
	al_draw_bitmap(image, posX, posY, NULL);
}

Paddle :: Paddle(string image_name, int x, int y, int w=150, int h=15)
{
	posX = x;
	posY = y;
	width = w;
	height = h;
	image=al_load_bitmap(image_name.c_str());
}

Paddle :: ~Paddle()
{
	al_destroy_bitmap(image);
}


