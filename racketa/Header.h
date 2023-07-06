#pragma once
#include "windows.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
#include <thread>

const int mapH = 30;       // 1 к 4, ширина к высоте
const int  mapW = 120;

char map[mapH][mapW + 1];
int count = 0;

typedef struct
{
	int x;
	int y;
	int width;
} TRacket;

typedef struct
{
	int x;
	int Sy;
	int Ly;
	int LxMin;
	int ex;
	int Lex;
	int Swidth;
	int Lwidth;
	float uskor;
	float Dtime;
	float speed;
	int Largeheight;
	int hp;
} TBall;

typedef struct
{
	int x1;
	int y1;
	float dx1;
	float dy1;
	int x2;
	int y2;
	float dx2;
	float dy2;
	float speed;
	float alpha;
	int damage;
} TBullet;

TRacket racket;
TBall ball;
TBullet bullet;
bool fire = false;
bool lose = false;



void setcur(int x, int y);
void ininRacket();
void putRacket();
void racketMove(int x, int y);
void initMap();
void showMap();
void initbullet();
void putbullet();
void firebullet();
void movebullet(float x, float y);
void initBall(); 
void putLargeBall();
void slow();