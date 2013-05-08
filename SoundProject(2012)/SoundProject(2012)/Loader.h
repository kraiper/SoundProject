#pragma once
#include "stdafx.h"
#include <sstream>
#include <fstream>

class Loader
{
public:
	Loader(void);
	~Loader(void);
	Object* LoadObject(char file[256],float mx,float mz,float my,float scale);
};

