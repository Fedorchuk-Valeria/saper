//---------------------------------------------------------------------------

#pragma hdrstop

#include "Flag.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void Flag::Press()
{
	count++;
	flag = 1;
}

void Flag::Release()
{
	count--;
	flag = 0;
}
