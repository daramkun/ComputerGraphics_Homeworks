//
//  main.cpp
//  OpenGLProgramming
//
//  Created by 진재연 on 2014. 10. 1..
//  Copyright (c) 2014년 진재연. All rights reserved.
//
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

float angle_A, angle_B;
bool rotation_A, rotation_B;

void display() {
    // 화면 색상을 A:255, R:0, G:0, B:0으로
    // 초기화하도록 설정
    glClearColor(0, 0, 0, 1);
    // 색상 버퍼를 초기화
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // 행렬 모드를 모델 및 뷰 행렬 모드로 전환
    glMatrixMode(GL_MODELVIEW);
    // 단위 행렬을 로드
    glLoadIdentity();
    // 뷰 행렬에 위치 (0, 24, 72), 방향 (0, 0, 0), 카메라 상위 (0, 1, 0)
    // 인 카메라를 적용
    gluLookAt(0, 10, 72, 0, 0, 0, 0, 1, 0);
    
    // 구 A
    glPushMatrix();
    {
        // 첫 번째 광원 설정
        // 붉은색 빛을 띈다
        glEnable(GL_LIGHT0);
        GLfloat diffuse0[]={1.0, 0.2, 0.2, 1.0};
        GLfloat ambient0[]={1.0, 1.0, 1.0, 1.0};
        GLfloat specular0[]={1.0, 0.0, 0.0, 1.0};
        GLfloat light0_pos[]={0, 0, 0, 1.0};
        glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
        
        // 광원이 앞면과 뒷면 모두에 적용되도록 한다
        glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
        
        // 구 B
        glPushMatrix();
        {
            // 자전을 위해 y축으로 반대 회전
            glRotatef(angle_B, 0, 1, 0);
            // 구 A로부터 떨어지기 위해 (30, 0, 0)만큼 이동
            glTranslatef (30, 0, 0);
            // 자전을 위해 y축으로 회전
            glRotatef(-angle_B + angle_A, 0, 1, 0);
            // x축으로 90도 회전
            glRotatef(90, 1, 0, 0);
            // 자전축 회전을 위해 z축으로 회전을 70도
            glRotatef(70, 0, 0, 1);
            
            // 구 B의 재질을 설정
            GLfloat ambient[] = {0.2, 0.2, 1, 1.0};
            GLfloat diffuse[] = {0.2, 0.2, 1, 1.0};
            GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
            GLfloat shine = 100.0f;
            glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
            glMaterialf(GL_FRONT, GL_SHININESS, shine);
            
            // 구를 그린다
            glutSolidSphere(3, 60, 60);
        }
        glPopMatrix();
        
        // 자전을 위해 y축으로 회전
        glRotatef(angle_A, 0, 1, 0);
        // x축으로 90도 회전
        glRotatef(90, 1, 0, 0);
        // 자전축 회전을 위해 z축으로 회전을 30도
        glRotatef(30, 0, 0, 1);
        
        // 구 A의 재질을 설정
        GLfloat ambient[] = {1, 0.2, 0.2, 1.0};
        GLfloat diffuse[] = {1, 0.2, 0.2, 1.0};
        GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
        GLfloat shine = 10.0f;
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
        glMaterialf(GL_FRONT, GL_SHININESS, shine);
        GLfloat emission[] = {0.4, 0.1, 0.1, 1};
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
        
        // 구를 그린다
        glutSolidSphere(7, 60, 60);
    }
    glPopMatrix();
    
    // 지금까지의 작업 결과를 화면에 출력
    glFlush ();
}

void reshape (int w, int h) {
    // 화면비 계산
    float ratio = w / (float)h;
    // 뷰포트를 화면 크기만큼 적용
    glViewport (0, 0, w, h);
    // 행렬 모드를 투영 행렬 모드로 전환
    glMatrixMode (GL_PROJECTION);
    // 단위 행렬을 로드
    glLoadIdentity ();
    // 45도 각도로 내려보고, 위에서 계산된 화면비를 사용하며
    // 1만큼 가까이 있고 1000만큼 멀리 있는 물체를 출력하도록
    // 투영 행렬을 적용
    gluPerspective (45, ratio, 1, 1000);
}

void keyboardDown ( unsigned char key, int x, int y )
{
    switch (key) {
        case 'a': rotation_A = true; break;
        case 'b': rotation_B = true; break;
    }
}

void keyboardUp ( unsigned char key, int x, int y )
{
    switch (key) {
        case 'a': rotation_A = false; break;
        case 'b': rotation_B = false; break;
    }
}

void timer ( int x )
{
    if(rotation_A)
        angle_A += 3;
    if(rotation_B)
        angle_B += 3;
    
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, const char * argv[]) {
    // GLUT 초기화
    glutInit(&argc, (char**)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("201002506 Jin Jae-yeon");
    
    // 콜백 함수 등록
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(1000 / 60, timer, 0);
    
    // 라이팅 켜기
    glEnable(GL_LIGHTING);
    // 깊이 테스트 켜기
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    // GLUT 메시지 루프 시작
    glutMainLoop();
    
    return 0;
}
