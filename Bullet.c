#include "game.h"
void BulletCheck(){
    if(bulletflag == 1){
        bulletflag = 2;
        BulletMake();
    }

    if(bulletflag == 2){
        BulletMove();

        if(by > 7){
            BulletReset();
        }
    }
}

void BulletMove(void){
    by += 0.4;
}

void BulletMake(void){
    bx = px;
    by = py;
}

void BulletReset(void){
    by = -200;
    bulletflag = 0;
}