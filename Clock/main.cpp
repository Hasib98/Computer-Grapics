/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#include<math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat i = 0.0f;

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed

}


void init(void)
{
    // select background color
    glClearColor(1.0, 1.0, 1.0, 0.0); // (red, green, blue, alpha), used by glClear

    // Define world coordinate frame
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // model in real word units
    // (left, right, bottom, top, near, far)
}


void Circle_Line(GLfloat x, GLfloat y, GLfloat radius)
{
    glColor3ub(255, 51, 204);
    //GLfloat x=.4f; GLfloat y=.4f; GLfloat radius =.2f;
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 3.14159265358979323846;

    glBegin(GL_LINE_LOOP);

    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / lineAmount)),
            y + (radius* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void Circle_Filled(float cx, float cy, float r, int num_segments) {
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


void rotation()
{



    glPushMatrix();

    glRotatef(i,0.0,0.0,-0.1);
    glColor3ub(74,74,238);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f( 0.0, -0.02f);
    glVertex2f( 0.3, 0.0f);
    glVertex2f( 0.0, 0.02f);
    glEnd();
    i+=0.005f;

    glRotatef(i,0.0,0.0,-0.1);
    glColor3ub(23, 23,183);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f( 0.0, -0.02f);
    glVertex2f( 0.4, 0.0f);
    glVertex2f( 0.0, 0.02f);
    glEnd();


    glRotatef(i,0.0,0.0,-0.1);
    glColor3ub(1, 0,102);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.0f);
    glVertex2f( 0.0, -0.02f);
    glVertex2f( 0.5, 0.0f);
    glVertex2f( 0.0, 0.02f);
    glEnd();
    //i+=0.05f;
    glPopMatrix();

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

   glColor3ub(61,168,236);
   Circle_Filled(0,0,0.55,200);
   glColor3ub(247,247,0);
   Circle_Filled(0,0,0.5,200);
    rotation();




    glFlush();
}

int main(int argc, char** argv)
{
    //Step#1 Create and initialize glut windowing system
    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(10,10);
    glutCreateWindow("CREATED BY S. M. HASIB 18-36939-1");
    //Step#2 Do Open GL related initializations
    init();
    //Step#3 Register Call back methods or Event Handler methods
    glutDisplayFunc(display);
    //Step#4 Enter in  main loop (an infinite loop listening to registered events and then call their registered methods if any)
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.

    glutMainLoop();
    return 0;
}
