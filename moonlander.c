/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
*
* moonlander.c
* 
* Characteristic of the moonlander
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

struct physicObject {
	double X; double DX; double DDX;
	double Y; double DY; double DDY;
	double Z; double DZ; double DDZ;
	double Roll; double DRoll; double DDRoll;
	double Yaw; double DYaw; double DDYaw;
	double Pitch; double DPitch; double DDPitch;
};

struct physicObject MoonLander_coordinate;

void MoonLander_SpaceshipInit()
{
	MoonLander_coordinate.X = 0;
	MoonLander_coordinate.DX = 0;
	MoonLander_coordinate.DDX = 0;
	MoonLander_coordinate.Y = 0;
	MoonLander_coordinate.DY = 0;
	MoonLander_coordinate.DDY = 0;
	MoonLander_coordinate.Z = 0;
	MoonLander_coordinate.DZ = 0;
	MoonLander_coordinate.DDZ = 0;
	MoonLander_coordinate.Roll = 0;
	MoonLander_coordinate.DRoll = 0;
	MoonLander_coordinate.DDRoll = 0;
	MoonLander_coordinate.Yaw = 0;
	MoonLander_coordinate.DYaw = 0;
	MoonLander_coordinate.DDYaw = 0;
	MoonLander_coordinate.Pitch = 0;
	MoonLander_coordinate.DPitch = 0;
	MoonLander_coordinate.DDPitch = 0;
}

//////////////////////////////////////////
void setX(double n)
{
	MoonLander_coordinate.X = n;
}
void setDX(double n)
{
	MoonLander_coordinate.DX = n;
}
void setDDX(double n)
{
	MoonLander_coordinate.DDX = n;
}
//////////////////////////////////////////
void setY(double n)
{
	MoonLander_coordinate.Y = n;
}
void setDY(double n)
{
	MoonLander_coordinate.DY = n;
}
void setDDY(double n)
{
	MoonLander_coordinate.DDY = n;
}
//////////////////////////////////////////
void setZ(double n)
{
	MoonLander_coordinate.Z = n;
}
void setDZ(double n)
{
	MoonLander_coordinate.DZ = n;
}
void setDDZ(double n)
{
	MoonLander_coordinate.DDZ = n;
}
//////////////////////////////////////////
void setRoll(double n)
{
	MoonLander_coordinate.Roll = n;
}
void setDRoll(double n)
{
	MoonLander_coordinate.DRoll = n;
}
void setDDRoll(double n)
{
	MoonLander_coordinate.DDRoll = n;
}
//////////////////////////////////////////
void setYaw(double n)
{
	MoonLander_coordinate.Yaw = n;
}
void setDYaw(double n)
{
	MoonLander_coordinate.DYaw = n;
}
void setDDYaw(double n)
{
	MoonLander_coordinate.DDYaw = n;
}
//////////////////////////////////////////
void setPitch(double n)
{
	MoonLander_coordinate.Pitch = n;
}
void setDPitch(double n)
{
	MoonLander_coordinate.DPitch = n;
}
void setDDPitch(double n)
{
	MoonLander_coordinate.DDPitch = n;
}
/////////////////////////////////////////////////////////
double getX()
{
	return MoonLander_coordinate.X;
}
double getDX()
{
	return MoonLander_coordinate.DX;
}
double getDDX()
{
	return MoonLander_coordinate.DDX;
}
//////////////////////////////////////////
double getY()
{
	return MoonLander_coordinate.Y;
}
double getDY()
{
	return MoonLander_coordinate.DY;
}
double getDDY()
{
	return MoonLander_coordinate.DDY;
}
//////////////////////////////////////////
double getZ()
{
	return MoonLander_coordinate.Z;
}
double getDZ()
{
	return MoonLander_coordinate.DZ;
}
double getDDZ()
{
	return MoonLander_coordinate.DDZ;
}
//////////////////////////////////////////
double getRoll()
{
	return MoonLander_coordinate.Roll;
}
double getDRoll()
{
	return MoonLander_coordinate.DRoll;
}
double getDDRoll()
{
	return MoonLander_coordinate.DDRoll;
}
//////////////////////////////////////////
double getYaw()
{
	return MoonLander_coordinate.Yaw;
}
double getDYaw()
{
	return MoonLander_coordinate.DYaw;
}
double getDDYaw()
{
	return MoonLander_coordinate.DDYaw;
}
//////////////////////////////////////////
double getPitch()
{
	return MoonLander_coordinate.Pitch;
}
double getDPitch()
{
	return MoonLander_coordinate.DPitch;
}
double getDDPitch()
{
	return MoonLander_coordinate.DDPitch;
}
//////////////////////////////////////////
void addX(double n)
{
	MoonLander_coordinate.X += n;
}
void addDX(double n)
{
	MoonLander_coordinate.DX += n;
}
void addDDX(double n)
{
	MoonLander_coordinate.DDX += n;
}
//////////////////////////////////////////
void addY(double n)
{
	MoonLander_coordinate.Y += n;
}
void addDY(double n)
{
	MoonLander_coordinate.DY += n;
}
void addDDY(double n)
{
	MoonLander_coordinate.DDY += n;
}
//////////////////////////////////////////
void addZ(double n)
{
	MoonLander_coordinate.Z += n;
}
void addDZ(double n)
{
	MoonLander_coordinate.DZ += n;
}
void addDDZ(double n)
{
	MoonLander_coordinate.DDZ += n;
}
//////////////////////////////////////////
void addRoll(double n)
{
	MoonLander_coordinate.Roll += n;
}
void addDRoll(double n)
{
	MoonLander_coordinate.DRoll += n;
}
void addDDRoll(double n)
{
	MoonLander_coordinate.DDRoll += n;
}
//////////////////////////////////////////
void addYaw(double n)
{
	MoonLander_coordinate.Yaw += n;
}
void addDYaw(double n)
{
	MoonLander_coordinate.DYaw += n;
}
void addDDYaw(double n)
{
	MoonLander_coordinate.DDYaw += n;
}
//////////////////////////////////////////
void addPitch(double n)
{
	MoonLander_coordinate.Pitch += n;
}
void addDPitch(double n)
{
	MoonLander_coordinate.DPitch += n;
}
void addDDPitch(double n)
{
	MoonLander_coordinate.DDPitch += n;
}
//////////////////////////////////////////

void MoonLander_phsics(double dt) {
	dt = dt / 1000;
	MoonLander_coordinate.X = 0.5 * MoonLander_coordinate.DDX * dt * dt + MoonLander_coordinate.DX * dt + MoonLander_coordinate.X;
	MoonLander_coordinate.Y = 0.5 * MoonLander_coordinate.DDY * dt * dt + MoonLander_coordinate.DY * dt + MoonLander_coordinate.Y;
	MoonLander_coordinate.Z = 0.5 * MoonLander_coordinate.DDZ * dt * dt + MoonLander_coordinate.DZ * dt + MoonLander_coordinate.Z;
	MoonLander_coordinate.Roll = 0.5 * MoonLander_coordinate.DDRoll * dt * dt + MoonLander_coordinate.DRoll * dt + MoonLander_coordinate.Roll;
	MoonLander_coordinate.Yaw = 0.5 * MoonLander_coordinate.DDYaw * dt * dt + MoonLander_coordinate.DYaw * dt + MoonLander_coordinate.Yaw;
	MoonLander_coordinate.Pitch = 0.5 * MoonLander_coordinate.DDPitch * dt * dt + MoonLander_coordinate.DPitch * dt + MoonLander_coordinate.Pitch;
	MoonLander_coordinate.DX = MoonLander_coordinate.DDX * dt + MoonLander_coordinate.DX;
	MoonLander_coordinate.DY = MoonLander_coordinate.DDY * dt + MoonLander_coordinate.DY;
	MoonLander_coordinate.DZ = MoonLander_coordinate.DDZ * dt + MoonLander_coordinate.DZ;
	MoonLander_coordinate.DRoll = MoonLander_coordinate.DDRoll * dt + MoonLander_coordinate.DRoll;
	MoonLander_coordinate.DYaw = MoonLander_coordinate.DDYaw * dt + MoonLander_coordinate.DYaw;
	MoonLander_coordinate.DPitch = MoonLander_coordinate.DDPitch * dt + MoonLander_coordinate.DPitch;
}

double ThrustDDXn = 0;
double ThrustDDYn = 0;
double ThrustDDZn = 0;
double ThrustDDRolln = 0;
double ThrustDDYawn = 0;
double ThrustDDPitchn = 0;

void ThrustDDX(double n)
{
	ThrustDDXn = n;
}
void ThrustDDY(double n)
{
	ThrustDDYn = n;
}
void ThrustDDZ(double n)
{
	ThrustDDZn = n;
}
void ThrustDDRoll(double n)
{
	ThrustDDRolln = n;
}

void ThrustDDYaw(double n)
{
	ThrustDDYawn = n;
}
void ThrustDDPitch(double n)
{
	ThrustDDPitchn = n;
}

int keyInput;
void manual()
{
	if (_kbhit())
	{
		keyInput = _getch();
		//x qaz
		if (keyInput == 113)
		{
			ThrustDDX(1);
		}
		if (keyInput == 97)
		{
			ThrustDDX(0);
		}
		if (keyInput == 122)
		{
			ThrustDDX(-1);
		}
		//y wsx
		if (keyInput == 119)
		{
			ThrustDDY(1);
		}
		if (keyInput == 115)
		{
			ThrustDDY(0);
		}
		if (keyInput == 120)
		{
			ThrustDDY(-1);
		}
		//z edc
		if (keyInput == 101)
		{
			ThrustDDZ(10);
		}
		if (keyInput == 100)
		{
			ThrustDDZ(0);
		}
		if (keyInput == 109)
		{
			ThrustDDX(-10);
		}
		//roll rfv
		if (keyInput == 114)
		{
			ThrustDDRoll(0.3);
		}
		if (keyInput == 102)
		{
			ThrustDDRoll(0);
		}
		if (keyInput == 118)
		{
			ThrustDDRoll(-0.3);
		}
		//yaw tgb
		if (keyInput == 116)
		{
			ThrustDDYaw(0.3);
		}
		if (keyInput == 103)
		{
			ThrustDDYaw(0);
		}
		if (keyInput == 98)
		{
			ThrustDDYaw(-0.3);
		}
		//pitch yhn
		if (keyInput == 121)
		{
			ThrustDDPitch(0.3);
		}
		if (keyInput == 104)
		{
			ThrustDDPitch(0);
		}
		if (keyInput == 110)
		{
			ThrustDDPitch(-0.3);
		}
	}
}

void thrusterLoop()
{
	//addDDX(ThrustDDXn * cos(getYaw()) + ThrustDDYn * sin(getYaw()));
	//addDDY(-ThrustDDXn * sin(getYaw()) + ThrustDDYn * cos(getYaw()));
	addDDX(ThrustDDXn);
	addDDY(ThrustDDYn);
	addDDZ(ThrustDDZn);
	addDDRoll(ThrustDDRolln);
	addDDYaw(ThrustDDYawn);
	addDDPitch(ThrustDDPitchn);
}

int getKey()
{
	return keyInput;
}
int manualON = 0;
void setManual()
{
	manualON = 1;
}
int  isManual()
{
	if (manualON)
		return 1;
	return 0;
}

int landed()
{
	if ((getX() < 0) || (getX() > 1000) || (getY() < 0) || (getY() > 1000))
	{
		return 0;
	}

	if (abs(getDX()) < 5)
	{
		if (abs(getDY()) < 5)
		{
			if (abs(getDZ() < 5))
			{
				if (abs(getDDX()) < 5)
				{
					if (abs(getDDY()) < 5)
					{
						if (abs(getDDZ() < 5))
						{
							return 1;
						}
					}
				}
			}
		}

	}
	return 0;
}

void end()
{
	if (landed())
	{
		gotoxy(1, 22);
		printf("landing complete");
	}
	else
	{
		gotoxy(1, 22);
		printf("landing failed");
	}
	textcolor(15);
	gotoxy(0, 24); // h = 23
	Sleep(2000);

}

//pilot msg
char msg1[] = "Tom: Reporting for duty.                                      ";
char msg2[] = "Tom: Major Tom to ground control. Moon is AMAZING!            ";
char msg3[] = "Tom: Planet Earth is blue.                                    ";
char* msgs[] = { msg1, msg2, msg3 };

char* getPilotMSG()
{
	int i = randint(0, 2);
	return msgs[i];
}

void pilotInit()
{
	gotoxy(1, 20);
	printf("%s", getPilotMSG());
}
