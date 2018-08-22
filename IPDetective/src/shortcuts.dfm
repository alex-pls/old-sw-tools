object ShortCutsFrm: TShortCutsFrm
  Left = 322
  Top = 163
  Width = 418
  Height = 453
  BorderIcons = [biSystemMenu, biMinimize, biHelp]
  BorderStyle = bsSizeToolWin
  Caption = 'ShortCuts'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object ShortCutsListView: TListView
    Left = 0
    Top = 0
    Width = 410
    Height = 421
    Align = alClient
    BorderStyle = bsNone
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
    IconOptions.AutoArrange = True
    RowSelect = True
    SortType = stText
    TabOrder = 0
    ViewStyle = vsReport
  end
end
