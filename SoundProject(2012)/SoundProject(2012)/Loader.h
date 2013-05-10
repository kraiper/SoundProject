#pragma once
#include "stdafx.h"
#include <sstream>
#include <fstream>
#include "Object.h"

class Loader
{
public:
	Loader(void);
	~Loader(void);
<<<<<<< HEAD
	void LoadObject(char file[256],float mx,float mz,float my,float scale,Object* object);
=======
	void LoadObject(char file[256],float mx,float mz,float my,float scale,Object* objekt,float invertX,float invertY,float invertZ);
>>>>>>> 66cb66d4ecebedfbeed0d377cddd583e42174c32
};

