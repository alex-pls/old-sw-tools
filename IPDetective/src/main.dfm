object mainFrm: TmainFrm
  Left = 203
  Top = 251
  AutoScroll = False
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'IP Detective'
  ClientHeight = 588
  ClientWidth = 897
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 897
    Height = 57
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 0
    object IPHost0_slb: TStaticText
      Left = 8
      Top = 16
      Width = 289
      Height = 24
      AutoSize = False
      BorderStyle = sbsSunken
      Caption = 'Target IP address:'
      Color = clMenu
      FocusControl = TargetIP_txt
      ParentColor = False
      TabOrder = 0
      OnClick = IPorHost_slbClick
    end
    object TargetIP_txt: TEdit
      Left = 176
      Top = 16
      Width = 121
      Height = 24
      BiDiMode = bdLeftToRight
      Color = clSilver
      ParentBiDiMode = False
      TabOrder = 1
      Text = '127.0.0.1'
    end
    object Button1: TButton
      Left = 328
      Top = 16
      Width = 105
      Height = 25
      Caption = '&Connect'
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 432
      Top = 16
      Width = 105
      Height = 25
      Caption = '&Disconnect'
      TabOrder = 3
    end
  end
  object ViewControlTabs: TPageControl
    Left = 0
    Top = 57
    Width = 897
    Height = 512
    ActivePage = Tab_LocalInfos
    Align = alClient
    MultiLine = True
    ParentShowHint = False
    ShowHint = True
    Style = tsFlatButtons
    TabIndex = 1
    TabOrder = 1
    object Tab_Settings: TTabSheet
      Hint = 'Change Options'
      Caption = 'Settings'
      object SettingsTabs: TPageControl
        Left = 0
        Top = 0
        Width = 889
        Height = 478
        ActivePage = SettingsGen_TabS
        Align = alClient
        BiDiMode = bdLeftToRight
        MultiLine = True
        ParentBiDiMode = False
        TabIndex = 0
        TabOrder = 0
        object SettingsGen_TabS: TTabSheet
          Caption = 'General'
          object GroupBox18: TGroupBox
            Left = 416
            Top = 144
            Width = 417
            Height = 121
            Caption = 'Saving Settings '
            TabOrder = 0
            object SaveToReg_Opt: TRadioButton
              Left = 24
              Top = 56
              Width = 153
              Height = 17
              Hint = 'Most easy way for Me and for You.'
              Caption = 'in Windows Registry.'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object RadioButton2: TRadioButton
              Left = 24
              Top = 32
              Width = 113
              Height = 17
              Hint = 'Very useful on multi-user Systems.'
              Caption = 'on a data file.'
              TabOrder = 1
            end
            object SaveonExit_chk: TCheckBox
              Left = 200
              Top = 56
              Width = 97
              Height = 17
              Caption = 'Save on Exit'
              Checked = True
              State = cbChecked
              TabOrder = 2
            end
            object DesktopAutoSave_chk: TCheckBox
              Left = 200
              Top = 32
              Width = 193
              Height = 17
              Hint = 'Save windows position on close.'
              Caption = 'Auto Save desktop settings.'
              TabOrder = 3
            end
            object KeepLog_chk: TCheckBox
              Left = 24
              Top = 88
              Width = 321
              Height = 17
              Caption = 'Save Events Log on Exit and Load on StartUp.'
              Checked = True
              State = cbChecked
              TabOrder = 4
            end
          end
          object GroupBox19: TGroupBox
            Left = 416
            Top = 8
            Width = 417
            Height = 129
            TabOrder = 1
            object TrayIcon_chk: TCheckBox
              Left = 8
              Top = 0
              Width = 81
              Height = 17
              Caption = 'Tray Icon'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
            object Tray_NotClose_chk: TCheckBox
              Left = 32
              Top = 56
              Width = 265
              Height = 17
              Hint = 'Closing the Application will minimize to a tray icon.'
              Caption = 'Minimize to Tray Icon instead of closing.'
              TabOrder = 1
            end
            object Tray_Minimize_chk: TCheckBox
              Left = 32
              Top = 32
              Width = 225
              Height = 17
              Caption = 'Minimize to Tray Icon.'
              Checked = True
              State = cbChecked
              TabOrder = 2
            end
            object Tray_ShowAl_chk: TCheckBox
              Left = 32
              Top = 80
              Width = 169
              Height = 17
              Caption = 'Show always Tray Icon.'
              TabOrder = 3
            end
          end
          object SettingsGenApply_Btn: TButton
            Left = 424
            Top = 408
            Width = 193
            Height = 25
            Hint = 'Save changes (of this tab) and apply them.'
            Caption = 'Apply changes and Save'
            TabOrder = 2
            OnClick = SettingsGenApply_BtnClick
          end
          object ReLoadGenSettings_btn: TButton
            Left = 640
            Top = 408
            Width = 193
            Height = 25
            Hint = 'Load last saved configuration (of this tab).'
            Cancel = True
            Caption = 'Discard changes'
            TabOrder = 3
            OnClick = ReLoadGenSettings_btnClick
          end
          object GroupBox20: TGroupBox
            Left = 8
            Top = 144
            Width = 401
            Height = 121
            Caption = 'Various'
            TabOrder = 4
            object RunStartUp_chk: TCheckBox
              Left = 24
              Top = 56
              Width = 201
              Height = 17
              Hint = 'Add a link in "StartUp" folder.'
              Caption = 'Run at Windows StartUp.'
              TabOrder = 0
            end
            object SplashShow_chk: TCheckBox
              Left = 24
              Top = 32
              Width = 185
              Height = 17
              Hint = 'Show always splash screen while loading data at startup.'
              Caption = 'Show Splash Screen.'
              Checked = True
              State = cbChecked
              TabOrder = 1
            end
            object DisableScreenSaver_chk: TCheckBox
              Left = 24
              Top = 88
              Width = 321
              Height = 17
              Caption = 'Disable ScreenSaver while running IP Detective.'
              TabOrder = 2
            end
          end
          object GroupBox26: TGroupBox
            Left = 8
            Top = 8
            Width = 401
            Height = 129
            Caption = 'Optimization'
            TabOrder = 5
            object SystemPerf_opt: TRadioButton
              Left = 24
              Top = 24
              Width = 353
              Height = 25
              Caption = 'Optimize System Performance and Application StartUp.'
              TabOrder = 0
            end
            object RadioButton23: TRadioButton
              Left = 24
              Top = 48
              Width = 273
              Height = 17
              Caption = 'Optimize Application and Serives speed.'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
            object Opt_LoadDLLs_chk: TCheckBox
              Left = 48
              Top = 72
              Width = 161
              Height = 17
              Caption = 'Load Services DLLs.'
              Checked = True
              State = cbChecked
              TabOrder = 2
            end
            object Opt_LoadData_chk: TCheckBox
              Left = 48
              Top = 88
              Width = 161
              Height = 17
              Caption = 'Load Application Data.'
              Checked = True
              State = cbChecked
              TabOrder = 3
            end
          end
          object SaveAllSettings_btn: TButton
            Left = 8
            Top = 408
            Width = 193
            Height = 25
            Hint = 'Sale all Application Settings'
            Caption = 'Save All Settings'
            TabOrder = 6
            OnClick = SaveAllSettings_btnClick
          end
          object ReLoadAllSettings_btn: TButton
            Left = 216
            Top = 408
            Width = 193
            Height = 25
            Hint = 'Load all Application Settings and discard any changes.'
            Caption = 'Reload All Settings'
            TabOrder = 7
            OnClick = ReLoadAllSettings_btnClick
          end
        end
        object SettingsConn_TabS: TTabSheet
          Caption = 'Connection'
          ImageIndex = 1
          OnShow = SettingsConn_TabSShow
          object SettingsConnApply_Btn: TButton
            Left = 424
            Top = 408
            Width = 193
            Height = 25
            Caption = 'Apply changes and Save'
            TabOrder = 0
          end
          object ReLoadConnSettings_btn: TButton
            Left = 640
            Top = 408
            Width = 193
            Height = 25
            Caption = 'Discard changes'
            TabOrder = 1
          end
          object GroupBox27: TGroupBox
            Left = 8
            Top = 8
            Width = 369
            Height = 425
            Caption = 'InterNet Connection'
            TabOrder = 2
            object Label24: TLabel
              Left = 48
              Top = 48
              Width = 28
              Height = 16
              Caption = 'Use:'
            end
            object Label25: TLabel
              Left = 32
              Top = 88
              Width = 40
              Height = 16
              Caption = 'Status:'
            end
            object CheckBox8: TCheckBox
              Left = 16
              Top = 384
              Width = 305
              Height = 25
              Hint = 
                'When Application detects an Internet Connection will ask the use' +
                'r for checking upgrades.'
              Caption = 'Ask user to Update when connected to Internet.'
              TabOrder = 0
            end
            object ComboBox3: TComboBox
              Left = 96
              Top = 40
              Width = 249
              Height = 24
              Color = clSilver
              ItemHeight = 16
              TabOrder = 1
              Text = 'Current Connection'
            end
            object SettingsConnCurrConn_slb: TStaticText
              Left = 96
              Top = 88
              Width = 249
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Not Connected'
              TabOrder = 2
            end
          end
        end
        object SettingsDir_TabS: TTabSheet
          Caption = 'Directories and DLLs'
          ImageIndex = 2
          object AppDirTreeView: TTreeView
            Left = 13
            Top = 8
            Width = 369
            Height = 417
            Indent = 19
            ReadOnly = True
            RowSelect = True
            TabOrder = 0
            OnChange = AppDirTreeViewChange
            Items.Data = {
              03000000260000000000000000000000FFFFFFFFFFFFFFFF000000000D000000
              0D536572766963657320444C4C731F000000000000000B000000FFFFFFFFFFFF
              FFFF00000000000000000650696E6765721F000000000000000C000000FFFFFF
              FFFFFFFFFF00000000000000000646696E67657225000000000000000D000000
              FFFFFFFFFFFFFFFF00000000000000000C506F7274205363616E6E6572230000
              00000000000E000000FFFFFFFFFFFFFFFF00000000000000000A547261636552
              6F7574651E000000000000000F000000FFFFFFFFFFFFFFFF0000000000000000
              0557686F6973250000000000000010000000FFFFFFFFFFFFFFFF000000000000
              00000C4F5320446574656374696F6E260000000000000011000000FFFFFFFFFF
              FFFFFF00000000000000000D454D61696C205365727669636528000000000000
              0012000000FFFFFFFFFFFFFFFF00000000000000000F53696D706C6520536572
              7669636573250000000000000013000000FFFFFFFFFFFFFFFF00000000000000
              000C575757205365727669636573270000000000000014000000FFFFFFFFFFFF
              FFFF00000000000000000E54726F6A616E205363616E6E65721C000000000000
              0015000000FFFFFFFFFFFFFFFF0000000000000000034C414E25000000000000
              0016000000FFFFFFFFFFFFFFFF00000000000000000C49435120536572766963
              6573210000000000000017000000FFFFFFFFFFFFFFFF00000000000000000849
              4351204D415049260000000000000000000000FFFFFFFFFFFFFFFF0000000002
              0000000D4C6F63616C20536572766572732B000000000000001F000000FFFFFF
              FFFFFFFFFF000000000000000012416E6F6E7950726F7879204950204C697374
              260000000000000030000000FFFFFFFFFFFFFFFF00000000000000000D57686F
              69732053657276657273290000000000000000000000FFFFFFFFFFFFFFFF0000
              000007000000104170706C69636174696F6E2044617461290000000000000029
              000000FFFFFFFFFFFFFFFF0000000000000000104465736B546F7020494E4920
              46696C6529000000000000002A000000FFFFFFFFFFFFFFFF0000000000000000
              1053657474696E6720494E492046696C6526000000000000002B000000FFFFFF
              FFFFFFFFFF00000000000000000D506F727473202F204E616D65732F00000000
              0000002C000000FFFFFFFFFFFFFFFF0000000000000000164F53204465746563
              74696F6E205265666572656E636532000000000000002D000000FFFFFFFFFFFF
              FFFF00000000000000001954726F6A616E205363616E6E657220506F7274204E
              616D657327000000000000002E000000FFFFFFFFFFFFFFFF0000000000000000
              0E53686F727443757473204C69737428000000000000002F000000FFFFFFFFFF
              FFFFFF00000000000000000F5265666572656E636573204C697374}
          end
          object GroupBox1: TGroupBox
            Left = 392
            Top = 8
            Width = 449
            Height = 417
            Caption = 'Details'
            ParentShowHint = False
            ShowHint = False
            TabOrder = 1
            object Label9: TLabel
              Left = 16
              Top = 88
              Width = 70
              Height = 16
              Caption = 'Actual Path:'
            end
            object Label10: TLabel
              Left = 16
              Top = 32
              Width = 75
              Height = 16
              Caption = 'Default Path:'
            end
            object OpenData_img: TImage
              Left = 400
              Top = 98
              Width = 32
              Height = 32
              Hint = 'Load another file.'
              AutoSize = True
              Center = True
              Picture.Data = {
                055449636F6E0000010001002020100000000000E80200001600000028000000
                2000000040000000010004000000000080020000000000000000000000000000
                0000000000000000000080000080000000808000800000008000800080800000
                C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
                FFFFFF0000000000000008888888888888888000000000000000000000000000
                000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
                FFF080000000000000000F8788788788FFF0800000000008888807777777777F
                FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
                FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
                FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
                FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
                FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
                FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
                FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
                000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
                000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
                000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
                BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
                00000000000000000000000000FF0000000000000000000000000000000F0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
                FC000007FC000007FC0000078000000700000007000000070000000700000007
                0000000700000007000000070000000F000001FF000001FF000001FF00000003
                0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
                FFFFF7FF}
              OnClick = OpenData_imgClick
            end
            object Label16: TLabel
              Left = 16
              Top = 144
              Width = 40
              Height = 16
              Caption = 'Status:'
            end
            object Label26: TLabel
              Left = 16
              Top = 272
              Width = 110
              Height = 16
              Caption = 'Advanced Details:'
            end
            object DirActPath_stlb: TStaticText
              Left = 16
              Top = 104
              Width = 377
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              BorderStyle = sbsSunken
              TabOrder = 0
            end
            object DirDefPath_stlb: TStaticText
              Left = 16
              Top = 48
              Width = 420
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              BorderStyle = sbsSunken
              TabOrder = 1
            end
            object DirDescript_stlb: TStaticText
              Left = 16
              Top = 160
              Width = 420
              Height = 90
              AutoSize = False
              BorderStyle = sbsSunken
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              ParentShowHint = False
              ShowHint = False
              TabOrder = 2
            end
            object Panel2: TPanel
              Left = 16
              Top = 288
              Width = 420
              Height = 114
              BevelOuter = bvLowered
              Caption = 'Panel2'
              TabOrder = 3
              object Memo1: TMemo
                Left = 1
                Top = 1
                Width = 418
                Height = 112
                Align = alClient
                BorderStyle = bsNone
                Color = clBtnFace
                ParentShowHint = False
                ReadOnly = True
                ScrollBars = ssVertical
                ShowHint = False
                TabOrder = 0
              end
            end
          end
        end
        object DeskTop_TabS: TTabSheet
          Caption = 'Desktop / Sounds'
          ImageIndex = 4
          object GroupBox35: TGroupBox
            Left = 8
            Top = 248
            Width = 249
            Height = 185
            Caption = 'Windows Transparency'
            TabOrder = 0
            object TranspForm_cmb: TComboBox
              Left = 16
              Top = 32
              Width = 217
              Height = 24
              Style = csDropDownList
              Color = clSilver
              ItemHeight = 16
              TabOrder = 0
              Items.Strings = (
                'Main'
                'Terminal'
                'ShortCuts'
                'Connections')
            end
            object TranspTrackBar: TTrackBar
              Left = 8
              Top = 80
              Width = 225
              Height = 45
              Hint = 'Set the Transparency %'
              Max = 255
              Min = 10
              Orientation = trHorizontal
              Frequency = 12
              Position = 255
              SelEnd = 0
              SelStart = 0
              TabOrder = 1
              TickMarks = tmBottomRight
              TickStyle = tsAuto
            end
            object TraspApply_btn: TButton
              Left = 16
              Top = 136
              Width = 105
              Height = 25
              Caption = 'Apply'
              TabOrder = 2
              OnClick = TraspApply_btnClick
            end
            object TransReset_btn: TButton
              Left = 120
              Top = 136
              Width = 107
              Height = 25
              Caption = 'Reset'
              TabOrder = 3
              OnClick = TransReset_btnClick
            end
          end
          object ReLoadDesktopSettings_btn: TButton
            Left = 640
            Top = 408
            Width = 193
            Height = 25
            Caption = 'Discard changes'
            TabOrder = 1
          end
          object SaveDesktopSetting_btn: TButton
            Left = 424
            Top = 408
            Width = 193
            Height = 25
            Caption = 'Apply changes and Save'
            TabOrder = 2
          end
          object GroupBox42: TGroupBox
            Left = 8
            Top = 8
            Width = 249
            Height = 233
            Caption = 'Desktop Settings'
            TabOrder = 3
          end
          object GroupBox43: TGroupBox
            Left = 264
            Top = 8
            Width = 577
            Height = 233
            TabOrder = 4
            object Image2: TImage
              Left = 528
              Top = 160
              Width = 32
              Height = 32
              Hint = 'Open List..'
              AutoSize = True
              Center = True
              Picture.Data = {
                055449636F6E0000010001002020100000000000E80200001600000028000000
                2000000040000000010004000000000080020000000000000000000000000000
                0000000000000000000080000080000000808000800000008000800080800000
                C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
                FFFFFF0000000000000008888888888888888000000000000000000000000000
                000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
                FFF080000000000000000F8788788788FFF0800000000008888807777777777F
                FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
                FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
                FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
                FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
                FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
                FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
                FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
                000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
                000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
                000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
                BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
                00000000000000000000000000FF0000000000000000000000000000000F0000
                0000000000000000000000000000000000000000000000000000000000000000
                00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
                FC000007FC000007FC0000078000000700000007000000070000000700000007
                0000000700000007000000070000000F000001FF000001FF000001FF00000003
                0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
                FFFFF7FF}
              OnClick = ShortCutOpenList_imgClick
            end
            object Label29: TLabel
              Left = 524
              Top = 200
              Width = 45
              Height = 16
              Caption = 'Update'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -13
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object CheckBox3: TCheckBox
              Left = 8
              Top = 0
              Width = 97
              Height = 17
              Caption = 'Play Sounds'
              Checked = True
              State = cbChecked
              TabOrder = 0
            end
            object ListBox1: TListBox
              Left = 16
              Top = 24
              Width = 545
              Height = 81
              Color = clSilver
              ItemHeight = 16
              Items.Strings = (
                'Application StartUp'
                'Application ShouDown'
                'general Execute Action'
                'swith Tab')
              TabOrder = 1
            end
            object StaticText5: TStaticText
              Left = 16
              Top = 112
              Width = 545
              Height = 33
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Description'
              TabOrder = 2
            end
            object StaticText7: TStaticText
              Left = 16
              Top = 160
              Width = 505
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'file path'
              TabOrder = 3
            end
            object Button3: TButton
              Left = 16
              Top = 192
              Width = 249
              Height = 25
              Caption = 'Set current sound'
              TabOrder = 4
            end
            object Button4: TButton
              Left = 272
              Top = 192
              Width = 249
              Height = 25
              Caption = 'Set default sounds'
              TabOrder = 5
            end
          end
        end
        object EventLog_TabS: TTabSheet
          Caption = 'Events Log'
          ImageIndex = 3
          object Log_Memo: TMemo
            Left = 8
            Top = 8
            Width = 865
            Height = 417
            Color = clSilver
            PopupMenu = txtBox_Popup
            ReadOnly = True
            ScrollBars = ssVertical
            TabOrder = 0
          end
        end
      end
    end
    object Tab_LocalInfos: TTabSheet
      Hint = 'Get local system informations'
      Caption = 'Local System'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = False
      object LS_PageControl: TPageControl
        Left = 0
        Top = 0
        Width = 889
        Height = 478
        ActivePage = TabSheet9
        Align = alClient
        TabIndex = 4
        TabOrder = 0
        object TabSheet5: TTabSheet
          Caption = 'Informations'
          DesignSize = (
            881
            447)
          object OSInfo_Memo: TMemo
            Left = 8
            Top = 16
            Width = 569
            Height = 393
            Color = clSilver
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            PopupMenu = txtBox_Popup
            ReadOnly = True
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object GetOSInfo_Btn: TButton
            Left = 587
            Top = 416
            Width = 289
            Height = 25
            Anchors = [akRight, akBottom]
            Caption = 'Get System Informations'
            TabOrder = 1
            OnClick = GetOSInfo_BtnClick
          end
          object OSReportClean_chk: TCheckBox
            Left = 448
            Top = 448
            Width = 89
            Height = 17
            Alignment = taLeftJustify
            Anchors = [akLeft, akBottom]
            Caption = 'Auto-Clean.'
            Color = clBtnFace
            ParentColor = False
            TabOrder = 2
          end
          object LocalInfos_TreeView: TTreeView
            Left = 587
            Top = 17
            Width = 289
            Height = 392
            Anchors = [akTop, akRight]
            Images = LocalSysImageList
            Indent = 19
            ReadOnly = True
            RightClickSelect = True
            RowSelect = True
            TabOrder = 3
            Items.Data = {
              04000000210000000A00000000000000FFFFFFFFFFFFFFFF0000000004000000
              08436F6D70757465721E000000010000000B000000FFFFFFFFFFFFFFFF000000
              0000000000054F776E657229000000020000000C000000FFFFFFFFFFFFFFFF00
              00000000000000104F70657261746976652053797374656D2500000003000000
              0D000000FFFFFFFFFFFFFFFF00000000000000000C446C6C732076657273696F
              6E20000000040000000E000000FFFFFFFFFFFFFFFF0000000000000000074465
              736B546F70210000000D00000014000000FFFFFFFFFFFFFFFF00000000030000
              000848617264776172651C0000000500000015000000FFFFFFFFFFFFFFFF0000
              000000000000034350551E0000000600000016000000FFFFFFFFFFFFFFFF0000
              000000000000054D6F64656D250000000700000017000000FFFFFFFFFFFFFFFF
              00000000000000000C53657269616C20506F727473210000000E0000001E0000
              00FFFFFFFFFFFFFFFF000000000300000008496E7465724E6574210000000800
              00001F000000FFFFFFFFFFFFFFFF00000000000000000853657474696E677321
              0000000900000020000000FFFFFFFFFFFFFFFF0000000000000000084163636F
              756E7473260000000A00000021000000FFFFFFFFFFFFFFFF0000000000000000
              0D4D61696C204163636F756E7473200000000F00000028000000FFFFFFFFFFFF
              FFFF0000000002000000074E6574576F726B1E0000000B00000029000000FFFF
              FFFFFFFFFFFF000000000000000005496E666F73200000000C0000002A000000
              FFFFFFFFFFFFFFFF00000000000000000757696E536F636B}
          end
        end
        object TabSheet6: TTabSheet
          Caption = 'Serial Ports I/O'
          ImageIndex = 1
          DesignSize = (
            881
            447)
          object GroupBox21: TGroupBox
            Left = 515
            Top = 8
            Width = 361
            Height = 385
            Anchors = [akTop, akRight]
            Caption = 'Output Data'
            TabOrder = 0
            object SerialSend_Btn: TButton
              Left = 16
              Top = 344
              Width = 329
              Height = 25
              Caption = 'Send'
              TabOrder = 1
              OnClick = SerialSend_BtnClick
            end
            object SerialOutData_REd: TRichEdit
              Left = 16
              Top = 24
              Width = 329
              Height = 321
              TabOrder = 0
            end
          end
          object SerialConnect_Btn: TButton
            Left = 627
            Top = 407
            Width = 249
            Height = 33
            Anchors = [akRight, akBottom]
            Caption = 'Connect'
            TabOrder = 1
            OnClick = SerialConnect_BtnClick
          end
          object GroupBox23: TGroupBox
            Left = 8
            Top = 8
            Width = 465
            Height = 305
            Caption = 'Input Data'
            TabOrder = 2
            object SerialDataIn_REd: TRichEdit
              Left = 16
              Top = 24
              Width = 433
              Height = 265
              Color = clBtnFace
              Lines.Strings = (
                '')
              ReadOnly = True
              TabOrder = 0
            end
          end
          object GroupBox24: TGroupBox
            Left = 8
            Top = 320
            Width = 465
            Height = 113
            Caption = 'Port Status'
            TabOrder = 3
            object Label21: TLabel
              Left = 18
              Top = 33
              Width = 24
              Height = 16
              Caption = 'Port'
            end
            object Label22: TLabel
              Left = 242
              Top = 33
              Width = 64
              Height = 16
              Caption = 'Baud Rate'
            end
            object Label23: TLabel
              Left = 16
              Top = 72
              Width = 37
              Height = 16
              Caption = 'Status'
            end
            object SerialPort_CBox: TComboBox
              Left = 88
              Top = 28
              Width = 121
              Height = 24
              Style = csDropDownList
              Color = clSilver
              ItemHeight = 16
              TabOrder = 0
              Items.Strings = (
                'COM1'
                'COM2'
                'COM3'
                'COM4')
            end
            object SerialBaud_CBox: TComboBox
              Left = 320
              Top = 28
              Width = 121
              Height = 24
              Style = csDropDownList
              Color = clSilver
              ItemHeight = 16
              TabOrder = 1
              Items.Strings = (
                '57600'
                '115200')
            end
            object SerialStatus_Lb: TStaticText
              Left = 88
              Top = 72
              Width = 353
              Height = 20
              Alignment = taRightJustify
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Socket Closed.'
              TabOrder = 2
            end
          end
          object SerialOpenSocket_Btn: TButton
            Left = 515
            Top = 407
            Width = 107
            Height = 33
            Anchors = [akRight, akBottom]
            Caption = 'Open Socket'
            TabOrder = 4
            OnClick = SerialOpenSocket_BtnClick
          end
        end
        object TabSheet7: TTabSheet
          Caption = 'Capture Screen'
          ImageIndex = 2
          DesignSize = (
            881
            447)
          object GroupBox22: TGroupBox
            Left = 8
            Top = 8
            Width = 297
            Height = 385
            Caption = 'Settings'
            TabOrder = 0
            object CaptureFullScreen_opt: TRadioButton
              Left = 32
              Top = 32
              Width = 113
              Height = 17
              Caption = 'Full Screen'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object RadioButton22: TRadioButton
              Left = 32
              Top = 56
              Width = 89
              Height = 17
              Caption = 'Window'
              TabOrder = 1
            end
            object CaptureWindow_Ed: TEdit
              Left = 48
              Top = 96
              Width = 193
              Height = 24
              TabOrder = 2
              Text = 'TAppBuilder'
            end
          end
          object GroupBox25: TGroupBox
            Left = 322
            Top = 8
            Width = 521
            Height = 425
            Anchors = [akTop, akRight]
            Caption = 'ScreenShot'
            TabOrder = 1
            object CaptureShot_Img: TImage
              Left = 16
              Top = 24
              Width = 487
              Height = 391
              Hint = 'Image has been stretched.'
              Center = True
              ParentShowHint = False
              ShowHint = True
              Stretch = True
            end
          end
          object CaptureScreen_Btn: TButton
            Left = 8
            Top = 402
            Width = 145
            Height = 33
            Anchors = [akLeft, akBottom]
            Caption = 'Capture'
            TabOrder = 2
            OnClick = CaptureScreen_BtnClick
          end
          object CaptureSave_Btn: TButton
            Left = 160
            Top = 402
            Width = 145
            Height = 33
            Anchors = [akLeft, akBottom]
            Caption = 'Save to File'
            TabOrder = 3
            OnClick = CaptureSave_BtnClick
          end
        end
        object TabSheet4: TTabSheet
          Caption = 'Clean Windows Logs'
          ImageIndex = 3
          DesignSize = (
            881
            447)
          object CleagLogs_Memo: TMemo
            Left = 8
            Top = 16
            Width = 529
            Height = 393
            Color = clSilver
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Courier New'
            Font.Style = []
            ParentFont = False
            PopupMenu = txtBox_Popup
            ReadOnly = True
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object LogsClear_btn: TButton
            Left = 552
            Top = 408
            Width = 289
            Height = 25
            Caption = 'Execute'
            TabOrder = 1
            OnClick = LogsClear_btnClick
          end
          object IELogs_TreeView: TTreeView
            Left = 587
            Top = 17
            Width = 289
            Height = 384
            Anchors = [akTop, akRight]
            Images = LocalSysImageList
            Indent = 19
            ReadOnly = True
            RightClickSelect = True
            RowSelect = True
            TabOrder = 2
            Items.Data = {
              0200000020000000000000000A000000FFFFFFFFFFFFFFFF0000000002000000
              0757696E646F77731F000000000000000B000000FFFFFFFFFFFFFFFF00000000
              0000000006526563656E7423000000000000000C000000FFFFFFFFFFFFFFFF00
              000000000000000A53746172742D3E52756E2A0000000000000064000000FFFF
              FFFFFFFFFFFF000000000200000011496E7465724E6574204578706C6F726572
              200000000000000065000000FFFFFFFFFFFFFFFF000000000000000007486973
              746F7279310000000000000066000000FFFFFFFFFFFFFFFF0000000000000000
              1854656D706F7261727920496E7465726E65742046696C6573}
          end
          object CleagLogsReportClean_chk: TCheckBox
            Left = 8
            Top = 448
            Width = 89
            Height = 17
            Anchors = [akLeft, akBottom]
            Caption = 'Auto-Clean.'
            Color = clBtnFace
            ParentColor = False
            TabOrder = 3
          end
          object CleagLogsShowAlert_chk: TCheckBox
            Left = 312
            Top = 416
            Width = 225
            Height = 17
            Alignment = taLeftJustify
            Caption = 'Prompt Alert before Cleaning Logs'
            Checked = True
            State = cbChecked
            TabOrder = 4
          end
        end
        object TabSheet9: TTabSheet
          Caption = 'Windows 2000 TweaK'
          ImageIndex = 4
          object GroupBox47: TGroupBox
            Left = 8
            Top = 8
            Width = 249
            Height = 193
            Caption = 'Auto Log-On'
            TabOrder = 0
            object Label32: TLabel
              Left = 16
              Top = 32
              Width = 36
              Height = 16
              Caption = 'Login:'
            end
            object Label33: TLabel
              Left = 16
              Top = 64
              Width = 50
              Height = 16
              Caption = 'Domain:'
            end
            object Label34: TLabel
              Left = 16
              Top = 96
              Width = 63
              Height = 16
              Caption = 'Password:'
            end
            object Edit2: TEdit
              Left = 104
              Top = 32
              Width = 121
              Height = 24
              Color = clSilver
              TabOrder = 0
            end
            object Edit4: TEdit
              Left = 104
              Top = 64
              Width = 121
              Height = 24
              Color = clSilver
              TabOrder = 1
            end
            object Edit5: TEdit
              Left = 104
              Top = 96
              Width = 121
              Height = 24
              Color = clSilver
              TabOrder = 2
            end
            object LS_Win2K_EnableLogOn_btn: TButton
              Left = 16
              Top = 144
              Width = 105
              Height = 25
              Caption = 'Enable'
              TabOrder = 3
              OnClick = LS_Win2K_EnableLogOn_btnClick
            end
            object Button11: TButton
              Left = 120
              Top = 144
              Width = 107
              Height = 25
              Caption = 'Disable'
              TabOrder = 4
            end
          end
        end
      end
    end
    object Tab_Automations: TTabSheet
      Hint = 'Perform more operations at once.'
      Caption = 'Automations'
      ImageIndex = 2
      DesignSize = (
        889
        478)
      object Auto_CListBox: TCheckListBox
        Left = 8
        Top = 8
        Width = 505
        Height = 449
        Columns = 2
        DragMode = dmAutomatic
        ItemHeight = 16
        Items.Strings = (
          'blabla bla')
        TabOrder = 0
        OnDragDrop = Auto_CListBoxDragDrop
        OnDragOver = Auto_CListBoxDragOver
        OnKeyPress = Auto_CListBoxKeyPress
      end
      object GroupBox30: TGroupBox
        Left = 563
        Top = 8
        Width = 321
        Height = 305
        Anchors = [akTop, akRight]
        Caption = 'Operations Archive'
        TabOrder = 1
        object ListBox2: TListBox
          Left = 16
          Top = 32
          Width = 289
          Height = 249
          DragMode = dmAutomatic
          ItemHeight = 16
          Items.Strings = (
            'Ping'
            'Whois'
            'Port Scanning'
            'Trojan Scanning')
          TabOrder = 0
        end
      end
      object GroupBox31: TGroupBox
        Left = 563
        Top = 327
        Width = 321
        Height = 137
        Anchors = [akRight, akBottom]
        Caption = 'Run Options'
        TabOrder = 2
      end
      object UpDown6: TUpDown
        Left = 492
        Top = 9
        Width = 20
        Height = 30
        Hint = 'Move Operation Up / Down'
        Min = 0
        Position = 0
        TabOrder = 3
        Wrap = False
      end
    end
    object Tab_Services: TTabSheet
      Caption = 'Services'
      ImageIndex = 3
      object ServicesTab: TPageControl
        Left = 0
        Top = 0
        Width = 889
        Height = 478
        ActivePage = TabPinger
        Align = alClient
        MultiLine = True
        PopupMenu = txtBox_Popup
        TabIndex = 0
        TabOrder = 0
        object TabPinger: TTabSheet
          Caption = 'Ping'
          OnShow = TabPingerShow
          DesignSize = (
            881
            426)
          object PingAdvanced_grp: TGroupBox
            Left = 16
            Top = 8
            Width = 433
            Height = 409
            Caption = 'Advanced Ping Settings'
            TabOrder = 4
            object Label31: TLabel
              Left = 16
              Top = 32
              Width = 129
              Height = 16
              AutoSize = False
              Caption = 'Send this data:'
            end
            object PingMessage_txt: TEdit
              Left = 16
              Top = 48
              Width = 377
              Height = 24
              Color = clSilver
              TabOrder = 0
            end
          end
          object Pinger_Memo: TMemo
            Left = 8
            Top = 8
            Width = 441
            Height = 409
            Color = clSilver
            PopupMenu = txtBox_Popup
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object PingConnect_Btn: TButton
            Left = 473
            Top = 392
            Width = 401
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'Connect!'
            TabOrder = 1
            OnClick = PingConnect_BtnClick
          end
          object GroupBox16: TGroupBox
            Left = 473
            Top = 112
            Width = 401
            Height = 273
            Anchors = [akTop, akRight]
            Caption = 'Connection Options'
            TabOrder = 2
            object Label17: TLabel
              Left = 216
              Top = 72
              Width = 51
              Height = 16
              Caption = 'TimeOut'
            end
            object Label18: TLabel
              Left = 216
              Top = 104
              Width = 36
              Height = 16
              Caption = 'Delay'
            end
            object Label19: TLabel
              Left = 216
              Top = 136
              Width = 49
              Height = 16
              Caption = 'Packets'
            end
            object Label20: TLabel
              Left = 216
              Top = 40
              Width = 71
              Height = 16
              Caption = 'Packet Size'
            end
            object Label27: TLabel
              Left = 359
              Top = 72
              Width = 18
              Height = 16
              Caption = 'ms'
            end
            object Label28: TLabel
              Left = 359
              Top = 104
              Width = 18
              Height = 16
              Caption = 'ms'
            end
            object Label30: TLabel
              Left = 359
              Top = 40
              Width = 33
              Height = 16
              Caption = 'bytes'
            end
            object RadioButton20: TRadioButton
              Left = 24
              Top = 32
              Width = 113
              Height = 17
              Caption = 'Ping '
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object PingN_txt: TEdit
              Left = 104
              Top = 32
              Width = 33
              Height = 24
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 1
              Text = '3'
            end
            object UpDown1: TUpDown
              Left = 137
              Top = 32
              Width = 19
              Height = 24
              Associate = PingN_txt
              Min = 1
              Max = 32767
              Position = 3
              TabOrder = 2
              Wrap = False
            end
            object PingLoop_opt: TRadioButton
              Left = 24
              Top = 64
              Width = 169
              Height = 17
              Caption = 'Ping untill user stops.'
              TabOrder = 3
            end
            object PingT_txt: TEdit
              Left = 296
              Top = 64
              Width = 41
              Height = 24
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 4
              Text = '3000'
              OnChange = PingT_txtChange
            end
            object UpDown2: TUpDown
              Left = 337
              Top = 64
              Width = 19
              Height = 24
              Associate = PingT_txt
              Min = 200
              Max = 32767
              Position = 3000
              TabOrder = 5
              Wrap = False
            end
            object PingD_txt: TEdit
              Left = 296
              Top = 96
              Width = 41
              Height = 24
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 6
              Text = '100'
              OnChange = PingD_txtChange
            end
            object UpDown3: TUpDown
              Left = 337
              Top = 96
              Width = 19
              Height = 24
              Associate = PingD_txt
              Min = 10
              Max = 32767
              Position = 100
              TabOrder = 7
              Wrap = False
            end
            object PingPn_txt: TEdit
              Left = 296
              Top = 128
              Width = 41
              Height = 24
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 8
              Text = '10'
              OnChange = PingPn_txtChange
            end
            object UpDown4: TUpDown
              Left = 337
              Top = 128
              Width = 19
              Height = 24
              Associate = PingPn_txt
              Min = 1
              Max = 32767
              Position = 10
              TabOrder = 9
              Wrap = False
            end
            object PingPsize_txt: TEdit
              Left = 296
              Top = 32
              Width = 41
              Height = 24
              Hint = 
                'ICMP Packet Header is not included and will be added to final Si' +
                'ze. (8 bytes).'
              Color = clSilver
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'MS Sans Serif'
              Font.Style = []
              ParentFont = False
              TabOrder = 10
              Text = '32'
              OnChange = PingPsize_txtChange
            end
            object UpDown5: TUpDown
              Left = 337
              Top = 32
              Width = 19
              Height = 24
              Associate = PingPsize_txt
              Min = 1
              Max = 32767
              Position = 32
              TabOrder = 11
              Wrap = False
            end
            object PingDefaults_chk: TCheckBox
              Left = 270
              Top = 248
              Width = 121
              Height = 17
              Alignment = taLeftJustify
              Caption = 'Default Values'
              Checked = True
              State = cbChecked
              TabOrder = 12
              OnClick = PingDefaults_chkClick
            end
            object PingAdvanced_slb: TStaticText
              Left = 12
              Top = 244
              Width = 129
              Height = 20
              AutoSize = False
              Caption = 'Advanced Settings'
              Color = clBtnFace
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clNavy
              Font.Height = -13
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentColor = False
              ParentFont = False
              TabOrder = 13
              OnClick = PingAdvanced_slbClick
            end
          end
          object GroupBox34: TGroupBox
            Left = 472
            Top = 8
            Width = 401
            Height = 97
            Anchors = [akTop, akRight]
            TabOrder = 3
            object IPHost4_slb: TStaticText
              Left = 16
              Top = 24
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clBtnFace
              FocusControl = PingTargetIP_txt
              ParentColor = False
              TabOrder = 1
              OnClick = IPorHost_slbClick
            end
            object PingTargetIP_txt: TEdit
              Left = 232
              Top = 24
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 0
              Text = '212.212.212.212'
            end
            object StaticText1: TStaticText
              Left = 16
              Top = 56
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target Port:'
              Color = clMenu
              ParentColor = False
              TabOrder = 2
            end
            object PingTargetPort_txt: TEdit
              Left = 344
              Top = 56
              Width = 41
              Height = 24
              Hint = 'Type here target Port used (0=default)'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 3
              Text = '13'
            end
          end
        end
        object TabFinger: TTabSheet
          Caption = 'Finger'
          ImageIndex = 1
          OnShow = TabFingerShow
          DesignSize = (
            881
            426)
          object Finger_Memo: TMemo
            Left = 8
            Top = 8
            Width = 441
            Height = 409
            Color = clSilver
            PopupMenu = txtBox_Popup
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object GroupBox32: TGroupBox
            Left = 472
            Top = 8
            Width = 401
            Height = 97
            Anchors = [akTop, akRight]
            TabOrder = 1
            object IPHost2_slb: TStaticText
              Left = 16
              Top = 24
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clMenu
              FocusControl = FingerTargetIP_txt
              ParentColor = False
              TabOrder = 1
              OnClick = IPorHost_slbClick
            end
            object FingerTargetIP_txt: TEdit
              Left = 232
              Top = 24
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 0
              Text = '193.205.194.17'
            end
            object StaticText6: TStaticText
              Left = 16
              Top = 56
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target Port:'
              Color = clMenu
              ParentColor = False
              TabOrder = 2
            end
            object FingerTargetPort_txt: TEdit
              Left = 344
              Top = 56
              Width = 41
              Height = 24
              Hint = 'Type here target Port used (0=default)'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 3
              Text = '79'
            end
          end
          object GroupBox33: TGroupBox
            Left = 472
            Top = 112
            Width = 401
            Height = 177
            Caption = 'User Details'
            TabOrder = 2
            object FingerUserName_txt: TEdit
              Left = 16
              Top = 32
              Width = 369
              Height = 24
              Color = clSilver
              TabOrder = 0
            end
          end
          object FingerSend_btn: TButton
            Left = 472
            Top = 392
            Width = 401
            Height = 25
            Caption = 'Send Query'
            TabOrder = 3
            OnClick = FingerSend_btnClick
          end
          object Button5: TButton
            Left = 472
            Top = 312
            Width = 401
            Height = 25
            Caption = 'List All Users'
            TabOrder = 4
          end
        end
        object TabPortScanner: TTabSheet
          Caption = 'Port Scanner'
          ImageIndex = 2
          OnShow = TabPortScannerShow
          DesignSize = (
            881
            426)
          object Button31: TButton
            Left = 475
            Top = 392
            Width = 401
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'View Report'
            TabOrder = 8
          end
          object GroupBox13: TGroupBox
            Left = 475
            Top = 240
            Width = 233
            Height = 113
            Anchors = [akTop, akRight]
            Caption = 'Scanning Type'
            TabOrder = 0
            object RadioButton10: TRadioButton
              Left = 16
              Top = 32
              Width = 161
              Height = 17
              Caption = 'Scan for all Ports.'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object RadioButton11: TRadioButton
              Left = 16
              Top = 80
              Width = 201
              Height = 17
              Caption = 'Scan for most common Ports.'
              TabOrder = 1
            end
            object RadioButton12: TRadioButton
              Left = 16
              Top = 56
              Width = 185
              Height = 17
              Caption = 'Scan only selected items.'
              TabOrder = 2
            end
          end
          object GroupBox14: TGroupBox
            Left = 475
            Top = 96
            Width = 401
            Height = 137
            Anchors = [akTop, akRight]
            Caption = 'Ports Database'
            TabOrder = 2
            object Label14: TLabel
              Left = 16
              Top = 32
              Width = 30
              Height = 16
              Caption = 'Path:'
            end
            object Label15: TLabel
              Left = 277
              Top = 104
              Width = 108
              Height = 16
              Caption = 'Update Database'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -13
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object PortScannerDataB_slb: TStaticText
              Left = 72
              Top = 32
              Width = 313
              Height = 20
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = '\Data\PortList.db'
              TabOrder = 0
            end
            object Button28: TButton
              Left = 72
              Top = 64
              Width = 145
              Height = 25
              Caption = 'Reflesh List'
              TabOrder = 1
            end
            object Button29: TButton
              Left = 224
              Top = 64
              Width = 161
              Height = 25
              Caption = 'Manage Database'
              TabOrder = 2
            end
          end
          object RadioGroup3: TRadioGroup
            Left = 715
            Top = 240
            Width = 161
            Height = 113
            Anchors = [akTop, akRight]
            Caption = 'List ShortCuts'
            TabOrder = 3
          end
          object RadioButton13: TRadioButton
            Left = 728
            Top = 288
            Width = 113
            Height = 17
            Caption = 'Check all'
            TabOrder = 4
          end
          object RadioButton14: TRadioButton
            Left = 728
            Top = 312
            Width = 113
            Height = 17
            Caption = 'Uncheck all.'
            TabOrder = 5
          end
          object RadioButton15: TRadioButton
            Left = 728
            Top = 264
            Width = 113
            Height = 17
            Caption = 'Check common.'
            TabOrder = 6
          end
          object PortScanning_btn: TButton
            Left = 475
            Top = 360
            Width = 401
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'Start Scanning'
            TabOrder = 7
            OnClick = PortScanning_btnClick
          end
          object ListView3: TListView
            Left = 8
            Top = 8
            Width = 441
            Height = 409
            Checkboxes = True
            Columns = <
              item
                AutoSize = True
                Caption = 'Port Name'
              end
              item
                Alignment = taRightJustify
                AutoSize = True
                Caption = 'default Port'
              end>
            GridLines = True
            Items.Data = {
              6D0000000300000000000000FFFFFFFFFFFFFFFF00000000000000001C465450
              202846696C65205472616E736665722050726F746F636F6C2900000000FFFFFF
              FFFFFFFFFF000000000000000004534D545000000000FFFFFFFFFFFFFFFF0000
              0000000000000654656C6E6574}
            MultiSelect = True
            ReadOnly = True
            RowSelect = True
            SortType = stText
            TabOrder = 1
            ViewStyle = vsReport
          end
          object GroupBox37: TGroupBox
            Left = 475
            Top = 8
            Width = 401
            Height = 65
            Anchors = [akTop, akRight]
            TabOrder = 9
            object StaticText2: TStaticText
              Left = 16
              Top = 24
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clBtnFace
              FocusControl = PortScannerTargetIP_txt
              ParentColor = False
              TabOrder = 1
              OnClick = IPorHost_slbClick
            end
            object PortScannerTargetIP_txt: TEdit
              Left = 232
              Top = 24
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 0
              Text = '127.0.0.1'
            end
          end
        end
        object TabTraceRoute: TTabSheet
          Caption = 'TraceRoute'
          ImageIndex = 3
          OnShow = TabTraceRouteShow
          DesignSize = (
            881
            426)
          object Memo6: TMemo
            Left = 8
            Top = 8
            Width = 441
            Height = 401
            Color = clSilver
            PopupMenu = txtBox_Popup
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object GroupBox36: TGroupBox
            Left = 472
            Top = 8
            Width = 401
            Height = 65
            Anchors = [akTop, akRight]
            TabOrder = 1
            object IPHos5_slb: TStaticText
              Left = 16
              Top = 24
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clBtnFace
              FocusControl = TraceTargetIP_txt
              ParentColor = False
              TabOrder = 1
              OnClick = IPorHost_slbClick
            end
            object TraceTargetIP_txt: TEdit
              Left = 232
              Top = 24
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 0
              Text = '127.0.0.1'
            end
          end
        end
        object TabWhois: TTabSheet
          Caption = 'Whois'
          ImageIndex = 4
          OnShow = TabWhoisShow
          DesignSize = (
            881
            426)
          object WhoIs_Memo: TMemo
            Left = 8
            Top = 8
            Width = 441
            Height = 409
            Color = clSilver
            ParentShowHint = False
            PopupMenu = txtBox_Popup
            ReadOnly = True
            ScrollBars = ssVertical
            ShowHint = False
            TabOrder = 0
          end
          object GroupBox3: TGroupBox
            Left = 475
            Top = 8
            Width = 401
            Height = 65
            Anchors = [akTop, akRight]
            TabOrder = 1
            object IPHost1_slb: TStaticText
              Left = 16
              Top = 24
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clBtnFace
              FocusControl = WhoIsTargetIP_txt
              ParentColor = False
              TabOrder = 1
              OnClick = IPorHost_slbClick
            end
            object WhoIsTargetIP_txt: TEdit
              Left = 232
              Top = 24
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 0
              Text = '127.0.0.1'
            end
          end
          object GroupBox4: TGroupBox
            Left = 475
            Top = 80
            Width = 401
            Height = 265
            Anchors = [akTop, akRight]
            Caption = 'Whois Servers'
            TabOrder = 2
            object Label3: TLabel
              Left = 316
              Top = 241
              Width = 68
              Height = 16
              Hint = 'Update the Serverlist from the InterNet.'
              Caption = 'Update List'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -13
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object WhoIsServers_lbx: TCheckListBox
              Left = 16
              Top = 24
              Width = 369
              Height = 209
              Color = clSilver
              ItemHeight = 16
              Items.Strings = (
                'whois.iternic.com'
                'whois.iternic.it')
              TabOrder = 0
            end
            object AddWIs_btn: TButton
              Left = 16
              Top = 240
              Width = 65
              Height = 17
              Caption = 'Add'
              TabOrder = 1
              OnClick = AddWIs_btnClick
            end
            object ImportWhoIsServers_btn: TButton
              Left = 152
              Top = 240
              Width = 73
              Height = 17
              Caption = 'Import'
              TabOrder = 2
              OnClick = ImportWhoIsServers_btnClick
            end
            object ExportWhoIsServers_btn: TButton
              Left = 224
              Top = 240
              Width = 73
              Height = 17
              Caption = 'Export'
              TabOrder = 3
              OnClick = ExportWhoIsServers_btnClick
            end
            object RemoveWIs_btn: TButton
              Left = 80
              Top = 240
              Width = 65
              Height = 17
              Caption = 'Remove'
              TabOrder = 4
              OnClick = RemoveWIs_btnClick
            end
          end
          object WhoisSend_btn: TButton
            Left = 475
            Top = 392
            Width = 401
            Height = 25
            Anchors = [akTop, akRight]
            Caption = 'Send Query'
            TabOrder = 3
            OnClick = WhoisSend_btnClick
          end
          object WhoIsValidateServers_btn: TButton
            Left = 472
            Top = 360
            Width = 401
            Height = 25
            Caption = 'Validate Servers'
            TabOrder = 4
            OnClick = WhoIsValidateServers_btnClick
          end
        end
        object TabOSDetection: TTabSheet
          Caption = 'OS Detection'
          ImageIndex = 5
          OnShow = TabOSDetectionShow
          DesignSize = (
            881
            426)
          object GroupBox40: TGroupBox
            Left = 472
            Top = 8
            Width = 401
            Height = 65
            Anchors = [akTop, akRight]
            TabOrder = 0
            object StaticText3: TStaticText
              Left = 16
              Top = 24
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clBtnFace
              FocusControl = OSDetectTargetIP_txt
              ParentColor = False
              TabOrder = 1
              OnClick = IPorHost_slbClick
            end
            object OSDetectTargetIP_txt: TEdit
              Left = 232
              Top = 24
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 0
              Text = '127.0.0.1'
            end
          end
          object OSDetect_Memo: TMemo
            Left = 8
            Top = 8
            Width = 433
            Height = 409
            Color = clSilver
            ParentShowHint = False
            PopupMenu = txtBox_Popup
            ReadOnly = True
            ScrollBars = ssVertical
            ShowHint = False
            TabOrder = 1
          end
          object GroupBox41: TGroupBox
            Left = 472
            Top = 80
            Width = 401
            Height = 121
            Caption = 'Scan Type'
            TabOrder = 2
            object RadioButton5: TRadioButton
              Left = 24
              Top = 32
              Width = 89
              Height = 17
              Caption = 'Heuristics'
              TabOrder = 0
            end
            object RadioButton17: TRadioButton
              Left = 24
              Top = 56
              Width = 73
              Height = 17
              Caption = 'Normal'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
            object RadioButton19: TRadioButton
              Left = 24
              Top = 80
              Width = 73
              Height = 17
              Caption = 'Fast'
              TabOrder = 2
            end
            object CheckBox1: TCheckBox
              Left = 192
              Top = 32
              Width = 193
              Height = 17
              Caption = 'Stop as soon as possible.'
              TabOrder = 3
            end
          end
        end
        object TabEMailValidator: TTabSheet
          Caption = 'E-Mail Validator'
          ImageIndex = 6
          OnShow = TabEMailValidatorShow
          object Memo7: TMemo
            Left = 8
            Top = 8
            Width = 409
            Height = 401
            Color = clSilver
            PopupMenu = txtBox_Popup
            ScrollBars = ssVertical
            TabOrder = 0
          end
        end
        object TabSimpleServices: TTabSheet
          Caption = 'Simple services'
          ImageIndex = 7
          OnShow = TabSimpleServicesShow
          object GroupBox5: TGroupBox
            Left = 432
            Top = 8
            Width = 401
            Height = 137
            Caption = 'Services'
            TabOrder = 0
            object Label4: TLabel
              Left = 216
              Top = 80
              Width = 89
              Height = 16
              Caption = '@ remote Port:'
            end
            object SimpleServices_cmb: TComboBox
              Left = 16
              Top = 72
              Width = 193
              Height = 24
              Hint = 'Select Service'
              Style = csDropDownList
              Color = clSilver
              ItemHeight = 16
              TabOrder = 0
              OnChange = SimpleServices_cmbChange
            end
            object SimpleSProtocolTCP_opt: TRadioButton
              Left = 16
              Top = 112
              Width = 113
              Height = 17
              Caption = 'TCP'
              Checked = True
              TabOrder = 1
              TabStop = True
            end
            object RadioButton6: TRadioButton
              Left = 80
              Top = 112
              Width = 57
              Height = 17
              Caption = 'UDP'
              TabOrder = 2
            end
            object SimpleSTargetPort_txt: TEdit
              Left = 312
              Top = 72
              Width = 73
              Height = 24
              Hint = 'Type here target Port used (0=default)'
              AutoSize = False
              Color = clSilver
              TabOrder = 3
              Text = '0'
            end
            object IPHost3_slb: TStaticText
              Left = 16
              Top = 32
              Width = 369
              Height = 24
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = 'Target IP address:'
              Color = clMenu
              FocusControl = SimpleSTargetIP_txt
              ParentColor = False
              TabOrder = 4
              OnClick = IPorHost_slbClick
            end
            object SimpleSTargetIP_txt: TEdit
              Left = 232
              Top = 32
              Width = 153
              Height = 24
              Hint = 'Type here target IP address or HostName.'
              AutoSize = False
              BiDiMode = bdLeftToRight
              Color = clSilver
              ParentBiDiMode = False
              TabOrder = 5
              Text = '127.0.0.1'
            end
          end
          object SimpleS_Memo: TMemo
            Left = 8
            Top = 8
            Width = 409
            Height = 409
            Color = clSilver
            Lines.Strings = (
              '')
            PopupMenu = txtBox_Popup
            TabOrder = 1
          end
          object GroupBox8: TGroupBox
            Left = 432
            Top = 152
            Width = 401
            Height = 113
            Caption = 'Description'
            TabOrder = 2
            object SimpleServiceDesc_slb: TStaticText
              Left = 16
              Top = 32
              Width = 369
              Height = 65
              AutoSize = False
              BorderStyle = sbsSunken
              TabOrder = 0
            end
          end
          object SimpleSConnect_btn: TButton
            Left = 432
            Top = 392
            Width = 401
            Height = 25
            Caption = 'Connect!'
            TabOrder = 3
            OnClick = SimpleSConnect_btnClick
          end
        end
        object TabWWWService: TTabSheet
          Caption = 'HTML Services'
          ImageIndex = 8
          OnShow = TabWWWServiceShow
          object Memo8: TMemo
            Left = 8
            Top = 8
            Width = 441
            Height = 401
            Color = clSilver
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object GroupBox17: TGroupBox
            Left = 464
            Top = 8
            Width = 409
            Height = 169
            Caption = 'GroupBox17'
            TabOrder = 1
          end
        end
        object TabTRScannerService: TTabSheet
          Caption = 'Trojan Scanner'
          ImageIndex = 9
          OnShow = TabTRScannerServiceShow
          DesignSize = (
            881
            426)
          object TrojanListView: TListView
            Left = 8
            Top = 8
            Width = 441
            Height = 409
            Checkboxes = True
            Columns = <
              item
                AutoSize = True
                Caption = 'Trojan Name'
              end
              item
                Alignment = taRightJustify
                AutoSize = True
                Caption = 'default Port'
              end>
            GridLines = True
            Items.Data = {
              970000000400000000000000FFFFFFFFFFFFFFFF00000000000000000C426163
              6B204F72696669636500000000FFFFFFFFFFFFFFFF0000000000000000114261
              636B204F726966696365203230303000000000FFFFFFFFFFFFFFFF0000000000
              000000164461724B20436F6E6E656354696F4E20496E5369446500000000FFFF
              FFFFFFFFFFFF000000000000000008537562536576656E}
            MultiSelect = True
            ReadOnly = True
            RowSelect = True
            SortType = stText
            TabOrder = 0
            ViewStyle = vsReport
          end
          object GroupBox6: TGroupBox
            Left = 467
            Top = 8
            Width = 401
            Height = 137
            Anchors = [akTop, akRight]
            Caption = 'Database'
            TabOrder = 1
            object Label6: TLabel
              Left = 16
              Top = 32
              Width = 30
              Height = 16
              Caption = 'Path:'
            end
            object Label5: TLabel
              Left = 277
              Top = 112
              Width = 108
              Height = 16
              Caption = 'Update Database'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlue
              Font.Height = -13
              Font.Name = 'MS Sans Serif'
              Font.Style = [fsUnderline]
              ParentFont = False
            end
            object StaticText4: TStaticText
              Left = 72
              Top = 32
              Width = 313
              Height = 20
              AutoSize = False
              BorderStyle = sbsSunken
              Caption = '\Data\TRList.db'
              TabOrder = 0
            end
            object TrojanListReflesh_btn: TButton
              Left = 72
              Top = 72
              Width = 145
              Height = 25
              Caption = 'Reflesh List'
              TabOrder = 1
            end
            object Button19: TButton
              Left = 224
              Top = 72
              Width = 161
              Height = 25
              Caption = 'Manage Database'
              TabOrder = 2
            end
          end
          object RadioGroup4: TRadioGroup
            Left = 672
            Top = 152
            Width = 161
            Height = 113
            Caption = 'List ShortCuts'
            TabOrder = 2
          end
          object GroupBox7: TGroupBox
            Left = 467
            Top = 152
            Width = 233
            Height = 113
            Anchors = [akTop, akRight]
            Caption = 'Scanning Type'
            TabOrder = 3
            object RadioButton7: TRadioButton
              Left = 16
              Top = 32
              Width = 161
              Height = 17
              Caption = 'Scan for all Ports.'
              Checked = True
              TabOrder = 0
              TabStop = True
            end
            object RadioButton8: TRadioButton
              Left = 16
              Top = 80
              Width = 201
              Height = 17
              Caption = 'Scan for most common Ports.'
              TabOrder = 1
            end
            object RadioButton9: TRadioButton
              Left = 16
              Top = 56
              Width = 185
              Height = 17
              Caption = 'Scan only selected items.'
              TabOrder = 2
            end
          end
          object RadioButton16: TRadioButton
            Left = 696
            Top = 184
            Width = 113
            Height = 17
            Caption = 'Check common.'
            TabOrder = 4
          end
          object TRCheckAll_opt: TRadioButton
            Left = 696
            Top = 208
            Width = 113
            Height = 17
            Caption = 'Check all'
            TabOrder = 5
            OnClick = TRCheckAll_optClick
          end
          object RadioButton18: TRadioButton
            Left = 696
            Top = 232
            Width = 113
            Height = 17
            Caption = 'Uncheck all.'
            TabOrder = 6
          end
        end
        object TabLANServices: TTabSheet
          Caption = 'LAN'
          ImageIndex = 10
          OnShow = TabLANServicesShow
          DesignSize = (
            881
            426)
          object LANInfo_Memo: TMemo
            Left = 8
            Top = 8
            Width = 449
            Height = 401
            Color = clSilver
            PopupMenu = txtBox_Popup
            ScrollBars = ssVertical
            TabOrder = 0
          end
          object LanInfos_TreeView: TTreeView
            Left = 483
            Top = 40
            Width = 393
            Height = 137
            Anchors = [akTop, akRight]
            AutoExpand = True
            Images = LANImageList
            Indent = 19
            ReadOnly = True
            RowSelect = True
            TabOrder = 1
            Items.Data = {
              0100000027000000000000000000000000000000FFFFFFFF0000000006000000
              0E4C6F63616C20436F6D70757465721E000000010000000B000000FFFFFFFFFF
              FFFFFF000000000000000005496E666F7327000000020000000C000000FFFFFF
              FFFFFFFFFF00000000000000000E45746865726E65742043617264731F000000
              030000000D000000FFFFFFFFFFFFFFFF0000000000000000064472697665731E
              000000040000000E000000FFFFFFFFFFFFFFFF00000000000000000555736572
              731F000000000000000F000000FFFFFFFFFFFFFFFF0000000000000000064772
              6F757073200000000000000010000000FFFFFFFFFFFFFFFF0000000000000000
              0753657276657273}
          end
          object LANReportClean_chk: TCheckBox
            Left = 784
            Top = 184
            Width = 89
            Height = 17
            Alignment = taLeftJustify
            Anchors = [akTop, akRight]
            Caption = 'Auto-Clean.'
            TabOrder = 2
          end
          object GroupBox28: TGroupBox
            Left = 483
            Top = 216
            Width = 393
            Height = 193
            Anchors = [akTop, akRight]
            Caption = 'ShortCuts'
            TabOrder = 3
            object LAN_LocExpl_btn: TButton
              Left = 152
              Top = 24
              Width = 121
              Height = 17
              Caption = 'Local Explorer'
              TabOrder = 6
              OnClick = LAN_LocExpl_btnClick
            end
            object LAN_CPSystem_btn: TButton
              Left = 16
              Top = 24
              Width = 129
              Height = 17
              Caption = 'CP -  System'
              TabOrder = 3
              OnClick = LAN_CPSystem_btnClick
            end
            object Map_btn: TButton
              Left = 280
              Top = 24
              Width = 97
              Height = 17
              Caption = 'Map Drive'
              TabOrder = 0
              OnClick = Map_btnClick
            end
            object unMap_btn: TButton
              Left = 280
              Top = 40
              Width = 97
              Height = 17
              Caption = 'UnMap Drive'
              TabOrder = 1
              OnClick = unMap_btnClick
            end
            object LAN_CPModem_btn: TButton
              Left = 16
              Top = 40
              Width = 129
              Height = 17
              Caption = 'CP -  Modem'
              TabOrder = 2
              OnClick = LAN_CPModem_btnClick
            end
            object LAN_CPInternet_btn: TButton
              Left = 16
              Top = 56
              Width = 129
              Height = 17
              Caption = 'CP -  InterNet'
              TabOrder = 4
              OnClick = LAN_CPInternet_btnClick
            end
            object LAN_IntExpl_btn: TButton
              Left = 152
              Top = 40
              Width = 121
              Height = 17
              Caption = 'InterNet Explorer'
              TabOrder = 5
              OnClick = LAN_IntExpl_btnClick
            end
            object ComboBox1: TComboBox
              Left = 16
              Top = 88
              Width = 361
              Height = 24
              Color = clSilver
              ItemHeight = 16
              TabOrder = 7
              Text = 'ComboBox1'
            end
          end
          object GetLANInfo_Btn: TButton
            Left = 485
            Top = 184
            Width = 281
            Height = 17
            Caption = 'Get LAN Informations'
            TabOrder = 4
            OnClick = GetLANInfo_BtnClick
          end
          object LANComputer_Cmb: TComboBox
            Left = 480
            Top = 8
            Width = 393
            Height = 24
            Color = clSilver
            DropDownCount = 16
            ItemHeight = 16
            MaxLength = 255
            TabOrder = 5
            Text = 'Local Computer'
            OnChange = LANComputer_CmbChange
          end
        end
        object TabICQ: TTabSheet
          Caption = 'ICQ Simple Client'
          ImageIndex = 11
          OnShow = TabICQShow
          object Button6: TButton
            Left = 184
            Top = 136
            Width = 329
            Height = 73
            Caption = 'Enter ICQ MAPI'
            TabOrder = 0
            OnClick = Button6Click
          end
        end
      end
    end
    object Tab_AttackConnection: TTabSheet
      Caption = 'Attack'
      ImageIndex = 4
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 458
        Height = 478
        Align = alClient
        BevelInner = bvLowered
        TabOrder = 0
        object GroupBox44: TGroupBox
          Left = 8
          Top = 8
          Width = 441
          Height = 225
          Caption = 'DLLs Loading'
          TabOrder = 0
          object AttackOpenDLL_img: TImage
            Left = 400
            Top = 32
            Width = 32
            Height = 32
            Picture.Data = {
              055449636F6E0000010001002020040000000000E80200001600000028000000
              2000000040000000010004000000000000020000000000000000000000000000
              0000000000000000000080000080000000808000800000008000800080800000
              C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
              FFFFFF0000000000000000000000000000040000000000000000000000000000
              004EFC0000000000000000000000000004EFEC00000000000000000000000000
              4EFECC00000000000000000000000004EFECC00000000000000000000000004E
              FECC00000000000000000000000004EFECC00000000000000000000000004EFE
              CC00000000000000000000000004EFECC000000000000000000000000087FECC
              000000000000000000000000087F7CC000000000000000887888888008F78800
              000000000000087777000000000880000000000000008777006FEFEFE0000000
              00000000000877706EFEFEFEFE60000000000000008FF706EFEFEFEFEFE60000
              00000000008FF06EFEFFFEFEFEF600000000000008FF06EFEFFFEFEFEFE67000
              0000000008FF06FEFFFEFEFEFEF670000000000008F06FEFFFFFEFEFEFE67000
              0000000008F06EFFFFFEFEFEFEF670000000000008F06FEFFFEFEFEFEFE67000
              0000000008706EFFFFFEFEFEFE6F70000000000008706FEFFFEFEFEFEF6F7000
              0000000000806EFEFFFEFEFEF6FF00000000000000806FEFEFEFEFEF6FFF0000
              00000000000806FEFEFEFEF677F000000000000000000666EFEFE66777000000
              0000000000000088666667777000000000000000000000008888887000000000
              0000000000000000000000000000000000000000000000000000000000000000
              00000000FFFFFFE3FFFFFFC1FFFFFF81FFFFFF01FFFFFE03FFFFFC07FFFFF80F
              FFFFF01FFFFFE03FFFFFC07FFF0180FFFC0001FFF80003FFF00007FFE00007FF
              C00007FFC00007FF800003FF800003FF800003FF800003FF800003FF800003FF
              800003FFC00007FFC00007FFE0000FFFF0001FFFF8003FFFFC007FFFFF01FFFF
              FFFFFFFF}
            OnClick = AttackOpenDLL_imgClick
          end
          object AttackLoadDLLDir_img: TImage
            Left = 400
            Top = 176
            Width = 32
            Height = 32
            Picture.Data = {
              055449636F6E0000010001002020040000000000E80200001600000028000000
              2000000040000000010004000000000000020000000000000000000000000000
              0000000000000000000080000080000000808000800000008000800080800000
              C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
              FFFFFF0000000000000000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000000000000000
              00000000000833333333333333333333333333300008B7B7B7B7B7B7B7B7B7B7
              B7B7B73000087B7B7B7B7B7B7B7B7B7B7B7B7B300087B7B7B7B7B7B7B7B7B7B7
              B7B7B700008B7B7B7B7B7B7B7B7B7B7B7B7B77000087B7B7B7B7B7B7B7B7B7B7
              B7B7B800008B7B7B7B7B7B7B7B7B7B7B7B7B780008B7B7B7B7B7B7B7B7B7B7B7
              B7B7B030087B7B7B7B7B7B7B7B7B7B7B7B7B703008B7B7B7B7B7B7B7B7B7B7B7
              B7B78030087B7B7B7B7B7B7B7B7B7B7B7B7B803087B7B7B7B7B7B7B7B7B7B7B7
              B7B708308B7B7B7B7B7B7B7B7B7B7B7B7B7B083087B7B7B7B7B7B7B7B7B7B7B7
              B7B80B308B7B7B7B7B7B7B7B7B7B7B7B7B7807308FFFFFFFFFFFFFFFFFFFFFFF
              FFF08B300887777777777777777777777777B7300008FB7B7B7B7B7B7B7B7B7B
              7B7B7B300008F7B7B7B7B7B7B7B7B7B7B7B7B7300008FB7B7B7B7B7B7B7B7B7B
              7B7B7B300008F7B7B7B7B7B7B7BFFFFFFFFFFF000008FB7B7B7B7B7B7B788888
              8888880000008FB7B7B7B7B7B780000000000000000008FB7B7B7B7B78000000
              000000000000008FFFFFFFFF8000000000000000000000088888888800000000
              0000000000000000000000000000000000000000000000000000000000000000
              00000000FFFFFFFFFFFFFFFFFFFFFFFFF0000001E0000000E0000000E0000000
              C0000000C0000000C0000000C000000080000000800000008000000080000000
              000000000000000000000000000000000000000080000000E0000000E0000000
              E0000000E0000001E0000003F0001FFFF8003FFFFC007FFFFE00FFFFFFFFFFFF
              FFFFFFFF}
            OnClick = AttackLoadDLLDir_imgClick
          end
          object AttackLoadDLLList_img: TImage
            Left = 400
            Top = 136
            Width = 32
            Height = 32
            Picture.Data = {
              055449636F6E0000010001002020100000000000E80200001600000028000000
              2000000040000000010004000000000080020000000000000000000000000000
              0000000000000000000080000080000000808000800000008000800080800000
              C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
              FFFFFF0000000000000008888888888888888000000000000000000000000000
              000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
              FFF080000000000000000F8788788788FFF0800000000008888807777777777F
              FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
              FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
              FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
              FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
              FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
              FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
              FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
              000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
              000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
              000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
              BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
              00000000000000000000000000FF0000000000000000000000000000000F0000
              0000000000000000000000000000000000000000000000000000000000000000
              00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
              FC000007FC000007FC0000078000000700000007000000070000000700000007
              0000000700000007000000070000000F000001FF000001FF000001FF00000003
              0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
              FFFFF7FF}
            OnClick = AttackLoadDLLList_imgClick
          end
          object AttackDLLs_lbx: TListBox
            Left = 16
            Top = 64
            Width = 377
            Height = 145
            Hint = 'Click for Select, Double Click for Execute'
            Color = clSilver
            ItemHeight = 16
            ParentShowHint = False
            PopupMenu = txtBox_Popup
            ShowHint = False
            TabOrder = 0
            OnDblClick = AttackLoadDLL_btnClick
          end
          object AttackDLLPath_stb: TStaticText
            Left = 16
            Top = 32
            Width = 377
            Height = 20
            Alignment = taRightJustify
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = 'commands file (one for each line)'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsItalic]
            ParentFont = False
            TabOrder = 1
          end
        end
        object GroupBox45: TGroupBox
          Left = 8
          Top = 272
          Width = 441
          Height = 193
          Caption = 'Avaiable Functions'
          TabOrder = 1
          object AttackFunctions_lbx: TListBox
            Left = 16
            Top = 24
            Width = 377
            Height = 153
            Color = clSilver
            ItemHeight = 16
            TabOrder = 0
            OnClick = AttackFunctions_lbxClick
          end
        end
        object AttackLoadDLL_btn: TButton
          Left = 24
          Top = 240
          Width = 185
          Height = 25
          Caption = 'Load'
          TabOrder = 2
          OnClick = AttackLoadDLL_btnClick
        end
        object AttackUnloadDLL_btn: TButton
          Left = 216
          Top = 240
          Width = 185
          Height = 25
          Caption = 'Unload'
          TabOrder = 3
          OnClick = AttackUnloadDLL_btnClick
        end
      end
      object Panel4: TPanel
        Left = 458
        Top = 0
        Width = 431
        Height = 478
        Align = alRight
        TabOrder = 1
        object GroupBox10: TGroupBox
          Left = 14
          Top = 8
          Width = 401
          Height = 97
          TabOrder = 0
          object StaticText8: TStaticText
            Left = 16
            Top = 24
            Width = 369
            Height = 24
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = 'Target IP address:'
            Color = clBtnFace
            FocusControl = AttackTargetIP_txt
            ParentColor = False
            TabOrder = 1
            OnClick = IPorHost_slbClick
          end
          object AttackTargetIP_txt: TEdit
            Left = 232
            Top = 24
            Width = 153
            Height = 24
            Hint = 'Type here target IP address or HostName.'
            AutoSize = False
            BiDiMode = bdLeftToRight
            Color = clSilver
            ParentBiDiMode = False
            TabOrder = 0
            Text = '212.212.212.212'
          end
          object StaticText9: TStaticText
            Left = 16
            Top = 56
            Width = 369
            Height = 24
            AutoSize = False
            BorderStyle = sbsSunken
            Caption = 'Target Port:'
            Color = clMenu
            ParentColor = False
            TabOrder = 2
          end
          object AttackTargetPort_txt: TEdit
            Left = 344
            Top = 56
            Width = 41
            Height = 24
            Hint = 'Type here target Port used (0=default)'
            AutoSize = False
            BiDiMode = bdLeftToRight
            Color = clSilver
            ParentBiDiMode = False
            TabOrder = 3
            Text = '13'
          end
        end
        object GroupBox46: TGroupBox
          Left = 16
          Top = 112
          Width = 401
          Height = 137
          Caption = 'Service'#39's Description'
          TabOrder = 1
          object AttackFunctionDesc_stb: TStaticText
            Left = 16
            Top = 32
            Width = 369
            Height = 81
            AutoSize = False
            BorderStyle = sbsSunken
            TabOrder = 0
          end
        end
        object AttackConnect_btn: TButton
          Left = 16
          Top = 440
          Width = 201
          Height = 25
          Caption = 'Connect'
          TabOrder = 2
          OnClick = AttackConnect_btnClick
        end
        object Button8: TButton
          Left = 216
          Top = 440
          Width = 201
          Height = 25
          Caption = 'Services on remote IP'
          TabOrder = 3
        end
        object Attack_Memo: TMemo
          Left = 16
          Top = 256
          Width = 401
          Height = 177
          Color = clSilver
          TabOrder = 4
        end
      end
    end
    object Tab_ActiveConnection: TTabSheet
      Caption = 'Active Connections'
      ImageIndex = 5
    end
    object Tab_Servers: TTabSheet
      Caption = 'Local Servers'
      ImageIndex = 6
      object GroupBox9: TGroupBox
        Left = 8
        Top = 8
        Width = 353
        Height = 185
        Caption = 'Server Options'
        TabOrder = 0
        object Label11: TLabel
          Left = 16
          Top = 40
          Width = 41
          Height = 16
          AutoSize = False
          Caption = 'Start a'
        end
        object Label12: TLabel
          Left = 296
          Top = 40
          Width = 48
          Height = 16
          AutoSize = False
          Caption = 'server'
        end
        object Label13: TLabel
          Left = 16
          Top = 80
          Width = 37
          Height = 16
          Caption = 'at port'
        end
        object LocalServer_cmb: TComboBox
          Left = 64
          Top = 32
          Width = 225
          Height = 24
          Style = csDropDownList
          Color = clSilver
          ItemHeight = 16
          TabOrder = 0
          OnChange = LocalServer_cmbChange
          Items.Strings = (
            'FTP Server'
            'AnonyProxy Server'
            'Echo Server')
        end
        object Edit10: TEdit
          Left = 64
          Top = 72
          Width = 73
          Height = 24
          AutoSize = False
          Color = clSilver
          TabOrder = 1
        end
        object Button26: TButton
          Left = 16
          Top = 128
          Width = 161
          Height = 33
          Caption = 'Start Server'
          TabOrder = 2
        end
        object Button27: TButton
          Left = 176
          Top = 128
          Width = 161
          Height = 33
          Caption = 'Stop Server'
          TabOrder = 3
        end
        object Button32: TButton
          Left = 176
          Top = 72
          Width = 161
          Height = 25
          Caption = 'Server Options'
          TabOrder = 4
        end
      end
      object GroupBox12: TGroupBox
        Left = 8
        Top = 200
        Width = 353
        Height = 257
        Caption = 'Servers Selection'
        TabOrder = 1
        object ListView1: TListView
          Left = 16
          Top = 24
          Width = 313
          Height = 217
          Color = clSilver
          Columns = <>
          TabOrder = 0
        end
      end
      object GroupBox15: TGroupBox
        Left = 368
        Top = 8
        Width = 481
        Height = 449
        Caption = 'Server Status'
        TabOrder = 2
        object Memo2: TMemo
          Left = 16
          Top = 24
          Width = 449
          Height = 409
          Color = clSilver
          TabOrder = 0
        end
      end
    end
    object Tab_Terminal: TTabSheet
      Caption = 'Terminal'
      ImageIndex = 7
      DesignSize = (
        889
        478)
      object TConsole_Memo: TMemo
        Left = 8
        Top = 8
        Width = 569
        Height = 425
        Color = clBlack
        DragMode = dmAutomatic
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -15
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        PopupMenu = Terminal_PopMnu
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object Term_Cmd_grp: TGroupBox
        Left = 587
        Top = 88
        Width = 297
        Height = 305
        Anchors = [akTop, akRight]
        Caption = 'Load Commands List'
        TabOrder = 1
        object OpenCmdList_img: TImage
          Left = 256
          Top = 32
          Width = 32
          Height = 32
          Hint = 'Load List..'
          AutoSize = True
          Center = True
          Picture.Data = {
            055449636F6E0000010001002020100000000000E80200001600000028000000
            2000000040000000010004000000000080020000000000000000000000000000
            0000000000000000000080000080000000808000800000008000800080800000
            C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
            FFFFFF0000000000000008888888888888888000000000000000000000000000
            000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
            FFF080000000000000000F8788788788FFF0800000000008888807777777777F
            FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
            FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
            FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
            FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
            FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
            FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
            FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
            000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
            000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
            000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
            BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
            00000000000000000000000000FF0000000000000000000000000000000F0000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
            FC000007FC000007FC0000078000000700000007000000070000000700000007
            0000000700000007000000070000000F000001FF000001FF000001FF00000003
            0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
            FFFFF7FF}
          Stretch = True
          OnClick = OpenCmdList_imgClick
        end
        object TerminalCmdPath_slb: TStaticText
          Left = 8
          Top = 32
          Width = 241
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          BorderStyle = sbsSunken
          Caption = 'commands file (one for each line)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsItalic]
          ParentFont = False
          TabOrder = 0
        end
        object TerminalCmdList_lbx: TListBox
          Left = 8
          Top = 64
          Width = 281
          Height = 177
          Hint = 'Click for Select, Double Click for Execute'
          Color = clSilver
          ItemHeight = 16
          ParentShowHint = False
          PopupMenu = txtBox_Popup
          ShowHint = False
          TabOrder = 1
          OnClick = TerminalCmdList_lbxClick
          OnDblClick = TerminalCmdList_lbxDblClick
        end
        object Term_FileOpt_btn: TButton
          Left = 160
          Top = 248
          Width = 129
          Height = 17
          Caption = 'File Options'
          TabOrder = 2
          OnClick = Term_FileOpt_btnClick
        end
        object TermSendListCmds_btn: TButton
          Left = 8
          Top = 248
          Width = 137
          Height = 17
          Caption = 'Send All Commands'
          TabOrder = 3
          OnClick = TermSendListCmds_btnClick
        end
        object TermLCmdSync_chk: TCheckBox
          Left = 8
          Top = 272
          Width = 281
          Height = 17
          Caption = 'Syncronise command box with selected item.'
          Checked = True
          State = cbChecked
          TabOrder = 4
        end
      end
      object TermConnect_btn: TButton
        Left = 584
        Top = 408
        Width = 145
        Height = 25
        Caption = 'Connect'
        TabOrder = 2
        OnClick = TermConnect_btnClick
      end
      object Button21: TButton
        Left = 584
        Top = 440
        Width = 297
        Height = 25
        Caption = 'Services on remote IP'
        TabOrder = 3
      end
      object GroupBox11: TGroupBox
        Left = 587
        Top = 0
        Width = 297
        Height = 81
        Anchors = [akTop, akRight]
        Caption = 'Connection Setting'
        TabOrder = 4
        object Label7: TLabel
          Left = 208
          Top = 40
          Width = 23
          Height = 16
          Caption = 'port'
        end
        object Label8: TLabel
          Left = 16
          Top = 40
          Width = 12
          Height = 16
          Caption = 'IP'
        end
        object TermTargetIP_txt: TEdit
          Left = 40
          Top = 32
          Width = 153
          Height = 24
          Hint = 'Type here target IP address or HostName.'
          AutoSize = False
          BiDiMode = bdLeftToRight
          Color = clSilver
          ParentBiDiMode = False
          TabOrder = 0
          Text = '127.0.0.1'
        end
        object TermTargetPort_txt: TEdit
          Left = 240
          Top = 32
          Width = 41
          Height = 24
          AutoSize = False
          BiDiMode = bdLeftToRight
          Color = clSilver
          ParentBiDiMode = False
          ParentShowHint = False
          ShowHint = False
          TabOrder = 1
          Text = '23'
        end
      end
      object TermDisconnect_btn: TButton
        Left = 736
        Top = 408
        Width = 145
        Height = 25
        Caption = 'Disconnect'
        TabOrder = 5
        OnClick = TermDisconnect_btnClick
      end
      object TConsole_cmb: TComboBox
        Left = 8
        Top = 440
        Width = 569
        Height = 25
        Color = clBlack
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clLime
        Font.Height = -15
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 17
        ParentFont = False
        TabOrder = 6
        OnKeyPress = TConsole_cmbKeyPress
      end
    end
    object Tab_ShortCuts: TTabSheet
      Caption = 'ShortCuts'
      ImageIndex = 8
      DesignSize = (
        889
        478)
      object ShortCutsListView: TListView
        Left = 8
        Top = 8
        Width = 569
        Height = 457
        Columns = <
          item
            AutoSize = True
            Caption = 'Application'
          end
          item
            Alignment = taRightJustify
            AutoSize = True
            Caption = 'Command Path'
          end>
        FlatScrollBars = True
        GridLines = True
        Items.Data = {
          5D0000000300000000000000FFFFFFFFFFFFFFFF00000000000000000D436F6E
          74726F6C2050616E656C00000000FFFFFFFFFFFFFFFF00000000000000000346
          545000000000FFFFFFFFFFFFFFFF00000000000000000654656C6E6574}
        PopupMenu = ShortCutsList_PopMnu
        SortType = stText
        TabOrder = 0
        ViewStyle = vsReport
        OnSelectItem = ShortCutsListViewSelectItem
      end
      object ShortCutsListGroup: TGroupBox
        Left = 587
        Top = 0
        Width = 297
        Height = 105
        Anchors = [akTop, akRight]
        Caption = 'Manage list'
        TabOrder = 1
        object ShortCutOpenList_img: TImage
          Left = 248
          Top = 32
          Width = 32
          Height = 32
          Hint = 'Open List..'
          AutoSize = True
          Center = True
          Picture.Data = {
            055449636F6E0000010001002020100000000000E80200001600000028000000
            2000000040000000010004000000000080020000000000000000000000000000
            0000000000000000000080000080000000808000800000008000800080800000
            C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
            FFFFFF0000000000000008888888888888888000000000000000000000000000
            000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
            FFF080000000000000000F8788788788FFF0800000000008888807777777777F
            FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
            FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
            FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
            FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
            FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
            FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
            FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
            000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
            000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
            000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
            BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
            00000000000000000000000000FF0000000000000000000000000000000F0000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
            FC000007FC000007FC0000078000000700000007000000070000000700000007
            0000000700000007000000070000000F000001FF000001FF000001FF00000003
            0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
            FFFFF7FF}
          OnClick = ShortCutOpenList_imgClick
        end
        object ShortCutsListFileOpt_btn: TButton
          Left = 16
          Top = 64
          Width = 225
          Height = 17
          Caption = 'File Options'
          TabOrder = 0
          OnClick = ShortCutsListFileOpt_btnClick
        end
        object ShortCutsFileList_slb: TStaticText
          Left = 16
          Top = 32
          Width = 225
          Height = 20
          Alignment = taRightJustify
          AutoSize = False
          BorderStyle = sbsSunken
          TabOrder = 1
        end
      end
      object Button25: TButton
        Left = 584
        Top = 440
        Width = 145
        Height = 25
        Caption = 'Save'
        TabOrder = 2
      end
      object GroupBox29: TGroupBox
        Left = 587
        Top = 112
        Width = 297
        Height = 161
        Anchors = [akTop, akRight]
        Caption = 'Add Item'
        TabOrder = 3
        object ShortCutOpenItemPath_img: TImage
          Left = 248
          Top = 80
          Width = 32
          Height = 32
          Hint = 'Import Application path..'
          AutoSize = True
          Center = True
          Picture.Data = {
            055449636F6E0000010001002020100000000000E80200001600000028000000
            2000000040000000010004000000000080020000000000000000000000000000
            0000000000000000000080000080000000808000800000008000800080800000
            C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
            FFFFFF0000000000000008888888888888888000000000000000000000000000
            000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
            FFF080000000000000000F8788788788FFF0800000000008888807777777777F
            FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
            FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
            FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
            FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
            FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
            FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
            FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
            000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
            000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
            000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
            BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
            00000000000000000000000000FF0000000000000000000000000000000F0000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
            FC000007FC000007FC0000078000000700000007000000070000000700000007
            0000000700000007000000070000000F000001FF000001FF000001FF00000003
            0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
            FFFFF7FF}
          OnClick = ShortCutOpenItemPath_imgClick
        end
        object ShortCutName_txt: TEdit
          Left = 16
          Top = 32
          Width = 265
          Height = 24
          AutoSize = False
          Color = clSilver
          TabOrder = 0
        end
        object CheckBox2: TCheckBox
          Left = 16
          Top = 128
          Width = 169
          Height = 17
          Caption = 'Enable Drag and Drop.'
          Enabled = False
          TabOrder = 1
        end
        object AddShortCut_btn: TButton
          Left = 192
          Top = 128
          Width = 91
          Height = 17
          Caption = 'Add'
          TabOrder = 2
          OnClick = AddShortCut_btnClick
        end
        object ShortCutPath_txt: TEdit
          Left = 16
          Top = 80
          Width = 225
          Height = 24
          AutoSize = False
          Color = clSilver
          TabOrder = 3
        end
      end
      object GroupBox39: TGroupBox
        Left = 584
        Top = 280
        Width = 297
        Height = 73
        Caption = 'Command Prompt'
        TabOrder = 4
        object ShortCutsCommandP_txt: TEdit
          Left = 16
          Top = 32
          Width = 265
          Height = 24
          AutoSize = False
          Color = clSilver
          TabOrder = 0
          OnKeyPress = ShortCutsCommandP_txtKeyPress
        end
      end
    end
    object Tab_References: TTabSheet
      Caption = 'References'
      ImageIndex = 9
      object Label1: TLabel
        Left = 804
        Top = 328
        Width = 45
        Height = 16
        Caption = 'Update'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object Ref_ListView: TListView
        Left = 8
        Top = 8
        Width = 569
        Height = 457
        Checkboxes = True
        Columns = <
          item
            AutoSize = True
            Caption = 'FileName'
          end
          item
            AutoSize = True
            Caption = 'Title'
          end>
        FlatScrollBars = True
        GridLines = True
        Items.Data = {
          780000000400000000000000FFFFFFFFFFFFFFFF000000000000000007524643
          3030303100000000FFFFFFFFFFFFFFFF00000000000000000752464330313532
          00000000FFFFFFFFFFFFFFFF0000000000000000075246433035353500000000
          FFFFFFFFFFFFFFFF00000000000000000752464330363636}
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnClick = Ref_ListViewClick
        OnSelectItem = Ref_ListViewSelectItem
      end
      object GroupBox2: TGroupBox
        Left = 592
        Top = 0
        Width = 297
        Height = 153
        Caption = 'Settings'
        TabOrder = 1
        object Label2: TLabel
          Left = 16
          Top = 32
          Width = 124
          Height = 16
          Caption = 'Files are locaded in :'
        end
        object Image1: TImage
          Left = 248
          Top = 56
          Width = 32
          Height = 32
          Hint = 'Open List..'
          AutoSize = True
          Center = True
          Picture.Data = {
            055449636F6E0000010001002020100000000000E80200001600000028000000
            2000000040000000010004000000000080020000000000000000000000000000
            0000000000000000000080000080000000808000800000008000800080800000
            C0C0C000808080000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000
            FFFFFF0000000000000008888888888888888000000000000000000000000000
            000080000000000000000FFFFFFFFFFFFFF080000000000000000FFFFFFFFFFF
            FFF080000000000000000F8788788788FFF0800000000008888807777777777F
            FFF0800000000000000000000000008888F080000000000FFFFFFFFFFFFFF07F
            FFF080000000000FFFFFFFFFFFFFF08788F080000000000F8788788788FFF07F
            FFF0800008888807777777777FFFF08878F0800000000000000000008888F07F
            FFF080000FFFFFFFFFFFFFF07FFFF088FFF080000FFFFFFFFFFFFFF08788F07F
            FFF080000F788787877888F07FFFF08878F080000FFFFFFFFFFFFFF088FFF07F
            FFF080000F888787878788F07FFFF08788F080000FFFFFFFFFFFFFF08788F07F
            FFF080000FF77887878878F07FFF0000000000000FFFFFFFFFFFFFF088700080
            000000000F8788778788FFF07F000080000000000FFFFFFFFFFFFFF080030080
            000000000F788878777788F0003B0000000008000FFFFFFFFFFFFFF003BB0000
            000008000F878788787878003BBB3333333308000FFFFFFFFFFFFF0FFBBBBBBB
            BBBB08000FFF8887878788F0FFBBFFFFFFFB08000FFFFFFFFFFFFFF00FFB0000
            00000000000000000000000000FF0000000000000000000000000000000F0000
            0000000000000000000000000000000000000000000000000000000000000000
            00000000FFF80007FFF00007FFF00007FFF00007FFF00007FE000007FC000007
            FC000007FC000007FC0000078000000700000007000000070000000700000007
            0000000700000007000000070000000F000001FF000001FF000001FF00000003
            0000000300000003000000030000000300000007000087FFFFFFC7FFFFFFE7FF
            FFFFF7FF}
          OnClick = ShortCutOpenList_imgClick
        end
        object RFCFiles_Ed: TEdit
          Left = 16
          Top = 56
          Width = 225
          Height = 24
          Color = clSilver
          TabOrder = 0
          Text = '\RFC\'
          OnDblClick = RFCFiles_EdDblClick
        end
        object RFCRefleshList_btn: TButton
          Left = 152
          Top = 104
          Width = 129
          Height = 25
          Caption = 'Reflesh List'
          TabOrder = 1
          OnClick = RFCRefleshList_btnClick
        end
        object RFCManageFiles_btn: TButton
          Left = 16
          Top = 104
          Width = 129
          Height = 25
          Caption = 'Manage Files'
          TabOrder = 2
          OnClick = RFCManageFiles_btnClick
        end
      end
      object GroupBox38: TGroupBox
        Left = 592
        Top = 160
        Width = 297
        Height = 153
        Caption = 'Search'
        TabOrder = 2
        object RadioButton3: TRadioButton
          Left = 16
          Top = 72
          Width = 153
          Height = 17
          Caption = 'in Database (Titles)'
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object RadioButton4: TRadioButton
          Left = 192
          Top = 72
          Width = 89
          Height = 17
          Alignment = taLeftJustify
          Caption = 'in each File'
          TabOrder = 1
        end
        object Edit3: TEdit
          Left = 16
          Top = 32
          Width = 265
          Height = 24
          Color = clSilver
          TabOrder = 2
        end
        object Button9: TButton
          Left = 16
          Top = 104
          Width = 121
          Height = 25
          Caption = 'Go!'
          TabOrder = 3
        end
        object Button10: TButton
          Left = 160
          Top = 104
          Width = 121
          Height = 25
          Caption = 'Stop!'
          TabOrder = 4
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 569
    Width = 897
    Height = 19
    Panels = <
      item
        Bevel = pbNone
        Text = 'Status'
        Width = 50
      end
      item
        Text = 'Not Connected'
        Width = 100
      end
      item
        Bevel = pbNone
        Style = psOwnerDraw
        Width = 50
      end
      item
        Bevel = pbNone
        Text = 'Active Connections'
        Width = 130
      end
      item
        Text = 'None'
        Width = 50
      end
      item
        Bevel = pbNone
        Style = psOwnerDraw
        Width = 50
      end>
    SimplePanel = False
  end
  object MainMenu: TMainMenu
    Images = MenuImageList
    Left = 792
    Top = 8
    object File1: TMenuItem
      Caption = '&Application'
      object Upgrades1: TMenuItem
        Caption = '&Upgrades'
        ImageIndex = 2
      end
      object ReportBugs1: TMenuItem
        Caption = '&Report Bugs'
        ImageIndex = 4
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object ShowLog_mnu: TMenuItem
        Caption = 'Show &Log'
        ImageIndex = 3
        OnClick = ShowLog_mnuClick
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'E&xit'
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      object N3: TMenuItem
        Caption = '-'
      end
      object CopyIP1: TMenuItem
        Caption = 'Copy IP'
      end
      object PasteIP1: TMenuItem
        Caption = 'Paste IP'
      end
      object N4: TMenuItem
        Caption = '-'
      end
    end
    object Connections1: TMenuItem
      Caption = 'Connections'
    end
    object Windows1: TMenuItem
      Caption = 'Windows'
      object WinMain_Mnu: TMenuItem
        Caption = 'main'
        Checked = True
        OnClick = WinMain_MnuClick
      end
      object TrayIcon_Mnu: TMenuItem
        Caption = 'TrayIcon'
        OnClick = TrayIcon_MnuClick
      end
      object N5: TMenuItem
        Caption = '-'
      end
      object WinShortcuts_Mnu: TMenuItem
        Caption = 'Shortcuts'
        OnClick = WinShortcuts_MnuClick
      end
      object WinTerminal_Mnu: TMenuItem
        Caption = 'Terminal'
        ImageIndex = 1
        OnClick = WinTerminal_MnuClick
      end
      object WinActiveConnections_Mnu: TMenuItem
        Caption = 'Active Connections'
        ImageIndex = 5
      end
      object N6: TMenuItem
        Caption = '-'
      end
      object Loaddesktop1: TMenuItem
        Caption = 'Load desktop'
        object default1: TMenuItem
          Caption = 'default'
        end
        object DesktopLastSaved_Mnu: TMenuItem
          Caption = 'Last saved'
          OnClick = DesktopLastSaved_MnuClick
        end
      end
      object SaveDesktop_Btn: TMenuItem
        Caption = 'Save desktop'
        OnClick = SaveDesktop_BtnClick
      end
    end
    object About1: TMenuItem
      Caption = 'A&bout'
      object IPDetective1: TMenuItem
        Caption = 'IP &Detective'
        OnClick = IPDetective1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object SurfeWorld: TMenuItem
        Caption = 'Surf eWorld Network'
        OnClick = SurfeWorldClick
      end
    end
  end
  object OpenDialog: TOpenDialog
    Left = 824
    Top = 8
  end
  object SaveDialog: TSaveDialog
    Left = 824
    Top = 24
  end
  object ShortCutsList_PopMnu: TPopupMenu
    MenuAnimation = [maRightToLeft, maTopToBottom]
    Left = 760
    Top = 8
    object Update1: TMenuItem
      Caption = 'Update'
    end
    object MenuItem1: TMenuItem
      Caption = '-'
    end
    object Style1: TMenuItem
      Caption = 'Style'
      object SmallIcons1: TMenuItem
        Caption = 'SmallIcons'
      end
      object Icons1: TMenuItem
        Caption = 'Icons'
      end
      object List1: TMenuItem
        Caption = 'List'
      end
      object Report1: TMenuItem
        Caption = 'Report'
        Checked = True
      end
    end
    object MenuItem2: TMenuItem
      Caption = '-'
    end
  end
  object Terminal_PopMnu: TPopupMenu
    MenuAnimation = [maRightToLeft, maTopToBottom]
    Left = 760
    Top = 24
    object MenuItem3: TMenuItem
      Caption = 'Update'
    end
    object MenuItem4: TMenuItem
      Caption = '-'
    end
    object MenuItem5: TMenuItem
      Caption = 'Style'
      object TerminalFont_mnu: TMenuItem
        Caption = 'Font'
        OnClick = TerminalFont_mnuClick
      end
      object TerminalColor_mnu: TMenuItem
        Caption = 'Color'
        OnClick = TerminalColor_mnuClick
      end
    end
    object MenuItem10: TMenuItem
      Caption = '-'
    end
    object MenuItem11: TMenuItem
      Caption = 'Save to file..'
    end
  end
  object Ticon_PopupMnu: TPopupMenu
    Left = 736
    Top = 8
    object Properties1: TMenuItem
      Caption = '&Windows'
      object WinTerminal_Mnu2: TMenuItem
        Caption = '&Terminal'
        OnClick = WinTerminal_MnuClick
      end
      object WinShortcuts_Mnu2: TMenuItem
        Caption = '&ShortCuts'
        OnClick = WinShortcuts_MnuClick
      end
      object WinActiveConn_Mnu2: TMenuItem
        Caption = 'Active &Connections'
        OnClick = WinActiveConn_MnuClick
      end
    end
    object N7: TMenuItem
      Caption = '-'
    end
    object Shutdown_Mnu: TMenuItem
      Caption = '&Shutdown'
      OnClick = Shutdown_MnuClick
    end
  end
  object txtBox_Popup: TPopupMenu
    Left = 736
    Top = 24
    object Find_Log_mnu: TMenuItem
      Caption = 'Find..'
      OnClick = Find_Log_mnuClick
    end
    object N11: TMenuItem
      Caption = '-'
    end
    object ClearLog_mnu: TMenuItem
      Caption = '&Clear'
      OnClick = ClearLog_mnuClick
    end
    object N8: TMenuItem
      Caption = '-'
    end
    object SaveLogtoFile_mnu: TMenuItem
      Caption = 'Save to File'
      OnClick = SaveLogtoFile_mnuClick
    end
  end
  object MenuImageList: TImageList
    Left = 792
    Top = 24
    Bitmap = {
      494C010106000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
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
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00800000008080800000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF008080
      8000000000008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF0000000000FFFFFF00FFFF
      FF00FFFFFF00800000008080800000FFFF00FF000000FF000000FF000000FF00
      0000FF000000FF000000FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000080808000FFFFFF00FFFFFF00FFFF
      FF00808080000000000080808000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FF0000008080800000FFFF00FF000000FF000000FF000000FF00
      0000FF000000FF000000FFFFFF00000000000000000000000000000000000000
      00000000000080808000000000000000000080808000FFFFFF0080808000C0C0
      C000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00000000000000
      0000FFFFFF00FF0000008080800000FFFF00FF000000FF000000FF000000FF00
      0000FF000000FF000000FFFFFF00000000000000000000000000FFFFFF008080
      8000000000008080800000000000808080000000000080808000000000000080
      0000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      800080808000FF0000008080800000FFFF00FFFFFF0000FFFF00000000000000
      0000FFFFFF0000FFFF00FFFFFF000000000080808000FFFFFF00FFFFFF00FFFF
      FF00808080000000000080808000808080000000000080808000000000000080
      0000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000FF000000FF00
      0000C0C0C000808000008080800000FFFF00FFFFFF0080800000FF000000FF00
      00008000000000FFFF00FFFFFF000000000080808000FFFFFF0080808000C0C0
      C000000000008080800080808000000000000000000080808000000000008080
      8000FFFFFF008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000FF0000000080
      000000800000008000008080800000FFFF00FFFFFF0080800000C0C0C0008000
      00008000000000FFFF00FFFFFF00000000000000000080808000000000008080
      0000000000008080800080808000000000000000000080808000FFFFFF008080
      8000808080008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF0000800000008000008080800000FFFF00FFFFFF0000FFFF00808080000080
      0000FFFFFF0000FFFF00FFFFFF00000000000000000080808000000000008080
      00000000000080808000808080000000000000000000C0C0C000C0C0C0000000
      0000000000008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080800000FFFFFF00FFFFFF00FFFF
      FF0000800000008000008080800000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF0080808000FFFFFF0080808000000000000000000080808000000000008080
      8000FFFFFF008080800000000000000000000000000000000000FFFFFF008080
      8000000000008080800000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF000080
      0000FF000000FF0000008080800000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF00808080008080800080000000000000000000000080808000FFFFFF008080
      80008080800080808000000000000000000080808000FFFFFF00FFFFFF00FFFF
      FF00808080000000000080808000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080808000C0C0C000FFFFFF00FFFF
      FF0000800000FF0000008080800000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
      FF00808080008000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080808000FFFFFF0080808000C0C0
      C000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00C0C0C000FFFF
      FF00008000000080000000800000008000000080000000800000008000000080
      0000800000008000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000008000
      0000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000080000000800000008000000080000000800000008000000080
      0000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000008000
      0000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF0080800000FFFFFF00FF000000008000000080000000800000008000000080
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000008080
      8000FFFFFF008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080800000808000008080000080800000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000FFFFFF008080
      8000808080008080800000000000000000000000000000000000000000000000
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
      000080808000C0C0C00000800000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C00000000000000000008080800080808000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      000080808000C0C0C000C0C0C000C0C0C000C0C0C00080808000808080008080
      800080808000C0C0C00080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C0000000
      0000C0C0C0000000000000000000C0C0C00080808000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000008000
      0000800000008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00C0C0
      C000C0C0C0000000000000000000C0C0C000C0C0C00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C0000000
      0000000000000000000000000000000000000000000000000000FF000000FF00
      0000FF00000080808000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000080808000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C0000000
      000000000000000000008080800000000000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080800000FF000000FF00
      0000FF0000008080800080808000800000008000000080000000800000008000
      0000C0C0C0008080800000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000080808000C0C0
      C00000000000000000000000000000000000C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C000C0C0C000C0C0C00080808000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000808080008080800000000000000000008080800000800000FF000000FF00
      0000FF0000008080800080808000FF000000FF000000FF000000FF0000008000
      0000C0C0C0008080800000000000000000000000000000000000000000000000
      000080808000FFFFFF00FFFFFF000000000000000000C0C0C000FFFFFF000000
      000080808000C0C0C0000000000000000000C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000C0C0C000808080000000000000000000C0C0C000C0C0C000FF000000FF00
      0000C0C0C0008080800080808000FF000000FF000000FF000000FF0000008000
      0000C0C0C0008080800000000000000000000000000000000000000000008080
      8000FFFFFF00FFFFFF00FFFFFF00C0C0C000C0C0C000FFFFFF0080808000FFFF
      FF00FFFFFF00000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C00080808000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000C0C0C000808080008080800000000000C0C0C000C0C0C000FF0000000080
      0000008000008080800080808000000000000000000000000000000000008000
      0000C0C0C000808080000000000000000000000000000000000080808000FFFF
      FF00FFFFFF00FFFFFF00C0C0C000C0C0C000FFFFFF0080808000FFFFFF00FFFF
      FF0080808000FFFFFF000000000000000000C0C0C00000000000000000000000
      0000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000C0C0C000808080008080800000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF000080000000FFFF0000FFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0008080800000000000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00C0C0C000C0C0C000FFFFFF0080808000FFFFFF00FFFFFF008080
      8000FFFFFF00000000000000000000000000C0C0C00000000000000000000000
      0000000000000000000000000000000000008080800000000000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FFFF
      0000FFFF0000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000C0C0C000808080008080800000000000FFFFFF00FFFFFF00FFFFFF000080
      0000FF00000000FFFF0000FFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C00080808000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00C0C0C000C0C0C000FFFFFF0080808000FFFFFF00FFFFFF0080808000FFFF
      FF0000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FFFF
      0000FFFF0000FFFF0000FFFF0000FF000000FF000000FF000000FF000000FF00
      0000C0C0C00080808000808080000000000080808000C0C0C000FFFFFF00FFFF
      FF0000800000FF000000FF00000000FFFF00FF000000FF000000008000000080
      0000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF0080808000FFFFFF000000
      000000000000000000000000000000000000C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C000C0C0C00000000000000000000000000000000000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FFFF
      0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF000000FF00
      0000C0C0C00080808000808080000000000000000000FFFFFF00C0C0C000FFFF
      FF00008000000080000000800000008000000080000000800000008000008000
      0000800000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000FFFFFF000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000C0C0C000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000C0C0C0008080800000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF000080000000800000008000000080000000800000008000008000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C000FFFF
      FF00000000000000000000000000FFFFFF00C0C0C000FFFFFF00C0C0C0000000
      0000000000000000000000000000000000000000000080808000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C00080808000000000000000000000000000000000000000000000000000FFFF
      FF0080800000FFFFFF00FF000000008000000080000000800000008000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080800000808000008080000080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000400FFE7000000000000FF8100000000
      0000FF00000000000000E3000000000000008081000000000000008100000000
      0000008100000000000081830000000000008103000000000001818000000000
      00018300000000000001FF00000000008003FF8100000000C007FF8100000000
      E00FFF8100000000F01FFF8300000000FFFFFFFFF803FFFF000FFFFFF001FFFF
      000F8007F000FFFF000F8003E000FFFF000FE003C000FF1F000F80078003F807
      000F80030003F001000F80030003E001000F80010003C003000F800100038007
      000F80010003000F000F80010003CC1F000F80018007FF3F000F8003C00FFFFF
      000F8003E01FFFFF001FFFFFF03FFFFF00000000000000000000000000000000
      000000000000}
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 704
    Top = 8
  end
  object FontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 6
    MaxFontSize = 18
    Options = [fdEffects, fdApplyButton]
    Left = 704
    Top = 24
  end
  object FindDialog: TFindDialog
    Left = 672
    Top = 8
  end
  object LocalSysImageList: TImageList
    Left = 632
    Top = 8
    Bitmap = {
      494C010110001300040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000005000000001002000000000000050
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
      0000000000000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800000000000000000000000000000000000000000000000
      0000000000000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      800080808000C0C0C00000000000000000000000000000000000000000000000
      0000808080000000000080808000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C00000000000C0C0C000800000008000
      00000000000000000000000000000000000080808000C0C0C00000FF0000C0C0
      C0000000000000000000808080000000000000000000FFFFFF0000FF0000C0C0
      C0000000000000000000C0C0C000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800000000000000000000000000000000000808080000000
      000080808000C0C0C00000000000C0C0C0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080000000800000008000
      00008000000000000000000000000000000080808000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00808080000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C0C0C0000000000000000000808080000000000080808000C0C0
      C00080808000FFFFFF00FFFFFF00FFFFFF00C0C0C00000000000000000000000
      0000000000000000000000000000000000000000000080000000FF0000008080
      800080808000800000008000000000000000000000008000000080000000FF00
      0000800000008000000000000000000000000000000080808000808080008080
      8000808080008080800000000000000000000000000080808000808080008080
      8000808080008080800080808000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000C0C0C000C0C0C0008080800000000000FFFF
      FF00FFFFFF00C0C0C000000000000000000080808000C0C0C00080808000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C000000000000000
      0000000000000000000000000000000000008000000080808000C0C0C0008080
      80008080800080808000C0C0C000FF000000000000008000000000800000FF00
      00008000000080000000000000000000000000000000FFFFFF00000000008000
      000080000000C0C0C00000000000000000000000000080808000808080008000
      0000800000008000000080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF0080808000C0C0C000FFFFFF008080800000000000C0C0C0008080
      80000000000080808000000000000000000000000000C0C0C000C0C0C0000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C0000000
      000000000000000000000000000000000000FF000000C0C0C000C0C0C0008080
      8000808080008080800080808000C0C0C0008000000000800000FF000000FF00
      0000FF000000FF000000800000000000000000000000FFFFFF0000000000FF00
      0000FF000000C0C0C0000000000000000000000000008080800080808000FF00
      0000FF0000008000000080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00808080008080800000FFFF00FFFFFF0000808000008080000000
      0000000000008080800000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0
      C00000000000000000000000000000000000FF000000C0C0C000C0C0C000C0C0
      C000808080008080800080808000C0C0C0008000000000800000FF000000FF00
      0000FF000000FF000000800000000000000000000000FFFFFF00000000000000
      000000000000C0C0C00000000000000000000000000080808000808080000000
      0000000000000000000080808000000000000000000000000000FFFFFF000000
      00000000000000000000FFFFFF0000FFFF00C0C0C00000FFFF00008080000080
      800000000000808080000000000000000000000000000000000000FFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0C0C000000000000000000000000000FF000000FFFFFF00C0C0C000C0C0
      C000C0C0C000808080008080800080808000FF0000008000000000800000FF00
      0000FF000000FF00000000800000000000000000000080808000808080008080
      8000808080008080800000000000000000000000000000000000808080008080
      8000808080008080800080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000808000C0C0C000C0C0C0008080800000FFFF0000FF
      FF00000000008080800000000000000000000000000000808000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C0C0C0000000000000000000FF000000FFFFFF00FFFFFF00C0C0
      C000C0C0C000C0C0C000C0C0C00080808000FF0000008000000000800000FF00
      0000FF000000FF00000000800000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF008080
      8000C0C0C000C0C0C0000080800000000000FFFFFF000080800000FFFF0000FF
      FF00FFFFFF008080800000000000000000000000000000FFFF00000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000C0C0C0008080
      80008080800000000000000000000000000080000000FFFF0000FFFF0000FFFF
      FF00FFFFFF00C0C0C000C0C0C000C0C0C000800000000080000000800000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000808080000000
      0000000000000000000000000000000000000000000000000000FFFFFF008080
      800000000000808000008080000000FFFF0000FFFF0000FFFF0000808000FFFF
      FF00FFFFFF008080800000000000000000000000800000000000000000000000
      00000000000000000000FFFFFF00FFFFFF0000000000C0C0C000808080000000
      0000000000000000000000000000808080008080800000000000000000000000
      000000000000000000000000000000000000808080008080800080000000FF00
      0000FF000000FF00000080000000000000000000000000000000000000000000
      000000000000FFFFFF00C0C0C000C0C0C0008080800080808000C0C0C0000000
      0000000000000000000000000000000000000000000000000000FFFFFF008080
      800000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800000000000000000000000000000000000000000000080
      0000008000000080000000000000C0C0C000C0C0C00000000000C0C0C000C0C0
      C0000000000000800000C0C0C0008080800080808000C0C0C000C0C0C000C0C0
      C000C0C0C000808080008080800080000000FF00000000800000008000000080
      0000008000008000000080000000000000000000000000000000000000000000
      0000000000008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF0080808000808080008080800080808000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800000000000000000000000000000000000000000000080
      0000C0C0C0000080000000800000000000000080000000000000000000000080
      0000C0C0C00000800000C0C0C0008080800000000000C0C0C000C0C0C0008080
      8000FFFFFF00FF000000FF000000008000000080000000800000808000000080
      0000008000008000000000000000000000000000000000000000000000000000
      00000000000080808000C0C0C000C0C0C000C0C0C000C0C0C000808080000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF008080800000000000000000000000000000000000000000000080
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000080000000800000C0C0C000808080000000000000000000C0C0C000FF00
      00000080000080800000FF000000008000000080000000800000008000000080
      0000008000008000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808000008080000080808000808080000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF000080800000000000000000000000000000000000000000000080
      0000008000000080000000800000C0C0C00000008000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C00080808000000000000000000000000000C0C0
      C000FFFFFF0080800000FF000000008000000080000000800000008000000080
      0000008000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000FFFF00008080000080808000808080000000
      000000000000000000000000000000000000000000000000000000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000008080800080800000FFFFFF00FF00000080800000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000080808000C0C0C000C0C0C000C0C0C000C0C0C000808080000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000808080000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0008080800000000000000000000000000000000000FF00
      0000FF00000000000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00C0C0
      C00000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000080808000808080000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0
      C000C0C0C000C0C0C00080808000000000000000000000000000FF0000000000
      0000FFFFFF00FFFFFF0080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C0C0C000C0C0
      C000FFFFFF000000000000000000C0C0C000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000000000
      0000000000000000000080808000808080000000000080000000FF000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0C0C000C0C0C0008080800000000000000000000000000000000000FFFF
      FF00FFFFFF008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000C0C0C000FFFFFF00FFFF
      FF00000000000000000000000000000000008080800080808000808080008080
      80008080800000000000000000000000000000000000C0C0C000C0C0C0000000
      00000000000000000000000000008080800000000000FF000000000000000000
      000080800000FF000000FF00000080800000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0C0C000C0C0C00080808000000000000000000000000000000000000000
      0000FFFFFF00C0C0C000C0C0C000C0C0C0000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000C0C0
      C000000000000000000000000000000000008080800000000000FFFF0000FFFF
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080000000800000008080
      0000FF00000080800000FF000000FF000000FF000000FFFFFF00FFFFFF00FFFF
      FF00C0C0C000C0C0C00080808000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00C0C0C0000000FF000000FF00000080008080
      800000008000000000000000000000000000C0C0C000FFFFFF00FFFFFF000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000008080800000000000FFFF0000FFFF
      0000000000000000000000000000000000000000000080808000000000000000
      00000000000000000000000000000000000080808000FF00000080000000FF00
      0000FFFFFF00FFFFFF00FFFFFF00FF0000008080000080800000FFFFFF00FFFF
      FF00FFFFFF00C0C0C00080808000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C000FFFFFF00FFFFFF008080
      80000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000000000000000
      0000000000000000000000000000000000008080800000000000FFFF0000FFFF
      0000000000000000000000000000000000000000000080808000FFFF0000FFFF
      0000FFFF0000000000000000000000000000808080008080800080800000FF00
      0000808000008080000080800000808000008080000080800000FFFFFF00FFFF
      FF00FFFFFF00C0C0C00080808000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000000000000000000000000000080808000FFFF0000FFFF
      0000FFFF00000000000000000000000000000000000080808000FF0000008080
      000080800000808000008080000080800000FFFF000080800000FFFFFF00FFFF
      FF00FFFFFF00C0C0C00080808000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF0000000000000000000000000000000000FFFFFF00C0C0C000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000000000
      00000000000000000000000000000000000000000000FF00000080808000FF00
      000080800000FFFFFF008000000080800000FFFF0000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C0C0C00080808000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF00C0C0
      C000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000008080
      0000FF000000FF000000808000008080000080800000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080808000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00C0C0C0000000000000000000000000000000000000000000FFFF
      FF00C0C0C000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000C0C0C000C0C0
      C000000000000000000000000000000000008080800000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF0080800000808000008080000080800000FFFFFF0080800000FFFFFF00FFFF
      FF00FFFFFF00C0C0C00080808000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00C0C0C000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF008080000080800000FFFFFF00FFFFFF00FFFF
      FF00C0C0C0008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00C0C0C00000000000000000000000000000000000000000000000
      000000000000FFFFFF00C0C0C000FFFFFF00FFFF0000FFFFFF0000000000FFFF
      FF00000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF008080
      8000C0C0C0008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00C0C0C000C0C0C00000000000FFFFFF000000
      000000000000000000000000000000000000000000000000000080808000FFFF
      0000FFFF0000FFFF000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000800000000000000000000000
      000000000000000000000000000000000000000000000000000080808000FFFF
      0000FFFF0000FFFF000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000000000000000000000008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C0008080800080808000808080008080800080808000808080008080
      8000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      000000000000FFFFFF0000000000FFFFFF000000000080808000000000000000
      0000000000008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF0000FFFF000080
      8000008080000000000000000000000000008080800000000000C0C0C000C0C0
      C000C0C0C0008080800080808000808080008080800080808000808080008080
      8000C0C0C00080808000C0C0C00000000000C0C0C000C0C0C000000000008080
      8000FFFFFF00C0C0C00080808000808080008080800080808000808080008080
      800080808000C0C0C000C0C0C00000000000000000000000000000000000FFFF
      FF00FFFFFF00C0C0C00080808000FFFFFF000000000000800000C0C0C0008080
      8000000000000000000000000000808080000000000000000000000000000000
      00000000000000000000000000000000000000FFFF00FFFFFF0000FFFF00C0C0
      C00000808000008080000080800000000000FFFFFF00FFFFFF0000000000C0C0
      C000C0C0C000C0C0C00080808000808080008080800080808000808080008080
      800080808000C0C0C000C0C0C00000000000C0C0C000C0C0C00000000000C0C0
      C000FFFFFF00C0C0C00080808000808080008080800080808000808080008080
      800080808000C0C0C000C0C0C0000000000000FFFF0000FFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000008080
      800000000000C0C0C00000000000000000000000000000000000000000000000
      000000000000C0C0C000C0C0C0008080800000FFFF00008080000080800000FF
      FF00C0C0C000000000000080800000000000FFFFFF0000000000FFFFFF000000
      0000000000000000000000000000808080008080800080808000808080008080
      800080808000C0C0C000C0C0C00000000000C0C0C000C0C0C000808080008080
      800080808000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C0000000000080808000FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF0080808000FFFF00000000000000FF000000000000C0C0
      C00080808000808080000000000000000000000000000000000000000000C0C0
      C000C0C0C000C0C0C000C0C0C000808080008080800000FFFF000080800000FF
      FF00000000000000000000FFFF000000000000000000C0C0C000C0C0C0000000
      000080808000C0C0C000C0C0C000808080008080800080808000808080008080
      800080808000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000008080800080808000FFFFFF000000
      000080808000C0C0C00000000000008000000000000000FF0000808080008080
      80000000000000000000000000000000000000000000C0C0C000C0C0C0008080
      8000C0C0C000FFFFFF00C0C0C00080808000C0C0C00000FFFF00000000000000
      000000FFFF0000FFFF00000000000000000080808000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00808080008080800080808000808080008080
      8000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C00000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF008080
      80008080800000000000C0C0C0000000000080808000FFFFFF0080808000FFFF
      FF00000000008080800080808000C0C0C000C0C0C000C0C0C000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C000FFFF
      FF00C0C0C00000000000C0C0C00080808000000000000000000000FFFF0000FF
      FF0000000000000000000000000000000000FFFFFF0000000000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C0008080800080808000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000000000008080
      80008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C00000000000C0C0C000000000008080800000000000000000008080
      8000FFFFFF000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000FFFFFF00C0C0C0000000
      0000C0C0C000C0C0C000C0C0C000808080008080800080808000808080008080
      800000000000000000000000000000000000FFFFFF00C0C0C00000000000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C0008080800000000000C0C0
      C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000000000008080
      80008080800080808000FFFFFF00FFFFFF00C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000808080000000000080808000000000000000000000000000808080000000
      000000000000000000000000000000000000C0C0C00000000000C0C0C000C0C0
      C00000000000FF000000C0C0C000808080008080800080808000000000000000
      000000000000000000000000000000000000FFFFFF00C0C0C000C0C0C0000000
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C00000000000C0C0
      C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000000000008080
      8000808080008080800080808000FFFFFF00C0C0C000C0C0C000FFFFFF008080
      80008080800000000000C0C0C000000000000000000000000000000000000000
      000080808000C0C0C0000000000000FFFF000000000000000000000000008080
      800080808000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000C0C0C000808080008080800080808000808080000000
      000000000000000000000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00C0C0C000C0C0C00000000000C0C0C000C0C0C000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00C0C0
      C000C0C0C00000000000C0C0C000000000000000000000000000000000000000
      0000808080008080800000000000000000000000000000FFFF00000000008080
      800000000000000000000000000000000000000000000000000000000000FFFF
      0000FF00000080000000C0C0C000808080008080800080808000808080000000
      000000000000000000000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C00000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000808080008080800000FFFF0000000000FF00000000000000000000008080
      8000000000000000000000000000000000000000000000000000000000008000
      000000000000C0C0C000FFFFFF00808080008080800080808000808080000000
      000000000000000000000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C00000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000C0C0C00000000000C0C0C00080000000800000008000
      0000800000008000000080000000800000008000000080000000800000008000
      00008000000080000000C0C0C000000000000000000000000000000000000000
      0000C0C0C000FFFFFF00000000000000000000FFFF0000000000C0C0C0008080
      800080808000000000000000000000000000000000000000000000000000C0C0
      C000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000808080000000
      000000000000000000000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00080808000808080008080800080808000808080008080
      800080808000C0C0C000C0C0C00000000000C0C0C00080808000800000008000
      0000800000008000000080000000800000008000000080000000800000008000
      00008000000080000000C0C0C000000000000000000000000000000000000000
      0000000000008080800080808000000000000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000FFFFFF00C0C0
      C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000000000000000
      000000000000000000000000000000000000FFFFFF0080808000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000000000000000000080808000FFFFFF00C0C0C000C0C0C000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000080008000C0C0
      C000C0C0C000C0C0C000FFFFFF000000000000000000FFFFFF00FFFFFF00FFFF
      FF00C0C0C0008080800000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C00000000000000000008080800080808000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000000000000000800080000000
      0000C0C0C000C0C0C000FFFFFF000000000000000000FFFFFF00FFFFFF00FFFF
      FF00C0C0C000C0C0C00000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C000C0C0C000C0C0C0000000
      0000C0C0C0000000000000000000C0C0C00080808000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000FFFFFF0000000000FF00FF00800080000000
      0000FFFFFF00FFFFFF00FFFFFF0000000000000000000000FF000000FF000000
      FF00C0C0C000C0C0C00000000000000000000000800000008000000080008080
      800080808000808080000000000000000000FFFFFF00FFFFFF00FFFFFF00C0C0
      C000C0C0C0000000000000000000C0C0C000C0C0C00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00FFFFFF00FFFFFF0000000000FF00FF00C0C0
      C000FFFFFF00FFFFFF00FFFFFF0000000000000000000000FF000000FF000000
      FF0000008000C0C0C000000000008080800000000000C0C0C000C0C0C0008080
      800080808000808080008080800000000000C0C0C000C0C0C000C0C0C0000000
      000000000000000000008080800000000000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000808000008080000080
      8000008080000080800000808000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000FF000000FF000000
      FF0000008000000080000000000080808000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000808080008080800000000000C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C000C0C0C000C0C0C00080808000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00FFFFFF00FFFFFF00C0C0C000C0C0C000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000080808000FFFFFF00FFFFFF00FFFF
      FF00C0C0C0000000800000000000808080008080800080808000808080008080
      800080808000C0C0C0008080800000000000C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      000000000000FF00000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF00000000000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C000000000000000000000000000C0C0C000C0C0C000C0C0C0008080
      8000FFFFFF00FFFFFF000000000080808000C0C0C000C0C0C000C0C0C000C0C0
      C0008080800080808000C0C0C00000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C00080808000C0C0C000C0C0C00000000000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000FF0000000000
      0000FF000000FF000000FF00000000000000FF000000FF0000000000000000FF
      FF0000FFFF0000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000000000000000000080800000808000000000000000000000000000FFFF
      0000FFFF000000000000000000000000000080808000C0C0C000C0C0C0008080
      8000FFFFFF00FFFFFF000000000080808000808080008080800080808000FFFF
      FF0080808000000000000000000000000000C0C0C00000000000000000000000
      0000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000000000000FF000000000000000000
      000000000000000000000000000000000000FF000000FF0000000000000000FF
      FF0000FFFF0000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF00000000000000000000000000000000000000000000FF
      FF0000FFFF000000000080808000000000000000000080808000000000000000
      00008080800080808000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FFFF
      FF0080808000000000000000000000000000C0C0C00000000000000000000000
      0000000000000000000000000000000000008080800000000000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF0000000000000000FF
      FF000080800000000000000000000000000000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF00000000000000000000FFFF00000000000000000000FF
      FF0000FFFF000000000080808000000000000000000000000000000000000000
      0000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FFFF
      FF0080808000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF0000000000000000000000FF0000000000000000000000
      0000800000000000000000000000000000000080800000808000008080000080
      8000008080000000000000FFFF0000FFFF000000000000FF000000FF00000080
      000000FFFF000000000080808000000000000000000000000000000000000000
      0000FFFFFF000000000080008000FF00FF00FF00FF00FF00FF00FF00FF00FFFF
      FF0080808000000000000000000000000000C0C0C000C0C0C000FFFFFF00C0C0
      C000C0C0C000C0C0C00000000000000000000000000000000000C0C0C000C0C0
      C0000000000000000000000000000000000000000000000000000000FF000000
      00000000FF000000FF000000FF00000000000000FF000000FF00000000000080
      0000008000000000000000000000000000000080800000808000008080000080
      80000080800000808000000000000000000000FF000000FF0000008000000000
      0000000000000000000080808000000000000000000000000000000000000000
      0000FFFFFF00000000000000000000000000000000000000000000000000FFFF
      FF0080808000000000000000000000000000C0C0C000C0C0C000FFFFFF000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C00000000000000000000000000000000000000000000000FF00000000000000
      0000000000000000000000000000000000000000FF000000FF00000000000080
      00000080000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000808000000000000000000000FF000000FF0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C00080808000000000000000000000000000C0C0C000C0C0C000C0C0C000FFFF
      FF00000000000000000000000000FFFFFF00C0C0C000FFFFFF00C0C0C0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000FFFFFF00000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000500000000100010000000000800200000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000C003FDFF003F81818001F0FF000F0180
      8001C07F000701808001003F000381818001001F00018181C001000F00018181
      C001800700008001C0018003000083C1C00180010000FFFFC00130030000F80F
      C00120000000F80FC00140000001F80FC001C0008001F81FC0018000C003F81F
      C0018000E007F81FC001C001F81FF81FE001FFFF8007C0FFE00180FF800700FF
      E001C1FF800701008001C1FF80070100A001C007000703010001800700070183
      0001800F803F038100018007801F828180018003800FF08180018003C007801F
      C001C003E007807FE001E003F00780FFE001FC03F807C1FFE003FE01FC0FC0FF
      E007FF03FE1FC0FFE00FFFFFFF3FC0FF0000FF3F3FFF00010000FC0F33CF0000
      0000F003E60300000000C000FC00000000000000F000000000000001C0000000
      00000007000100000000001F000700000000601F000700000000F1CF001F0000
      0000F2E7801F00000000F027801F00000000F007801F00000000F307801F0000
      0000F9CF801F00000000FC1FC07F0000FFFFFFFF86A3FFB887FF000F87C3FF00
      83FF000FFFFFFE0081FF000F8A4780008003000F852100008001000FFBFF0000
      8000000FD07300000000000FBA0300000000000FD00300000003000FBA030001
      9003000FD0030001F003000FBA030001F003000FD0030001F003000FBA030007
      F003000FD00303FFF803001FBF87FFFF00000000000000000000000000000000
      000000000000}
  end
  object LANImageList: TImageList
    Left = 632
    Top = 16
    Bitmap = {
      494C010105000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
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
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF00000000000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000FFFFFF00FFFFFF0080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00C0C0C000C0C0C000C0C0C0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00C0C0C0000000FF000000FF00000080008080
      8000000080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0C000FFFFFF00FFFFFF008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000000000000000FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00C0C0C00000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF00C0C0C00000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000C0C0C0008080
      80008080800000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C00000808000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C0000000000000000000000000000000
      0000000000000000000000FFFF0000FFFF000080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000080808000C0C0C0000000FF00FFFFFF008080
      8000808080008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000C0C0C0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF00000000000000FF000000FF00000000000000FF00FFFFFF00000000000000
      0000000000000000000000000000000000000080800000808000008080000080
      800000808000008080000080800080808000FFFFFF000000000000FFFF000080
      800000000000C0C0C00080808000000000000000000000808000008080000080
      8000008080000080800000808000008080000080800000808000008080000080
      8000008080000080800000000000000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      FF00000000000000FF0000000000000000000000FF00FFFFFF00000000000000
      000000000000000000000000000000000000C0C0C00000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00FFFFFF000080
      80000080800000808000000000000000000000000000C0C0C000C0C0C000C0C0
      C00000FFFF0000800000FF000000FF000000FF00000000000000C0C0C000C0C0
      C000C0C0C000C0C0C00000000000000000008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800000000000000000000000000000000000FFFFFF000000
      FF000000000000000000FFFFFF00000000000000FF00FFFFFF00000000000000
      000000000000000000000000000000000000C0C0C00000FFFF0080000000FF00
      000080000000FFFF0000FFFF000000008000FFFFFF0000FFFF00C0C0C00000FF
      FF000080800000808000000000000000000000000000C0C0C00000FFFF00C0C0
      C0000080000000FF000000800000FF000000008000000080000000800000C0C0
      C000C0C0C000C0C0C000000000000000000080808000C0C0C000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0C0C0008080800080808000000000000000000000000000FFFFFF000000
      FF0000000000FFFFFF00FFFFFF000000000000000000FFFFFF00000000000000
      000000000000000000000000000000000000C0C0C00000FFFF0080000000FFFF
      FF008000000000FFFF0000FFFF000000800000808000C0C0C000C0C0C000C0C0
      C00000FFFF000000000000FFFF000000000000808000C0C0C000C0C0C000C0C0
      C000FFFF0000FFFF0000FFFF0000FFFF0000008000000080000000000000C0C0
      C000C0C0C00000000000000000000000000080808000C0C0C000FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0C0C0008080800080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
      000000000000000000000000000000000000C0C0C00000FFFF0080000000FF00
      00008000000000FFFF0000FFFF0000008000FFFFFF000000000000FFFF000000
      0000008080008080800000FFFF00000000000080800000FFFF00C0C0C000C0C0
      C000FFFFFF00FFFF000000800000FFFF0000FFFF00000080000000800000C0C0
      C000C0C0C000000000000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C00080808000808080008080800080808000808080008080800080808000C0C0
      C000C0C0C0008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C00000FFFF0080000000FF00
      000080000000808000008080000000008000FFFFFF0000FFFF00808080008080
      800000FFFF00008080000000000000000000C0C0C000C0C0C000C0C0C000C0C0
      C0000080000000FF000000FF000000800000FFFF0000FF00000000FFFF00C0C0
      C000C0C0C000C0C0C0000000000000000000C0C0C00000000000000000000000
      0000C0C0C00000000000C0C0C0000000000000000000000000008080800000FF
      0000C0C0C0008080800080808000000000000000000000000000000000000000
      000000000000000000000000000000FF000000FF000000000000C0C0C0000000
      000000000000000000000000000000000000C0C0C00000FFFF0080000000FF00
      0000800000008080000080800000000080000000FF0000008000008080000080
      800000FFFF0000FFFF000000000000000000FFFFFF00C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C00000FF000000FF00000080000000FFFF00C0C0C000C0C0
      C000C0C0C000FFFFFF00C0C0C00000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF000000000000000000C0C0
      C000C0C0C000C0C0C00080808000000000000000000000FF000000FF000000FF
      000000FF00000000000000FF000000FF000000FF000000FF0000000000000000
      000000000000000000000000000000000000C0C0C00000FFFF00800000008000
      000080000000FF000000FFFFFF000000800000008000000080000000FF0000FF
      FF0000FFFF0000FFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000C0C0C0000000000000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000000000008080
      8000808080008080800080808000000000000000000000800000008000000080
      00000080000000FF000000800000C0C0C000C0C0C0000080000000FF00000080
      000000000000000000000000000000000000C0C0C00000FFFF0000FFFF008000
      0000FFFFFF008000000000FFFF0000FFFF0000008000FFFFFF000000800000FF
      FF0000FFFF0000FFFF0000000000000000000000000000808000C0C0C000C0C0
      C000FFFFFF0000008000FFFFFF00C0C0C00000008000FFFFFF00C0C0C000FFFF
      FF00C0C0C000C0C0C0000000000000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000800000000000000080
      00000080000000FF000000800000C0C0C000C0C0C0000080000000FF00000080
      000000000000000000000000000000000000C0C0C00000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF000000000000000000000000000080800000FFFF00C0C0
      C000FFFFFF00FFFFFF0000808000FFFFFF00C0C0C00000808000FFFFFF00C0C0
      C000C0C0C000C0C0C0000000000000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000800000008000000080
      0000008000000000000000800000C0C0C000C0C0C00000800000000000000080
      0000FFFFFF00000000000000000000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000000000000080800000FFFF0000FF
      FF00C0C0C000FFFFFF00FFFFFF0000808000FFFFFF00FFFFFF00C0C0C0000000
      000000000000000000000000000000000000C0C0C000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      000000000000000000000000000000000000000000000080000000FF00000080
      0000008000000000000000800000008000000080000000800000000000000080
      0000FFFFFF000000000000000000000000008080800000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF00808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000008080000080
      80000080800000808000FFFFFF00FFFFFF00FFFFFF00C0C0C000000000000000
      00000000000000000000000000000000000080808000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000800000000000000000
      0000008000000000000000800000000000000000000000800000C0C0C0000080
      0000C0C0C0000000000000000000000000000000000080808000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00C0C0C00000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000000000000000000000000000808080008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C0C0C000C0C0C00000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFF00000000000080FF000000000000
      C1FF000000000000C1FF000000000000C0070000000000008007000000000000
      800F000000000000800700000000000080030000000000008003000000000000
      C003000000000000E003000000000000FC03000000000000FE01000000000000
      FF03000000000000FFFF000000000000FFEFFC7FFC7FFFFFFF838000FC7F803F
      FE00FEFFFEFF803F00008001FEFF803F000080010003803F0000800100018033
      0000000100018023000100010001FFC7000100010001FC0F000100010001801B
      000100010001800B00018001001F800300018003001F80030003801F001F8003
      00FFC03F041F800381FFFE7F8E3FFFF900000000000000000000000000000000
      000000000000}
  end
  object ShortCutsPopupMnu: TPopupMenu
    Left = 584
    Top = 8
    object OpenFile: TMenuItem
      Caption = '&Open File'
      OnClick = OpenFileClick
    end
    object EditwithNotepad: TMenuItem
      Caption = '&Edit with Notepad'
      OnClick = EditwithNotepadClick
    end
    object N10: TMenuItem
      Caption = '-'
    end
    object loadDefault: TMenuItem
      Caption = 'load &Default'
    end
  end
end
