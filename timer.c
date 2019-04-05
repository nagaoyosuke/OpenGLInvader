#include "game.h"

void timer(int value){

    theta = fmod( theta + 0.5, 360.0 );//回転　使わない

    if(start == 1){//startが1なら色々実行する（ゲームスタート）

        PlayerMoveCheck();
        BulletCheck();

        InvaiderHitCheck();//インヴェイダーの当たり判定を呼び出す
        InvaiderMove();
       // bx += movex;   // x軸のボールの動き(仮)
       // by += movey;   // y軸のボールの動き(仮)
    }
    glutPostRedisplay();
    glutTimerFunc(30, timer, 1);//timerをループさせるなり
}