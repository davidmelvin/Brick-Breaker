/*
 * RegBrick Class Implementation
 * Requires one hit to destroy
 */
#include "Include.h"
using namespace std;

RegBrick::RegBrick(int x, int y, string imgName) : Brick(x, y, imgName)
{

}
RegBrick::RegBrick(int x, int y, int w, int h, string imgName) : Brick(x, y, w, h, imgName)
{

}