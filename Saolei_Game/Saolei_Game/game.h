#ifndef GAME
#define GAME

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define ROW 11
#define COL 11
#define ROW_R 9
#define COL_R 9
#define THUNDER_NUM 20

void Board_init();
void Play_game();
void Thunder_Design(char buf[][COL]);
void Thunder_init(char buf[][COL], int row, int col, char data);
void Show_buf(char buf[][COL], int row, int col);
void Thunder_find(char buf[][ROW]);//ÅÅÀ×
void To_Dis(show_thunder, x, y);
#endif
