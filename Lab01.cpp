//
//  main.cpp
//  OpenGLProgramming
//
//  Created by 진재연 on 2014. 10. 1..
//  Copyright (c) 2014년 진재연. All rights reserved.
//
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

void display() {
    // 행렬 모드를 모델 및 뷰 행렬 모드로 전환
    glMatrixMode(GL_MODELVIEW);
    // 단위 행렬을 로드
    glLoadIdentity();
    // 뷰 행렬에 위치 (0, 0, 10), 방향 (0, 0, 0), 카메라 상위 (0, 1, 0)
    // 인 카메라를 적용
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
    
    // z축으로 회전을 -45도
    glRotatef(-45, 0, 0, 1);
    // (0, 5, 0)만큼 이동
    glTranslatef (0, 5, 0);
    // z축으로 회전을 45도
    glRotatef(45, 0, 0, 1);
    
    // 구를 그린다
    glutWireSphere(1, 60, 10);
    
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

int main(int argc, const char * argv[]) {
    // GLUT 초기화
    glutInit(&argc, (char**)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Test");
    
    // 화면 색상을 A:255, R:0, G:0, B:0으로
    // 초기화하도록 설정
    glClearColor(0, 0, 0, 1);
    // 색상 버퍼를 초기화
    glClear(GL_COLOR_BUFFER_BIT);
    // 화면에 그리는 물체의 색상은 R:255, G:255, B:255
    glColor3f(1, 1, 1);
    
    // 콜백 함수 등록
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    // GLUT 메시지 루프 시작
    glutMainLoop();
    
    return 0;
}
