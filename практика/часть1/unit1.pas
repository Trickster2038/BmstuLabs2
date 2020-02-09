unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ExtCtrls,
  ExtDlgs;

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
    Button8: TButton;
    ComboBox1: TComboBox;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Memo1: TMemo;
    PaintBox1: TPaintBox;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
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
  Form1.Memo1.Text := 'Waiting';
end;

procedure TForm1.Button1Click(Sender: TObject);
var
  s: string;
  maxCost, code: integer;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  Form1.Memo1.Text := 'cost | ram | disk | proc' + #13 + #10;
  while not EOF(f1) do
  begin
    Read(f1, buf);
    val(Form1.Edit1.Text, maxCost, code);
    // add protection
    if (buf.exist) and (buf.cost <= maxCost) then
    begin
      str(buf.cost, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.ram, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.hdd, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      case buf.proc of
        0: s := 'x32';
        1: s := 'x64';
        2: s := 'other';
      end;
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      Form1.Memo1.Text := Form1.Memo1.Text + #13 + #10;
    end;
  end;
  CloseFile(f1);
end;

procedure TForm1.Button2Click(Sender: TObject);
var
  s: string;
  minRam, code: integer;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  Form1.Memo1.Text := 'cost | ram | disk | proc' + #13 + #10;
  while not EOF(f1) do
  begin
    Read(f1, buf);
    val(Form1.Edit2.Text, minRam, code);
    // add protection
    if (buf.exist) and (buf.ram >= minRam) then
    begin
      str(buf.cost, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.ram, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.hdd, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      case buf.proc of
        0: s := 'x32';
        1: s := 'x64';
        2: s := 'other';
      end;
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      Form1.Memo1.Text := Form1.Memo1.Text + #13 + #10;
    end;
  end;
  CloseFile(f1);
end;

procedure TForm1.Button3Click(Sender: TObject);
var
  s: string;
  minRam, minDisk, procType, code: integer;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  Form1.Memo1.Text := 'cost | ram | disk | proc' + #13 + #10;
  while not EOF(f1) do
  begin
    Read(f1, buf);
    val(Form1.Edit3.Text, minDisk, code);
    val(Form1.Edit2.Text, minRam, code);
    // add protection
    if (buf.exist) and (buf.ram >= minRam) and (buf.hdd >= minDisk) and
      (buf.proc = Form1.ComboBox1.ItemIndex) then
    begin
      str(buf.cost, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.ram, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.hdd, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      case buf.proc of
        0: s := 'x32';
        1: s := 'x64';
        2: s := 'other';
      end;
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      Form1.Memo1.Text := Form1.Memo1.Text + #13 + #10;
    end;
  end;
  CloseFile(f1);
end;

//TROUBLE SHOOTING
//Mem Table refresh
procedure TForm1.Button4Click(Sender: TObject);
var
  maxCost, maxRam: integer;
  k1, k2: real;
  bufOld: comp;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  maxCost := 0;
  maxRam := 0;
  while not EOF(f1) do
  begin
    Read(f1, buf);
    if buf.exist then
    begin
      if buf.cost > maxCost then
        maxCost := buf.cost;
      if buf.Ram > maxRam then
        maxRam := buf.ram;
    end;
  end;
  k1 := PaintBox1.Width;
  k2 := PaintBox1.Height;
  reset(f1);
  Read(f1, bufOld);
  Read(f1, buf);
  // ADD SORT
  while not EOF(f1) do
  begin
    //brush
    PaintBox1.Canvas.Line(
      trunc(k1 * (bufOld.ram / maxRam)),
      PaintBox1.Height - trunc(k2 * (bufOld.cost / maxCost)),
      trunc(k1 * (buf.ram / maxRam)),
      PaintBox1.Height - trunc(k2 * (buf.cost / maxCost)));
    bufOld := buf;
    Read(f1, buf);
  end;
  CloseFile(f1);
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

var
  // rename vars
  s: string;
  minRam, minDisk, procType, code: integer;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  Form1.Memo1.Text := 'Deleted';
  while not EOF(f1) do
  begin
    Read(f1, buf);
    val(Form1.Edit3.Text, minDisk, code);
    val(Form1.Edit2.Text, minRam, code);
    // add protection
    if (buf.exist) and (buf.ram = minRam) and (buf.hdd = minDisk) and
      (buf.proc = Form1.ComboBox1.ItemIndex) then
    begin
      buf.cost := 0;
      buf.exist := False;
      buf.hdd := 0;
      buf.proc := 0;
      buf.ram := 0;
      Write(f1, buf);
    end;
  end;
  CloseFile(f1);
end;

procedure TForm1.Button7Click(Sender: TObject);
var
  s: string;
begin
  assignFile(f1, 'comps.dat');
  reset(f1);
  Form1.Memo1.Text := 'cost | ram | disk | proc' + #13 + #10;
  while not EOF(f1) do
  begin
    Read(f1, buf);
    if buf.exist then
    begin
      str(buf.cost, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.ram, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      str(buf.hdd, s);
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      case buf.proc of
        0: s := 'x32';
        1: s := 'x64';
        2: s := 'other';
      end;
      Form1.Memo1.Text := Form1.Memo1.Text + s + ' | ';
      Form1.Memo1.Text := Form1.Memo1.Text + #13 + #10;
    end;
  end;
  CloseFile(f1);
end;

procedure TForm1.Button8Click(Sender: TObject);
var
  f2: f;
begin
  Form1.Memo1.Text := 'Mem table refreshed';
  AssignFile(f2, 'buffer.dat');
  Rewrite(f2);
  AssignFile(f1, 'comps.dat');
  reset(f1);
  while not EOF(f1) do
  begin
    Read(f1, buf);
    if buf.exist then
      Write(f2, buf);
  end;
  CloseFile(f1);
  CloseFile(f2);
  rewrite(f1);
  reset(f2);
  while not EOF(f2) do
  begin
    Read(f2, buf);
    Write(f1, buf);
  end;
  closeFile(f1);
  closeFile(f2);
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
