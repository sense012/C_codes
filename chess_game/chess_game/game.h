#pragma once
#include <stdio.h>
#pragma warning(disable:4996)
#include <time.h>
#include <stdlib.h>
//自定义常量
#define ROW 3
#define COL 3
//游戏实现函数game
void game();
//初始化棋盘
void Makeboard();
//棋盘打印函数
void Printbpard(char[][COL], int, int);
//玩家下棋
void player(char[][COL], int, int);
//电脑下棋
void AnotI(char[][COL], int, int);
//输赢判断
//玩家赢返回*，电脑赢返回#，平局返回Q，游戏继续返回C
char ifwin(char[][COL], int, int);