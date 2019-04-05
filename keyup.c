#include "game.h"
//(ノД`)・゜・。実装できてません〜〜〜〜
void keyup(unsigned char key, int x, int y){    // キーを離した時の挙動
    switch(key){    // a A を離したときに移動を止める
        case 'a':
        case 'A': 
        leftflag = 0;
        break;

        case 'd':   // d D を離した時に移動を止める
        case 'D':
        rightflag = 0;
        break;

        default: break;

    }   
}