#pragma once

void Hide_Cursor();//隱藏光標
void Set_OUTPUTpos(int x, int y);//移動顯示鼠標位置
void SetColorRGB(int want_colorPOS, int R, int G, int B);//改變windows內建的色碼表顏色
void Correct_color();//呼叫SetColorRGB校正顏色
void SetColor(int color);//顯示顏色
bool SetConsoleSize(int W, int H);//調整黑窗大小