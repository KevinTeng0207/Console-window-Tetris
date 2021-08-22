#pragma once

void Show(int SCORE, int LEVEL, int next_sq[4][4]);//顯示
void Map_zero();//地圖初始化
void Set_boundary();//初始地圖邊界
void Memory_square();//記住上一個方塊
void Square_show(int temp[4][4]);//下一個方塊
void Random_square(char *temp);//隨機產生下一個方塊
void Eliminate(int &SCORE);//消行
void Find_squareXY(int sq[4][4], int &sqY, int &sqX);//X*Y
int which_square(int sq[4][4]);//哪一個方塊(1~7)
void Put_map(int sq[4][4], int Ypos, int Xpos, int littleY, int littleX);//放入地圖
bool Move_if(int sqY, int sqX, int Ypos, int Xpos, int littleY, int littleX, int type);//判斷移動
int Keyboard_if(char command, int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int &count);//判斷鍵盤
void GETrotatepoint(int y1, int x1, int centerY, int centerX, int &ansY, int &ansX, double angree);//繞行一個點旋轉的formula
void Rotate(int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int &count);//旋轉(順時針)
void Kick_wall(int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int sqtest);//踢牆
void find_centerINMAP(int &Y, int &X, int test, int Ypos, int Xpos, int littleY, int littleX);//在地圖中找出方塊中心點
bool Rotate_if(int sq[4][4], int Ypos, int Xpos, int sqY, int sqX, int littleY, int littleX, int count); //判斷旋轉
int ScoreTOlevel(int SCORE);//依據分數改變等級
int LevelTOspeed(int LEVEL);//依據等級改變落下速度
bool Gameover();//判斷遊戲結束