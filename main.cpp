// Chip8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Condition.h"
#include <signal.h>
#include "Chip8.h"
void OnSignal(int s);
static Condition s_hEvent;


int main()
{
	signal(SIGINT, OnSignal);
	signal(SIGTERM, OnSignal);
	signal(SIGABRT, OnSignal);
	signal(SIGBREAK, OnSignal);
	

	Chip8 *p = new Chip8();

	p->Start();

	s_hEvent.Wait(); //Wait until exit signal
	delete p;

    return 0;
}


void OnSignal(int s)
{
	switch (s)
	{
	case SIGINT:
	case SIGTERM:
	case SIGABRT:
	case SIGBREAK:
		s_hEvent.BeginSynchronized();
		s_hEvent.Signal();
		s_hEvent.EndSynchronized();
		break;
	}

	signal(s, OnSignal);
}



