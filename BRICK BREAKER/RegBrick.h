#ifndef REGBRICK_H //Wrapper
#define REGBRICK_H
#include "Include.h"
using namespace std;

class RegBrick : public Brick
{

public:
	RegBrick(int x, int y, string imgName);
	RegBrick(int x, int y, int w, int h, string imgName);
};

#endif