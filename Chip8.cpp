#include "stdafx.h"
#include "Chip8.h"

std::map<int16, OpCode<Chip8>*>	Chip8::s_OpCodeTable;


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
		{ 0x0000,"cls","00E0", &Chip8::cls_check,&Chip8::cls_run,"clear display" }

	};
	
	for (int i = 0; i < sizeof(opcodeTable) / sizeof(*opcodeTable); i++)
	{
		void * data = (void*)malloc(sizeof(*opcodeTable));
		if (data == nullptr)
			continue;
		memcpy(data, (void *)&opcodeTable[i], sizeof(*opcodeTable));

		s_OpCodeTable.insert( std::make_pair(opcodeTable[i].opcode,(OpCode<Chip8>*)data) );
	}

	
	//Test
	auto itr = s_OpCodeTable.find(0x0000);
	(this->*itr->second->run)(1, 2, 3, 4, 5, 6);

}


uint32	__stdcall Chip8::Cycle()
{
	return 0;
}