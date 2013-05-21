#include "ObjHandler.h"

ObjHandler::ObjHandler(ID3D10Effect* FX)
{
	load = new Loader();
//#pragma omp parallel for
//	{
//		for(int i = 0; i < 3;i++)
//		{
//
//		}
//	}

	objList.push_back(new Object("Sounds/ZerglingSoundTroll.mp3"));
	objList.push_back(new Object("Sounds/ZerglingSoundTroll.mp3"));
	objList.push_back(new Object("Sounds/ZerglingSoundTroll.mp3"));
	
	load->LoadObject("Object files\\Bunker\\Bunker.obj",0,0,0,5,objList.at(0),1,-1,1);
	load->LoadObject("Object files\\Bunker\\Bunker.obj",0,-40,0,5,objList.at(1),1,-1,1);
	load->LoadObject("Object files\\Bunker\\Bunker.obj",0,-80,0,5,objList.at(2),1,-1,1);

	objList.at(0)->InitBuffers(FX,"Pics/Terrain_texture.jpg");
	objList.at(1)->InitBuffers(FX,"Pics/Terrain_texture.jpg");
	objList.at(2)->InitBuffers(FX,"Pics/Terrain_texture.jpg");

	//Hydralisk = new Object("Sounds/ZerglingSoundTroll.mp3");
	//load->LoadObject("Object files\\Zergling\\zergling_obj.OBJ",0,0,0,5,Hydralisk,1,-1,1);
	//load->LoadObject("Object files\\Bunker\\Bunker.obj",0,0,0,5,Hydralisk,1,-1,1);
	//Hydralisk->InitBuffers(FX,"Pics/Terrain_texture.jpg");

	//Bunker = new Object("");
	//load->LoadObject
	
}


ObjHandler::~ObjHandler(void)
{
}

void ObjHandler::Update(float dt)
{
	/*for(int i = 0;i < objList.size();i++)
	{
		objList.at(i)->Update(dt,0,0,0);
	}*/
	objList.at(0)->Update(dt,0,0,0);
	objList.at(1)->Update(dt,0,0,0);
	objList.at(2)->Update(dt,0,0,0);
	//Hydralisk->Update(dt,0,0,0);
}

void ObjHandler::Draw()
{
	for(int i = 0;i < objList.size();i++)
	{
		objList.at(i)->Draw();
	}
	objList.at(0)->Draw();
	objList.at(1)->Draw();
	objList.at(2)->Draw();

	//Hydralisk->Draw();
}