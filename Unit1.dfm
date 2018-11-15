object RES: TRES
  Left = 194
  Top = 127
  Width = 815
  Height = 437
  Caption = 'RES'
  Color = clInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Corbel'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 15
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 152
    Height = 15
    Caption = 'The price of sold real estate: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Corbel'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label4: TLabel
    Left = 288
    Top = 304
    Width = 93
    Height = 15
    Caption = 'Enter parameter: '
    Visible = False
  end
  object Button4: TButton
    Left = 280
    Top = 96
    Width = 233
    Height = 25
    Caption = 'ADD ELEMENT'
    TabOrder = 4
    Visible = False
    OnClick = Button4Click
  end
  object StringGrid2: TStringGrid
    Left = 40
    Top = 32
    Width = 777
    Height = 52
    Color = clBtnFace
    ColCount = 10
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
    Visible = False
    ColWidths = (
      39
      59
      55
      104
      87
      99
      97
      96
      64
      64)
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 24
    Width = 777
    Height = 253
    Color = clBtnFace
    ColCount = 10
    FixedCols = 0
    RowCount = 10
    TabOrder = 0
    OnClick = StringGrid1Click
    ColWidths = (
      39
      59
      55
      104
      87
      99
      98
      94
      64
      64)
  end
  object Edit1: TEdit
    Left = 384
    Top = 296
    Width = 121
    Height = 23
    Color = clBtnFace
    TabOrder = 1
    Visible = False
    OnChange = Edit1Change
  end
  object Button3: TButton
    Left = 280
    Top = 328
    Width = 233
    Height = 25
    Caption = 'SEARCH ELEMENT'
    TabOrder = 2
    Visible = False
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 280
    Top = 296
    Width = 233
    Height = 25
    Caption = 'DELETE ELEMENT'
    TabOrder = 5
    Visible = False
    OnClick = Button5Click
  end
  object Edit2: TEdit
    Left = 160
    Top = 0
    Width = 57
    Height = 23
    Color = clBtnFace
    TabOrder = 6
    Visible = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 359
    Width = 799
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object MainMenu1: TMainMenu
    Left = 8
    object Start1: TMenuItem
      Caption = 'Read in File'
      OnClick = Start1Click
    end
    object Print1: TMenuItem
      Caption = 'Print'
      OnClick = Print1Click
    end
    object Sorting1: TMenuItem
      Caption = 'Sorting'
      object PurposeazOnlyforNRP1: TMenuItem
        Caption = 'Purpose(a-z)(Only for NRP)'
        OnClick = PurposeazOnlyforNRP1Click
      end
      object Addressaz1: TMenuItem
        Caption = 'Address(a-z)'
        OnClick = Addressaz1Click
      end
      object Rooms1: TMenuItem
        Caption = 'Rooms(<)'
        OnClick = Rooms1Click
      end
    end
    object Definition1: TMenuItem
      Caption = 'Definition'
      object Maxsquare1: TMenuItem
        Caption = 'Max square'
        object Rp1: TMenuItem
          Caption = 'RP'
          OnClick = Rp1Click
        end
        object NRP1: TMenuItem
          Caption = 'NRP'
          OnClick = NRP1Click
        end
        object ALL1: TMenuItem
          Caption = 'ALL'
          OnClick = ALL1Click
        end
      end
      object Minsquare1: TMenuItem
        Caption = 'Min square'
        object RP2: TMenuItem
          Caption = 'RP'
          OnClick = RP2Click
        end
        object NRP2: TMenuItem
          Caption = 'NRP'
          OnClick = NRP2Click
        end
        object ALL2: TMenuItem
          Caption = 'ALL'
          OnClick = ALL2Click
        end
      end
    end
    object Search1: TMenuItem
      Caption = 'Search'
      object Address1: TMenuItem
        Caption = 'Address'
        OnClick = Address1Click
      end
      object Owner1: TMenuItem
        Caption = 'Owner'
        object Byparametr1: TMenuItem
          Caption = 'By parametr'
          OnClick = Byparametr1Click
        end
        object Whohave2RP1: TMenuItem
          Caption = 'Who have >2 RP'
          OnClick = Whohave2RP1Click
        end
      end
      object NumbersOf1: TMenuItem
        Caption = 'Numbers of rooms'
        OnClick = NumbersOf1Click
      end
      object Totalarea1: TMenuItem
        Caption = 'Total area'
        OnClick = Totalarea1Click
      end
      object Kitchenarea1: TMenuItem
        Caption = 'Kitchen area'
        OnClick = Kitchenarea1Click
      end
      object Roomsarea1: TMenuItem
        Caption = 'Rooms area'
        OnClick = Roomsarea1Click
      end
      object Repaircondition1: TMenuItem
        Caption = 'Repair condition'
        OnClick = Repaircondition1Click
      end
      object Purpose1: TMenuItem
        Caption = 'Purpose'
        OnClick = Purpose1Click
      end
      object Price1: TMenuItem
        Caption = 'Price'
        OnClick = Price1Click
      end
    end
    object Add1: TMenuItem
      Caption = 'Add '
      object RP3: TMenuItem
        Caption = 'RP'
        OnClick = RP3Click
      end
      object NRP3: TMenuItem
        Caption = 'NRP'
        OnClick = NRP3Click
      end
    end
    object Delete1: TMenuItem
      Caption = 'Delete'
      object ChooseElement1: TMenuItem
        Caption = 'Choose Element'
        OnClick = ChooseElement1Click
      end
      object AllElements1: TMenuItem
        Caption = 'All Elements'
        OnClick = AllElements1Click
      end
    end
    object Save1: TMenuItem
      Caption = 'Save'
      OnClick = Save1Click
    end
  end
end
