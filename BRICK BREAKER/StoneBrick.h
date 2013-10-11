#ifndef STONEBRICK_H //Wrapper
#define STONEBRICK_H
#include "Include.h"
using namespace std;

class StoneBrick : public Brick
{
	int hardness;//equals number of hits needed to break
public:
	int getHardness();
	void setHardness(int h);
};

#endif