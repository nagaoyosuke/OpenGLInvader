#include "game.h"

double px = 0.0;//barのx軸
double py = -7.0;//barのy軸
int start = 0;//start用のフラグ
double bx = 0.0;//ballのx軸
double by = -100.0;//ballのy軸
double movex = 0.1;//x軸の移動
double movey = -0.1;//y軸の移動
int leftflag = 0;//左移動のフラグ
int rightflag = 0;//右移動のフラグ
int bulletflag = 0;

double theta = 0.0;

//表面素材のデータ
float mtrl_diffuse[] = { 0.6, 0.6, 0.6, 1.0};
float mtrl_specular[] = { 0.4, 0.4, 0.4, 1.0};
float mtrl_shininess[] = {100.0};// range [0,127]

float light0_position[]  = {20.0, 30.0, 2.0, 1.0};
float light0_ambient[]   = { 1.0,  1.0, 1.0, 1.0};
float light0_diffuse[]   = { 1.0,  1.0, 1.0, 1.0};
float light0_specular[]  = { 0.5,  0.5, 0.5, 1.0};
float light0_direction[] = {-0.4, -0.6, -0.04};

void init(void)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BlockGame");
    glClearColor(0.0, 0.0, 0.0, 1.0); 
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    init();
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyup); 
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutTimerFunc(100, timer, 0);
    glutMainLoop();
    return 0;
}

void display(void){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    light();

    if(start == 0){
        InvaiderInit();
    }

    /*invaider生成*/
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            /*配列の中身が1ならブロックを描画する*/
            if(invaiders[i][j] == 1){
                glPushMatrix();
                    glMaterialfv(GL_FRONT, GL_DIFFUSE, mtrl_diffuse);
                    glMaterialfv(GL_FRONT, GL_SPECULAR, mtrl_specular);
                    glMaterialfv(GL_FRONT, GL_SHININESS, mtrl_shininess);
                    glTranslated(invaidersPosX[i][j],invaidersPosY[i][j],0.0);
                    glutSolidCube(1.0);
                glPopMatrix();
            }
        }
    }

    /*bar生成*/
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mtrl_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mtrl_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mtrl_shininess);
        glTranslated(px,py,0.0);
        glScaled(3.0,0.5,1.0);
        glutSolidCube(1.0);
    glPopMatrix();
        
    /*bullet生成*/
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mtrl_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mtrl_specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, mtrl_shininess);
        glTranslated(bx,by,0.0);
        glutSolidSphere(0.2,10,10);
    glPopMatrix();

    glutSwapBuffers();
}


void light(void)
{
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glEnable(GL_LIGHT0);
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();//単位行列を初期化
    gluPerspective(90.0, (double)w/(double)h, 0.1, 30.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//単位行列を初期化
    gluLookAt(0.0,-8.0,10.0, 0.0,0.0,0.0, 0.0,1.0,0.0);
}