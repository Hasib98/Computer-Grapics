

#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>

void init(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);

	// Define world coordinate frame
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}




void LinesBelowRoof() {
	glColor3ub(80, 86, 94);
	glBegin(GL_QUADS);
	glVertex2f(-0.95, 0.18);
	glVertex2f(-0.95, 0.21);
	glVertex2f(0.936, 0.21);
	glVertex2f(0.936, 0.18);

	glColor3ub(167, 168, 166);
	glVertex2f(-0.924, 0.18);
	glVertex2f(-0.924, 0.13);
	glVertex2f(0.906, 0.13);
	glVertex2f(0.906, 0.18);
	glEnd();
}

void Body() {
	glColor3ub(218, 218, 218);
	glBegin(GL_QUADS);
	glVertex2f(-0.85,0.9);
	glVertex2f(-0.85, -0.9);
	glVertex2f(0.816, -0.9);
	glVertex2f(0.816, 0.9);
	glEnd();
}

void Windows() {
	glColor3ub(163, 167, 168);
	glBegin(GL_QUADS);
	glVertex2f(-0.75, -0.3);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.3, -0.6);
	glVertex2f(-0.75, -0.6);

	glVertex2f(0.75, -0.3);
	glVertex2f(0.3, -0.3);
	glVertex2f(0.3, -0.6);
	glVertex2f(0.75, -0.6);


	glVertex2f(-0.75, 0.0);
	glVertex2f(-0.3, 0.0);
	glVertex2f(-0.3, 0.3);
	glVertex2f(-0.75, 0.3);

	glVertex2f(0.75, 0.0);
	glVertex2f(0.3, 0.0);
	glVertex2f(0.3, 0.3);
	glVertex2f(0.75, 0.3);


	glVertex2f(-0.75, 0.6);
	glVertex2f(-0.3, 0.6);
	glVertex2f(-0.3, 0.9);
	glVertex2f(-0.75, 0.9);

	glVertex2f(0.75, 0.6);
	glVertex2f(0.3, 0.6);
	glVertex2f(0.3, 0.9);
	glVertex2f(0.75, 0.9);
	glEnd();
}

void Door() {
	glColor3ub(147, 133, 124);
	glBegin(GL_QUADS);
	glVertex2f(-0.2, -0.6);
	glVertex2f(0.2, -0.6);
	glVertex2f(0.2, -0.9);
	glVertex2f(-0.2, -0.9);
	glEnd();
}

void BottomLine() {
	glColor3ub(56, 58, 73);
	glBegin(GL_QUADS);
	glVertex2f(-0.924, -0.95);
	glVertex2f(0.906, -0.95);
	glVertex2f(0.906, -0.9);
	glVertex2f(-0.924, -0.9);
	glEnd();
}

void Circle(float cx, float cy, float r, int num_segments) {
	const float PI = 3.14159;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++) {
		float theta = i * (2.0f * PI / num_segments);
		float x = r * cos(theta);
		float y = r * sin(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void DoorKnob() {
	glColor3ub(255, 242, 0);
	Circle(0.15, -0.75, 0.02, 30);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	LinesBelowRoof();
	Body();
	Windows();
    BottomLine();
	Door();
	DoorKnob();


	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitWindowSize(600, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Created by S. M. Hasib (18-36939-1)");
	init();

	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}


