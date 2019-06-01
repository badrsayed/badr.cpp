#include<GL\glut.h>
#include<string>
GLfloat degree = 1;
void displaypyramid()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(degree, 1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.3f, 0.4f, 0.5f);
	glVertex3f(0.2f, -0.6f, 1.0f);
	glVertex3f(0.2f, 0.3f, 1.0f);
	glVertex3f(0.5f, 0.3f, 1.0f);
	glVertex3f(0.5f, -0.6f, 1.0f);
	//*************************************
	glColor3f(0.7f, 0.5f, 0.8f);
	glVertex3f(0.5f, -0.6f, 1.0f);
	glVertex3f(0.5f, 0.3f, 1.0f);
	glVertex3f(0.9f, 0.6f, 0.0f);
	glVertex3f(0.9f, -0.3f, 0.0f);
	//*************************************
	glColor3f(0.1f, 0.6f, 0.5f);
	glVertex3f(0.5f, -0.3f, 0.0f);
	glVertex3f(0.5f, 0.6f, 0.0f);
	glVertex3f(0.9f, 0.6f, 0.0f);
	glVertex3f(0.9f, -0.3f, 0.0f);
	//*************************************
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, -0.6f, 1.0f);
	glVertex3f(0.2f, 0.3f, 1.0f);
	glVertex3f(0.5f, 0.6f, 0.0f);
	glVertex3f(0.5f, -0.3f, 0.0f);
	//*************************************
	glEnd();
	degree += 1;
	glutSwapBuffers();
}
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30.0f, aspect, 0.1f, 80.0f);  
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Cubic rotate");
	glutDisplayFunc(displaypyramid);
	glutReshapeFunc(reshape);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glutTimerFunc(3000, timer, 0);
	glutMainLoop();
	return 0;
}
