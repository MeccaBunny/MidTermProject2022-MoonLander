/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
*
* YourCode.c
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

void setup()
{
	setManual();
}

void loop()
{
	if (getZ() < 200)
	{
		addDDZ(-0.5 * getDZ());
	}
}
