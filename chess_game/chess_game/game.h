#pragma once
#include <stdio.h>
#pragma warning(disable:4996)
#include <time.h>
#include <stdlib.h>
//�Զ��峣��
#define ROW 3
#define COL 3
//��Ϸʵ�ֺ���game
void game();
//��ʼ������
void Makeboard();
//���̴�ӡ����
void Printbpard(char[][COL], int, int);
//�������
void player(char[][COL], int, int);
//��������
void AnotI(char[][COL], int, int);
//��Ӯ�ж�
//���Ӯ����*������Ӯ����#��ƽ�ַ���Q����Ϸ��������C
char ifwin(char[][COL], int, int);