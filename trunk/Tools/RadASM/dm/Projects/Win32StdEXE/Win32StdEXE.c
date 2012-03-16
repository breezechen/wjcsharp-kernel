#include <windows.h>

LRESULT CALLBACK WndProc (HWND,UINT,WPARAM,LPARAM);
#define VW_FONT 0x01

TCHAR 			szAppName[]		= {"MyTextOut"};
TCHAR 			szClassName[]	= {"PhDClass"};
TCHAR			szMessage[]		= {"Hello World from Digital Mars and Radasm"};

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR szCmdLine, int nShowCmd )
{
	BOOL			bRet;
	HWND			hwnd;
	MSG				msg;
	WNDCLASS 		wc;

	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hbrBackground	= (HBRUSH) GetStockObject(WHITE_BRUSH);
	wc.hCursor			= LoadCursor(hInstance,IDC_ARROW);
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon(hInstance,IDI_APPLICATION);
	wc.lpszClassName	= szClassName;
	wc.lpszMenuName		= NULL;

	if (!RegisterClass ( & wc ) )
	{
		MessageBox(NULL,TEXT("This program requires Windows NT or Newer!"),
			TEXT("Attention"),MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szClassName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow (hwnd,nShowCmd);
	UpdateWindow (hwnd);
	while ( (bRet = GetMessage ( &msg, NULL, 0, 0 )  ) != 0)
	{
		if ( bRet == -1 )
		{
			MessageBox (hwnd,TEXT ("Error!"),szAppName,MB_ICONERROR);
			return 1;
		}
		else
		{
			TranslateMessage ( &msg );
			DispatchMessage ( &msg );
		}

	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC				hdc;
	PAINTSTRUCT		ps;
	RECT			rc;
	int				x;
	int				y;

	switch (message)
	{
		case WM_CREATE:
			
			break;

		case WM_PAINT:
			hdc = BeginPaint(hwnd,&ps);
			GetClientRect (hwnd, &rc);
			x = (rc.left + rc.right) ;
			y = (rc.top + rc.bottom) ;

			TextOut(hdc,x/2 - 200,y/2,szMessage,lstrlen(szMessage));

			EndPaint(hwnd,&ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	
		default:
		return DefWindowProc( hwnd, message, wParam, lParam );	
	}
	
	return 0;
}
