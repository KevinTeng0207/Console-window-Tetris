#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "console.h"
#include "sequare.h"

using namespace std;

int main()
{	
	int Y, X, squareY, squareX, adjustY, adjustX, rotate;
	int temp[4][4] = {}, next[4][4] = {}, replacement[4][4] = {};
	int score, TIME, blankIF, level;
	unsigned long start;
	srand((unsigned int)time(NULL));	
	////*************控制台設定*************////
	#ifdef DEBUG_PRINT
		Correct_color();
	#endif	
	SetConsoleSize(66, 26);
	Hide_Cursor();
	////**************遊戲開始**************////
	Set_boundary();
	score = Score;
	Random_square((char*)temp);
	Random_square((char*)next);
	while (Gameover())
	{
		Y = 0;
		X = ((mapX - 2) / 2) - 1;
		adjustY = 0;
		adjustX = 0;	
		rotate = 0;		
		level = ScoreTOlevel(score);
		Find_squareXY(temp, squareY, squareX);				
		do
		{					
			Map_zero();
			Put_map(temp, ++Y, X, adjustY, adjustX);
			Show(score, level, next);
			start = GetTickCount();
			TIME = LevelTOspeed(level);
			do
			{
				if (_kbhit())
				{
					blankIF = Keyboard_if(_getch(), temp, Y, X, squareY, squareX, adjustY, adjustX, rotate);
					if (blankIF)
						break;
					Show(score, level, next);
				}
			} while (GetTickCount() - start <= TIME);
		} while (Move_if(squareY, squareX, Y, X, adjustY, adjustX, down));
		Memory_square();		
		Eliminate(score);			
		Show(score, level, next);
		memcpy(temp, next, sizeof(next));
		Random_square((char*)next);		
	}	

	return 0;
}
