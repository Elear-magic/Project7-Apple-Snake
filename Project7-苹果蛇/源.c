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

/// <summary>
/// ��ȡ�ı��ļ�������
/// </summary>
/// <param name="path">�ı��ļ���·��</param>
/// <returns>��������������д��󷵻�0</returns>
int getFileRowCount(char path[]) {
	FILE* fp;
	int flag = 0, file_row = 0, count = 0;
	if ((fp = fopen(path, "r")) == NULL) {
		return 0;
	}
	while (!feof(fp)) {
		flag = fgetc(fp);
		if (flag == '\n') {
			count++;
		}
	}
	file_row = count + 1; //�������һ��
	//printf("row = %d\n", file_row);
	fclose(fp);
	return file_row;
}



int main(void) {
	getFileRowCount_TEST();
	
}

