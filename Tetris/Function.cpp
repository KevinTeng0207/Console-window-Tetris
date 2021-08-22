#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Function.h"
#include "console.h"
#include "define.h"

using namespace std;

extern int map[mapY][mapX];
extern int color_map[mapY][mapX];
extern int J[4][4];
extern int L[4][4];
extern int T[4][4];
extern int O[4][4];
extern int S[4][4];
extern int Z[4][4];
extern int I[4][4];


void Set_boundary()//初始地圖邊界
{
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			if (i == 0 || i == (mapY - 1))
				map[i][j] = 9;
			else if (j == 0 || j == (mapX - 1))
				map[i][j] = 9;
		}
	}
}
void Map_zero()
{
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
			if (map[i][j] != 8 && map[i][j] != 9)
				map[i][j] = 0;
	}
}
void Memory_square()
{
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			if (map[i][j] >= 1 && map[i][j] <= 7)
			{
				color_map[i][j] = map[i][j];
				map[i][j] = 8;				
			}
				
		}
	}
}
void Show(int SCORE,int LEVEL, int next_sq[4][4])//地圖
{
	Set_OUTPUTpos(20, 2);
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			switch (map[i][j])
			{
			case 1:
				#ifdef DEBUG_PRINT
					SetColor(BLUE);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;
			
			case 2:
				#ifdef DEBUG_PRINT
					SetColor(ORANGE);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;			
			case 3:
				#ifdef DEBUG_PRINT
					SetColor(PURPLE);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;			
			case 4:
				#ifdef DEBUG_PRINT
					SetColor(YELLOW);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;
			case 5:
				#ifdef DEBUG_PRINT
					SetColor(GREEN);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;
			case 6:	
				#ifdef DEBUG_PRINT
					SetColor(RED);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;
			case 7:
				#ifdef DEBUG_PRINT
					SetColor(CYAN_BLUE);
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;
			case 8:
				#ifdef DEBUG_PRINT
					switch(color_map[i][j])
					{
					case 1:
						SetColor(BLUE);
						break;
					case 2:
						SetColor(ORANGE);
						break;
					case 3:
						SetColor(PURPLE);
						break;
					case 4:
						SetColor(YELLOW);
						break;
					case 5:
						SetColor(GREEN);
						break;
					case 6:
						SetColor(RED);
						break;
					case 7:
						SetColor(CYAN_BLUE);
						break;

					}
					cout << "■";
				#else
					cout << map[i][j];
				#endif
				break;		
			case 0:
				#ifdef DEBUG_PRINT
					SetColor(0);
					cout << "□";
				#else
					cout << 0;
				#endif
				break;			
			case 9://邊界
				#ifdef DEBUG_PRINT
					SetColor(13);
					cout << "※";
				#else
					cout << 9;
				#endif
				break;
			}
		}
		Set_OUTPUTpos(20, i + 3);
	}	
	/***********SCORE*********/
	Set_OUTPUTpos(5, 6);
	printf("Score:  %04d", SCORE);
	Set_OUTPUTpos(5, 7);
	cout << "------------";
	/***********NEXT*********/		
	Square_show(next_sq);
	/***********LEVEL*********/
	Set_OUTPUTpos(5, 3);
	printf("Level:  %4d", LEVEL);
	Set_OUTPUTpos(5, 4);
	cout << "------------";
}
void Square_show(int temp[4][4])
{				
	Set_OUTPUTpos(54, 4);
	SetColor(0);
	cout << "□";	
	int printX, printY = 4;
	int test = which_square(temp);
	switch (test)
	{
	case 1:
		printX = 50;
		break;
	case 2:
		printX = 52;
		break;
	case 3:
		printX = 50;
		printY = 5;
		break;
	case 4:
		printX = 51;
		printY = 5;
		break;
	case 5:
		printX = 50;
		printY = 5;
		break;
	case 6:
		printX = 50;
		printY = 5;
		break;
	case 7:
		printX = 52;
		break;
	}	
	Set_OUTPUTpos(printX, printY);	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (temp[i][j])
			{
				switch (test)
				{
				case 1:
					SetColor(1);
					break;
				case 2:
					SetColor(14);
					break;
				case 3:
					SetColor(5);
					break;
				case 4:
					SetColor(6);
					break;
				case 5:
					SetColor(2);
					break;
				case 6:
					SetColor(4);
					break;
				case 7:
					SetColor(3);
					break;
				}
				cout << "■";
			}				
			else
			{
				SetColor(0);
				cout << "□";
			}				
		}
		Set_OUTPUTpos(printX, i + printY + 1);		
	}	
	/***********邊界*********/
	SetColor(13);	
	Set_OUTPUTpos(50, 2);
	cout << "※※※※※";
	Set_OUTPUTpos(50, 9);
	cout << "※※※※※";
	for (int i = 1; i <= 6; i++)
	{
		SetColor(13);
		Set_OUTPUTpos(48, 2 + i);
		cout << "※";
		Set_OUTPUTpos(60, 2 + i);
		cout << "※";
	}	
}
void Random_square(char *temp)
{
	int a = (rand() % 7) + 1;		
	#ifdef DEBUG_RANDOM
		a = DEBUG_RANDOM;		
	#endif		
	//cout << a;
	switch (a)//把方塊的記憶體丟入temp
	{
	case 1:
		memcpy(temp, J, sizeof(J));		
		break;
	case 2:
		memcpy(temp, L, sizeof(L));		
		break;
	case 3:
		memcpy(temp, T, sizeof(T));		
		break;
	case 4:
		memcpy(temp, O, sizeof(O));	
		break;
	case 5:
		memcpy(temp, S, sizeof(S));	
		break;
	case 6:
		memcpy(temp, Z, sizeof(Z));		
		break;
	case 7:
		memcpy(temp, I, sizeof(I));
		break;
	}	
}
void Put_map(int sq[4][4], int Ypos, int Xpos, int littleY, int littleX)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sq[i][j])
				map[i + Ypos - littleY][j + Xpos - littleX] = sq[i][j];
		}
	}
}
bool Move_if(int sqY, int sqX, int Ypos, int Xpos, int littleY, int littleX, int type)
{
	int Y, X;
	int temp;
	switch (type)
	{
	case 1://down
		Y = (Ypos + sqY) - 1;
		X = (Xpos + sqX);
		for (int i = 1; i <= sqX; i++)		
		{
			switch (map[Y][X])
			{
			case 8:
				temp = Y - 1;
				if(map[temp][X])
					return false;	
				break;
			case 1:case 2:
			case 3:case 4:
			case 5:case 6:
			case 7:
				temp = Y + 1;
				if (map[temp][X])
					return false;
			}
			--X;
		}		
		break;
	case 2://left
		Y = (Ypos + sqY) - 1;
		X = (Xpos + 1);
		for (int i = 1; i <= sqY; i++)
		{
			switch (map[Y][X])
			{
			case 8:
				return false;
			case 1:case 2:
			case 3:case 4:
			case 5:case 6:
			case 7:
				int temp = X - 1;
				if (map[Y][temp])
					return false;
			}
			--Y;
		}
		break;
	case 3://right
		Y = (Ypos + sqY) - 1;
		X = (Xpos + sqX);
		for (int i = 1; i <= sqY; i++)
		{
			switch (map[Y][X])
			{
			case 8:
				return false;
			case 1:case 2:
			case 3:case 4:
			case 5:case 6:
			case 7:
				int temp = X + 1;
				if (map[Y][temp])
					return false;
			}
			--Y;
		}
		break;
	}
	return true;
}
void Find_squareXY(int sq[4][4], int &sqY, int &sqX)
{	
	bool flag = false;
	bool A = 0, B = 0, C = 0, D = 0;
	sqY = 0;
	sqX = 0;	
	for (int i = 0; i < 4; i++)
	{		
		for (int j = 0; j < 4; j++)
		{	
			if (sq[i][j])			
			{				
				switch (j)
				{
				case 0:
					if (A == 0)
					{
						++sqX;
						A = true;
					}						
					break;
				case 1:
					if (B == 0)
					{
						++sqX;
						B = true;
					}
					break;
				case 2:
					if (C == 0)
					{
						++sqX;
						C = true;
					}
					break;
				case 3:
					if (D == 0)
					{
						++sqX;
						D = true;
					}
					break;
				}
				flag = true;
			}
		}			
		if (flag)
		{
			sqY += 1;
			flag = false;
		}		
	}	
}
int Keyboard_if(char command, int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int &count)
{
	int test;
	test = which_square(sq);
	switch (command)
	{
	case 16://shift(replace)
		{

		}
		return 1;
	case 32://space(quick down)
		while (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, down))
		{
			Map_zero();
			Put_map(sq, ++Ypos, Xpos, littleY, littleX);
		}
		return 1;
	case 72://up		
		if (Rotate_if(sq, Ypos, Xpos, sqY, sqX, littleY, littleX, count))
		{
			Rotate(sq, Ypos, Xpos, sqY, sqX, littleY, littleX, ++count);
			Map_zero();
			Put_map(sq, Ypos, Xpos, littleY, littleX);
		}
		else
		{
			Kick_wall(sq, Ypos, Xpos, sqY, sqX, littleY, littleX, test);
			if (Rotate_if(sq, Ypos, Xpos, sqY, sqX, littleY, littleX, count))
			{
				Rotate(sq, Ypos, Xpos, sqY, sqX, littleY, littleX, ++count);
				Map_zero();
				Put_map(sq, Ypos, Xpos, littleY, littleX);
			}			
		}				
		return 0;
	case 75://left
		if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, left))
		{
			Map_zero();
			Put_map(sq, Ypos, --Xpos, littleY, littleX);
		}		
		return 0;
	case 77://right	
		if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, right))
		{
			Map_zero();
			Put_map(sq, Ypos, ++Xpos, littleY, littleX);
		}		
		return 0;
	case 80://down	
		if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, down))
		{
			Map_zero();
			Put_map(sq, ++Ypos, Xpos, littleY, littleX);
		}		
		return 0;
	}
	return 0;
}
void Eliminate(int &SCORE)
{
	int test = 0;	
	int temp = 0;
	int tmp_map[mapY][mapX] = {};	
	memcpy(tmp_map, map, sizeof(map));	
	for (int i = 1; i < mapY - 1; i++)
	{
		for (int j = 1; j < mapX - 1; j++)
			test += map[i][j];
		if (test == (8 * (mapX - 2)))
		{			
			++temp;
			for (int x = i; x >= 1; x--)
			{
				if (x - 1 != 0)
					memcpy(map[x], tmp_map[x - 1], sizeof(tmp_map[x - 1]));
				else
					for (int j = 1; j < mapX - 1; j++)
						map[x][j] = 0;
			}		
		}		
		memcpy(tmp_map, map, sizeof(map));
		test = 0;
	}
	switch (temp)
	{
	case 1:
		SCORE += 100;
		break;
	case 2:
		SCORE += 200;
		break;
	case 3:
		SCORE += 400;
		break;
	case 4:
		SCORE += 800;
		break;
	}
}
void GETrotatepoint(int y1, int x1, int centerY, int centerX, int &ansY, int &ansX, double angle)
{
	ansY = 0;
	ansX = 0;
	double X = (x1 - centerX)*cos(angle * PI / 180) - (y1 - centerY)*sin(angle * PI / 180) + centerX;
	double Y = (y1 - centerY)*cos(angle * PI / 180) + (x1 - centerX)*sin(angle * PI / 180) + centerY;
	ansY = (int)round(Y);
	ansX = (int)round(X);
}
void Kick_wall(int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int sqtest)
{
	int Y = 0, X = 0;
	find_centerINMAP(Y, X, sqtest, Ypos, Xpos, littleY, littleX);
	if (sqtest == 4)
		return;
	switch (map[Y][X - 1])
	{
	case 8:case 9:
		if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, right))
		{
			Map_zero();			
			Put_map(sq, Ypos, ++Xpos, littleY, littleX);				
		}		
		return;
	}
	switch (map[Y][X + 1])
	{
	case 8:case 9:
		if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, left))
		{
			Map_zero();
			Put_map(sq, Ypos, --Xpos, littleY, littleX);
			if (sqtest == 7)
			{
				if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, left))
				{
					Map_zero();
					Put_map(sq, Ypos, --Xpos, littleY, littleX);
				}
			}						
		}
		return;				
	}	
	switch (map[Y - 1][X])	
	{
	case 8:case 9:
		if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, down))
		{
			Map_zero();
			Put_map(sq, ++Ypos, Xpos, littleY, littleX);
			if (sqtest == 7)
			{
				if (Move_if(sqY, sqX, Ypos, Xpos, littleY, littleX, down))
				{
					Map_zero();
					Put_map(sq, ++Ypos, Xpos, littleY, littleX);
				}
			}			
		}		
		return;
	}
	
}
void Rotate(int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int &count)
{
	int Y, X, test;
	int moveY, moveX;
	int temp_sq[4][4] = {};
	test = which_square(sq);	
	count %= 4;
	switch (test)
	{
	case 1:
		Y = 1;
		X = 2;
		switch (count)
		{
		case 0:
			Ypos -= 1;
			littleY -= 1;
			break;
		case 2:
			Xpos += 1;
			littleX += 1;
			break;
		case 3:
			Xpos -= 1;
			littleX -= 1;
			Ypos += 1;
			littleY += 1;
			break;
		}
		break;
	case 2:
		Y = 1;
		X = 1;
		switch (count)
		{
		case 0:
			Xpos += 1;
			littleX += 1;
			break;
		case 1:
			Ypos += 1;
			littleY += 1;
			Xpos -= 1;
			littleX -= 1;
			break;
		case 2:
			Ypos -= 1;
			littleY -= 1;
			break;
		}
		break;
	case 3:
		Y = 1;
		X = 2;
		switch (count)
		{
		case 1:
			Xpos += 1;
			littleX += 1;
			break;
		case 2:
			Xpos -= 1;
			littleX -= 1;
			Ypos += 1;
			littleY += 1;
			break;
		case 3:
			Ypos -= 1;
			littleY -= 1;
			break;
		}
		break;
	case 4:
		return;
	case 5:
		Y = 1;
		X = 2;
		switch (count)
		{
		case 1:
			Xpos += 1;
			littleX += 1;
			break;
		case 2:
			Xpos -= 1;
			littleX -= 1;
			Ypos += 1;
			littleY += 1;
			break;
		case 3:
			Ypos -= 1;
			littleY -= 1;
			break;
		}
		break;
	case 6:
		Y = 1;
		X = 2;
		switch (count)
		{
		case 1:
			Xpos += 1;
			littleX += 1;
			break;
		case 2:
			Xpos -= 1;
			littleX -= 1;
			Ypos += 1;
			littleY += 1;
			break;
		case 3:
			Ypos -= 1;
			littleY -= 1;
			break;
		}
		break;
	case 7:
		Y = 2;
		X = 1;
		switch (count)
		{
		case 1:case 3:
			Ypos += 2;
			littleY += 2;
			Xpos -= 1;
			littleX -= 1;
			break;
		case 2:case 0:
			Ypos -= 2;
			littleY -= 2;
			Xpos += 1;
			littleX += 1;
			break;
		}
		break;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sq[i][j])
			{
				GETrotatepoint(i, j, Y, X, moveY, moveX, 90);
				if (moveY == 4)
					moveY = 0;
				temp_sq[moveY][moveX] = sq[i][j];
			}
		}
	}
	memcpy(sq, temp_sq, sizeof(temp_sq));	
	Find_squareXY(sq, sqY, sqX);
}
bool Rotate_if(int sq[4][4], int Ypos, int Xpos, int sqY, int sqX, int littleY, int littleX, int count)
{
	int Y, X, test;	
	int ypos, xpos, littley, littlex;
	int moveY, moveX;
	int fakecount = count + 1;
	test = which_square(sq);	
	fakecount %= 4;
	ypos = Ypos;
	xpos = Xpos;
	littley = littleY;
	littlex = littleX;
	switch (test)
	{
	case 1:
		Y = 1;
		X = 2;
		switch (fakecount)
		{
		case 0:
			ypos = Ypos - 1;
			littley = littleY - 1;
			break;
		case 2:
			xpos = Xpos + 1;
			littlex = littleX + 1;
			break;
		case 3:
			xpos = Xpos - 1;
			littlex = littleX - 1;
			ypos = Ypos + 1;
			littley = littleY + 1;
			break;
		}
		break;
	case 2:
		Y = 1;
		X = 1;
		switch (fakecount)
		{
		case 0:
			xpos = Xpos + 1;
			littlex = littleX + 1;
			break;
		case 1:
			ypos = Ypos + 1;
			littley = littleY + 1;
			xpos = Xpos - 1;
			littlex = littleX - 1;
			break;
		case 2:
			ypos = Ypos - 1;
			littley = littleY - 1;
			break;
		}
		break;
	case 3:
		Y = 1;
		X = 2;
		switch (fakecount)
		{
		case 1:
			xpos = Xpos + 1;
			littlex = littleX + 1;
			break;
		case 2:
			xpos = Xpos - 1;
			littlex = littleX - 1;
			ypos = Ypos + 1;
			littley = littleY + 1;
			break;
		case 3:
			ypos = Ypos - 1;
			littley = littleY - 1;
			break;
		}
		break;
	case 4:
		return false;
	case 5:
		Y = 1;
		X = 2;
		switch (fakecount)
		{
		case 1:
			xpos = Xpos + 1;
			littlex = littleX + 1;
			break;
		case 2:
			xpos = Xpos - 1;
			littlex = littleX - 1;
			ypos = Ypos + 1;
			littley = littleY + 1;
			break;
		case 3:
			ypos = Ypos - 1;
			littley = littleY - 1;
			break;
		}
		break;
	case 6:
		Y = 1;
		X = 2;
		switch (fakecount)
		{
		case 1:
			xpos = Xpos + 1;
			littlex = littleX + 1;
			break;
		case 2:
			xpos = Xpos - 1;
			littlex = littleX - 1;
			ypos = Ypos + 1;
			littley = littleY + 1;
			break;
		case 3:
			ypos = Ypos - 1;
			littley = littleY - 1;
			break;
		}
		break;
	case 7:
		Y = 2;
		X = 1;
		switch (fakecount)
		{
		case 1:case 3:
			ypos = Ypos + 2;
			littley = littleY + 2;
			xpos = Xpos - 1;
			littlex = littleX - 1;
			break;
		case 2:case 0:
			ypos = Ypos - 2;
			littley = littleY - 2;
			xpos = Xpos + 1;
			littlex = littleX + 1;
			break;
		}
		break;
	}
	for (int i = 0 ; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sq[i][j])
			{
				GETrotatepoint(i, j, Y, X, moveY, moveX, 90);
				if (map[ypos - littley + moveY][xpos - littlex + moveX] == 8 || map[ypos - littley + moveY][xpos - littlex + moveX] == 9)
					return false;
			}
		}
	}
	return true;
}
void find_centerINMAP(int &Y, int &X, int test, int Ypos, int Xpos, int littleY, int littleX)
{
	switch (test)
	{
	case 1:
		Y = Ypos + 1 - littleY;
		X = Xpos + 2 - littleX;
		break;
	case 2:
		Y = Ypos + 1 - littleY;
		X = Xpos + 1 - littleX;
		break;
	case 3:
		Y = Ypos + 1 - littleY;
		X = Xpos + 2 - littleX;
		break;
	case 4:
		return;
	case 5:
		Y = Ypos + 1 - littleY;
		X = Xpos + 2 - littleX;
		break;
	case 6:
		Y = Ypos + 1 - littleY;
		X = Xpos + 2 - littleX;
		break;
	case 7:
		Y = Ypos + 2 - littleY;
		X = Xpos + 1 - littleX;
		break;
	}
}
int which_square(int sq[4][4])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (sq[i][j])
				return sq[i][j];
	return 0;
}
bool Gameover()
{
	if (map[1][5] == 8 || map[1][6] == 8)
		return false;
	else
		return true;
}
int LevelTOspeed(int LEVEL)
{
	switch (LEVEL)
	{
	case 1:
		return 1000;
	case 2:
		return 900;
	case 3:
		return 800;
	case 4:
		return 700;
	case 5:
		return 600;
	case 6:
		return 500;
	case 7:
		return 400;
	case 8:
		return 300;
	case 9:
		return 200;
	case 10:
		return 100;	
	default:
		return 50;
	}
}
int ScoreTOlevel(int SCORE)
{		
	int level = SCORE / 1500;
	return level + 1;	
}