unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    ComboBox1: TComboBox;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Memo1: TMemo;
    procedure Button1Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Edit2Change(Sender: TObject);
    procedure Edit3Change(Sender: TObject);
    procedure FormCreate(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

type
  comp = record
    cost, proc, ram, hdd: integer;
    exist: boolean;
  end;

  f = file of comp;

var
  f1: f;
  buf: comp;

{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
begin

end;

procedure TForm1.Button1Click(Sender: TObject);
begin

end;

procedure TForm1.Button5Click(Sender: TObject);
var
  code: integer;
  s: string;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
 {Str(,s);
  Val(s, buf.cost, code);}
  Val(Form1.Edit1.Text, buf.cost, code);
  Val(Form1.Edit2.Text, buf.ram, code);
  Val(Form1.Edit3.Text, buf.hdd, code);
  // add protection by code
  buf.exist := True;
  buf.proc := Form1.ComboBox1.ItemIndex;
  Seek(f1, FileSize(f1));
  Write(f1, buf);
  CloseFile(f1);
end;

procedure TForm1.Button6Click(Sender: TObject);
var s:string;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  Form1.Memo1.Text:='cost | ram | disk | proc';
  while not EOF(f1) do
  begin
    read(f1,buf);
    if buf.exist then
     begin
     str(buf.cost, s);
     Form1.Memo1.Text:=Form1.Memo1.Text + s + ' | ';

     end;
  end;
end;

procedure TForm1.Edit2Change(Sender: TObject);
begin
 // for id
end;

procedure TForm1.Edit3Change(Sender: TObject);
begin
 // for id
end;

end.
