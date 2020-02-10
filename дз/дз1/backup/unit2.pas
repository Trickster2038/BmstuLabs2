unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics,
  Dialogs, ExtCtrls, StdCtrls,
  ComCtrls, ColorBox;

type
  TFigure = object
  private
    x, y: integer;
    connect: TPaintBox;
  public
    procedure Init(a, b: integer; assoc: TPaintBox);
  end;

  TSquare = object(TFigure)
  private
    size: integer;
  public
    procedure Init(a, b, s: integer; assoc: TPaintBox);
    procedure Draw(clr: TColor);
  end;



implementation

procedure TFigure.Init(a, b: integer; assoc: TPaintBox);
begin
  Self.x := a;
  Self.y := b;
  Self.connect := assoc;
end;

procedure TSquare.Init(a, b, s: integer; assoc: TPaintBox);
begin
  inherited Init(a, b, assoc);
  Self.size := s;
end;

procedure TSquare.Draw(clr: TColor);
begin
  Self.connect.canvas.brush.color := clRed;
  Self.connect.canvas.rectangle(x, y, x + size, y + size);
end;

end.
