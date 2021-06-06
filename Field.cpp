//---------------------------------------------------------------------------

#pragma hdrstop

#include "Field.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Field::FillingWithBombs(TStringGrid *Field)
{
    index = 0;
	int col, row;
	int numberOfSigns;
    if(bombs)
	{
		delete bombs;
	}
	bombs = new Bombs;

	for(int i = 0; i < 80; i++)
	{
		numberOfSigns = bombs->NumberOfSigns(bombs->positions[i]);

		if(numberOfSigns == 2)
		{
			col = bombs->positions[i] / 10;
			row = bombs->positions[i] % 10;
		}

		if(numberOfSigns == 3)
		{
			col = bombs->positions[i] / 10;
			if(col > 19)
			{
				col = bombs->positions[i] / 100;
				row = bombs->positions[i] % 100;
			} else
			{
				row = bombs->positions[i] % 10;
			}
		}

		if(numberOfSigns == 4)
		{
			col = bombs->positions[i] / 100;
			row = bombs->positions[i] % 100;
		}

		Field->Cells[col][row] = "b";
	}
}

void Field::FillingWithNumbers(TStringGrid *Field)
{
	int num = 0;

	for(int i = 1; i < 21; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(Field->Cells[i][j] != "b")
			{
				for(int k = i-1; k < i+2; k++)
				{
					for(int l = j-1; l < j+2; l++)
					{
						if(k != 0 && l != -1 && k != 21 && l != 20)
						{
							if(Field->Cells[k][l] == "b") num++;
						}
					}
				}

				Field->Cells[i][j] = num;
			}
			num = 0;
		}
		num = 0;
	}
}

void Field::AmountOfSafeCells(TStringGrid *Field)
{
	safe—ells = 0;

	for(int i = 1; i < 21; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			if(Field->Cells[i][j] != "b")
			{
				safe—ells++;
			}
		}
	}
}

void Field::ClickOnSafeCells(int i, int j)
{
	grayCells[index] = i * pow(10, bombs->NumberOfSigns(i)) + j;
	index++;
}

int Field::Check(int i, int j)
{
	int check = i * pow(10, bombs->NumberOfSigns(i)) + j;
	int doubleClick = 1;

	for(int i = 0; i < index; i++)
	{
		if(grayCells[i] == check)
		{
			doubleClick = 0;
			break;
		}
	}

	return doubleClick;
}
