#include "lib.h"

/// <summary>
/// zhushi
/// </summary>
/// <returns>fanhui</returns>
int isExitgame()
{
	int x;
	x = MessageBox(NULL, TEXT("�Ƿ�Ҫ�˳���Ϸ"), TEXT("�Ի���"), MB_YESNO);
	if (x == IDYES)
	{
		return 1;
	}
	else { return 0; }

}

/// <summary>
/// ��ʾ�ύ
/// </summary>
void aaaa() {

}

void GameErrorlnfo(wchar_t info[]) {
	wchar_t text[100];
	wsprintf(text, L"%s", info);
	MessageBox(NULL, text, TEXT("��������"), MB_ICONERROR);
}

void GameErrorlnfo_TEST() {
	GameErrorlnfo(L"123123");
}

int main(void) {

	GameErrorlnfo_TEST();
}

