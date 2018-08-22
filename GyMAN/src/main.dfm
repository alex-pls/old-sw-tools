object mainFrm: TmainFrm
  Left = 221
  Top = 137
  Width = 685
  Height = 578
  Caption = 'GyManager 1.02'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000000020000000000000000000000000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0088888888888888888888888000000000877777777777777777777770000000
    8888888888888888888888887800000087777777777777777777777788000008
    88888888888888888888888788000008FFFFFFFFFFFFFFFFFFFFFF8778000000
    8FFFFFFFFFFFFFFFFFFFFFF8780000008FFFFFFFFFFFFFF777777FF878000000
    8FFFFFFFFFFFFFFFFFFFFFF87800000008FF77777777777777777FFF88000000
    08FFFFFFFFFFFFFFFFFFFFFF8800000008FFF7777777777777777FFF88000000
    08FFFFFFFFFFFFFFFFFFFFFF8800000008FFF7777777777777777FFF88000000
    08FFFFFFFFFFFFFFFFFFFFFF8800000008FFFFFFF777777777777FFF88000000
    08FFFFFFFFFFFFFFFFFFFFFF8800000008FFFFFFF7777F7777777FFF88000000
    08FFFFFFFFFFFF777F777FFF8800000008FFFFFFF7777F77FFFF7FFF88000000
    08FFFFFFFFFFFF777FF77FFF8800000008FFFFFFF7777F77FFFF7FFF88000000
    08FFFFFFFFFFFF77FFF77FFF8800000008FFFF7777777F7777777FFF88000000
    08FFFFFFFFFFFF7777777FFF8800000008FFFFFFFFFFFFFFFFFFFFFF88000000
    08F8F8F8F8F8F8F8F8F8F8F888000000037B7B7B7B7B7B7B7B7B7B7B38000000
    03B7B7B7B7B7B7B7B7B7B7B73300000003FFFFFFFFFFFFFFFFFFFFFF33000000
    03B7B7B7B7B7B7B7B7B7B7B7B30000000033333333333333333333333300FC00
    0007FC000003F0000003F0000003E0000003E0000003F0000003F0000003F000
    0003F8000003F8000003F8000003F8000003F8000003F8000003F8000003F800
    0003F8000003F8000003F8000003F8000003F8000003F8000003F8000003F800
    0003F8000003F8000003F8000003F8000003F8000003F8000003FC000003}
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 677
    Height = 501
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Images = ImageList
    MultiLine = True
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = ' Gestione giornaliera Tessere         '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      OnShow = Aggiorna1Click
      object Panel1: TPanel
        Left = 561
        Top = 254
        Width = 238
        Height = 273
        TabOrder = 0
        OnDblClick = FotoTessera1Click
        object ImageS: TImage
          Left = 12
          Top = 14
          Width = 200
          Height = 240
          ParentShowHint = False
          ShowHint = True
          Stretch = True
          OnClick = ImageSClick
        end
      end
      object GroupBox4: TGroupBox
        Left = 9
        Top = 16
        Width = 514
        Height = 289
        Caption = 'Tessere Scadute'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
        object Label4: TLabel
          Left = 453
          Top = 16
          Width = 33
          Height = 16
          Caption = 'giorni'
          Enabled = False
        end
        object ExpiredList: TValueListEditor
          Left = 25
          Top = 64
          Width = 459
          Height = 182
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goRowSelect, goThumbTracking]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
          TitleCaptions.Strings = (
            'Nome'
            'Scadenza')
          OnClick = ExpiredListClick
          ColWidths = (
            150
            305)
        end
        object Button7: TButton
          Left = 244
          Top = 252
          Width = 114
          Height = 25
          Hint = 'Modifica manualmente la Scadenza.'
          Caption = 'Modifica'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = Button7Click
        end
        object Button8: TButton
          Left = 373
          Top = 252
          Width = 114
          Height = 25
          Hint = 'Proroga la data di Scadenza di un mese.'
          Caption = 'Proroga'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          OnClick = Button8Click
        end
        object Button10: TButton
          Left = 25
          Top = 252
          Width = 136
          Height = 25
          Hint = 'Aggiungi un nuovo cliente al database'
          Caption = 'Aggiungi Cliente'
          TabOrder = 3
          OnClick = Button10Click
        end
        object StaticText10: TStaticText
          Left = 25
          Top = 32
          Width = 373
          Height = 26
          AutoSize = False
          BevelKind = bkSoft
          Caption = 'Varianza (mostra tessere che scadono entro)'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 4
        end
        object cmb_dayscad: TComboBox
          Left = 396
          Top = 32
          Width = 90
          Height = 24
          BevelKind = bkSoft
          BevelOuter = bvRaised
          Color = clMoneyGreen
          Ctl3D = False
          ItemHeight = 16
          ParentCtl3D = False
          TabOrder = 5
          Text = '10'
          OnChange = Aggiorna1Click
          OnKeyPress = cmb_dayscadKeyPress
          Items.Strings = (
            '15'
            '10'
            '9'
            '8'
            '7'
            '6'
            '5'
            '4'
            '3'
            '2'
            '1'
            '30'
            '60'
            '90'
            '365')
        end
      end
      object MonthCalendar: TMonthCalendar
        Left = 561
        Top = 25
        Width = 225
        Height = 183
        Cursor = crHandPoint
        AutoSize = True
        BorderWidth = 1
        CalColors.BackColor = clMoneyGreen
        CalColors.TitleBackColor = clNavy
        CalColors.MonthBackColor = clMoneyGreen
        Date = 38040.8704176852
        TabOrder = 2
        OnDblClick = Calendario1Click
      end
      object GroupBox5: TGroupBox
        Left = 9
        Top = 318
        Width = 514
        Height = 211
        Caption = 'Tessere in Scadenza'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 3
        object Label3: TLabel
          Left = 453
          Top = 17
          Width = 33
          Height = 16
          Caption = 'giorni'
          Enabled = False
        end
        object ExpiringList: TValueListEditor
          Left = 25
          Top = 64
          Width = 459
          Height = 105
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect, goThumbTracking]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
          TitleCaptions.Strings = (
            'Nome'
            'Scadenza')
          OnClick = ExpiringListClick
          ColWidths = (
            150
            305)
        end
        object StaticText6: TStaticText
          Left = 25
          Top = 32
          Width = 373
          Height = 26
          AutoSize = False
          BevelKind = bkSoft
          Caption = 'Varianza (mostra tessere che scadono entro)'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 1
        end
        object cmb_dayspan: TComboBox
          Left = 396
          Top = 32
          Width = 90
          Height = 24
          BevelKind = bkSoft
          BevelOuter = bvRaised
          Color = clMoneyGreen
          Ctl3D = False
          ItemHeight = 16
          ParentCtl3D = False
          TabOrder = 2
          Text = '1'
          OnChange = Aggiorna1Click
          OnKeyPress = cmb_dayspanKeyPress
          Items.Strings = (
            '10'
            '9'
            '8'
            '7'
            '6'
            '5'
            '4'
            '3'
            '2'
            '1')
        end
        object Button5: TButton
          Left = 373
          Top = 176
          Width = 114
          Height = 25
          Hint = 'Proroga la data di Scadenza di un mese.'
          Caption = 'Proroga'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = Button5Click
        end
        object Button6: TButton
          Left = 244
          Top = 176
          Width = 114
          Height = 25
          Hint = 'Modifica manualmente la Scadenza.'
          Caption = 'Modifica'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
          OnClick = Button6Click
        end
        object Button12: TButton
          Left = 25
          Top = 176
          Width = 136
          Height = 25
          Hint = 'Visualizza la lista clienti ordiata per data di scadenza.'
          Caption = 'Lista per scadenza'
          TabOrder = 5
          OnClick = Button12Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = ' Gestione Clienti         '
      ImageIndex = 12
      object DBGrid: TDBGrid
        Left = 0
        Top = 25
        Width = 680
        Height = 443
        Align = alClient
        Color = clMoneyGreen
        Ctl3D = False
        DataSource = DataSource
        ParentCtl3D = False
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -15
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
      object DBNavigator1: TDBNavigator
        Left = 0
        Top = 0
        Width = 680
        Height = 25
        DataSource = DataSource
        Align = alTop
        Flat = True
        Ctl3D = True
        Hints.Strings = (
          'Primo Cliente'
          'Cliente precedente'
          'Cliente successivo'
          'Ultimo Cliente'
          'Inserisci Cliente'
          'Elimina Cliente'
          'Modifica Cliente'
          'Applica Modifiche'
          'Annulla Modifiche'
          'Aggiorna')
        ParentCtl3D = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
      end
    end
    object TabSheet3: TTabSheet
      Caption = ' Dettagli Cliente         '
      ImageIndex = 13
      object GroupBox1: TGroupBox
        Left = 9
        Top = 9
        Width = 445
        Height = 229
        Caption = 'Dati Anagrafici'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 0
        object Label1: TLabel
          Left = 160
          Top = 95
          Width = 82
          Height = 16
          Caption = 'gg/mm/aaaa'
          Enabled = False
        end
        object StaticText1: TStaticText
          Left = 25
          Top = 32
          Width = 136
          Height = 25
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Nome e Cognome'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 4
        end
        object StaticText2: TStaticText
          Left = 25
          Top = 73
          Width = 136
          Height = 24
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Data di Nascita'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 5
        end
        object DBEdit1: TDBEdit
          Left = 160
          Top = 32
          Width = 255
          Height = 22
          BevelOuter = bvNone
          Color = clCream
          Ctl3D = False
          DataSource = DataSource
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentCtl3D = False
          ParentFont = False
          TabOrder = 0
          OnKeyPress = DBEditKeyPress
        end
        object DBEdit4: TDBEdit
          Left = 160
          Top = 73
          Width = 255
          Height = 22
          BevelOuter = bvNone
          Color = clCream
          Ctl3D = False
          DataSource = DataSource
          ParentCtl3D = False
          TabOrder = 1
          OnClick = DBEditDateClick
          OnKeyPress = DBEditKeyPress
        end
        object StaticText7: TStaticText
          Left = 25
          Top = 132
          Width = 136
          Height = 24
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Indirizzo'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 6
        end
        object DBEdit5: TDBEdit
          Left = 160
          Top = 132
          Width = 255
          Height = 22
          DataSource = DataSource
          TabOrder = 2
          OnKeyPress = DBEditKeyPress
        end
        object StaticText8: TStaticText
          Left = 25
          Top = 172
          Width = 136
          Height = 25
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Contatto Telefonico'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 7
        end
        object DBEdit6: TDBEdit
          Left = 160
          Top = 172
          Width = 255
          Height = 22
          DataSource = DataSource
          TabOrder = 3
          OnKeyPress = DBEditKeyPress
        end
      end
      object GroupBox2: TGroupBox
        Left = 9
        Top = 247
        Width = 445
        Height = 247
        Caption = 'Dati Cliente'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 1
        object Label2: TLabel
          Left = 160
          Top = 57
          Width = 82
          Height = 16
          Caption = 'gg/mm/aaaa'
          Enabled = False
        end
        object StaticText3: TStaticText
          Left = 25
          Top = 74
          Width = 136
          Height = 24
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Iscrizione dal'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 4
        end
        object StaticText4: TStaticText
          Left = 25
          Top = 34
          Width = 136
          Height = 25
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Data scadenza'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 5
        end
        object StaticText5: TStaticText
          Left = 25
          Top = 149
          Width = 136
          Height = 22
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Note aggiuntive'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 6
        end
        object Button3: TButton
          Left = 350
          Top = 74
          Width = 64
          Height = 24
          Hint = 'Imposta la data di iscrizione a oggi.'
          Caption = 'oggi'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 7
          OnClick = Button3Click
        end
        object Button4: TButton
          Left = 350
          Top = 34
          Width = 64
          Height = 25
          Hint = 'Proroga la data di Scadenza di un mese.'
          Caption = 'proroga'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 8
          OnClick = Button4Click
        end
        object DBMemo1: TDBMemo
          Left = 25
          Top = 170
          Width = 390
          Height = 56
          BevelOuter = bvNone
          Color = clCream
          DataSource = DataSource
          TabOrder = 3
        end
        object DBEdit2: TDBEdit
          Left = 160
          Top = 34
          Width = 186
          Height = 22
          BevelOuter = bvNone
          Color = clCream
          Ctl3D = False
          DataSource = DataSource
          ParentCtl3D = False
          TabOrder = 0
          OnClick = DBEditDateClick
          OnKeyPress = DBEditKeyPress
        end
        object DBEdit3: TDBEdit
          Left = 160
          Top = 74
          Width = 186
          Height = 22
          BevelOuter = bvNone
          Color = clCream
          Ctl3D = False
          DataSource = DataSource
          ParentCtl3D = False
          TabOrder = 1
          OnClick = DBEditDateClick
          OnKeyPress = DBEditKeyPress
        end
        object DBCheckBox1: TDBCheckBox
          Left = 165
          Top = 116
          Width = 43
          Height = 17
          DataSource = DataSource
          TabOrder = 2
          ValueChecked = 'True'
          ValueUnchecked = 'False'
        end
        object StaticText9: TStaticText
          Left = 25
          Top = 113
          Width = 136
          Height = 25
          AutoSize = False
          BevelInner = bvSpace
          BevelKind = bkSoft
          Caption = 'Certificato Medico'
          Color = clMoneyGreen
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -15
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentColor = False
          ParentFont = False
          TabOrder = 9
        end
      end
      object GroupBox3: TGroupBox
        Left = 473
        Top = 9
        Width = 331
        Height = 544
        Caption = 'FotoTessera'
        Ctl3D = False
        ParentCtl3D = False
        TabOrder = 2
        object Button11: TButton
          Left = 25
          Top = 500
          Width = 129
          Height = 24
          Hint = 'Carica immagine da file in formato BMP o JPEG.'
          Caption = 'Carica da file..'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          OnClick = Button11Click
        end
        object DBImage1: TDBImage
          Left = 25
          Top = 32
          Width = 281
          Height = 422
          Center = False
          Ctl3D = False
          DataSource = DataSource
          ParentCtl3D = False
          TabOrder = 2
          OnDblClick = EditorImmagini1Click
        end
        object Button1: TButton
          Left = 182
          Top = 500
          Width = 129
          Height = 24
          Hint = 'Esporta l'#39'immagine..'
          Caption = 'Salva con nome..'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 1
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 25
          Top = 465
          Width = 128
          Height = 25
          Hint = 'Acquisici immagine da Scanner.'
          Caption = 'Acquisisci..'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnClick = Button2Click
        end
        object Button9: TButton
          Left = 182
          Top = 465
          Width = 128
          Height = 25
          Hint = 'Modifica immagine con l'#39'Editor.'
          Caption = 'Modifica..'
          ParentShowHint = False
          ShowHint = True
          TabOrder = 4
          OnClick = EditorImmagini1Click
        end
      end
      object DBNavigator2: TDBNavigator
        Left = 9
        Top = 505
        Width = 440
        Height = 50
        DataSource = DataSource
        Flat = True
        Ctl3D = True
        Hints.Strings = (
          'Primo Cliente'
          'Cliente precedente'
          'Cliente successivo'
          'Ultimo Cliente'
          'Inserisci Cliente'
          'Elimina Cliente'
          'Modifica Cliente'
          'Salva'
          'Ripristina'
          'Aggiorna')
        ParentCtl3D = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
      end
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 501
    Width = 677
    Height = 19
    Panels = <
      item
        Bevel = pbRaised
        BiDiMode = bdRightToLeft
        ParentBiDiMode = False
        Text = 'eWorld ReSearch'
        Width = 120
      end
      item
        Text = 'Benvenuto in GyManager'
        Width = 500
      end>
    SimplePanel = False
  end
  object MainMenu1: TMainMenu
    Images = ImageList
    Left = 504
    object File1: TMenuItem
      Caption = '&File'
      object Nuovodatabase1: TMenuItem
        Caption = 'Nuovo database..'
        ImageIndex = 17
        ShortCut = 113
        OnClick = Nuovodatabase1Click
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object CaricaFile1: TMenuItem
        Caption = 'Carica database..'
        ImageIndex = 1
        ShortCut = 114
        OnClick = CaricaFile1Click
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object SalvaconNome1: TMenuItem
        Caption = 'Backup database...'
        ImageIndex = 3
        ShortCut = 114
        OnClick = SalvaconNome1Click
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object exit1: TMenuItem
        Caption = 'E&xit'
        ImageIndex = 4
        ShortCut = 16472
        OnClick = exit1Click
      end
    end
    object Modifica1: TMenuItem
      Caption = '&Modifica'
      object Aggiorna1: TMenuItem
        Caption = 'A&ggiorna'
        ImageIndex = 5
        ShortCut = 116
        OnClick = Aggiorna1Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Aquisisci1: TMenuItem
        Caption = 'Acquisisci Immagine..'
        ImageIndex = 14
        ShortCut = 119
        OnClick = Aquisisci1Click
      end
      object N4: TMenuItem
        Caption = '-'
      end
      object Ordinaper1: TMenuItem
        Caption = 'Ordina per'
        ImageIndex = 6
        object Nome1: TMenuItem
          Caption = 'Nome'
          OnClick = Nome1Click
        end
        object Scadenza1: TMenuItem
          Caption = 'Scadenza'
          Checked = True
          OnClick = Scadenza1Click
        end
        object Iscrizione1: TMenuItem
          Caption = 'Iscrizione'
          OnClick = Iscrizione1Click
        end
        object Datadinascita1: TMenuItem
          Caption = 'Data di nascita'
          OnClick = Datadinascita1Click
        end
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object ClientisenzaCertificato1: TMenuItem
        Caption = 'Clienti senza Certificato'
        ImageIndex = 19
        ShortCut = 117
        OnClick = ClientisenzaCertificato1Click
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object EsportaListaCompleta1: TMenuItem
        Caption = 'Esporta Lista..'
        ImageIndex = 16
        OnClick = EsportaListaCompleta1Click
      end
      object EsportaListaNomi1: TMenuItem
        Caption = 'Esporta Lista Nomi..'
        ImageIndex = 15
        OnClick = EsportaListaNomi1Click
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object SvuotaDatabase: TMenuItem
        Caption = 'Svuota Database'
        ImageIndex = 7
        OnClick = SvuotaDatabaseClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Opzioni1: TMenuItem
        Caption = '&Opzioni..'
        ImageIndex = 8
        ShortCut = 16463
        OnClick = Opzioni1Click
      end
    end
    object Visualizza1: TMenuItem
      Caption = '&Visualizza'
      object Calendario1: TMenuItem
        Caption = '&Calendario..'
        ImageIndex = 0
        ShortCut = 120
        OnClick = Calendario1Click
      end
      object FotoTessera1: TMenuItem
        Caption = 'FotoTessera..'
        ImageIndex = 18
        ShortCut = 121
        OnClick = FotoTessera1Click
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object EditorImmagini1: TMenuItem
        Caption = 'Editor Immagini..'
        ImageIndex = 10
        ShortCut = 122
        OnClick = EditorImmagini1Click
      end
    end
    object Abotu1: TMenuItem
      Caption = '&A riguardo di..'
      object GyMan1: TMenuItem
        Caption = 'GyMan..'
        ImageIndex = 11
        ShortCut = 112
        OnClick = GyMan1Click
      end
      object eWorldReSearch1: TMenuItem
        Caption = 'eWorld ReSearch..'
        ImageIndex = 9
        ShortCut = 123
        OnClick = eWorldReSearch1Click
      end
    end
  end
  object DataSource: TDataSource
    DataSet = Table
    Left = 536
  end
  object OpenDialog: TOpenDialog
    Left = 672
  end
  object SaveDialog: TSaveDialog
    Left = 632
  end
  object OpenPictureDialog: TOpenPictureDialog
    Left = 688
  end
  object SavePictureDialog: TSavePictureDialog
    Left = 648
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 584
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 600
  end
  object Table: TTable
    AfterPost = TableAfterPost
    Left = 552
  end
  object ImageList: TImageList
    Left = 480
    Bitmap = {
      494C010114001800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000006000000001001000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000004000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000200021042186318631863
      FF7F186318631042186318630002000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000042FF7F0000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF7FFF7FFF7F104200000000000000000000000218631863186318631863
      18631863186318631863FF7F0002000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000018631863FF7FFF7F
      000000000000000000000000000000000000000000000000000000000000FF7F
      FF7FFF7FFF7FFF7F00000000000000000000000000020002FF7F00400040FF7F
      FF7FFF7FFF7FFF7FFF7F000200020000000000000000000000000000FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F00000000000000401863FF7FFF7FFF7F
      FF7F004000000000000000000000000000000000000000000000FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F1042000000000000000000020002FF7F00400040FF7F
      100010001000FF7FFF7FFF7F00020000000000000000000000000000FF7F1042
      1042FF7F10421042FF7F10421042FF7F00000000000000420042FF7FFF7FFF7F
      FF7F0042186300420000000000000000000000000000FF7FFF7FFF7F10401F7C
      000000000000FF7FFF7F0000000000000000000000021863FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F00020000000000000000000000000000FF7F1042
      1042FF7F10421042FF7F10421042FF7F0000000018631863FF7FFF7FFF7FFF7F
      FF7F004218631863004200400000000000000000FF7FFF7FFF7FFF7FFF7F0000
      104010420000FF7FFF7FFF7F104200000000000000020002FF7F007C007CFF7F
      186318631863FF7FFF7F000200020000000000000000000000000000FF7F1042
      1042FF7F10421042FF7F10421042FF7F0000004018631863FF7FFF7F00000000
      FF7FFF7FFF7F00420042186300420040000000000000FF7FFF7FFF7FFF7F0000
      0000FF7FFF7FFF7FFF7FFF7F000000000000000000020002FF7F007C007CFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F00020000000000000000000000000000FF7F1042
      1042FF7F10421042FF7F10421042FF7F000000420042FF7F1042FF7FFF7F0042
      FF7F00000042FF7FFF7FFF7F00421863004200000000FF7FFF7FFF7FFF7F0000
      0000FF7FFF7F0000FF7FFF7FFF7F10420000000000021863FF7F00400040FF7F
      FF7FFF7FFF7FFF7FFF7FFF7F00020000000000000000000000000000FF7F1042
      1042FF7F10421042FF7F10421042FF7F00001863FF7FFF7F004010421863FF7F
      004200000000FF7FFF7FFF7FFF7FFF7F0042000000000000FF7FFF7F00000000
      0000FF7F0000FF7FFF7FFF7FFF7F00000000000000020002FF7F00400040FF7F
      100010001000FF7FFF7F000200020000000000000000000000000000FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0000FF7F1863FF7F1863104210421863
      FF7F10001F000000FF7FFF7FFF7FFF7F0000000000001042FF7FFF7F00000000
      0000FF7F0000FF7FFF7FFF7FFF7F10421042000000020002FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F0002000000000000000000000000000010001000
      1000100010001000100010001000100000001042FF7F1042FF7F18631863FF7F
      0042FF7F10001F000000FF7FFF7F000000000000000000000000FF7FFF7F0000
      000000000000FF7FFF7FFF7F000010420000000000021863FF7FFF7FFF7F1863
      00420042FF7FFF7FFF7FFF7F0002000000000000000000000000000000000000
      00000000000000000000000000000000000000001042FF7F1042186318630040
      FF7FFF7FFF7F10001F0000000000000000000000000000001042FF7FFF7FFF7F
      FF7FFF7FFF7FFF7F00001042000000000000000000020002FF7FFF7FFF7F0042
      00420042FF7FFF7FE07F00020002000000000000000000000000000000000000
      000000000000000000000000000000000000000000001042FF7FFF7F1863FF7F
      FF7FFF7FFF7FFF7F10001F0000000000000000000000000000000000FF7FFF7F
      FF7F18630000104200000000000000000000000000020002FF7FFF7FFF7FFF7F
      00421863FF7FFF7FFF7FFF7F0002000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000104200001042
      FF7FFF7FFF7FFF7F000010001F000000000000000000000000000000FF7FFF7F
      0000104200000000000000000000000000000000000218631863186318631863
      18631863186318631863FF7F0002000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00001042FF7F0000000000001000100000000000000000000000000000001042
      0000000000000000000000000000000000000000000218631042186318631863
      FF7F186318631042186300020002000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001042104210421042104210421042
      1042104210421042104210421042104210420000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F10420000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F10420000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000042083146
      CE39210400000000000000000000000000000000000000000000000000000000
      000000001863186318631863186310420000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F10420000000000000000000000000000
      00000000000000000000000000000000000000000000000000000821DE7B5153
      734E754ED0392104000000000000000000000000000000000000000000000000
      00000000186318631863FF7FFF7F18630000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F1042FF7F0000FF7F0000FF7F0000FF7F
      0000FF7F0000000000000000000000000000420831468C31CE397B6F9C735A6B
      39679652774E784E903121040000000000000000000000000000000000000000
      000000001863186318631863FF7F18630000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F1042FF7F0000FF7F0000FF7F0000FF7F
      0000FF7F00000000000000000000000000007B6F7B6F7B6FBD779C737C6B7F5B
      FF7F5E57B656754E7A4E7C4E9231000000000000000000000000000010021002
      100210021002100200001042104218630000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F1042FF7F0000FF7F0000FF7F0000FF7F
      0000FF7F0000000000000000000000000000BD77DE7B7E633E53BE739E6B7F5B
      FF7F5F53FE3E9D2E353611425D4A1942000000000000000000000000FF03FF03
      FF03FF03FF03FF0310021863FF7F18630000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F1042FF7F0000FF7F0000FF7F0000FF7F
      0000FF7F00000000000000000000000000000000C6181042B556185F9E6B7F5B
      FF7F5F53FE3E9D2E3B1ED811AE2DD3390000000000000000000000000000FF03
      FF03FF03FF03FF03FF030000186318630000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F1042FF7F0000FF7F0000FF7F0000E07F
      00000042104200000000000000000000000000000000000000000000C6181042
      9452DB4A783AAD31292518427D4E91310000000000000000000000000000FF03
      FF03000000000000FF031002104218630000FF7F1042104210421042FF7F1042
      10421042FF7F1042104210421042FF7F10421000100010001000100010001000
      E07F00421042E07F000000000000000000000000000000000000000000000000
      8410C6188E31794E794E4D290000000000000000000000000000000000000000
      FF03000000000000FF031863000018630000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F10421000100010001000100010000042
      00420042E07FE07F000000000000000000000000000000002104A5144A29734E
      5A6B1863744E2925000000000000000000000000000000000000000000000000
      FF03FF03FF03FF03FF03FF031002186300001F001F001F001F001F001F001F00
      1F001F001F001F001F001F001F001F0010420000000000000000000000000000
      E07FE07F186318630000000000000000000000002925F75EBD77BD77BD77BD77
      9C73292500000000000000000000000000000000000000000000000000000000
      00000000FF03FF030000FF03FF03000000001F00FF7F1F001F001F00FF7F1F00
      1F001F00FF7F1F001F001F00FF7F1F0010420000000000000000000000000000
      E07F0042000000420000000000000000000000006B2D734E744E53292F25A514
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000004200000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000001042104210421042
      1042104210421042104210421042000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000010001000
      1000100010000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000010421042104210421042
      1042104210421042104210421042104200000000000000000000000000000000
      0000000000000000000000000000000000000000000000001000100010001000
      100010001000100010000000000000000000304330435047504B504B704F7053
      7157715B915B915F9163B167B167000000000000104210421042104210421042
      1042104210421042104210421863104200000000000000000000004200000000
      004200420000000000420000000000000000000000001F001F001F001F000002
      000210001F00000200021000000000000000CC36EC3AEC3AEC3AEC3EEC420C43
      915F915F9163B167B16BB26BD26F0000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F1042104200000000000000000000004200000042
      0042FF7F0042004200420000000000000000000010021F001F001F001F000002
      0002000210001F001F0010001000000000002001400140014001400140014001
      4001E00020012D53D26FD273D2770000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F10421042000000000000186300420000FF7F0000
      0042FF7F0000FF7FFF7F0042000000000000104200021F001F001F001F000002
      0002000210021F001F001F00000000000000E0002001E000E000E00000010001
      C20900010412504F915B915F915F00000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F1042000000000000186300420042FF7FFF7F
      000000000000FF7F00000042000000000000186318631F001F00186310020002
      00020002000210021F001F001042104200000001C209E000E000E000E0004001
      ED36A105304330432F3F0E3B0C3300000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F1042000000000000186300420042FF7FFF7F
      FF7F104200000000FF7F0000000000000000186318631F000002000200020002
      00020002000210021F001F001F0018630000AB2EC209E000E0002001E0008001
      0D370C33EB2ECD263D023E023E0200000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F1042000000000000186318630000FF7FFF7F
      FF7F10420000FF7F004200000000000000001863FF7FFF7FFF7F000200020002
      000200021F0000021F001F001042104200002E3B671E4001200180018001661A
      150EDB01DB01DB01DB01DB01FB0100000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F1042000000000000186318630042FF7F0000
      FF7F104200000000FF7F00000000000000001002FF7FFF7FFF7F000200020002
      00021F000002000210421F001F0000000000E926A71E8001A001800180017801
      980198019801990199019901B90100000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7F1863FF7F1863FF7FFF7F10420000000000001863186300000000FF7F
      FF7FFF7F0000000000000000000000000000FF7FFF7FFF7F00021F001F001F00
      1F001F0000021F00000200021042104200008412830E80013743D13237437B2A
      D81556015701570157015701570100000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7F1863FF7F1863FF7FFF7F1042000000000000186318630000FF7F0000
      FF7F1863104200000000000000000000000010421863FF7FFF7F00021F001F00
      1F001F001F001F0000020002000000000000352F7F475D437F477F477F477F47
      7F477F47191E971114011501150100000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7F1863FF7F1863FF7FFF7F104200000000000018631863000000000000
      FF7F186310420000000000000000000000000000FF7F1863FF7F000200020002
      000200020002000200021042104200000000FF26FF26FF26FF26FF26FF26FF26
      FF26FF26FF26BE67DE731B57F30400000000000000001042FF7FFF7FFF7FFF7F
      FF7FFF7F186318631863FF7FFF7F104200000000000018631863186318631863
      18631863104200000000000000000000000000000000FF7FFF7FFF7F00020002
      000200020002000200021042000000000000DF5FBF16BF12BF12BF12FF26BF12
      BF127F4BDF5FDF5FDF5FDF5FDF5F000000000000000010421042104210421042
      1042104210421042104210421042104200000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF7F1002FF7F1F00
      0002000200020002000200000000000000007E577E577E577E577E577E577E57
      7E577E577E577E577E577E577E57000000000000000000421863186318631863
      1863186318631863186318631863004200000000000000000000000000000000
      00000000000000000000000000000000000000000000000000001042FF7F1002
      1002100210021042000000000000000000001D4B1D4B1D4B1D4B1D4B1D4B1D4B
      1D4B1D4B1D4B1D4B1D4B1D4B1D4B000000000000000000421863186318631863
      1863186318631863186318631863004200000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000010421042
      1042104210421042104210421042000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      6001A000000000000000000000000000000000000000000000000000FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000000000000000
      00000000FF7FFF7FFF7F000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000000000000000
      C109C62AC00000000000000000000000000000000000000000000000FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7F0000000000000000000000000000000000000000
      1042FF7FFF7FFF7FFF7FFF7F000000000000000000006865C260036504610365
      0365E264E164C164A0648058FF7F000000000000000000000000000000000000
      800128338A3FE104000000000000000000000000000010421042000018631863
      1863186318631863FF7FFF7F000000000000000000001042186318631863007C
      FF7FFF7F007C007C007CFF7FFF7F0000000000000000C16C2471467167716671
      6571447123712275E070A064FF7F0000000000000000E0000000000000000000
      0001C62AEC4B28378000000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000FF7FFF7F0000000000000000000010421863186318631863
      FF7FFF7F007C007C007CFF7FFF7F0000000000000000E26C667188719176FF7F
      BC7FDE7FDD7F42750175C064FF7F00000000000000000212E004000000000000
      2001483BCB47EC4BC20D000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000FF7FFF7F0000000000000000000010421863186318631863
      FF7FFF7F007C007C007CFF7FFF7F0000000000000000046D88710D76DD7FA971
      877186754D7ABD7F2271E168FF7F0000000000000000631AE52A200500002000
      431AAA43CA47CB47C626000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000FF7FFF7F0000000000000000000010421863186318631863
      1042FF7FFF7FFF7FFF7FFF7F000000000000000000002571A971BC7F0D76A971
      FF7F66714471DD7F23710365FF7F000000000000000042162633E52A2005A109
      683B893FAA43CA47A522000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000FF7FFF7F0000000000000000000010421863186318631863
      18631042FF7FFF7FFF7F0000000000000000000000004671CB75FF7FAA718971
      FF7F667144719B7F24710465FF7F00000000000000004216052F2633E52A0633
      683B683F893FAA43641E000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F00001F001F001F00000000000000000010421042104210421042
      104210421863000000000000000000000000000000006771EC75177BD47A8971
      FF7F46712471FF7F25712465FF7F000000000000000042120427052F26332637
      4737683B683F683B4005000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000000000000000000000000000000010421863186318631863
      1863186310420000000000000000000000000000000088712E760D76FF7FD47A
      8871CB75DD7F4F7645712565FF7F0000000000000000210EE4220427052F2633
      26374737683B431A4000000000000000000000000000FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7F0000000000000000000000000000000010421863186318631863
      18631863104200000000000000000000000000000000A97171762E760C76167B
      FF7FBC7FEC75677146710465FF7F0000000000000000210AC31AE4220427052F
      26332637C52660000000000000000000000000001F001F001F001F001F001F00
      1F001F001F001F00000000000000000000000000000010421042104210421042
      10421042186300000000000000000000000000000000CB75D47A70762E760D76
      EC75EC75CB75A97167710465FF7F00000000000000000106A216C31AE422E426
      052B263306336109000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000010421863186318631863
      18631863104200000000000000000000000000000000DE7FCA71A97188716771
      6771467145714571036D8969FF7F00000000000000000006A10EA216C31AE422
      E426052B26330633610900000000000000000000000000000000000000000000
      0000104200000000000000000000000000000000000010421863186318631863
      1863186310420000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000002810AA10EA216C31A
      E422E426052B26330633A10D0000000000000000000000000000000000000000
      0000000010420000000000000000000000000000000000001863186318631863
      1863186310420000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080018001800180018001
      8001800180018001800180010000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000104210421042
      1042104210420000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000EA6E0056002D000000000000
      0000000000000000000000000000000000000000186318631863186318631863
      1863186318630000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000C7726F7F6E7F6E7F0977826A
      603D200800000000000000000000000000001042186318631863186318631863
      18631863186300420000000000000000000000001042FF7F1863FF7F1863FF7F
      1863FF7F18631863186318631863000000000000000000000000000000000000
      0000000000000000000000000000000000000000507FDA7F8F7F8F7F8F7F8F7F
      8F7F8F7F4C7BC46EE02800000000000000001042186318631863186318631863
      18631863186300000000000000000000000000001042FF7F1863FF7F1863FF7F
      1863FF7F1863186318631863186300000000000000007B055C01AD0000000000
      D000BD3A020000000000000000000000000000004F7F977BB07FB07FB07FB07F
      B07FB07FB07FB07FE76E00000000000000001863186318631863186318631863
      186318630000FF7F0000000000000000000000001042FF7F1863FF7F1863FF7F
      1863FF7F1863FF7F1863FF7F186300000000000000005C2E1D471D471D471D47
      7E53FA253F4BF004000000000000000000000000517FC76ED27FD27FD27FD27F
      D27F5177707FD27FF67F8018000000000000FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F10421000FF7F000000000000000000001042FF7F1863FF7F1863FF7F
      1863FF7F1863FF7F1863FF7F186300000000000015011F47FF01BF013E4B3E4B
      BF5B7D367D5B9D673E4FBE05D100000000000000507F0A7BFB7FF37FF37FF37F
      917F5F533F4FD27FF97FA46A0000000000000000FF7F186318631042FF7F1000
      FF7FFF7F1000FF7F0000004200420042000000001042FF7F1863FF7F1863FF7F
      1863FF7F1863FF7F1863FF7F18630000000000007B09BF26BF011F023E4B9F57
      DC3EDC4A5B32CD764D7BFF7B3E4F534600000000727F4D7FEA6EDB7FFE7FF97F
      7F579F579F5B5F53FB7FFB7F2008000000000000FF7F1863186318631042FF7F
      FF7FFF7FFF7F0000E07FE07FE07FE07F000000001042FF7F1863FF7F1863FF7F
      1863FF7F1863FF7F1863FF7F18630000000000007D327F1AFF0DBF2A3E4B9E57
      5C2EDE427D5F607E607FA07E7D6300000000205AB27F907F907F907F4E7FF84E
      B97B9F5FDF5FDF637F5FFD7F415E000000000000104218631863186318631042
      FF7FFF7F0000E07F007CE07F007CE07F000000001042FF7F1863FF7F1863FF7F
      1863FF7F0040FF7F0040FF7F18630000000038011F47407DC07C0B623E4B9E57
      FE429D67BE6BE07E207F417EAE2D00000000005AD47FF27FF27FB07FDC467F5B
      5F53F35ACC62EC6E7577FF7FFD7F00000000000000001042104210421042E07F
      10420000E07FE07FE07FE07FE07FE07F000000001042FF7F1863FF7F1863FF7F
      1863FF7F0040FF7F0040FF7F1863000000009B0D4A6AE07C207D5D535D537C32
      DC4ADC4AA20ED867737759670000000000004062F67FF37FF27FBB467F5F5F53
      5F533F4F3F4F3F4FBF6B3F4F00000000000000000000000000001042E07FE07F
      E07FE07FE07FE07FE07FE07FE07FE07F00000000104218631863186318631863
      1863FF7F1863FF7F1863FF7F1863000000009D36817DA07CC4715D53F946BD3A
      DC4A9D6B2217C427A10A734A0000000000000000967BF67FBB46BF6BBF6F3F4F
      3F4F3F4F5F535F57BF6FFB5200000000000000000000000000001042E07FE07F
      E07FE07FE07FE07FE07FE07FE07FE07F00000000104218631863186318631863
      1863FF7F1863FF7F1863FF7F186300000000FE42DD42BC3E5832000000000000
      DD425247C42722171343000000000000000000004062205E714ADF77DF77DF77
      5F535F575F579F637E63000000000000000000000000000000001042E07FE07F
      E07FE07FE07FE07FE07FE07FE07FE07F00000000104210001000100010001000
      1000104210421042104210421042000000000000000000000000000000000000
      0000DD42DD42303F964600000000000000000000000000000000FD4EFF7BFF7B
      FF7B7F5B9F67DF77000000000000000000000000000000000000104218631863
      1863186318631042104210421042104200000000104210421042104210421042
      1042104210421042104210421042000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000005E5FFF7F
      DF77DF77FF7F860C00000000000000000000000000000000000000001042FF7F
      FF7FFF7F10420000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BF6F
      FF327F5BF32D0000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000600000000100010000000000000300000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFF7FFFFDFC003FFFFF3FFFF1F8003
      FFFFE1FFFC0F8003FFFFC0FFF00F8003F801C03FC0078003B801800F00078003
      98010003000380030801000080038003080100008001800398010000C0018003
      B8010001C0008003F8010003E0018003FFFF8007E0078003FFFFC003F01F8003
      FFFFF411F07F8003FFFFFF39F9FF8003FFFFFFFFFFFFFFFF0000FFFFFFFFFFFF
      0000FFFFFC7FFFC10000FFFFF01FFF80000000798007FF00000000790001FF00
      000000790000B8000000007900001800000000798000080000000039F8001C00
      00000019F003BC0000000019C00FFE000000FE1F803FFE010000FE5F81FFFF4B
      0001FF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE003FFFFF01F0001C001
      FE7FE00F00018001F24FC0070001C001C00780030001C001C00300010001C001
      C00300010001C001C00700010001C001C00F00010001C001C00F00010001C001
      C03F00010001C001C03F00010001C001C03F80030001C001C03FC0070001C001
      FFFFE00F0001C001FFFFF01F0001C001FFFFFE1FF803FFFFFFFFFE0FF003FF07
      C007EE07F003E003C003C603C003C003C003C2038003C003C003C0038003C003
      C003C0038003C003C003C0038003C007C003C0038003C01FC003C003801FC01F
      C003C007801FC01FC003C007801FC01FC003C003FFFFC01FC003C001DF7FC01F
      FFFFC001E9BFE01FFFFFC003DF3FF03FFFFFFFFF83FF801FFFFFFFFF003F801F
      8003FFFF0007001F8003C21F0007001F8003C00F0003000F8003800100030007
      800380010001800080038001000180008003000100018000800300010000C000
      800300030001F000800300038003F000800306078007F0008003FF07F00FF001
      8003FFFFF80FF83FFFFFFFFFFC1FFFFF00000000000000000000000000000000
      000000000000}
  end
  object expTable: TTable
    Left = 448
  end
end
