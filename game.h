#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void light(void);//ライト
void resize(int w, int h);//カメラ
void RightMove(void);//右移動
void LeftMove(void);//左移動
void PlayerMoveCheck(void);
void display(void);//図形の描画
void keyboard(unsigned char key, int x, int y);//キーダウン
void keyup(unsigned char key, int x, int y);//キーアップ
void timer(int value);//タイマーぐるぐる
void InvaiderHitCheck(void);//インヴェイダーの当たり判定
void InvaiderInit(void);
void InvaiderMove(void);
void BulletMove(void);
void BulletMake(void);
void BulletCheck(void);
void BulletReset(void);

extern double px;//barのx軸
extern double py;//barのy軸
extern double theta;//回転　使わない
extern int start;//start用のフラグ
extern double bx;//ballのx軸
extern double by;//ballのy軸
extern double movex;//x軸の移動
extern double movey;//y軸の移動
int invaiders[10][10];//インヴェイダー用の配列
double invaidersPosX[10][10];//インヴエイダーの座標用の配列
double invaidersPosY[10][10];//インヴエイダーの座標用の配列
double invaiderVec;
double invaiderDown;

extern int leftflag;//左移動のフラグ
extern int rightflag;//右移動のフラグ
extern int bulletflag;//0:球打てる,1:球打つ瞬間,2:待機時間
