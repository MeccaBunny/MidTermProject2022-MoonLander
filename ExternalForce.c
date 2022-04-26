/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
*
* ExternalForce.c
* 
* Unknown and known force to the lander.
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

void initialForce()
{
	setX(500);
	setY(500);
	setZ(2000);
	setDX(0);
	setDY(0);
	setDRoll(0);
	setDYaw(0);
	setDPitch(0);
	setDDZ(0);
}

double addfX=0;
double addfY=0;
double addfZ=0;
double addfRoll=0;
double addfYaw=0;
double addfPitch=0;

void force()
{
	addDDZ(-9.8 / 6);

	addfX += (2 * randd() - 1) * 0.01;
	addfY += (2 * randd() - 1) * 0.01;
	addfZ += (2 * randd() - 1) * 0.01;
	addfRoll += (2 * randd() - 1) * 0.0001;
	addfYaw += (2 * randd() - 1) * 0.001;
	addfPitch += (2 * randd() - 1) * 0.0001;

	addDDX(addfX);
	addDDY(addfY);
	addDDZ(addfZ);
	addDDRoll(addfRoll);
	addDDYaw(addfYaw);
	addDDPitch(addfPitch);
}
