#include <GL/glut.h>
#include <cmath>

void drawAirConditioner();
void display(void);

double rotation_y = 0;
double rotate_All = 0;

void draw3D(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
	glShadeModel(GL_SMOOTH);
	glViewport(10, 100, 480, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(58.0, (GLfloat)640 / (GLfloat)480, 1.0, 200.0);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -30);
	glRotatef(rotate_All, 1.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(rotation_y, 1.0, 1.0, 1.0);

	drawAirConditioner();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void drawAirConditioner()
{
	// Main body
	glColor3f(0.4, 0.4, 0.4);  // Gray color
	glutSolidCube(6.0);

	// Front vent
	glColor3f(0.8, 0.8, 0.8);  // Light gray color
	glBegin(GL_QUADS);
	glVertex3f(-2.5, -3.0, 3.1);
	glVertex3f(2.5, -3.0, 3.1);
	glVertex3f(2.5, 3.0, 3.1);
	glVertex3f(-2.5, 3.0, 3.1);
	glEnd();

	// Control panel
	glColor3f(0.2, 0.2, 0.2);  // Dark gray color
	glBegin(GL_QUADS);
	glVertex3f(-2.2, 2.5, 3.2);
	glVertex3f(2.2, 2.5, 3.2);
	glVertex3f(2.2, 3.0, 3.2);
	glVertex3f(-2.2, 3.0, 3.2);
	glEnd();

	// Side vents
	glColor3f(0.6, 0.6, 0.6);  // Medium gray color
	glBegin(GL_QUADS);
	glVertex3f(3.0, -2.5, 0.0);
	glVertex3f(3.0, -2.5, 3.0);
	glVertex3f(3.0, 2.5, 3.0);
	glVertex3f(3.0, 2.5, 0.0);

	glVertex3f(-3.0, -2.5, 0.0);
	glVertex3f(-3.0, -2.5, 3.0);
	glVertex3f(-3.0, 2.5, 3.0);
	glVertex3f(-3.0, 2.5, 0.0);
	glEnd();
}

void timer(int value)
{
	rotation_y += 5.0;
	if (rotation_y > 360)
		rotation_y -= 360;

	rotate_All += 0.5;
	if (rotate_All > 360)
		rotate_All -= 360;

	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3D Air Conditioner");
	glutDisplayFunc(display);
	glutTimerFunc(25, timer, 0);
	draw3D();
	glutMainLoop();
	return(0);
}