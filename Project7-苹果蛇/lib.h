#include <stdio.h>
#include <Windows.h>
#include <io.h>

#pragma warning(disable : 4996)

/**
 * ����������ɫ
 */
void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//����������ɫ
}

/**
 * ����ƶ���(x,y)λ��
 */
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//ʹ��굽�����x��y����λ�ã���Ҫ����#include<windows.h>
}

/**
 * ���ؿ���̨���
 */
void HideCursor() {
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

/**
 * ���ÿ���̨�Ŀ��
 */
void setcmdHW(int width, int height) {
    char chCmd[32];
    sprintf(chCmd, "mode con cols=%d lines=%d", width, height);
    system(chCmd);
}

/**
 * ��տ���̨
 */
void cls() {
    system("cls");
}

/**
 * ��ͣ�������������
 */
void pause() {
    system("pause");
}

/**
 * ��ȡָ��Ŀ¼�µ������ļ���
 * �������ַ������飬�ļ���׺��������·�����������
 * ����ֵ��1=δ�ҵ���0=����
 */
int getFilesName(char* arr[], char* path, char* suffix, int count) {
    char pathstr[MAX_PATH];
    sprintf(pathstr, "%s/*.%s", path, suffix);

    struct _finddata_t fa;
    int fHandle = _findfirst(pathstr, &fa);
    if (fHandle == -1) {
        return 1;//�쳣���أ���ǰĿ¼��û���ļ�
    }
    int i = 0;
    do {
        arr[i] = (char*)malloc(MAX_PATH);
        if (arr[i]) {
            strcpy(arr[i], fa.name);
        }
        i++;
        //printf("����������ҵ��ļ�:%s\n", fa.name);
    } while ((_findnext(fHandle, &fa) == 0) && (i < count));
    _findclose(fHandle);
    return 0;
}