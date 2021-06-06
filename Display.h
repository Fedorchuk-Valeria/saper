//---------------------------------------------------------------------------

#ifndef DisplayH
#define DisplayH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TPlayDisplay : public TForm
{
__published:	// IDE-managed Components
	TStaticText *C;
	TStaticText *A;
	TStaticText *G;
	TStaticText *E;
	TStaticText *P;
	TStringGrid *Field;
	TStaticText *End;
	TButton *ReplayButton;
	TButton *HintButton;
	TLabel *flagMode;
	void __fastcall SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall ReplayButtonClick(TObject *Sender);
	void __fastcall HintButtonClick(TObject *Sender);
	void __fastcall MouseWheellDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall MouseWheellUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
   //	void __fastcall FieldClick(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TPlayDisplay(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPlayDisplay *PlayDisplay;
//---------------------------------------------------------------------------
#endif
