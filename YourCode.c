/**************************************************************
* ���¼ҽ�����������Ʈ �߰� ������Ʈ (�� ���� �ý���)
* ��ϴ��б� ���ɷκ����а� 2021042010 �ڿ���
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
