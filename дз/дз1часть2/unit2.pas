unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls;

type
  TFigure = object
  private
    canv: TPaintBox;
  public
    procedure Init(inp: TPaintBox);
    procedure Draw(t: real);
  end;

  TCircle = object(TFigure)
    procedure Draw(t: real);
  end;

implementation

procedure TFigure.Init(inp: TPaintBox);
begin
  Self.canv := inp;
end;

procedure TFigure.Draw(t: real);
begin
  // abstract
end;

procedure TCircle.Draw(t: real);
var
  x1, y1, x2, y2: integer;
begin
  x1 := 125 - trunc(125 * cos(t));
  y1 := 125 - trunc(125 * sin(t));
  x2 := 125 - trunc(125 * cos(t + PI / 2));
  y2 := 125 - trunc(125 * sin(t + PI / 2));
  Self.canv.canvas.Clear;
  Self.canv.canvas.pie(25, 25, 225, 225, x1, y1, x2, y2);
end;

end.
