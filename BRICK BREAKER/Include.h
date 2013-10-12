/*
 * Header file containing all includes; designed to avoid multiple inclusions of header files
*/

#ifndef INCLUDE_H //Wrapper
#define INCLUDE_H
//system include files
#include <iostream>
#include <string>
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

#define WIDTH 300
#define HEIGHT 600
//NOTE: We need to decide on width and height for screen

#endif