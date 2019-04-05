#include "game.h"

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'a':   // a を入力すると左に動く
        case 'A': 
        //glutIdleFunc(leftmove);
        leftflag = 1;
        break;

        case 'd':   // d を入力すると右に動く
        case 'D':
        //glutIdleFunc(rightmove);
        rightflag = 1;
        break;

        case '\040':// spaceでスタート
        start = 1;
        break;

        case 'q':   // q Q ESC を入力するとプログラム終了
        case 'Q':
        case '\033':
        exit(0);

        case 'p':
        if(bulletflag == 0){
            bulletflag = 1;
        }

        default: 
        break;
    }
}