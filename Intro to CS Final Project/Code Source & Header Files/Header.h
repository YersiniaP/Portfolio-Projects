#include "Space.h"
#ifndef TILESPACE_H
#define TILESPACE_H

class TileSpace : public Space
{
private:
	char lockStatus;

public:
	TileSpace();
	TileSpace(Space* upSquare, Space* downSquare, Space* leftSquare, Space* rightSquare);

	void doorLock(bool);
};
#endif