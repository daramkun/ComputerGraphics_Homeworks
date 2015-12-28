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
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 행렬 모드를 모델 및 뷰 행렬 모드로 전환
    glMatrixMode(GL_MODELVIEW);
    // 단위 행렬을 로드
    glLoadIdentity();
    // 뷰 행렬에 위치 (0, 24, 72), 방향 (0, 0, 0), 카메라 상위 (0, 1, 0)
    // 인 카메라를 적용
    gluLookAt(0, 24, 72, 0, 0, 0, 0, 1, 0);
    
    // 구 A
    glPushMatrix();
    {
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
            
            // 화면에 그리는 물체의 색상은 R:50, G:51, B:255
            glColor3f(0.2f, 0.2f, 1);
            // 구를 그린다
            glutWireSphere(3, 10, 10);
        }
        glPopMatrix();
        
        // 자전을 위해 y축으로 회전
        glRotatef(angle_A, 0, 1, 0);
        // x축으로 90도 회전
        glRotatef(90, 1, 0, 0);
        // 자전축 회전을 위해 z축으로 회전을 30도
        glRotatef(30, 0, 0, 1);
        
        // 화면에 그리는 물체의 색상은 R:255, G:127, B:76
        glColor3f(1, 0.5f, 0.3f);
        // 구를 그린다
        glutWireSphere(7, 10, 10);
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("201002506 Jin Jae-yeon");
    
    // 콜백 함수 등록
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutTimerFunc(1000 / 60, timer, 0);
    
    // GLUT 메시지 루프 시작
    glutMainLoop();
    
    return 0;
}
