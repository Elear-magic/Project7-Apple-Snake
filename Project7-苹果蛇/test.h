
void GameErrorlnfo(wchar_t info[]);

void GameErrorlnfo_TEST() {
	GameErrorlnfo(L"123123");
}

int getFileRowCount(char path[]);

void getFileRowCount_TEST() {
	int r = getFileRowCount("map/1.txt");
	printf("�ļ�������%d\n", r);
}