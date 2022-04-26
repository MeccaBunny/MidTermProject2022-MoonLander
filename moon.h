#ifndef MOON_H
#define MOON_H

void MoonSurface_create();
void endMoon();
void moonInit();
int getFactorPointX(int i);
int getFactorPointY(int i);
int getFactorPointZ(int i);
void endMoon();
int getFactorSize();
int getSurface2(double h);
double S(double x);
void setDDAllzero();
void timeInit();
double getTime();
double getDTime();
void updateTime();
double getMessageTime();
double addMessageTime(double k);
void setMessageTime(double k);
double getMoveTime();
void addMoveTime(double k);
void setMoveTime(double k);
int randint(int sn, int en);
double randd();

#endif