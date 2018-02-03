#include <GL/glut.h>
#include <stdlib.h>
double p[3];

void initial(void) {
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void changeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspect;
	aspect = (float)w / (float)h;
	gluPerspective(90, aspect, 2.0, 5000000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay() {
	static GLfloat fElect1 = 250.f, flight = 0.0f;
	static GLint i = 0; i++;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, fElect1, -250.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(10.0f, 90.0, 90.0);	//小球的属性
	if (flight == 0.0f && fElect1 > -250.0f)
		fElect1 -= i*1.0f;	//自由落体
	if (fElect1 <= -245.0f)
		flight = 1.0f;	  //标记值
	if (flight == 1.0f && fElect1 < 250.0f)
		fElect1 += 10.0f;		//反弹设置
	if (fElect1 >= 250.0f) {
		flight = 0.0f;
		i = 0;
	}	//第二次下落设置
	glutSwapBuffers();
}

void timerFunc(int value) {
	glutPostRedisplay();
	glutTimerFunc(100, timerFunc, 1);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("陈星宇");
	glutReshapeFunc(changeSize);
	glutDisplayFunc(myDisplay);
	glutTimerFunc(500, timerFunc, 1);
	initial();
	glutMainLoop();
	return 0;
}
