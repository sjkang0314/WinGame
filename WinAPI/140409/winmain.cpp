#include <windows.h> 
#include <tchar.h> //유니코드 기반
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); //WndProc 윈도우의 메시지를 받는 함수
HINSTANCE g_hInst;
LPWSTR lpszClass=L"ApiBase";
//윈프로그램의 시작점
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance 
					 ,LPSTR lpszCmdParam,int nCmdShow)
{
	
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	//만들 윈도우의 스타일 및 속성을 설정
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass); //등록
	//윈도우 생성 위에서 설정을 기반으로 생성
	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow); //윈도우를 보여줌
	//WM_QUIT 메시지를 받을때까지 반복적으로 메시지를 기다림
	while(GetMessage(&Message,0,0,0)) 
	{
		TranslateMessage(&Message); //문자인지 아닌지를 검사
		DispatchMessage(&Message);
	}
	return Message.wParam;
}
//메시지를 받는 함수
LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch(iMessage) {
 case WM_CREATE:
	 return 0;
 case WM_PAINT:
	 hdc=BeginPaint(hWnd, &ps);
	 EndPaint(hWnd, &ps);
	 return 0;
 case WM_DESTROY:
	 PostQuitMessage(0);
	 return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}