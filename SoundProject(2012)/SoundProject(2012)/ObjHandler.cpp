#include "ObjHandler.h"


ObjHandler::ObjHandler(ID3D10Effect* FX)
{
	load = new Loader();
	Hydralisk = new Object("Sounds/ZerglingSoundTroll.mp3");
	//load->LoadObject("Object files\\Zergling\\zergling_obj.OBJ",0,0,0,5,Hydralisk,1,-1,1);
	load->LoadObject("Object files\\Bunker\\Bunker.obj",0,0,0,5,Hydralisk,1,-1,1);
	Hydralisk->InitBuffers(FX,"Pics/Terrain_texture.jpg");

	//Bunker = new Object("");
	//load->LoadObject
	
}


ObjHandler::~ObjHandler(void)
{
}

void ObjHandler::Update(float dt)
{
	Hydralisk->Update(dt,0,0,0);
}

void ObjHandler::Draw()
{
	Hydralisk->Draw();
}