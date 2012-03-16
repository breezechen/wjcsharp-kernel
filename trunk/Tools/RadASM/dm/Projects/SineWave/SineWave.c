#include <windows.h>
#include <math.h>

const long int NUM  = 10000;
const float TWOPI  = (2.0 * 3.14159);

LRESULT CALLBACK WndProc (HWND,UINT,WPARAM,LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	static TCHAR szAppName[]		= TEXT ( "SineWave" );
	static TCHAR szWinClassName[]	= TEXT ( "PaulClass" );
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
	{
		return 1;
	}
	
	hwnd = CreateWindow(
		szWinClassName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	
	if (!hwnd)
		return 1;
		
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
	static int 		cxClient;
	static int		cyClient;
	int				i;
	HDC				hdc;
	PAINTSTRUCT		ps;
	POINT			apt[NUM];
	
	switch (message)
	{
	case WM_SIZE:
		cxClient = LOWORD (lParam);
		cyClient = HIWORD (lParam);
		break;
		
		
	case WM_PAINT:
		hdc = BeginPaint(hwnd,&ps);
		
		MoveToEx(hdc, 0,		cyClient / 2, NULL);
		LineTo	(hdc, cxClient,	cyClient / 2);
		for ( i = 0; i < NUM; i++)
		{
			apt[i].x = i * cxClient / NUM;
			apt[i].y = (int) (cyClient / 2 * (1 - sin (TWOPI * i / NUM )));
		}
		
		Polyline (hdc, apt, NUM);
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