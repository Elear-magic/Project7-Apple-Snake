#include <stdio.h>
#include <Windows.h>
#include <io.h>

#pragma warning(disable : 4996)

/**
 * ����������ɫ
 */
void Color(int c) {
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
 * �������ַ������飬����·�����ļ���׺�����������
 * ����ֵ��-1=δ�ҵ���0=����
 */
int getFilesName(char* arr[], char* path, char* suffix, int count) {
    char pathstr[MAX_PATH];
    sprintf(pathstr, "%s/*.%s", path, suffix);

    struct _finddata_t fa;
    int fHandle = _findfirst(pathstr, &fa);
    if (fHandle == -1) {
        return -1;//�쳣���أ���ǰĿ¼��û���ļ�
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

/**
 * ��ȡָ��Ŀ¼�£�ָ�������ļ�������
 * ����������·�����ļ���׺��
 * ����ֵ��ָ�������ļ�������
 */
int getFilesNum(char* path, char* suffix) {
    char pathstr[MAX_PATH];
    sprintf(pathstr, "%s/*.%s", path, suffix);

    struct _finddata_t fa;
    int fHandle = _findfirst(pathstr, &fa);
    if (fHandle == -1) {
        return 0;
    }
    int i = 0;
    do {
        i++;
    } while ((_findnext(fHandle, &fa) == 0));
    _findclose(fHandle);

    return i;
}

//�����ƣ�sas
#define sas(a, b) StrAndStr(a, b)
/**
 * ƴ���ַ�������ǿ�棩
 * �������ַ���a���ַ���b������Ϊ������
 * ����ֵ���ַ���ָ�룬0Ϊ�쳣
 */
char* StrAndStr(char* a, char* b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (strlen(a) == 0 || strlen(b) == 0) {
        return 0;
    }
    char* s = (char*)malloc(strlen(a) + strlen(b) + 1);
    if (s) {
        return strcat(strcpy(s, a), b);
    }
}

//�����ƣ�printcf
#define printcf(color, _Format, ...) printColorf(color, _Format, __VA_ARGS__)
/**
 * printf �Ųʰ�
 * ��������ɫ����ʽ�ַ����������б�
 * 0   =   ����ɫ  * 8   =   ��ɫ
 * 1   =   ��ɫ    * 9   =   ��ɫ
 * 2   =   ��ɫ    * 10  =   ����ɫ
 * 3   =   ��ɫ    * 11  =   ����ɫ
 * 4   =   ����ɫ  * 12  =   ��ǳ��ɫ
 * 5   =   ��ɫ    * 13  =   ����ɫ
 * 6   =   ��ɫ    * 14  =   ����ɫ
 * 7   =   ��ɫ    * 15  =   ����ɫ
 */
void printColorf(int color, char const* const _Format, ...) {
    if (color == 0) {
        va_list args;
        va_start(args, _Format);
        vprintf(_Format, args);
        va_end(args);
    }
    else {
        Color(color - 1);
        va_list args;
        va_start(args, _Format);
        vprintf(_Format, args);
        va_end(args);
        Color(15);
    }
}