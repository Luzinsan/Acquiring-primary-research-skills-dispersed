; ��� ����������
#define   Name       "XPainter"
; ������ ����������
#define   Version    "0.0.1"
; �����-�����������
#define   Publisher  "ZKL"
; ���� ����� ������������
#define   URL        "https://github.com/Luzinsan/Acquiring-primary-research-skills-dispersed"
; ��� ������������ ������
#define   ExeName    "XPainter.exe"

[Setup]

; ���������� ������������� ����������, 
;��������������� ����� Tools -> Generate GUID
AppId={{D8527779-796C-4391-8CE1-44DD996934AD}

; ������ ����������, ������������ ��� ���������
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; ���� ��������� ��-���������
DefaultDirName={pf}\{#Name}
; ��� ������ � ���� "����"
DefaultGroupName={#Name}

; �������, ���� ����� ������� ��������� setup � ��� ������������ �����
OutputDir=U:\XPainter-setup
OutputBaseFileName=XPainter-setup

; ���� ������
SetupIconFile=U:\ProjectQt\for_build\icons8_impossible_shapes_64_8PK_icon.ico

; ��������� ������
Compression=lzma
SolidCompression=yes

[Languages]
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "U:\ProjectQt\build-ZKL-Desktop_Qt_5_13_2_MinGW_32_bit-Release\release\Manual\About.txt"

[Tasks]
; �������� ������ �� ������� �����
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]

; ����������� ����
Source: "U:\ProjectQt\build-ZKL-Desktop_Qt_5_13_2_MinGW_32_bit-Release\release\XPainter.exe"; DestDir: "{app}"; Flags: ignoreversion

; ������������� �������
Source: "U:\ProjectQt\build-ZKL-Desktop_Qt_5_13_2_MinGW_32_bit-Release\release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{userdesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; WorkingDir: "{app}";IconFilename: "{app}\Icons\icons8_impossible_shapes_64_8PK_icon.ico"; Tasks: desktopicon;
