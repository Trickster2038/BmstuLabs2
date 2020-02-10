unit Unit2;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils;

type
  TFigure = object
  private
    x, y: integer;
  public
    procedure Init(a, b: integer);
  end;



implementation

procedure TFigure.Init(a, b: integer);
begin
  Self.x := a;
  Self.y := b;
end;

end.
