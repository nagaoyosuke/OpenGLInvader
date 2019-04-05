#include "game.h"
void PlayerMoveCheck(){
    if(leftflag == 1){//leftflagが1ならleftmoveを呼び出す
        //glutIdleFunc(LeftMove);
        LeftMove();
    }else if(rightflag == 1){//rightflagが1ならrightmoveを呼び出す
        //glutIdleFunc(RightMove);
        RightMove();
    }
}

void LeftMove(){    // 自機左移動
    if(px > -8.0){   // 左端の当たり判定
        px -= 0.1;     
    }
}

void RightMove(){   // 自機右移動
    if(px < 8.0){// 右端の当たり判定
        px += 0.1;
    }
}