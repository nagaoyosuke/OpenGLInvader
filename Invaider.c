#include "game.h"

void InvaiderInit(void){
    invaiderVec = 0.1;
    invaiderDown = 0;
    //使う配列を1で初期化
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 3; y++){
            invaiders[x][y] = 1;
            invaidersPosX[x][y] = (double)x * 2 - 10;
            invaidersPosY[x][y] = (double)y * 2;
        }
    }
}
void InvaiderHitCheck(){
    double witdh = 0.4;
    double height = 0.9;
    double heightb = 0.2;
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 3; y ++){
            //当たったら配列を0に変更して消滅
            //iは-10.0しなくちゃいけない 配列の順番にマイナスは使えないので ←理解不能
            // インヴェイダー上の判定
            if(invaidersPosX[x][y] - witdh  < bx && bx < invaidersPosX[x][y] + witdh &&
            invaidersPosY[x][y] - height < by && by < invaidersPosY[x][y] - witdh){
                if(invaiders[x][y] == 1){
                    invaiders[x][y] = 0;
                    BulletReset();
                    return;
                }
            }
            // インヴェイダー下の判定
            if(invaidersPosX[x][y] - witdh  < bx && bx < invaidersPosX[x][y] + witdh  &&
            invaidersPosY[x][y] + witdh < by  && by < invaidersPosY[x][y] + height){
                if(invaiders[x][y] == 1){
                    BulletReset();
                    invaiders[x][y] = 0;
                    return;
                }
            }
            // インヴェイダー左の判定
            if(invaidersPosX[x][y] - witdh  < bx && bx < invaidersPosX[x][y] - heightb  &&
            invaidersPosY[x][y] - witdh < by  && by < invaidersPosY[x][y] + witdh){
                if(invaiders[x][y] == 1){
                    BulletReset();
                    invaiders[x][y] = 0;
                    return;
                }
            }
            // インヴェイダー上の判定
            if(invaidersPosX[x][y] + heightb  < bx && bx < invaidersPosX[x][y] + witdh &&
            invaidersPosY[x][y] - witdh < by  && by < invaidersPosY[x][y] + witdh){
                if(invaiders[x][y] == 1){
                    BulletReset();
                    invaiders[x][y] = 0;
                    return;
                }
            }    

            if(invaiders[x][y] == 1){
                if(invaidersPosY[x][y] < -6.0){
                    exit(1);
                }
            }     
        }
    }
}

void InvaiderMove(void){
    if(invaidersPosX[0][0] < -11.0){
        invaiderVec = 0.1;
        invaiderDown = 0.4;
    }
    if(invaidersPosX[0][0] > -4.0){
        invaiderVec = -0.1;
        invaiderDown = 0.4;
    }
    
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 3; y ++){
            invaidersPosX[x][y] += invaiderVec;
            invaidersPosY[x][y] -= invaiderDown;
        }
    }

    invaiderDown = 0;
}