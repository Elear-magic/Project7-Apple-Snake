#include <stdio.h>
#include <Windows.h>

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
void HideCursor(){
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

/**
 * ���ÿ���̨�Ŀ��
 */
void setcmdHW(int width,int height) {
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