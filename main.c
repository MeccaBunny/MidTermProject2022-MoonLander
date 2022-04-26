/**************************************************************
* 오픈소스기초프로젝트 중간 프로젝트 (달 착륙 시스템)
* 충북대학교 지능로봇공학과 2021042010 박영준
* 
* main.c
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

int main()
{
	prtSensorData(); 
	prtData();
	loadingScreen(); // Display a loading screen.
	moonInit(); // Allocate moon surface.
				// Reason why dinamic allocation is needed is because surface of the moon is too big to store in stack.
				// It is more safe and efficient to allocate moon surface to heap.
	timeInit();
	MoonLander_SpaceshipInit();
	pilotInit();

	initialForce(); // Set Initial Force to the moonLander.
	
	setup(); // User's Code.

	int ON = 1;
	while (ON)
	{
		updateTime();
		MoonLander_phsics(getDTime()); // Move Lander according to dt.
		if (getSurface2( (getZ() / 100 + 0.1))) // getSurface get surface data of the moon. And set the sensor data to screen.
		{										// returns 1 if landed.
			ON = 0;
		}
		prtSensorData(); // Display sensor data to screen.
		prtData(); // Display lander's X, Y, Z, Roll, Yaw, Pitch.

		setDDAllzero(); // Set all force to zero to add every force given to the lander.
		force(); // external Force.
		if (isManual()) // If User Set code to manual, is Manual is 1.
		{
			manual(); // Get keyboard input and move lander by force.
			thrusterLoop();

			gotoxy(1, 17);
			printf("keyboard: %d", getKey()); // Display user's key input.
		}

		loop(); // User's Code.
		
		Sleep(1); // Make sure 0 < dt.
	}

	prtSensorData(); 
	prtData();

	endMoon(); // free MoonSurface
	end();
	return 0;
}