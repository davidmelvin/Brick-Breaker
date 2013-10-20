/*
 * StoneBrick Class Implementation
 * Requires multiple hits to destroy (each time show cracks)
 */
#include "Include.h"
using namespace std;

StoneBrick::StoneBrick(int x, int y, string imgName, int h) : Brick(x, y, imgName)
{
	hardness = h;
}
StoneBrick::StoneBrick(int x, int y, int w, string imgName, int h) : Brick(x, y, w, h, imgName)
{
	hardness = h;
}

int StoneBrick::getHardness()
{
	return hardness;
}
void StoneBrick::setHardness(int h)
{
	hardness = h;
}