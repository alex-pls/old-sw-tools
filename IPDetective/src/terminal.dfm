object TerminalFrm: TTerminalFrm
  Left = 292
  Top = 151
  Width = 402
  Height = 436
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSizeToolWin
  Caption = 'Terminal'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnPaint = FormPaint
  PixelsPerInch = 120
  TextHeight = 16
  object TConsole_Memo: TMemo
    Left = 0
    Top = 0
    Width = 394
    Height = 381
    Align = alClient
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -15
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    PopupMenu = mainFrm.Terminal_PopMnu
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Panel: TPanel
    Left = 0
    Top = 381
    Width = 394
    Height = 23
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object TConsole_cmb: TComboBox
      Left = -7
      Top = -2
      Width = 400
      Height = 25
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -15
      Font.Name = 'Courier New'
      Font.Style = []
      ItemHeight = 17
      ParentFont = False
      TabOrder = 0
      OnKeyPress = TConsole_cmbKeyPress
    end
  end
end
