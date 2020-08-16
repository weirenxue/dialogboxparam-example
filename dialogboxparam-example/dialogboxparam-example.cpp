// dialogboxparam-example.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "dialogboxparam-example.h"



INT_PTR WINAPI DlgProcFirst(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR WINAPI DlgProcSecond(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	// The resourse "IDM_FIRST" dialog box is displayed. 
	// If it return 1 when closed, the resource "IDD_SECOND" will be displayed.
	if (DialogBoxParam(hInstance, MAKEINTRESOURCE(IDM_FIRST), NULL, DlgProcFirst, _ttoi(lpCmdLine))) {
		DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_SECOND), NULL, DlgProcSecond, _ttoi(lpCmdLine));
	}
	return 0;
}

INT_PTR WINAPI DlgProcFirst(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		switch (wParam) {
		case IDCANCEL:
			// Close the dialog box and return value 0.
			EndDialog(hwnd, 0);
			return TRUE;
		case IDOK:
			// Close the dialog box and return value 1.
			EndDialog(hwnd, 1);
			return TRUE;
		}
		break;
	}
	return FALSE;
}
INT_PTR WINAPI DlgProcSecond(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		switch (wParam) {
		case IDCANCEL:
			// Close the dialog box and return value 0.
			EndDialog(hwnd, 0);
			return TRUE;
		case IDOK:
			// Close the dialog box and return value 0.
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}