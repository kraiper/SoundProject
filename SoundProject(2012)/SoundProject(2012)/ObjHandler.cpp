#include "ObjHandler.h"


ObjHandler::ObjHandler(ID3D10Effect* FX)
{
	load = new Loader();
	Hydralisk = new Object("Sounds/ZerglingSoundTroll.mp3");
	//Hydralisk = load->LoadObject("Object files\\Hydralisk_obj\\babylon station.obj",0,0,0,1);
	//Hydralisk = load->LoadObject("Object files\\Hydralisk_obj\\Hydralisk_obj.obj",0,0,0,1);
<<<<<<< HEAD
<<<<<<< HEAD
	load->LoadObject("Object files\\Zergling\\zergling_obj.OBJ",0,0,0,5,Hydralisk);
=======
	load->LoadObject("Object files\\Zergling\\zergling_obj.OBJ",0,0,0,5,Hydralisk,1,-1,1);
>>>>>>> 66cb66d4ecebedfbeed0d377cddd583e42174c32
=======
	load->LoadObject("Object files\\Zergling\\zergling_obj.OBJ",0,0,0,5,Hydralisk,1,-1,1);
>>>>>>> 66cb66d4ecebedfbeed0d377cddd583e42174c32
	//Hydralisk->InitBuffers(FX,"Object files\\Hydralisk_obj\\Hydtex.jpg");
	Hydralisk->InitBuffers(FX,"Pics/Terrain_texture.jpg");
	
}


ObjHandler::~ObjHandler(void)
{
}

void ObjHandler::Update(float dt)
{
<<<<<<< HEAD
<<<<<<< HEAD
	Hydralisk->Update();
=======
	Hydralisk->Update(dt,0,0,-1);
>>>>>>> 66cb66d4ecebedfbeed0d377cddd583e42174c32
=======
	Hydralisk->Update(dt,0,0,-1);
>>>>>>> 66cb66d4ecebedfbeed0d377cddd583e42174c32
}

void ObjHandler::Draw()
{
	Hydralisk->Draw();
}