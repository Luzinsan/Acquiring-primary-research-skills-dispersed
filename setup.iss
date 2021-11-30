; Имя приложения
#define   Name       "XPainter"
; Версия приложения
#define   Version    "0.0.1"
; Фирма-разработчик
#define   Publisher  "ZKL"
; Сайт фирмы разработчика
#define   URL        "https://github.com/Luzinsan/Acquiring-primary-research-skills-dispersed"
; Имя исполняемого модуля
#define   ExeName    "XPainter.exe"

[Setup]

; Уникальный идентификатор приложения, 
;сгенерированный через Tools -> Generate GUID
AppId={{D8527779-796C-4391-8CE1-44DD996934AD}

; Прочая информация, отображаемая при установке
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

; Путь установки по-умолчанию
DefaultDirName={pf}\{#Name}
; Имя группы в меню "Пуск"
DefaultGroupName={#Name}

; Каталог, куда будет записан собранный setup и имя исполняемого файла
OutputDir=U:\XPainter-setup
OutputBaseFileName=XPainter-setup

; Файл иконки
SetupIconFile=U:\ProjectQt\for_build\icons8_impossible_shapes_64_8PK_icon.ico

; Параметры сжатия
Compression=lzma
SolidCompression=yes

[Languages]
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "U:\ProjectQt\build-ZKL-Desktop_Qt_5_13_2_MinGW_32_bit-Release\release\Manual\About.txt"

[Tasks]
; Создание иконки на рабочем столе
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]

; Исполняемый файл
Source: "U:\ProjectQt\build-ZKL-Desktop_Qt_5_13_2_MinGW_32_bit-Release\release\XPainter.exe"; DestDir: "{app}"; Flags: ignoreversion

; Прилагающиеся ресурсы
Source: "U:\ProjectQt\build-ZKL-Desktop_Qt_5_13_2_MinGW_32_bit-Release\release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{userdesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; WorkingDir: "{app}";IconFilename: "{app}\Icons\icons8_impossible_shapes_64_8PK_icon.ico"; Tasks: desktopicon;
