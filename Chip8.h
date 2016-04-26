#pragma once

#define func(type,name) type (T::*name)(unsigned u,unsigned p,unsigned y,unsigned x, unsigned kk, unsigned nnn)


template<class T>
class OpCode
{
public:
	int16	opcode;
	const char *assem;
	const char *exp;
	func(bool, check);
	func(void, run);
	const char *desc;

};
class Chip8
{
public:
	Chip8();
	~Chip8();

public:

	void Start();
	void LoadOpCodes();
	static uint32 __stdcall Cycle();

private:
	std::thread	*m_pMainCycler;
	static std::map<int16,OpCode<Chip8>*>	s_OpCodeTable;


private:
	bool cls_check(unsigned u, unsigned p, unsigned y, unsigned x, unsigned kk, unsigned nnn);
	void cls_run(unsigned u, unsigned p, unsigned y, unsigned x, unsigned kk, unsigned nnn);


};
