#pragma once

void Show(int SCORE, int LEVEL, int next_sq[4][4]);//���
void Map_zero();//�a�Ϫ�l��
void Set_boundary();//��l�a�����
void Memory_square();//�O��W�@�Ӥ��
void Square_show(int temp[4][4]);//�U�@�Ӥ��
void Random_square(char *temp);//�H�����ͤU�@�Ӥ��
void Eliminate(int &SCORE);//����
void Find_squareXY(int sq[4][4], int &sqY, int &sqX);//X*Y
int which_square(int sq[4][4]);//���@�Ӥ��(1~7)
void Put_map(int sq[4][4], int Ypos, int Xpos, int littleY, int littleX);//��J�a��
bool Move_if(int sqY, int sqX, int Ypos, int Xpos, int littleY, int littleX, int type);//�P�_����
int Keyboard_if(char command, int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int &count);//�P�_��L
void GETrotatepoint(int y1, int x1, int centerY, int centerX, int &ansY, int &ansX, double angree);//¶��@���I���઺formula
void Rotate(int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int &count);//����(���ɰw)
void Kick_wall(int sq[4][4], int &Ypos, int &Xpos, int &sqY, int &sqX, int &littleY, int &littleX, int sqtest);//����
void find_centerINMAP(int &Y, int &X, int test, int Ypos, int Xpos, int littleY, int littleX);//�b�a�Ϥ���X��������I
bool Rotate_if(int sq[4][4], int Ypos, int Xpos, int sqY, int sqX, int littleY, int littleX, int count); //�P�_����
int ScoreTOlevel(int SCORE);//�̾ڤ��Ƨ��ܵ���
int LevelTOspeed(int LEVEL);//�̾ڵ��ŧ��ܸ��U�t��
bool Gameover();//�P�_�C������