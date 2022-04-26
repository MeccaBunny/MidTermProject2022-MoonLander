#ifndef VISUALTOOL_H
#define VISUALTOOL_H

void textcolor(int colorNum);
void gotoxy(int x, int y);
void prtFrame();
void prtAscii(double k);
void prtSensorData();
void prtData();
void screenSetData(int x, int y, double data);
double screenGetData(int x, int y);
void loadingScreen();

#endif