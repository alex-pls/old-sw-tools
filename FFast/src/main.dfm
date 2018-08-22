object mainFrm: TmainFrm
  Left = 396
  Top = 216
  Width = 548
  Height = 379
  Caption = 'Fast Catalog Manager 1.0'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 540
    Height = 321
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Ricerca'
      object Bevel1: TBevel
        Left = 24
        Top = 24
        Width = 297
        Height = 25
      end
      object Label1: TLabel
        Left = 30
        Top = 30
        Width = 61
        Height = 16
        Caption = 'Macchina:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Bevel2: TBevel
        Left = 24
        Top = 152
        Width = 297
        Height = 25
      end
      object Label2: TLabel
        Left = 30
        Top = 158
        Width = 58
        Height = 16
        Caption = 'Catalogo:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Bevel3: TBevel
        Left = 24
        Top = 88
        Width = 297
        Height = 25
      end
      object Label3: TLabel
        Left = 30
        Top = 94
        Width = 58
        Height = 16
        Caption = 'Matricola:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object MacBox: TComboBox
        Left = 320
        Top = 24
        Width = 185
        Height = 24
        BevelInner = bvLowered
        BevelKind = bkFlat
        Color = clMoneyGreen
        Ctl3D = True
        ItemHeight = 16
        ParentCtl3D = False
        TabOrder = 0
        OnChange = Button8Click
        OnKeyPress = MacBoxKeyPress
      end
      object CatBox: TComboBox
        Left = 320
        Top = 152
        Width = 185
        Height = 24
        BevelInner = bvLowered
        BevelKind = bkFlat
        Color = clMoneyGreen
        ItemHeight = 16
        TabOrder = 2
        OnChange = CatBoxChange
      end
      object MatBox: TEdit
        Left = 320
        Top = 88
        Width = 185
        Height = 22
        BevelInner = bvNone
        BevelOuter = bvNone
        Color = clSkyBlue
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
        OnClick = MatBoxClick
        OnKeyPress = MatBoxKeyPress
      end
      object InfoText1: TStaticText
        Left = 24
        Top = 216
        Width = 481
        Height = 20
        AutoSize = False
        BevelInner = bvSpace
        BevelKind = bkSoft
        Color = clMoneyGreen
        ParentColor = False
        TabOrder = 3
      end
      object InfoText2: TStaticText
        Left = 24
        Top = 240
        Width = 481
        Height = 20
        AutoSize = False
        BevelInner = bvSpace
        BevelKind = bkSoft
        Color = clMoneyGreen
        ParentColor = False
        TabOrder = 4
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Gestisci Cataloghi'
      ImageIndex = 2
      object Bevel4: TBevel
        Left = 8
        Top = 8
        Width = 329
        Height = 25
      end
      object Label6: TLabel
        Left = 14
        Top = 14
        Width = 115
        Height = 16
        Caption = 'Macchina Corrente:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 192
        Top = 80
        Width = 14
        Height = 16
        Caption = '=>'
      end
      object MacBox2: TComboBox
        Left = 336
        Top = 8
        Width = 185
        Height = 24
        BevelInner = bvNone
        BevelKind = bkFlat
        Color = clMoneyGreen
        ItemHeight = 16
        TabOrder = 0
        OnChange = Button8Click
        OnKeyPress = MacBoxKeyPress
      end
      object ListCats: TListBox
        Left = 8
        Top = 48
        Width = 177
        Height = 177
        BevelInner = bvNone
        BevelOuter = bvNone
        Color = clMoneyGreen
        Ctl3D = False
        ItemHeight = 16
        ParentCtl3D = False
        TabOrder = 4
        OnClick = ListCatsClick
      end
      object Button8: TButton
        Left = 8
        Top = 232
        Width = 177
        Height = 25
        Caption = 'Aggiorna'
        TabOrder = 5
        OnClick = Button8Click
      end
      object Panel1: TPanel
        Left = 216
        Top = 48
        Width = 305
        Height = 73
        BevelOuter = bvLowered
        TabOrder = 1
        object Label8: TLabel
          Left = 24
          Top = 8
          Width = 93
          Height = 16
          Caption = 'Dalla Matricola:'
        end
        object Label9: TLabel
          Left = 24
          Top = 40
          Width = 84
          Height = 16
          Caption = 'Alla Matricola:'
        end
        object EditCat1: TEdit
          Left = 136
          Top = 8
          Width = 145
          Height = 22
          BevelInner = bvNone
          BevelOuter = bvNone
          Color = clSkyBlue
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 0
          OnKeyPress = EditCatKeyPress
        end
        object EditCat2: TEdit
          Left = 136
          Top = 40
          Width = 145
          Height = 22
          BevelInner = bvNone
          BevelOuter = bvNone
          Color = clSkyBlue
          Ctl3D = False
          ParentCtl3D = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnKeyPress = EditCatKeyPress
        end
      end
      object Button9: TButton
        Left = 448
        Top = 120
        Width = 75
        Height = 25
        Caption = 'Salva'
        TabOrder = 2
        OnClick = Button9Click
      end
      object Button7: TButton
        Left = 8
        Top = 256
        Width = 177
        Height = 25
        Caption = 'Elimina Catalogo'
        TabOrder = 6
        OnClick = Button7Click
      end
      object GroupBox3: TGroupBox
        Left = 200
        Top = 152
        Width = 321
        Height = 129
        Caption = 'Aggiungi Catalogo'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 3
        object Label7: TLabel
          Left = 15
          Top = 25
          Width = 40
          Height = 16
          Caption = 'Nome:'
        end
        object Label10: TLabel
          Left = 14
          Top = 73
          Width = 93
          Height = 16
          Caption = 'Dalla Matricola:'
        end
        object Label11: TLabel
          Left = 167
          Top = 73
          Width = 84
          Height = 16
          Caption = 'Alla Matricola:'
        end
        object Button10: TButton
          Left = 168
          Top = 40
          Width = 129
          Height = 25
          Caption = 'Aggiungi'
          TabOrder = 3
          OnClick = Button10Click
        end
        object EditAddCat: TEdit
          Left = 16
          Top = 41
          Width = 129
          Height = 22
          BevelInner = bvNone
          BevelOuter = bvNone
          Color = clSkyBlue
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 0
        end
        object EditAddCat2: TEdit
          Left = 168
          Top = 89
          Width = 129
          Height = 22
          BevelInner = bvNone
          BevelOuter = bvNone
          Color = clSkyBlue
          Ctl3D = False
          ParentCtl3D = False
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          OnKeyPress = EditAddCat2KeyPress
        end
        object EditAddCat1: TEdit
          Left = 16
          Top = 89
          Width = 129
          Height = 22
          BevelInner = bvNone
          BevelOuter = bvNone
          Color = clSkyBlue
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 1
          OnKeyPress = EditAddCat2KeyPress
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Gestisci Macchine'
      ImageIndex = 3
      object GroupBox1: TGroupBox
        Left = 8
        Top = 184
        Width = 513
        Height = 89
        Caption = 'Aggiungi una Macchina'
        TabOrder = 0
        object Label4: TLabel
          Left = 16
          Top = 56
          Width = 98
          Height = 16
          Caption = 'Nome Macchina'
        end
        object EditMac: TEdit
          Left = 16
          Top = 32
          Width = 305
          Height = 22
          BevelInner = bvNone
          BevelOuter = bvNone
          Color = clSkyBlue
          Ctl3D = False
          ParentCtl3D = False
          TabOrder = 0
          OnKeyPress = EditMacKeyPress
        end
        object Button6: TButton
          Left = 360
          Top = 32
          Width = 131
          Height = 25
          Caption = 'Aggiungi'
          TabOrder = 1
          OnClick = Button6Click
        end
      end
      object GroupBox2: TGroupBox
        Left = 8
        Top = 8
        Width = 345
        Height = 169
        Caption = 'Lista Macchine'
        TabOrder = 1
        object ListMacs: TListBox
          Left = 16
          Top = 32
          Width = 305
          Height = 97
          Color = clMoneyGreen
          Ctl3D = False
          ItemHeight = 16
          ParentCtl3D = False
          TabOrder = 0
          OnClick = ListMacsClick
        end
        object MacInfo: TStaticText
          Left = 16
          Top = 136
          Width = 305
          Height = 20
          AutoSize = False
          BevelInner = bvNone
          BevelKind = bkFlat
          Color = clMoneyGreen
          ParentColor = False
          TabOrder = 1
        end
      end
      object Button3: TButton
        Left = 368
        Top = 152
        Width = 153
        Height = 25
        Caption = 'Elimina Macchina'
        TabOrder = 5
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 368
        Top = 120
        Width = 153
        Height = 25
        Caption = 'Esporta Lista'
        TabOrder = 3
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 368
        Top = 48
        Width = 153
        Height = 25
        Caption = 'Aggiorna'
        TabOrder = 2
        OnClick = Button5Click
      end
      object StaticMacN: TStaticText
        Left = 368
        Top = 16
        Width = 153
        Height = 20
        AutoSize = False
        BevelInner = bvNone
        BevelKind = bkFlat
        Color = clMoneyGreen
        ParentColor = False
        TabOrder = 4
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 440
    object File1: TMenuItem
      Caption = '&File'
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object OpenDataFile1: TMenuItem
        Caption = 'Open Data File..'
        OnClick = OpenDataFile1Click
      end
      object SaveData1: TMenuItem
        Caption = 'Save Data File..'
        OnClick = SaveData1Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object ViewDataFile1: TMenuItem
        Caption = 'View Data File'
        OnClick = ViewDataFile1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'E&xit'
        OnClick = Exit1Click
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      object Aggiorna1: TMenuItem
        Caption = 'Aggiorna'
        OnClick = Button5Click
      end
      object RicaricaDati1: TMenuItem
        Caption = 'Ricarica Dati'
        OnClick = RicaricaDati1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object EsportaListaMacchine1: TMenuItem
        Caption = 'Esporta Lista Macchine'
        OnClick = Button4Click
      end
    end
    object A1: TMenuItem
      Caption = 'About'
      OnClick = A1Click
    end
  end
  object SaveDialog: TSaveDialog
    Left = 504
  end
  object OpenDialog: TOpenDialog
    Left = 472
  end
end
