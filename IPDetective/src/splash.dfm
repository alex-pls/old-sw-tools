object SplashFrm: TSplashFrm
  Left = 273
  Top = 137
  Cursor = crHourGlass
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'Welcome to IP Detective 2002'
  ClientHeight = 356
  ClientWidth = 533
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 533
    Height = 356
    Align = alClient
    BorderStyle = bsSingle
    TabOrder = 0
    object Panel4: TPanel
      Left = 232
      Top = 296
      Width = 65
      Height = 49
      BorderStyle = bsSingle
      TabOrder = 2
      object Image1: TImage
        Left = 14
        Top = 6
        Width = 32
        Height = 32
        Picture.Data = {
          055449636F6E0000010001002020040000000000E80200001600000028000000
          2000000040000000010004000000000000020000000000000000000000000000
          0000000000000000000080000080000000808000800000008000800080800000
          C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
          FFFFFF0000000000000000000000000000000000000000000000000000000000
          000000000000000000000077777700000000000000222220000088FFFFFFFFF0
          000000000022222000087F70000000000000000000AAAAA08887F707F0000000
          00000000007A7A70777F7F7F0CCCCC000000000000777770FFFFFFF0CCCCCCC0
          0000000000FFFFF00000000CCCCCCC020C0000000000000002A2A220CCCCCC06
          0CC0000000003B302AAAA2A20CCCCCCCC022000000003BB30AAAAA220CCCCCCC
          02200000000003BB30AAAAA220CCCCC022222000000003FBB30AAAA220C00000
          0002000000000037BB30A260ECC3BBBBB02220000000003F7BB30200EEE37BBB
          02222200000000A3F7BB30B0EEE377BB302220000000007A3F7BBBB0EEE3777B
          B30222000000007FA3F7BBB0EEE373F7BB3022000000007FFF377BB0EEE3323F
          7BB302000000007FF37777B0EEE3EEC3F7BB02000000000733333330EEE2E220
          3F7BB00000000007FFE2A22EEEEEEEA203F7B000000000007F2AA22EEEEEEE2A
          2C3F73000000000002AAA222EEEEEEE2CCC3FB00000000000A77AAA222E22CEE
          EC333B000000000000AF7AAA222222CEECBB3B0000000000000AA7AAAAA2222C
          CBBB33000000000000000AA7F7AAAA2203330000000000000000000AAAAAAA00
          0000000000000000000000000000000000000000000000000000000000000000
          00000000FFFFFFFFFFFC0FFF80F001FF80E000FF800000FF800003FF800000FF
          8000003F8000001F8000000FF0000007F0000007F8000003F8000003FC000001
          FC000001FC000001FC000001FC000001FC000001FC000001FE000003FE000003
          FF000001FF800001FF800001FFC00001FFE00003FFF8008FFFFE03FFFFFFFFFF
          FFFFFFFF}
      end
    end
    object Panel2: TPanel
      Left = 8
      Top = 296
      Width = 225
      Height = 49
      TabOrder = 0
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 209
        Height = 16
        AutoSize = False
        Caption = 'IP Detective'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
      end
      object AppVersion_Lbl: TLabel
        Left = 8
        Top = 24
        Width = 209
        Height = 16
        AutoSize = False
        Caption = 'version 1.039403048030043234'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        Transparent = True
      end
    end
    object Panel3: TPanel
      Left = 296
      Top = 296
      Width = 225
      Height = 49
      TabOrder = 1
      object Label3: TLabel
        Left = 8
        Top = 24
        Width = 212
        Height = 16
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'by Alessandro Polo'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Transparent = True
      end
      object CompileTime_Lbl: TLabel
        Left = 8
        Top = 8
        Width = 209
        Height = 16
        Alignment = taRightJustify
        AutoSize = False
        Caption = 'compiled on 00/00/2002'
        Transparent = True
      end
    end
  end
end
