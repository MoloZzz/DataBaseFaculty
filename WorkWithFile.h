#pragma once

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include"Structures.h"


#define ESC 27
#define UP 72
#define DOWN 80
#define ENTER 13

using namespace std;



HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void d(short x, short y)
{
    SetConsoleCursorPosition(h, { x,y });
}

void ConsoleCursorVisible(bool show, short size)
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(h, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(h, &structCursorInfo);
}



void menu() {
    int data = 0;


    SetConsoleTitle(L"NLS");
    system("CLS");
    setlocale(0, "RU");
    ConsoleCursorVisible(false, 100);
    string T[] = {"Start","Exit"};

    char aT = 0;
    char c;

    while (true)
    {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++)
        {
            if (i == aT) SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(h, FOREGROUND_RED);
            d(x, y++);
            cout << T[i] << endl;
        }

        c = _getch();
        if (c == -32) c = _getch();
        switch (c)
        {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0)
                --aT;
            break;
        case DOWN:
            if (aT < size(T) - 1)
                ++aT;
            break;
        case ENTER:
            switch (aT)
            {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "Start" << endl;
                Sleep(1500);
                system("CLS");
                break;
            }
            case 1:
            {
                exit(0);
                break;
            }
            default:
                cout << "" << (char)c << endl;
            }
        }
    }
}
