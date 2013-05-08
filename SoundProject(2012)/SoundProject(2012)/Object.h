#pragma once
#include "stdafx.h"
#include "Camera.h"

extern Camera* Cam;
extern ID3D10InputLayout* g_pVertexLayout;

extern ID3D10Device* g_pd3dDevice;

static ID3D10EffectShaderResourceVariable*	object_mfxDiffuseMapVar;
static ID3D10EffectTechnique* object_pTechRenderLine;
static ID3D10Effect* object_pEffect;

class Object
{
private:

	Vertex* fData;
	float rotX,rotY,rotZ;
	D3DXVECTOR3 frameMove;
	std::vector<Vertex> Data;
	ID3D10Buffer* Buffer;
	ID3D10ShaderResourceView* Texture;
	D3DXMATRIX world;
	D3DXMATRIX translation;
	D3DXQUATERNION Rotation;
	
	
	int tick;
public:
	Object(void);
	~Object(void);
	//Lägger till ett nytt värde i slutet på data
	void addData(Vertex iData);
	//Lägger till den sista vertex facet till Data
	void lastFace();
	//Returnerar Data
	void getData(std::vector<Vertex> *in);
	//Initsierar Buffers
	void InitBuffers(ID3D10Effect* FX,char file[256] );
	//Returnerar buffer storleken storleken på Data antal vertexes
	int getBufferSize();
	//Uppdate
	void Update();
	//Sätter World matrisen
	void setWorld();
	//Flyttar roterar och skalar objektet
	void setData(float moveX,float moveY,float moveZ,float scale);
	//Draw
	void Draw();
};

