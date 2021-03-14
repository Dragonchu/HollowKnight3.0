#pragma once
#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#define hunterwidth 180
#define hunterheight 140

extern IMAGE hunter[8];
extern IMAGE hunter_mask[8];
extern int hunterx;
extern int huntery;
extern int fire;
extern int bulletx;
extern int bullety;
extern int bulletr;
extern int bulleta;
extern int hunterfall;
extern int firstfire;
extern int hunterblood;
extern int score;

void loadmonsterimage();
void mycleardevice();
void huntermake();
void hunterattack();
void ifhunterdie();