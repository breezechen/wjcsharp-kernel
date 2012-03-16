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