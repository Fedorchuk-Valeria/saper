//---------------------------------------------------------------------------

#ifndef FieldH
#define FieldH
//---------------------------------------------------------------------------
#endif

#include "Display.h"
#include "Bombs.h"
#include <vcl.h>

class Field
{
  Bombs* bombs = NULL;
  int grayCells[350];
  int index = 0;

  public:
	int safe—ells;

    int can = 1;

	void FillingWithBombs(TStringGrid *Field);

	void FillingWithNumbers(TStringGrid *Field);

	void AmountOfSafeCells(TStringGrid *Field);

	void ClickOnSafeCells(int i, int j);

	int Check(int i, int j);

	~Field()
	{
        delete bombs;
    }
};
