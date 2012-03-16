Win32 App (no res)
Provador
Win32 Hello World
[*BEGINPRO*]
[*BEGINDEF*]
[MakeDef]
Menu=0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0
1=
2=0,O,$B\dmc.exe  -S -mn -p -c -C -WA -d -o"$3" -o+space,2
3=5,O,$B\link.exe /SUBSYSTEM:WINDOWS /EXETYPE:NT "$3" | "$5" ||gdi32.lib
4=0,0,,5
5=
6=*.obj,O,$B\dmc  /mn /c  /I"$I",*.c
7=0,0,"$E\OllyDbg",5
11=
12=0,O,$B\dmc.exe  -S -mn -p -c -C -d -o"$3" -o+space | 2
13=5,O,$B\link.exe /SUBSYSTEM:WINDOWS /EXETYPE:NT "$3" | "$5"
14=0,0,,5
15=
16=*.obj,O,$B\dmc  /mn /c /g2  /I"$I",*.c
17=0,0,"$E\OllyDbg",5
[MakeFiles]
0=Provador.rap
1=Provador.rc
2=Provador.c
3=Provador.obj
4=Provador.res
5=Provador.exe
6=Provador.def
7=Provador.dll
8=Provador.txt
9=Provador.lib
10=Provador.mak
11=Provador.cpp
12=Provador.com
13=Provador.ocx
14=Provador.idl
15=Provador.tlb
[Resource]
[StringTable]
[Accel]
[VerInf]
[Group]
Group=Added files,Assembly,Resources,Misc,Modules
1=2
2=2
[*ENDDEF*]
[*BEGINTXT*]
Provador.c
/*-----------------------------------------------------------
HelloWin.c -- Displays "Hello, Windows XP!" in client area 
(c) Charles Petzold, 1998
-----------------------------------------------------------*/

#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR	szAppName[ ] = TEXT("HelloWin");
	HWND			hwnd;
	MSG				msg;
	BOOL			bRet;
	WNDCLASS		wndclass;
	wndclass.style			= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc	= WndProc;
	wndclass.cbClsExtra		= 0;
	wndclass.cbWndExtra		= 0;
	wndclass.hInstance		= hInstance;
	wndclass.hIcon			= LoadIcon ( NULL,IDI_APPLICATION );
	wndclass.hCursor		= LoadCursor ( NULL, IDC_ARROW );
	wndclass.hbrBackground	= (HBRUSH) GetStockObject (WHITE_BRUSH);
	wndclass.lpszMenuName	= NULL;
	wndclass.lpszClassName	= szAppName;
	
	if (!RegisterClass (&wndclass))
	{
		MessageBox (NULL, TEXT ("This program requires Windows NT or Newer!"), szAppName, MB_ICONERROR);
		
		return 0;
	}
	hwnd = CreateWindow ( szAppName,
		TEXT ("The Hello Program"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	
	ShowWindow (hwnd, iCmdShow);
	UpdateWindow (hwnd);
	
	while ( ( bRet = GetMessage ( &msg, NULL, 0, 0 ) ) != 0 )
	{
		if (bRet == -1)
		{
			ExitProcess (0);
		}
		else
		{
			TranslateMessage ( &msg );
			DispatchMessage ( &msg );
		}
	}
	return (WPARAM)msg.wParam;
}

LRESULT CALLBACK WndProc ( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT ps;
	RECT		rect;
	
	switch ( message )
	{
	case WM_CREATE:
		break;
		
	case WM_PAINT:
		hdc = BeginPaint ( hwnd, &ps );
		GetClientRect ( hwnd, &rect );
		
		DrawText (hdc, TEXT ("Hello, Windows XP!"), -1, &rect, DT_SINGLELINE |
			DT_CENTER | DT_VCENTER);
		EndPaint (hwnd, &ps);
		break;
		
	case WM_DESTROY:
		PostQuitMessage (0);
		break;

	default:
	return DefWindowProc (hwnd, message, wParam, lParam);
	}
	
	return 0;	
}

[*ENDTXT*]
[*BEGINTXT*]
Provador.h
[*ENDTXT*]
[*ENDPRO*]
