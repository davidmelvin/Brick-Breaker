/*
 * StoneBrick Class Implementation
 * Requires multiple hits to destroy (each time show cracks)
 */
#include "Include.h"
using namespace std;

int StoneBrick::getHardness()
{
	return hardness;
}
void StoneBrick::setHardness(int h)
{
	hardness = h;
}