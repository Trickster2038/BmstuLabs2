unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ExtCtrls, StdCtrls, Unit2;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    PaintBox1: TPaintBox;
    PaintBox2: TPaintBox;
    PaintBox3: TPaintBox;
    Timer1: TTimer;
    procedure Button1Click(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

var
  circle: TCircle;
  square: TSquare;
  ellipse: TEllipse;
  arg: real;


{$R *.lfm}

{ TForm1 }

procedure TForm1.Button1Click(Sender: TObject);
begin
  arg := 0;
  Circle.Init(PaintBox1);
  Square.Init(PaintBox2);
  ellipse.Init(PaintBox3);
  Timer1.Enabled := not (Timer1.Enabled);
  //test
 { arg := 0;
  while True do
    begin
    sleep(200);
    if CheckBox1.Checked then
    begin
      if arg > (PI * 2) then
        arg := 0;
      arg := arg + 0.01;
      Circle.Init(PaintBox1);
      Circle.Draw(arg);
    end;

    end;                     }
end;

procedure TForm1.Timer1Timer(Sender: TObject);
begin
  if arg > (PI * 2) then
    arg := 0;
  arg := arg + 0.1;
  Circle.Draw(arg);
  Square.Draw(arg);
  Ellipse.Draw(arg);
end;

end.
