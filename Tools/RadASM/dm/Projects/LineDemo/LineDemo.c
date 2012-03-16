/*--------------------------------------------------
  Linedemo.c -- Line-Drawing Demonstration Program
				(c) Charles Petzold, 1998
----------------------------------------------------*/

#include <windows.h>
LRESULT CALLBACK WndProc (HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	static TCHAR szAppName[]		= TEXT( "AppName" );
	static TCHAR szWinClassName[]	= TEXT ( "ClassName" );
	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wc;
	BOOL		bRet;


	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.lpfnWndProc		= WndProc;
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= szWinClassName;

	if (!RegisterClass(&wc))
		return 1;

	hwnd = CreateWindow(
		szWinClassName,
		szAppName,
		WS_OVERLAPPEDWINDOW|WS_HSCROLL|WS_VSCROLL,
		0,
		0,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hwnd) return 1;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while ( ( bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if ( bRet == -1 )
		{
			MessageBox( hwnd, TEXT("Window Message Error"),
						TEXT("Attention"),MB_ICONERROR);
			return 0;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return msg.wParam;
	}
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int cxClient, cyClient;
	HDC				hdc;
	PAINTSTRUCT		ps;

	switch (message)
	{
		case WM_SIZE:
			cxClient = LOWORD (lParam);
			cyClient = HIWORD (lParam);
			break;

		case WM_PAINT:
			hdc = BeginPaint(hwnd,&ps);
			Rectangle (hdc, cxClient / 8, cyClient / 8,
						7 * cxClient / 8,  7 * cyClient / 8);
			
			MoveToEx	( hdc, 0, 0, NULL );
			LineTo		( hdc, cxClient, cyClient );
			
			MoveToEx	( hdc, 0, cyClient, NULL );
			LineTo		( hdc, cxClient, 0 );

			Ellipse		( hdc, cxClient / 8, cyClient / 8,
							7 * cxClient / 8, 7 * cyClient / 8);

			RoundRect	( hdc, cxClient / 4, cyClient / 4,
							3 * cxClient / 4, 3 * cyClient / 4,
								cxClient / 4, cyClient / 4);
			EndPaint(hwnd,&ps);
			break;

		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc( hwnd, message, wParam, lParam );
	}
	return 0;
}