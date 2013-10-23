/*
 * Header file containing all includes; designed to avoid multiple inclusions of header files
*/

#ifndef INCLUDE_H //Wrapper
#define INCLUDE_H

//system include files
#include <iostream>
#include <string>
#include <math.h>
//allegro include files
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\bitmap.h>
//user defined include files
#include "Brick.h"
#include "BlockBrick.h"
#include "StoneBrick.h"
#include "RegBrick.h"
#include "Paddle.h"
#include "Ball.h"

#define PI 3.1415926535897932384626433832795028841971
#define WIDTH 600
#define HEIGHT 600
#define FPS 60

#endif