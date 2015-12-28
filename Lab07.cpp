//
//  main.cpp
//  GLProgramming
//
//  Created by jinjae-yeon on 2014. 11. 19..
//  Copyright (c) 2014년 DARAM WORLD. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <vector>
#include <sys/time.h>

class Planet
{
	friend void idle ();
	friend void display ();
	
public:
	Planet ( float distanceFrom = 0, float rotationAxis = 0, float rotationRate = 0, float skiddingRate = 0 ) : m_distanceFrom ( distanceFrom ), m_rotationAmount ( 0 ), m_skiddingAmount ( 0 ), m_rotationAxis ( rotationAxis ), m_rotationRate ( rotationRate ), m_skiddingRate ( skiddingRate )
	{
		innerPlanet = nullptr;
		nextPlanet = nullptr;
	}
	virtual ~Planet ()
	{
		if ( innerPlanet != nullptr )
			delete innerPlanet;
		if ( nextPlanet != nullptr )
			delete nextPlanet;
	}
	
public:
	virtual void update () { }
	virtual void render () { }
	
private:
	void onUpdate ()
	{
		m_skiddingAmount += m_skiddingRate;
		m_rotationAmount += m_rotationRate;
		
		update ();
		if ( innerPlanet != nullptr )
			innerPlanet->onUpdate ();
		if ( nextPlanet != nullptr )
			nextPlanet->onUpdate ();
	}
	
	void onRender ()
	{
		glPushMatrix ();
		
		glRotatef(m_rotationAmount, 0, 1, 0);
		
		glRotatef(-m_rotationAxis, 0, 0, 1);
		
		glTranslatef(m_distanceFrom, 0, 0);
		glRotatef(m_skiddingRate, 0, 1, 0);
		
		glRotatef(m_rotationAxis, 0, 0, 1);
		
		if ( innerPlanet != nullptr )
			innerPlanet->onRender ();
		
		render ();
		
		glPopMatrix ();
		
		if ( nextPlanet != nullptr )
			nextPlanet->onRender ();
	}
	
protected:
	float m_rotationAxis;
	float m_rotationRate;
	float m_skiddingRate;
	float m_distanceFrom;
	
protected:
	Planet * innerPlanet;
	Planet * nextPlanet;
	
private:
	float m_skiddingAmount;
	float m_rotationAmount;
};

class Neptune : public Planet
{
public:
	Neptune () : Planet ( 240, 0, 3.22f, 0 )
	{
		
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.4, 0.4, 0.9, 1.0};
		GLfloat diffuse[] = {0.4, 0.4, 0.9, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 6, 40, 40 );
	}
};

class Uranos : public Planet
{
public:
	Uranos () : Planet ( 200, 0, 2.22f, 0 )
	{
		nextPlanet = new Neptune ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.2, 0.2, 0.9, 1.0};
		GLfloat diffuse[] = {0.2, 0.2, 0.9, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 6, 40, 40 );
	}
};

class Saturn : public Planet
{
public:
	Saturn () : Planet ( 160, 5.25f, 3.22f, 0 )
	{
		nextPlanet = new Uranos ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat diffuse[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 12, 40, 40 );
	}
};

class Ganymede : public Planet
{
public:
	Ganymede () : Planet ( 30, 0, 2.22f, 0 )
	{
		
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat diffuse[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 2, 40, 40 );
	}
};

class Io : public Planet
{
public:
	Io () : Planet ( 40, 0, 8.22f, 0 )
	{
		nextPlanet = new Ganymede ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat diffuse[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 3, 40, 40 );
	}
};

class Jupiter : public Planet
{
public:
	Jupiter () : Planet ( 120, 0, 4.22f, 0 )
	{
		nextPlanet = new Saturn ();
		innerPlanet = new Io ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.8, 0.5, 0.2, 1.0};
		GLfloat diffuse[] = {0.8, 0.5, 0.2, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 15, 40, 40 );
	}
};

class Mars : public Planet
{
public:
	Mars () : Planet ( 80, 0, 5.55f, 0 )
	{
		nextPlanet = new Jupiter ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.8, 0.4, 0.2, 1.0};
		GLfloat diffuse[] = {0.8, 0.4, 0.2, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 5, 40, 40 );
	}
};

class Moon : public Planet
{
public:
	Moon () : Planet ( 10, 0, 8.0f, 0 )
	{
		
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat diffuse[] = {0.6, 0.4, 0.3, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 3, 40, 40 );
	}
};

class Earth : public Planet
{
public:
	Earth () : Planet ( 60, 0, 7.0f, 0 )
	{
		nextPlanet = new Mars ();
		innerPlanet = new Moon ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.5, 0.4, 0.75, 1.0};
		GLfloat diffuse[] = {0.5, 0.4, 0.75, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 7, 40, 40 );
	}
};

class Venus : public Planet
{
public:
	Venus () : Planet ( 40, 0, 7.25f, 0 )
	{
		nextPlanet = new Earth ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.3, 0.6, 0.2, 1.0};
		GLfloat diffuse[] = {0.3, 0.6, 0.2, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 7, 40, 40 );
	}
};

class Mercury : public Planet
{
public:
	Mercury () : Planet ( 20, 0, 8.5f, 0 )
	{
		nextPlanet = new Venus ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.7, 0.4, 0.2, 1.0};
		GLfloat diffuse[] = {0.7, 0.4, 0.2, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0, 0, 0, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 2, 40, 40 );
	}
};

class Sun : public Planet
{
public:
	Sun ()
	{
		innerPlanet = new Mercury ();
	}
	
	void render ()
	{
		GLfloat ambient[] = {0.75, 0.4, 0.4, 1.0};
		GLfloat diffuse[] = {0.75, 0.4, 0.4, 1.0};
		GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
		GLfloat shine = 10.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		GLfloat emission[] = {0.4, 0.1, 0.1, 1};
		glMaterialfv(GL_FRONT, GL_EMISSION, emission);
		
		glutSolidSphere ( 10, 40, 40 );
	}
};

void idle ();
void display ();
void reshape ( int width, int height );
void keyboardDown ( unsigned char key, int x, int y );
void keyboardUp ( unsigned char key, int x, int y );

Planet * sun;
int camera_x, camera_y = 240, camera_z = 260;
bool isKeyDown[256];

int main ( int argc, const char * argv [] )
{
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
	glutIdleFunc(idle);
	
	// 라이팅 켜기
	glEnable(GL_LIGHTING);
	// 깊이 테스트 켜기
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	sun = new Sun ();
	
	// GLUT 메시지 루프 시작
	glutMainLoop();
	
	delete sun;
	
    return 0;
}

void idle ()
{
	static long long lastTime;
	static unsigned day = 1;
	timeval ts;
	gettimeofday(&ts, nullptr);
	
	long long currentTime = ts.tv_sec * 1000 + ts.tv_usec / 1000;
	
	if ( ( currentTime - lastTime ) / 1000.0f >= ( 1 / 30.0f ) )
	{
		char title [ 128 ];
		sprintf ( title, "%s (Day: %d)", "201002506 Jin Jae-yeon", ++day );
		glutSetWindowTitle(title);
		
		float unit = 2;
		
		if(isKeyDown['w']) camera_z -= unit;
		if(isKeyDown['s']) camera_z += unit;
		if(isKeyDown['a']) camera_x -= unit;
		if(isKeyDown['d']) camera_x += unit;
		if(isKeyDown['q']) camera_y += unit;
		if(isKeyDown['e']) camera_y -= unit;
		
		sun->onUpdate ();
		
		glutPostRedisplay ();
		
		lastTime = currentTime;
	}
}

void display ()
{
	glClearColor ( 0, 0, 0, 1 );
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	glMatrixMode ( GL_MODELVIEW );
	glLoadIdentity ();
	
	gluLookAt(camera_x, camera_y, camera_z, 0, 0, 0, 0, 1, 0);
	
	glEnable(GL_LIGHT0);
	GLfloat diffuse0[]={1.0, 0.6, 0.6, 0.6};
	GLfloat ambient0[]={1.0, 1.0, 1.0, 1.0};
	GLfloat specular0[]={1.0, 0.3, 0.3, 0.3};
	GLfloat light0_pos[]={0, 0, 0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
	
	sun->onRender ();
	
	glFlush ();
}

void reshape ( int width, int height )
{
	glViewport ( 0, 0, width, height );
	
	glMatrixMode ( GL_PROJECTION );
	glLoadIdentity ();
	gluPerspective ( 45, width / ( float ) height, 1, 1000 );
}

void keyboardDown ( unsigned char key, int x, int y )
{
	isKeyDown[key] = true;
}

void keyboardUp ( unsigned char key, int x, int y )
{
	isKeyDown[key] = false;
}
