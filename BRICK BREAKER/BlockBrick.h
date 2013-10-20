#ifndef BLOCKBRICK_H //Wrapper
#define BLOCKBRICK_H
#include "Include.h"
using namespace std;

class BlockBrick : public Brick
{

public:
	BlockBrick(int x, int y, string imgName);
	BlockBrick(int x, int y, int w, int h, string imgName);
};

#endif