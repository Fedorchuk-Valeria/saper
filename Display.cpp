//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Display.h"
#include "Field.h"
#include "Flag.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPlayDisplay *PlayDisplay;
Field field;
Flag flag;

//---------------------------------------------------------------------------
__fastcall TPlayDisplay::TPlayDisplay(TComponent* Owner)
	: TForm(Owner)
{
	field.FillingWithBombs(Field);
	field.FillingWithNumbers(Field);
	field.AmountOfSafeCells(Field);
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	if(Field->Cells[ACol][ARow] == "b" && flag.flag == 0 && field.can == 1)
	{
        for(int j = 0; j < 21; j++)
		{
			Field->Rows[j]->Clear();
		}

		Field->Canvas->Brush->Color = clRed;

		for(int i = 0; i < 21; i++)
		{
			for(int j = 0; j < 21; j++)
			{
				TRect Rect = Field->CellRect(i, j);
				Field->Canvas->FillRect(Rect);
			}
		}
		End->Left = 270;
		End->Caption = "GAME OVER";
		field.can = 0;
	} else if(Field->Cells[ACol][ARow] != "b" && flag.flag == 0 && field.can == 1)
	{
		TRect Rect = Field->CellRect(ACol, ARow);
		Field->Canvas->Brush->Color = clGray;
		Field->Canvas->FillRect(Rect);
        Field->Canvas->Font->Color = clBlack;
		Field->Canvas->TextOut(Rect.Left, Rect.Top, Field->Cells[ACol][ARow]);
		if(field.Check(ACol, ARow) == 1)
		{
			field.safeÑells--;
			field.ClickOnSafeCells(ACol, ARow);
		}
	} else if(flag.flag == 1 && field.can == 1)
	{
	   TRect Rect = Field->CellRect(ACol, ARow);
	   Field->Canvas->Brush->Color = clRed;
	   Field->Canvas->FillRect(Rect);
	}
	if(field.safeÑells == 0)
	{
		Field->Canvas->Brush->Color = clGreen;

		for(int i = 0; i < 21; i++)
		{
			for(int j = 0; j < 21; j++)
			{
				TRect Rect = Field->CellRect(i, j);
				Field->Canvas->FillRect(Rect);
			}
		}
		End->Left = 270;
		End->Caption = "YOU WIN";
		field.can = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if(Button == mbRight && flag.count == 0)
	{
		flag.Press();
		flagMode->Caption = "flag mode";
	} else if(Button == mbRight)
	{
		flag.Release();
        flagMode->Caption = "";
    }
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::ReplayButtonClick(TObject *Sender)
{
	End->Caption = "";
	End->Left = -50;
	Field->Canvas->Brush->Color = clBlack;
	for(int i = 0; i < 21; i++)
	{
		for(int j = 0; j < 21; j++)
		{
			TRect Rect = Field->CellRect(i, j);
			Field->Canvas->FillRect(Rect);
		}
	}
    for(int j = 0; j < 21; j++)
	{
        Field->Rows[j]->Clear();
	}
	field.FillingWithBombs(Field);
	field.FillingWithNumbers(Field);
	field.AmountOfSafeCells(Field);
	field.can = 1;
}
//---------------------------------------------------------------------------


void __fastcall TPlayDisplay::HintButtonClick(TObject *Sender)
{
    ShowMessage("To enable flash mode, click on the right mouse button;\n to disable, click again");
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::MouseWheellDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled)
{
	Handled = true;
}
//---------------------------------------------------------------------------

void __fastcall TPlayDisplay::MouseWheellUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
    Handled = true;
}
//---------------------------------------------------------------------------

