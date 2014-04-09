#include <windows.h> 
#include <tchar.h> //�����ڵ� ���
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); //WndProc �������� �޽����� �޴� �Լ�
HINSTANCE g_hInst;
LPWSTR lpszClass=L"ApiBase";
//�����α׷��� ������
int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance 
					 ,LPSTR lpszCmdParam,int nCmdShow)
{
	
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	//���� �������� ��Ÿ�� �� �Ӽ��� ����
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
	RegisterClass(&WndClass); //���
	//������ ���� ������ ������ ������� ����
	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow); //�����츦 ������
	//WM_QUIT �޽����� ���������� �ݺ������� �޽����� ��ٸ�
	while(GetMessage(&Message,0,0,0)) 
	{
		TranslateMessage(&Message); //�������� �ƴ����� �˻�
		DispatchMessage(&Message);
	}
	return Message.wParam;
}
//�޽����� �޴� �Լ�
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