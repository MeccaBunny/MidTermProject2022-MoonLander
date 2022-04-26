/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
*
* visualTool.c
* 
* Function to create fancy screen.
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<conio.h>

#include "moon.h"
#include "moonlander.h"
#include "VisualTool.h"
#include "ExternalForce.h"
#include "YourCode.h"

const int screenW = 100;
const int screenH = 23;
double screen[18][77] = { 0, };

void textcolor(int colorNum) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void prtFrame()
{
	textcolor(14);

	gotoxy(0, 0);
	for (int i = 0; i < screenW; i++)
		printf("*");
	for (int i = 1; i <= screenH; i++)
	{
		gotoxy(0, i);
		printf("*");
		gotoxy(screenW - 1, i);
		printf("*");
	}
	gotoxy(0, screenH);
	for (int i = 0; i < screenW; i++)
		printf("*");

	gotoxy(0, screenH - 4);
	for (int i = 0; i < screenW; i++)
		printf("*");

	for (int i = 1; i <= screenH - 4; i++)
	{
		gotoxy(20, i);
		printf("*");
	}

	gotoxy(0, 4);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 6);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 8);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 10);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 12);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 14);
	for (int i = 0; i < 20; i++)
		printf("*");

	gotoxy(0, 16);
	for (int i = 0; i < 20; i++)
		printf("*");

	textcolor(7);

	gotoxy(1, 1);
	printf("Moon Lander");
	gotoxy(1, 2);
	printf("중간 프로젝트");
	gotoxy(1, 3);
	printf("박영준2021042010");

	gotoxy(1, 5);
	printf("x:");

	gotoxy(1, 7);
	printf("y:");

	gotoxy(1, 9);
	printf("z:");

	gotoxy(1, 11);
	printf("roll:");

	gotoxy(1, 13);
	printf("yaw:");

	gotoxy(1, 15);
	printf("pitch:");
}

void prtAscii(double k)
{
	if (k > 0.9)
	{
		printf("@");
	}
	else if (k > 0.7)
	{
		printf("W");
	}
	else if (k > 0.5)
	{
		printf("&");
	}
	else if (k > 0.4)
	{
		printf("B");
	}
	else if (k > 0.3)
	{
		printf("E");
	}
	else if (k > 0.2)
	{
		printf("c");
	}
	else if (k > 0.1)
	{
		printf("=");
	}
	else if (k > 0.6)
	{
		printf("*");
	}
	else if (k > 0.03)
	{
		printf(";");
	}
	else if (k > 0.01)
	{
		printf("-");
	}
	else if (k > 0.001)
	{
		printf("'");
	}
	else
	{
		printf(" ");
	}
}

void prtSensorData()
{
	textcolor(8);
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 77; j++)
		{
			gotoxy(j + 22, i + 1);
			prtAscii(screen[i][j]);
		}
	}
	gotoxy(56,9);
	textcolor(4);
	printf("o");

}

void prtData()
{
	prtFrame();

	textcolor(7);
	gotoxy(1, 5);
	printf("x:%03lf", getX());
	gotoxy(1, 7);
	gotoxy(1, 7);
	printf("y:%03lf", getY());
	gotoxy(1, 9);
	printf("z:%03lf", getZ());
	gotoxy(1, 11);
	printf("roll:%03lf", getRoll() * 180 / 3.1415926535);
	gotoxy(1, 13);
	printf("yaw:%03lf", getYaw() * 180 / 3.1415926535);
	gotoxy(1, 15);
	printf("pitch:%03lf", getPitch() * 180 / 3.1415926535);

	addMessageTime(getDTime());
	if (getMessageTime() > 5000)
	{
		gotoxy(1, 20);
		char* msg = getPilotMSG();
		printf("%s", msg);
		setMessageTime(0);
	}
	textcolor(14);

}

void screenSetData(int x, int y, double data)
{
	screen[y][x] = data;
}

double screenGetData(int x, int y)
{
	return screen[y][x];
}

void loadingScreen()
{
	textcolor(6);
	gotoxy(1, 20);
	printf("Connecting Lander 24-FC1");

	gotoxy(30, 2);
	printf("Q: DDX+");
	gotoxy(30, 3);
	printf("A: DDX0");
	gotoxy(30, 4);
	printf("Z: DDX-");

	gotoxy(40, 2);
	printf("W: DDY+");
	gotoxy(40, 3);
	printf("S: DDY0");
	gotoxy(40, 4);
	printf("X: DDY-");

	gotoxy(50, 2);
	printf("E: DDZ+");
	gotoxy(50, 3);
	printf("D: DDZ0");
	gotoxy(50, 4);
	printf("C: DDZ-");

	gotoxy(60, 2);
	printf("R: DDRoll+");
	gotoxy(60, 3);
	printf("F: DDRoll0");
	gotoxy(60, 4);
	printf("V: DDRoll-");

	gotoxy(70, 2);
	printf("T: DDYaw+");
	gotoxy(70, 3);
	printf("G: DDYaw0");
	gotoxy(70, 4);
	printf("B: DDYaw-");

	gotoxy(80, 2);
	printf("Y: DDPitch+");
	gotoxy(80, 3);
	printf("H: DDPitch0");
	gotoxy(80, 4);
	printf("N: DDPitch-");

	textcolor(14);
}
