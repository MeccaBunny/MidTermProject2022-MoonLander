/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
*
* moon.c
* 
* Characteristic of the moon.
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

const int moonSize = 1000;
double** MoonSurface;

void MoonSurface_create() //This function create N*N size moon surface.
{
	double** pseudoMoon;
	pseudoMoon = (double**)malloc(sizeof(double*) * moonSize);
	for (int i = 0; i < 1000; i++)
		pseudoMoon[i] = (double *)malloc(sizeof(double) * moonSize);
	MoonSurface = pseudoMoon;
}

int factorSize = 300;
int* factorPointX;
int* factorPointY;
int* factorPointZ;

void moonInit()
{
	factorPointX = malloc(sizeof(int) * factorSize);
	factorPointY = malloc(sizeof(int) * factorSize);
	factorPointZ = malloc(sizeof(int) * factorSize);

	for (int i = 0; i < 100; i++)
	{
		factorPointX[i] = randint(5, 995);
		factorPointY[i] = randint(5, 995);
		factorPointZ[i] = randint(1, 10);
	}
	MoonSurface_create();

	gotoxy(1,21);
	for(int a = 0; a < 1000; a++)
	{
		for (int b = 0; b < 1000; b++)
		{
			double t = 0;
			for (int i = 0; i < factorSize; i++)
			{
				t += (double)getFactorPointZ(i) * exp(-(pow(b - getFactorPointX(i), 2) + pow(a - getFactorPointY(i), 2)) / 1000);
			}
			MoonSurface[a][b] = t;
		}
		if (a % 20 == 0)
		{
			printf("#");
		}
	}
	gotoxy(1, 21);
	for(int i = 0; i < 50; i++)
		printf(" ");
}

double S(double x)
{
	return 3 * pow(x, 2) - 2 * pow(x, 3);
}

int getSurface2(double h)
{
	for (int y = -9; y < 9; y++)
	{
		for (int x = -38; x < 39; x++)
		{
			//double px = getX() + x * h;
			double px = getX() + cos(getYaw()) * x * h + sin(getYaw()) * y * h;
			//double py = getY() + y * h;
			double py = getY() - sin(getYaw()) * x * h + cos(getYaw()) * y * h;

			if (((3 < px) && (px < 997)) && ((3 < py) && (py < 997)))
			{
				int ax = floor(px);
				int ay = floor(py);
				double a = MoonSurface[ax][ay];
				double b = MoonSurface[ax + 1][ay];
				double c = MoonSurface[ax][ay + 1];
				double d = MoonSurface[ax + 1][ay + 1];
				double kk = a;
				kk += (b - a)* S(px - (double)floor(px));
				kk += (c - a) * S(py - (double)floor(py));
				kk += (a - b - c + d)* S(px - (double)floor(px))* S(py - (double)floor(py));
				screenSetData(x + 38, y + 9, kk);
			}
			else
			{
				screenSetData(x + 38, y + 9, 0);
			}
		}
	}
	double max = screenGetData(0, 0);
	double min = screenGetData(0, 0);
	for (int y = 0; y < 18; y++)
	{
		for (int x = 0; x < 77; x++)
		{
			if (max < screenGetData(x, y))
				max = screenGetData(x, y);
			if (min > screenGetData(x, y))
				min = screenGetData(x, y);
		}
	}
	double k;
	int end = 0;
	for (int y = 0; y < 18; y++)
	{
		for (int x = 0; x < 77; x++)
		{
			k = screenGetData(x, y);

			if ((y == 8) && (x == 34))
			{
				double p = k;
				//gotoxy(50, 24);
				//printf("%lf", p);
				if (getZ() < 10 * p)
				{
					end = 1;
				}
			}
			//k = (double)(k - min) / max;
			k = (double)k / max;
			screenSetData(x, y, k);
		}
	}

	if (end)
		return 1;
	return 0;
}

int getFactorPointX(int i)
{
	return factorPointX[i];
}
int getFactorPointY(int i)
{
	return factorPointY[i];
}
int getFactorPointZ(int i)
{
	return factorPointZ[i];
}

void endMoon()
{
	free(factorPointX);
	free(factorPointY);
	free(factorPointZ);

	for (int i = 0; i < moonSize; i++)
	{
		free(MoonSurface[i]);
	}
	free(MoonSurface);
}

int getFactorSize()
{
	return factorSize;
}

void setDDAllzero()
{
	setDDX(0);
	setDDY(0);
	setDDZ(0);
	setDDRoll(0);
	setDDYaw(0);
	setDDPitch(0);
}

double t;
double dt;
double starting_time;
double msgt;
double mvt;

void timeInit()
{
	t = clock();
	dt = 0;
	starting_time = t;
	msgt = 0;
	mvt = 0;

}

double getTime()
{
	return t;
}
double getDTime()
{
	return dt;
}
void updateTime()
{
	dt = (double)clock() - t;
	t = clock();
}

double getMessageTime()
{
	return msgt;
}
double addMessageTime(double k)
{
	msgt += k;
}
void setMessageTime(double k)
{
	msgt = k;
}


double getMoveTime()
{
	return mvt;
}
void addMoveTime(double k)
{
	mvt += k;
}
void setMoveTime(double k)
{
	mvt = k;
}

int randint(int sn, int en)
{
	static int init = 0;
	if (!init)
	{
		srand(time(NULL));
		init = 1;
	}
	return rand() % (en - sn + 1) + sn;
}

double randd()
{
	return (double)rand() / RAND_MAX;
}