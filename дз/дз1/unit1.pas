unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, ColorBox;

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
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
begin
  //
end;

procedure TForm1.PaintBox1Click(Sender: TObject);
begin
  //fill
end;

end.

