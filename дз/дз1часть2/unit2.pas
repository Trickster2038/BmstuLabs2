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

  TSquare = object(TFigure)
    procedure Draw(t: real);
  end;

  TEllipse = object(TFigure)
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

procedure TSquare.Draw(t: real);
var
  x1, y1, x2, y2, x3, y3, x4, y4: integer;
begin
  x1 := 125 - trunc(90 * cos(t));
  y1 := 125 - trunc(90 * sin(t));
  x2 := 125 - trunc(90 * cos(t + PI / 2));
  y2 := 125 - trunc(90 * sin(t + PI / 2));
  x3 := 125 - trunc(90 * cos(t + PI));
  y3 := 125 - trunc(90 * sin(t + PI));
  x4 := 125 - trunc(90 * cos(t + 3 * PI / 2));
  y4 := 125 - trunc(90 * sin(t + 3 * PI / 2));
  Self.canv.canvas.Clear;
  Self.canv.canvas.line(x1, y1, x2, y2);
  Self.canv.canvas.line(x2, y2, x3, y3);
  Self.canv.canvas.line(x3, y3, x4, y4);
  Self.canv.canvas.line(x4, y4, x1, y1);

  {Self.canv.canvas.line(125 - x1, 125 - y1, x2, y2);
  Self.canv.canvas.line(x1, y1, 125 - x2, 125 - y2);
  Self.canv.canvas.line(125 - x1, 125 - y1, 125 - x2, 125 - y2);         }
end;

procedure TEllipse.Draw(t: real);
var
  x1, y1, x2, y2, x3, y3, x4, y4, xc1, yc1, xc2, yc2: integer;
begin
  x1 := 125 - trunc(60 * cos(t));
  y1 := 125 - trunc(60 * sin(t));
  x2 := 125 - trunc(60 * cos(t + PI / 2));
  y2 := 125 - trunc(60 * sin(t + PI / 2));
  x3 := 125 - trunc(60 * cos(t + PI));
  y3 := 125 - trunc(60 * sin(t + PI));
  x4 := 125 - trunc(60 * cos(t + 3 * PI / 2));
  y4 := 125 - trunc(60 * sin(t + 3 * PI / 2));
  xc1 := trunc((x2 + x3) / 2);
  yc1 := trunc((y2 + y3) / 2);
  xc2 := trunc((x4 + x1) / 2);
  yc2 := trunc((y4 + y1) / 2);
  Self.canv.canvas.Clear;

  //Self.canv.canvas.line(xc1, yc1, xc2, yc2);
  Self.canv.canvas.line(x1, y1, x2, y2);
  //Self.canv.canvas.line(x2, y2, x3, y3);
  Self.canv.canvas.line(x3, y3, x4, y4);
  //Self.canv.canvas.line(x4, y4, x1, y1);

  Self.canv.canvas.arc(xc1 - 40, yc1 - 40, xc1 + 40, yc1 + 40, x3, y3, x2, y2);
  Self.canv.canvas.arc(xc2 - 40, yc2 - 40, xc2 + 40, yc2 + 40, x1, y1, x4, y4);

  {Self.canv.canvas.line(125 - x1, 125 - y1, x2, y2);
  Self.canv.canvas.line(x1, y1, 125 - x2, 125 - y2);
  Self.canv.canvas.line(125 - x1, 125 - y1, 125 - x2, 125 - y2);         }
end;

end.
