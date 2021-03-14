#include "MonsterAction.h"
#include "HornetAction.h"
IMAGE hunter[8];
IMAGE hunter_mask[8];
int hunterx;
int huntery;
int huntervx;
int huntervy;
int fire;
int bulletx = -10;
int bullety;
int bulletr = 10;
int bulleta;
int firstfire;
int hunterfall = 2;
int hunterblood = 100;
int score = 0;

void loadmonsterimage()
{
	loadimage(&hunter[0], _T("../monster/hunter/hunter (1).gif"), hunterwidth, hunterheight);
	loadimage(&hunter[1], _T("../monster/hunter/hunter (3).gif"), hunterwidth, hunterheight);
	loadimage(&hunter[2], _T("../monster/hunter/hunter (4).gif"), hunterwidth, hunterheight);
	loadimage(&hunter[3], _T("../monster/hunter/hunter (5).gif"), hunterwidth, hunterheight);
	loadimage(&hunter[4], _T("../monster/hunter/hunter (6).gif"), hunterwidth, hunterheight);
	loadimage(&hunter[5], _T("../monster/hunter/hunter (7).gif"), hunterwidth, hunterheight);
	loadimage(&hunter[6], _T("../monster/hunter/hunter (8).gif"), hunterwidth, hunterheight);

	loadimage(&hunter_mask[0], _T("../monster/hunter_mask/hunter (1).bmp"), hunterwidth, hunterheight);
	loadimage(&hunter_mask[1], _T("../monster/hunter_mask/hunter (3).bmp"), hunterwidth, hunterheight);
	loadimage(&hunter_mask[2], _T("../monster/hunter_mask/hunter (4).bmp"), hunterwidth, hunterheight);
	loadimage(&hunter_mask[3], _T("../monster/hunter_mask/hunter (5).bmp"), hunterwidth, hunterheight);
	loadimage(&hunter_mask[4], _T("../monster/hunter_mask/hunter (6).bmp"), hunterwidth, hunterheight);
	loadimage(&hunter_mask[5], _T("../monster/hunter_mask/hunter (7).bmp"), hunterwidth, hunterheight);
	loadimage(&hunter_mask[6], _T("../monster/hunter_mask/hunter (8).bmp"), hunterwidth, hunterheight);
}
void mycleardevice()
{
	ifknightdie();
	ifhunterdie();
	putimage(0, 0, &img_bkpicture);
	for (size_t i = 0; i < knightblood/5; i++)
	{
		putimage(bloodwidth*i, 0, &img_blood_mask, SRCAND);
		putimage(bloodwidth*i, 0, &img_blood, SRCPAINT);
	}
	hunterattack();
	solidcircle(knightbulletx, knightbullety, knightbulletr);
	knightbullety-=10;
}
void huntermake()
{
	srand((unsigned)time(NULL));
	hunterx = rand() % (width - hunterwidth);
	huntery = rand() % (height / 2);
}
void hunterattack()
{
	if (firstfire == 0)
	{
		bulleta = 0;
		bulletx = hunterx + hunterwidth / 2;
		bullety = huntery + hunterheight;
		firstfire = 1;
	}

	if (knightx >= hunterx)
	{
		hunterx += 2;
	}
	else
	{
		hunterx -= 2;
	}

	if (knighty >= huntery)
	{
		huntery += hunterfall;;
	}

	if (huntery >= height - knightheight - 50)
	{
		hunterfall *= -1;
	}
	if (huntery <= 0)
	{
		hunterfall *= -1;
	}

	if (hunterx <= 0)
	{
		hunterx = 0;
	}
	else if (hunterx >= width - hunterwidth)
	{
		hunterx = width - hunterwidth;
	}
	if (huntery <= 0)
	{
		huntery = 0;
	}
	else if (huntery >= height - hunterheight)
	{
		huntery = height - hunterheight;
	}

	if (bullety > height - bulletr)
	{
		fire = rand() % 13;
		if (fire == 5)
		{
			bulleta = 0;
			bulletx = hunterx + hunterwidth / 2;
			bullety = huntery + hunterheight;
		}
	}

	putimage(hunterx, huntery, &hunter_mask[fortogether % 6], NOTSRCERASE);
	putimage(hunterx, huntery, &hunter[fortogether % 6], SRCINVERT);
	solidcircle(bulletx, bullety, bulletr);
	bullety += bulleta;
	bulleta++;

	fortogether++;
}
void ifhunterdie()
{
	if (hunterblood == 0)
	{
		Sleep(1000);
		gamewin();
	}
	if (knightbulletx >= hunterx && knightbulletx<= hunterx+hunterwidth && knightbullety<=huntery+hunterheight && knightbullety>=huntery)
	{
		hunterblood--;
		score++;
		Sleep(50);
	}
}