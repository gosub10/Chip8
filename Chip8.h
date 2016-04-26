#pragma once
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

};

template<class T>
class OpCode
{
public:
	const char *asm;
	const char *exp;
	bool (T::*check)(unsigned u,unsigned p,unsigned y,unsigned x, unsigned kk, unsigned nnn);
	void (T::*run)(unsigned u, unsigned p, unsigned y, unsigned x, unsigned kk, unsigned nnn);
	const char *desc;
};