#pragma once
#define width 640
#define height 480
#define knightwidth 180
#define knightheight 167
#define kmovewidth 140
#define kmoveheight 140
#define stateleft 1
#define stateright 0
#define menuwidth 177
#define menuheight 199
#define gameoverwidth 500
#define gameoverheight 486
#define menustatebegin 1
#define menustateexit 2
#define cgwidth 424
#define cgheight 256
#define bloodwidth 30
#define bloodheight 30
#define cgplayed 1
#define cgnplay 0

extern int fortogether;
extern int state;
extern char key;
extern char forekey;
extern int knightx;
extern int knighty;
extern int knightblood;
extern int knightbulletx;
extern int knightbullety;
extern int knightbulletr;

extern int knightbulletx;
extern int knightbullety;

extern int cgplaystate;

extern IMAGE img_bkpicture;

/************************************攻击*******************************************************************/
extern IMAGE attack[13];
extern IMAGE attack_mask[13];
extern IMAGE attackr[13];
extern IMAGE attackr_mask[13];
/*******************************************************************************************************/

/************************************向右走*******************************************************************/
extern IMAGE left_to_right[7];
extern IMAGE right[8];
extern IMAGE left_to_right_mask[7];
extern IMAGE right_mask[8];
/********************************************************************************************************/

/************************************向左走******************************************************************/
extern IMAGE right_to_left[7];
extern IMAGE left[9];
extern IMAGE right_to_left_mask[7];
extern IMAGE left_mask[9];
/********************************************************************************************************/

/***********菜单**************/
extern IMAGE img_menu[8];
/*****************************/

/***********结束****************/
extern IMAGE img_gameover[16];
/******************************/

/************CG********************/
extern IMAGE img_cg1[49];
extern IMAGE img_cg2[50];
/*********************************/

/*************血量********************/
extern IMAGE img_blood;
extern IMAGE img_blood_mask;
/************************************/
void loadknightimage();
void moveright();
void moveleft();
void moveattack();
void part2();
void begin();
void moveshift();
void menu();
void pausemenu();
void loadmenu();
void loadgameover();
void ifknightdie();
void gameover();
void gamewin();
void loadcg();
void playcg1();
void playcg2();
void readRecordFile();
void writeRecordFile();