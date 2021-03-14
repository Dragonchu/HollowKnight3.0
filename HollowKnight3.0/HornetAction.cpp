#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <conio.h>
#include "HornetAction.h"
#include "MonsterAction.h"
int state;
char forekey;
char key = 'd';
int knightx = 0;
int knighty = height - knightheight + 25;
int knightbulletx;
int knightbullety;
int knightbulletr = 5;
int knightblood = 30;
int cgplaystate = cgnplay;

int fortogether = 0;

/*****背景*******/
IMAGE img_bkpicture;

/****攻击****/
IMAGE attackr[13];
IMAGE attackr_mask[13];
IMAGE attack[13];
IMAGE attack_mask[13];
/*****向右走*******/
IMAGE left_to_right[7];
IMAGE left_to_right_mask[7];
IMAGE right[8];
IMAGE right_mask[8];
/****向左走*******/
IMAGE right_to_left[7];
IMAGE right_to_left_mask[7];
IMAGE left[9];
IMAGE left_mask[9];

IMAGE img_menu[8];
IMAGE img_gameover[16];

IMAGE img_cg1[49];
IMAGE img_cg2[50];

IMAGE img_blood;
IMAGE img_blood_mask;

void loadknightimage()
{
	/***********************加载背景***********************************/
	loadimage(&img_bkpicture, _T("../background/bkpicture.jpg"), 640, 480);

	/*********************************加载攻击图片*******************************************/
	loadimage(&attack[0], _T("../hornetattack/attack (1).gif"), knightwidth, knightheight);
	loadimage(&attack[1], _T("../hornetattack/attack (2).gif"), knightwidth, knightheight);
	loadimage(&attack[2], _T("../hornetattack/attack (3).gif"), knightwidth, knightheight);
	loadimage(&attack[3], _T("../hornetattack/attack (4).gif"), knightwidth, knightheight);
	loadimage(&attack[4], _T("../hornetattack/attack (5).gif"), knightwidth, knightheight);
	loadimage(&attack[5], _T("../hornetattack/attack (6).gif"), knightwidth, knightheight);
	loadimage(&attack[6], _T("../hornetattack/attack (7).gif"), knightwidth, knightheight);
	loadimage(&attack[7], _T("../hornetattack/attack (8).gif"), knightwidth, knightheight);
	loadimage(&attack[8], _T("../hornetattack/attack (9).gif"), knightwidth, knightheight);
	loadimage(&attack[9], _T("../hornetattack/attack (10).gif"), knightwidth, knightheight);
	loadimage(&attack[10], _T("../hornetattack/attack (11).gif"), knightwidth, knightheight);
	loadimage(&attack[11], _T("../hornetattack/attack (12).gif"), knightwidth, knightheight);
	loadimage(&attack[12], _T("../hornetattack/attack (13).gif"), knightwidth, knightheight);

	loadimage(&attack_mask[0], _T("../hornetattack_mask/attack_mask (1).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[1], _T("../hornetattack_mask/attack_mask (2).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[2], _T("../hornetattack_mask/attack_mask (3).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[3], _T("../hornetattack_mask/attack_mask (4).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[4], _T("../hornetattack_mask/attack_mask (5).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[5], _T("../hornetattack_mask/attack_mask (6).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[6], _T("../hornetattack_mask/attack_mask (7).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[7], _T("../hornetattack_mask/attack_mask (8).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[8], _T("../hornetattack_mask/attack_mask (9).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[9], _T("../hornetattack_mask/attack_mask (10).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[10], _T("../hornetattack_mask/attack_mask (11).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[11], _T("../hornetattack_mask/attack_mask (12).bmp"), knightwidth, knightheight);
	loadimage(&attack_mask[12], _T("../hornetattack_mask/attack_mask (13).bmp"), knightwidth, knightheight);
	/***向右***/
	loadimage(&attackr[0], _T("../hornetattackr/attack (1).gif"), knightwidth, knightheight);
	loadimage(&attackr[1], _T("../hornetattackr/attack (2).gif"), knightwidth, knightheight);
	loadimage(&attackr[2], _T("../hornetattackr/attack (3).gif"), knightwidth, knightheight);
	loadimage(&attackr[3], _T("../hornetattackr/attack (4).gif"), knightwidth, knightheight);
	loadimage(&attackr[4], _T("../hornetattackr/attack (5).gif"), knightwidth, knightheight);
	loadimage(&attackr[5], _T("../hornetattackr/attack (6).gif"), knightwidth, knightheight);
	loadimage(&attackr[6], _T("../hornetattackr/attack (7).gif"), knightwidth, knightheight);
	loadimage(&attackr[7], _T("../hornetattackr/attack (8).gif"), knightwidth, knightheight);
	loadimage(&attackr[8], _T("../hornetattackr/attack (9).gif"), knightwidth, knightheight);
	loadimage(&attackr[9], _T("../hornetattackr/attack (10).gif"), knightwidth, knightheight);
	loadimage(&attackr[10], _T("../hornetattackr/attack (11).gif"), knightwidth, knightheight);
	loadimage(&attackr[11], _T("../hornetattackr/attack (12).gif"), knightwidth, knightheight);
	loadimage(&attackr[12], _T("../hornetattackr/attack (13).gif"), knightwidth, knightheight);

	loadimage(&attackr_mask[0], _T("../hornetattackr_mask/attack_mask (1).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[1], _T("../hornetattackr_mask/attack_mask (2).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[2], _T("../hornetattackr_mask/attack_mask (3).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[3], _T("../hornetattackr_mask/attack_mask (4).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[4], _T("../hornetattackr_mask/attack_mask (5).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[5], _T("../hornetattackr_mask/attack_mask (6).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[6], _T("../hornetattackr_mask/attack_mask (7).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[7], _T("../hornetattackr_mask/attack_mask (8).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[8], _T("../hornetattackr_mask/attack_mask (9).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[9], _T("../hornetattackr_mask/attack_mask (10).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[10], _T("../hornetattackr_mask/attack_mask (11).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[11], _T("../hornetattackr_mask/attack_mask (12).bmp"), knightwidth, knightheight);
	loadimage(&attackr_mask[12], _T("../hornetattackr_mask/attack_mask (13).bmp"), knightwidth, knightheight);
	/*************************************************************************************/


	/**********************************加载向右移动图片*********************************************************/
	loadimage(&left_to_right[0], _T("../hornetmove/left_to_right/left_to_right (1).gif"), kmovewidth, kmoveheight);
	loadimage(&left_to_right[1], _T("../hornetmove/left_to_right/left_to_right (2).gif"), kmovewidth, kmoveheight);
	loadimage(&left_to_right[2], _T("../hornetmove/left_to_right/left_to_right (3).gif"), kmovewidth, kmoveheight);
	loadimage(&left_to_right[3], _T("../hornetmove/left_to_right/left_to_right (4).gif"), kmovewidth, kmoveheight);
	loadimage(&left_to_right[4], _T("../hornetmove/left_to_right/left_to_right (5).gif"), kmovewidth, kmoveheight);
	loadimage(&left_to_right[5], _T("../hornetmove/left_to_right/left_to_right (6).gif"), kmovewidth, kmoveheight);
	loadimage(&left_to_right[6], _T("../hornetmove/left_to_right/left_to_right (7).gif"), kmovewidth, kmoveheight);

	loadimage(&right[0], _T("../hornetmove/right/right (1).gif"), kmovewidth, kmoveheight);
	loadimage(&right[1], _T("../hornetmove/right/right (2).gif"), kmovewidth, kmoveheight);
	loadimage(&right[2], _T("../hornetmove/right/right (3).gif"), kmovewidth, kmoveheight);
	loadimage(&right[3], _T("../hornetmove/right/right (4).gif"), kmovewidth, kmoveheight);
	loadimage(&right[4], _T("../hornetmove/right/right (5).gif"), kmovewidth, kmoveheight);
	loadimage(&right[5], _T("../hornetmove/right/right (6).gif"), kmovewidth, kmoveheight);
	loadimage(&right[6], _T("../hornetmove/right/right (7).gif"), kmovewidth, kmoveheight);

	loadimage(&left_to_right_mask[0], _T("../hornetmove_mask/left_to_right/left_to_right_mask (1).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_to_right_mask[1], _T("../hornetmove_mask/left_to_right/left_to_right_mask (2).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_to_right_mask[2], _T("../hornetmove_mask/left_to_right/left_to_right_mask (3).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_to_right_mask[3], _T("../hornetmove_mask/left_to_right/left_to_right_mask (4).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_to_right_mask[4], _T("../hornetmove_mask/left_to_right/left_to_right_mask (5).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_to_right_mask[5], _T("../hornetmove_mask/left_to_right/left_to_right_mask (6).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_to_right_mask[6], _T("../hornetmove_mask/left_to_right/left_to_right_mask (7).bmp"), kmovewidth, kmoveheight);

	loadimage(&right_mask[0], _T("../hornetmove_mask/right/right_mask (1).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_mask[1], _T("../hornetmove_mask/right/right_mask (2).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_mask[2], _T("../hornetmove_mask/right/right_mask (3).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_mask[3], _T("../hornetmove_mask/right/right_mask (4).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_mask[4], _T("../hornetmove_mask/right/right_mask (5).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_mask[5], _T("../hornetmove_mask/right/right_mask (6).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_mask[6], _T("../hornetmove_mask/right/right_mask (7).bmp"), kmovewidth, kmoveheight);

	/****************************************************************************************************/

	/*****************************************向左走*************************************************************/
	loadimage(&right_to_left[0], _T("../hornetmove/right_to_left/right_to_left (1).gif"), kmovewidth, kmoveheight);
	loadimage(&right_to_left[1], _T("../hornetmove/right_to_left/right_to_left (2).gif"), kmovewidth, kmoveheight);
	loadimage(&right_to_left[2], _T("../hornetmove/right_to_left/right_to_left (3).gif"), kmovewidth, kmoveheight);
	loadimage(&right_to_left[3], _T("../hornetmove/right_to_left/right_to_left (4).gif"), kmovewidth, kmoveheight);
	loadimage(&right_to_left[4], _T("../hornetmove/right_to_left/right_to_left (5).gif"), kmovewidth, kmoveheight);
	loadimage(&right_to_left[5], _T("../hornetmove/right_to_left/right_to_left (6).gif"), kmovewidth, kmoveheight);

	loadimage(&right_to_left_mask[0], _T("../hornetmove_mask/right_to_left/right_to_left_mask (1).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_to_left_mask[1], _T("../hornetmove_mask/right_to_left/right_to_left_mask (2).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_to_left_mask[2], _T("../hornetmove_mask/right_to_left/right_to_left_mask (3).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_to_left_mask[3], _T("../hornetmove_mask/right_to_left/right_to_left_mask (4).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_to_left_mask[4], _T("../hornetmove_mask/right_to_left/right_to_left_mask (5).bmp"), kmovewidth, kmoveheight);
	loadimage(&right_to_left_mask[5], _T("../hornetmove_mask/right_to_left/right_to_left_mask (6).bmp"), kmovewidth, kmoveheight);

	loadimage(&left[0], _T("../hornetmove/left/left (1).gif"), kmovewidth, kmoveheight);
	loadimage(&left[1], _T("../hornetmove/left/left (2).gif"), kmovewidth, kmoveheight);
	loadimage(&left[2], _T("../hornetmove/left/left (3).gif"), kmovewidth, kmoveheight);
	loadimage(&left[3], _T("../hornetmove/left/left (4).gif"), kmovewidth, kmoveheight);
	loadimage(&left[4], _T("../hornetmove/left/left (5).gif"), kmovewidth, kmoveheight);
	loadimage(&left[5], _T("../hornetmove/left/left (6).gif"), kmovewidth, kmoveheight);
	loadimage(&left[6], _T("../hornetmove/left/left (7).gif"), kmovewidth, kmoveheight);
	loadimage(&left[7], _T("../hornetmove/left/left (8).gif"), kmovewidth, kmoveheight);

	loadimage(&left_mask[0], _T("../hornetmove_mask/left/left_mask (1).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[1], _T("../hornetmove_mask/left/left_mask (2).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[2], _T("../hornetmove_mask/left/left_mask (3).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[3], _T("../hornetmove_mask/left/left_mask (4).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[4], _T("../hornetmove_mask/left/left_mask (5).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[5], _T("../hornetmove_mask/left/left_mask (6).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[6], _T("../hornetmove_mask/left/left_mask (7).bmp"), kmovewidth, kmoveheight);
	loadimage(&left_mask[7], _T("../hornetmove_mask/left/left_mask (8).bmp"), kmovewidth, kmoveheight);

	/***********************************************************************************************************/

	/********加载血量****************/
	loadimage(&img_blood, _T("../background/blood.bmp"), bloodwidth, bloodheight);
	loadimage(&img_blood_mask, _T("../background/blood_mask.bmp"), bloodwidth, bloodheight);
	/*******************************/


}
void moveright()
{
	if (forekey != 'd')
	{
		for (int i = 0; i < 6; i++)
		{
			BeginBatchDraw();
			mycleardevice();
			putimage(knightx, knighty, &left_to_right_mask[i], NOTSRCERASE);
			putimage(knightx, knighty, &left_to_right[i], SRCINVERT);
			Sleep(80);
			EndBatchDraw();
			knightx += 4;
			if (knightx >= width - knightwidth + 85)
			{
				knightx = width - knightwidth + 85;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		BeginBatchDraw();
		mycleardevice();
		putimage(knightx, knighty, &right_mask[i], NOTSRCERASE);
		putimage(knightx, knighty, &right[i], SRCINVERT);
		Sleep(80);
		EndBatchDraw();
		knightx += 4;
		if (knightx >= width - knightwidth + 85)
		{
			knightx = width - knightwidth + 85;
		}
	}
	forekey = key;
	state = stateright;
}
void moveleft()
{
	if (forekey != 'a')
	{
		for (int i = 0; i < 5; i++)
		{
			BeginBatchDraw();
			mycleardevice();
			putimage(knightx, knighty, &right_to_left_mask[i], NOTSRCERASE);
			putimage(knightx, knighty, &right_to_left[i], SRCINVERT);
			Sleep(80);
			EndBatchDraw();
		}
		knightx -= 4;
		if (knightx <= -45)
		{
			knightx = -45;
		}
	}
	for (int i = 1; i < 8; i++)
	{
		BeginBatchDraw();
		mycleardevice();
		putimage(knightx, knighty, &left_mask[i], NOTSRCERASE);
		putimage(knightx, knighty, &left[i], SRCINVERT);
		Sleep(80);
		EndBatchDraw();
		knightx -= 4;
		if (knightx <= -45)
		{
			knightx = -45;
		}
	}
	forekey = key;
	state = stateleft;
}
void moveattack()
{
	if (knightbullety <= 0)
	{
		knightbulletx = knightx + knightwidth / 2;
		knightbullety = knighty + 160;
	}
	if (state == stateleft)
	{
		for (int i = 0; i < 13; i++)
		{
			BeginBatchDraw();
			mycleardevice();
			putimage(knightx, knighty, &attack_mask[i], NOTSRCERASE);
			putimage(knightx, knighty, &attack[i], SRCINVERT);
			Sleep(100);
			EndBatchDraw();
		}

	}
	else if (state == stateright)
	{
		for (int i = 0; i < 13; i++)
		{
			BeginBatchDraw();
			mycleardevice();
			putimage(knightx, knighty, &attackr_mask[i], NOTSRCERASE);
			putimage(knightx, knighty, &attackr[i], SRCINVERT);

			Sleep(100);
			EndBatchDraw();
		}
	}

}
void part2()
{
	while (true)
	{
		if (_kbhit())
			key = _getwch();
		switch (key)
		{
		case 's':moveattack(); key = forekey; break;
		case 'd':moveright(); break;
		case 'a':moveleft(); break;
		case 'r':moveshift(); key = forekey; break;
		case 27:cleardevice(); pausemenu(); key = 0; break;
		}
	}
}
void begin()
{
	loadcg();
	loadmenu();
	loadgameover();
	loadknightimage();
	loadmonsterimage();
	initgraph(width, height);
	setbkcolor(BLACK);
	setfillcolor(WHITE);
	setlinestyle(PS_SOLID, 5);
	setlinecolor(WHITE);
	settextcolor(WHITE);
	settextstyle(30, 0, _T("楷体"));
	menu();
	if (cgplaystate == cgnplay)
	{
		playcg1();
		playcg2();
	}
	//putimage(0, 0, &img_bkpicture);
	//putimage(knightx, knighty, &attack_mask[0], NOTSRCERASE);
	//putimage(knightx, knighty, &attack[0], SRCINVERT);
	//putimage(hunterx, huntery, &hunter_mask[fortogether % 6], NOTSRCERASE);
	//putimage(hunterx, huntery, &hunter[fortogether % 6], SRCINVERT);
	PlaySound(TEXT("../background/larkin.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void moveshift()
{
	if (state == stateright)
	{
		for (int i = 0; i < 7; i++)
		{
			BeginBatchDraw();
			mycleardevice();
			putimage(knightx, knighty, &right_mask[i], NOTSRCERASE);
			putimage(knightx, knighty, &right[i], SRCINVERT);
			Sleep(80);
			EndBatchDraw();
			knightx += 15;
			if (knightx >= width - knightwidth + 85)
			{
				knightx = width - knightwidth + 85;
			}
		}
	}
	if (state == stateleft)
	{
		for (int i = 1; i < 8; i++)
		{
			BeginBatchDraw();
			mycleardevice();
			putimage(knightx, knighty, &left_mask[i], NOTSRCERASE);
			putimage(knightx, knighty, &left[i], SRCINVERT);
			Sleep(80);
			EndBatchDraw();
			knightx -= 15;
			if (knightx <= -45)
			{
				knightx = -45;
			}
		}
	}
}
void loadmenu()
{

	loadimage(&img_menu[0], _T("../menu/menu (1).gif"), menuwidth, menuheight);
	loadimage(&img_menu[1], _T("../menu/menu (2).gif"), menuwidth, menuheight);
	loadimage(&img_menu[2], _T("../menu/menu (3).gif"), menuwidth, menuheight);
	loadimage(&img_menu[3], _T("../menu/menu (4).gif"), menuwidth, menuheight);
	loadimage(&img_menu[4], _T("../menu/menu (5).gif"), menuwidth, menuheight);
	loadimage(&img_menu[5], _T("../menu/menu (6).gif"), menuwidth, menuheight);
	loadimage(&img_menu[6], _T("../menu/menu (7).gif"), menuwidth, menuheight);
	loadimage(&img_menu[7], _T("../menu/menu (8).gif"), menuwidth, menuheight);
}
void loadgameover()
{
	loadimage(&img_gameover[0], _T("../gameover/gameover (1).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[1], _T("../gameover/gameover (2).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[2], _T("../gameover/gameover (3).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[3], _T("../gameover/gameover (4).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[4], _T("../gameover/gameover (5).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[5], _T("../gameover/gameover (6).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[6], _T("../gameover/gameover (7).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[7], _T("../gameover/gameover (8).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[8], _T("../gameover/gameover (9).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[9], _T("../gameover/gameover (10).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[10], _T("../gameover/gameover (11).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[11], _T("../gameover/gameover (12).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[12], _T("../gameover/gameover (13).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[13], _T("../gameover/gameover (14).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[14], _T("../gameover/gameover (15).gif"), gameoverwidth, gameoverheight);
	loadimage(&img_gameover[15], _T("../gameover/gameover (16).gif"), gameoverwidth, gameoverheight);

}
void menu()
{

	settextcolor(WHITE);
	settextstyle(30, 0, _T("楷体"));
	outtextxy(60, 80, _T("1 新游戏"));
	outtextxy(60, 160, _T("2 读取存档"));
	outtextxy(60, 240, _T("3 退出游戏"));
	settextcolor(WHITE);
	while (true)
	{
		int menustate = 0;

		for (int i = 0; i < 8; i++)
		{
			BeginBatchDraw();
			putimage(width / 2, height / 2, &img_menu[i]);
			EndBatchDraw();
			Sleep(180);
		}
		if (_kbhit())
			menustate = _getwch();
		if (menustate == '1')
			break;
		if (menustate == '2')
		{
			readRecordFile();
			break;
		}
		if (menustate == '3')
			exit(1);
	}

}
void pausemenu()
{

	PlaySound(TEXT("../background/Ther.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	settextcolor(WHITE);
	settextstyle(30, 0, _T("楷体"));
	outtextxy(60, 80, _T("1 继续游戏"));
	outtextxy(60, 160, _T("2 保存档案"));
	outtextxy(60, 240, _T("3 退出游戏"));
	settextcolor(WHITE);
	int menustate = 0;
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			BeginBatchDraw();
			putimage(width / 2, height / 2, &img_menu[i]);
			EndBatchDraw();
			Sleep(180);
		}
		if (_kbhit())
			menustate = _getwch();
		if (menustate == '1')
			break;
		if (menustate == '2')
		{
			writeRecordFile();
			break;
		}
		if (menustate == '3')
			exit(1);
	}
	putimage(0, 0, &img_bkpicture);
	putimage(knightx, knighty, &attack_mask[0], NOTSRCERASE);
	putimage(knightx, knighty, &attack[0], SRCINVERT);
	putimage(hunterx, huntery, &hunter_mask[fortogether % 6], NOTSRCERASE);
	putimage(hunterx, huntery, &hunter[fortogether % 6], SRCINVERT);
	PlaySound(TEXT("../background/larkin.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void ifknightdie()
{
	if (knightblood == 0)
	{
		gameover();
	}
	else if (bulletx >= knightx + 30 && bulletx <= knightx + 100 && bullety >= height - knightheight + 100 && bullety <= height)
	{
		knightblood--;
		Sleep(250);
	}
}
void gameover()
{
	settextcolor(WHITE);
	settextstyle(30, 0, _T("楷体"));
	Sleep(1000);
	PlaySound(TEXT("../background/love.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (true)
	{

		for (int i = 0; i < 16; i++)
		{
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &img_gameover[i]);
			outtextxy(40, 40, _T("游"));
			outtextxy(40, 80, _T("戏"));
			outtextxy(40, 120, _T("结"));
			outtextxy(40, 160, _T("束"));

			EndBatchDraw();
			Sleep(300);
		}
	}
}
void gamewin()
{
	settextcolor(WHITE);
	settextstyle(30, 0, _T("楷体"));
	Sleep(1000);
	PlaySound(TEXT("../background/love.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (true)
	{

		for (int i = 0; i < 16; i++)
		{
			BeginBatchDraw();
			cleardevice();
			putimage(0, 0, &img_gameover[i]);
			outtextxy(40, 40, _T("游"));
			outtextxy(40, 80, _T("戏"));
			outtextxy(40, 120, _T("胜"));
			outtextxy(40, 160, _T("利"));
			EndBatchDraw();
			Sleep(300);
		}
	}
}
void loadcg()
{
	loadimage(&img_cg1[0], _T("../cg/cg1/cg (1).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[1], _T("../cg/cg1/cg (2).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[2], _T("../cg/cg1/cg (3).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[3], _T("../cg/cg1/cg (4).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[4], _T("../cg/cg1/cg (5).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[5], _T("../cg/cg1/cg (6).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[6], _T("../cg/cg1/cg (7).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[7], _T("../cg/cg1/cg (8).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[8], _T("../cg/cg1/cg (9).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[9], _T("../cg/cg1/cg (10).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[10], _T("../cg/cg1/cg (11).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[11], _T("../cg/cg1/cg (12).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[12], _T("../cg/cg1/cg (13).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[13], _T("../cg/cg1/cg (14).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[14], _T("../cg/cg1/cg (15).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[15], _T("../cg/cg1/cg (16).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[16], _T("../cg/cg1/cg (17).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[17], _T("../cg/cg1/cg (18).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[18], _T("../cg/cg1/cg (19).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[19], _T("../cg/cg1/cg (20).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[20], _T("../cg/cg1/cg (21).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[21], _T("../cg/cg1/cg (22).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[22], _T("../cg/cg1/cg (23).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[23], _T("../cg/cg1/cg (24).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[24], _T("../cg/cg1/cg (25).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[25], _T("../cg/cg1/cg (26).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[26], _T("../cg/cg1/cg (27).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[27], _T("../cg/cg1/cg (28).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[28], _T("../cg/cg1/cg (29).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[29], _T("../cg/cg1/cg (30).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[30], _T("../cg/cg1/cg (31).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[31], _T("../cg/cg1/cg (32).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[32], _T("../cg/cg1/cg (33).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[33], _T("../cg/cg1/cg (34).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[34], _T("../cg/cg1/cg (35).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[35], _T("../cg/cg1/cg (36).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[36], _T("../cg/cg1/cg (37).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[37], _T("../cg/cg1/cg (38).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[38], _T("../cg/cg1/cg (39).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[39], _T("../cg/cg1/cg (40).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[40], _T("../cg/cg1/cg (41).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[41], _T("../cg/cg1/cg (42).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[42], _T("../cg/cg1/cg (43).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[43], _T("../cg/cg1/cg (44).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[44], _T("../cg/cg1/cg (45).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[45], _T("../cg/cg1/cg (46).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[46], _T("../cg/cg1/cg (47).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[47], _T("../cg/cg1/cg (48).gif"), cgwidth, cgheight);
	loadimage(&img_cg1[48], _T("../cg/cg1/cg (49).gif"), cgwidth, cgheight);

	loadimage(&img_cg2[0], _T("../cg/cg2/cg (1).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[1], _T("../cg/cg2/cg (2).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[2], _T("../cg/cg2/cg (3).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[3], _T("../cg/cg2/cg (4).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[4], _T("../cg/cg2/cg (5).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[5], _T("../cg/cg2/cg (6).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[6], _T("../cg/cg2/cg (7).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[7], _T("../cg/cg2/cg (8).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[8], _T("../cg/cg2/cg (9).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[9], _T("../cg/cg2/cg (10).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[10], _T("../cg/cg2/cg (11).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[11], _T("../cg/cg2/cg (12).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[12], _T("../cg/cg2/cg (13).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[13], _T("../cg/cg2/cg (14).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[14], _T("../cg/cg2/cg (15).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[15], _T("../cg/cg2/cg (16).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[16], _T("../cg/cg2/cg (17).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[17], _T("../cg/cg2/cg (18).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[18], _T("../cg/cg2/cg (19).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[19], _T("../cg/cg2/cg (20).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[20], _T("../cg/cg2/cg (21).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[21], _T("../cg/cg2/cg (22).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[22], _T("../cg/cg2/cg (23).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[23], _T("../cg/cg2/cg (24).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[24], _T("../cg/cg2/cg (25).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[25], _T("../cg/cg2/cg (26).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[26], _T("../cg/cg2/cg (27).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[27], _T("../cg/cg2/cg (28).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[28], _T("../cg/cg2/cg (29).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[29], _T("../cg/cg2/cg (30).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[30], _T("../cg/cg2/cg (31).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[31], _T("../cg/cg2/cg (32).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[32], _T("../cg/cg2/cg (33).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[33], _T("../cg/cg2/cg (34).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[34], _T("../cg/cg2/cg (35).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[35], _T("../cg/cg2/cg (36).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[36], _T("../cg/cg2/cg (37).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[37], _T("../cg/cg2/cg (38).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[38], _T("../cg/cg2/cg (39).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[39], _T("../cg/cg2/cg (40).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[40], _T("../cg/cg2/cg (41).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[41], _T("../cg/cg2/cg (42).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[42], _T("../cg/cg2/cg (43).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[43], _T("../cg/cg2/cg (44).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[44], _T("../cg/cg2/cg (45).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[45], _T("../cg/cg2/cg (46).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[46], _T("../cg/cg2/cg (47).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[47], _T("../cg/cg2/cg (48).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[48], _T("../cg/cg2/cg (49).gif"), cgwidth, cgheight);
	loadimage(&img_cg2[49], _T("../cg/cg2/cg (50).jpg"), 620, 387);

}
void playcg1()
{
	PlaySound(TEXT("../background/allalright.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	Sleep(2500);
	for (int i = 0; i < 49; i++)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(100, 100, &img_cg1[i]);
		EndBatchDraw();
		Sleep(60);
	}

}
void playcg2()
{
	for (int i = 0; i < 49; i++)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(100, 100, &img_cg2[i]);
		EndBatchDraw();
		Sleep(60);
	}
	Sleep(4500);
	int i = 0, j = height + 10, k = height + 40, l = height + 80, m = height + 120, n = height + 40 * 4, o = height + 40 * 5;
	int p = height + 40 * 6, q = height + 40 * 7;
	while (j != 120)
	{
		BeginBatchDraw();
		cleardevice();
		putimage(0, 0, 629, 387, &img_cg2[49], 0, i++);
		settextstyle(30, 0, _T("楷体"));
		outtextxy(100, j--, _T("你确定要去吗?"));
		outtextxy(400, k--, _T("是的"));
		outtextxy(100, l--, _T("为了你那所谓的梦想？"));
		outtextxy(100, m--, _T("你会抛弃一切？"));
		outtextxy(100, n--, _T("包括我？"));
		outtextxy(400, o--, _T("对不起"));
		outtextxy(400, p--, _T("梦想是魔鬼"));
		outtextxy(400, q--, _T("他掐着我的咽喉"));
		EndBatchDraw();
		Sleep(100);
	}

	Sleep(9000);
}
void readRecordFile()
{

	FILE *fp;
	fp = fopen(".\\gameRecord.dat", "r");
	fscanf(fp, "%d %d %d %d %d %d %d %d %d %d", &knightblood, &knightbulletx, &knightbullety, &knightx, &knighty, &hunterx, &huntery, &hunterblood, &state, &cgplaystate);
	fclose(fp);
}
void writeRecordFile()
{
	cgplaystate = cgplayed;
	FILE *fp;
	fp = fopen(".\\gameRecord.dat", "w");
	fprintf(fp, "%d %d %d %d %d %d %d %d %d %d", knightblood, knightbulletx, knightbullety, knightx, knighty, hunterx, huntery, hunterblood, state, cgplaystate);
	fclose(fp);
}