#include "lib.h"//ͷ�ļ���lib��
#include "test.h"//ÿ�������Ĳ�������������

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



void GameErrorlnfo(wchar_t info[]) {
	wchar_t text[100];
	wsprintf(text, L"%s", info);
	MessageBox(NULL, text, TEXT("��������"), MB_ICONERROR);
}



int main(void) {
	getFileRowCount_TEST();
	
}

