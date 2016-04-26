#include "stdafx.h"
#include "Chip8.h"




Chip8::Chip8()
{
}


Chip8::~Chip8()
{
}

void Chip8::Start()
{
	LoadOpCodes();


//	m_pMainCycler = new std::thread(Cycle);
	

}

void Chip8::LoadOpCodes()
{
	static OpCode<Chip8>	opcodeTable[] = 
	{
	//	{ "cls","00E0", }

	};

}


uint32	__stdcall Chip8::Cycle()
{

}