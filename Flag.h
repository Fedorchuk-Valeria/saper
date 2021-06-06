//---------------------------------------------------------------------------

#ifndef FlagH
#define FlagH
//---------------------------------------------------------------------------
#endif

class Flag
{
  public:
	int flag;
	int count;

	Flag()
	{
		flag = 0;
		count = 0;
	}

	void Press();

	void Release();
};
