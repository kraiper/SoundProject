#pragma once
#include "stdafx.h"
#include "Object.h"
#include "Loader.h"

//extern ID3D10Device* g_pd3dDevice;
//extern ID3D10Effect* g_pEffect;

class ObjHandler
{
private:
	Object* Hydralisk;
	Loader* load;
public:
	ObjHandler(ID3D10Effect* FX);
	~ObjHandler(void);
	void Update();
	void Draw();
};

