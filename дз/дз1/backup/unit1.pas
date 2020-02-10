unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, ColorBox, Unit2;

type

  { TForm1 }

  TForm1 = class(TForm)
    ColorBox1: TColorBox;
    ComboBox1: TComboBox;
    Edit1: TEdit;
    Label1: TLabel;
    PaintBox1: TPaintBox;
    UpDown1: TUpDown;
    procedure Button1Click(Sender: TObject);
    procedure PaintBox1Click(Sender: TObject);
    procedure PaintBox1MouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: integer);
  private

  public

  end;

var
  Form1: TForm1;

implementation

var
  sq: TSquare;

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
begin

end;

procedure TForm1.PaintBox1Click(Sender: TObject);
begin

end;

procedure TForm1.PaintBox1MouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: integer);
var
  ss, code: integer;
begin
  val(Edit1.Text, ss, code);
  PaintBox1.Canvas.Brush.Color := ColorBox1.Color;
  if ComboBox1.ItemIndex = 1 then
  begin
    sq.Init(X, Y, ss, PaintBox1);
    sq.Draw(ColorBox1.Selected);
  end;
end;

end.
