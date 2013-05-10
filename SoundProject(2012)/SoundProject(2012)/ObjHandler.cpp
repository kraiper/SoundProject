#include "ObjHandler.h"


ObjHandler::ObjHandler(ID3D10Effect* FX)
{
	load = new Loader();
	Hydralisk = new Object();
	//Hydralisk = load->LoadObject("Object files\\Hydralisk_obj\\babylon station.obj",0,0,0,1);
	//Hydralisk = load->LoadObject("Object files\\Hydralisk_obj\\Hydralisk_obj.obj",0,0,0,1);
	load->LoadObject("Object files\\Zergling\\zergling_obj.OBJ",0,0,0,5,Hydralisk,1,-1,1);
	//Hydralisk->InitBuffers(FX,"Object files\\Hydralisk_obj\\Hydtex.jpg");
	Hydralisk->InitBuffers(FX,"Pics/Terrain_texture.jpg");
	
}


ObjHandler::~ObjHandler(void)
{
}

void ObjHandler::Update(float dt)
{
	Hydralisk->Update(dt,0,0,-1);
}

void ObjHandler::Draw()
{
	Hydralisk->Draw();
}