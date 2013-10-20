/*
 * BlockBrick Class Implementation
 * Block brick cannot be penetrated
 */
#include "Include.h"
using namespace std;

BlockBrick::BlockBrick(int x, int y, string imgName) : Brick(x, y, imgName)
{

}

BlockBrick::BlockBrick(int x, int y, int w, int h, string imgName) : Brick(x, y, w, h, imgName)
{

}