// OpenGL 2D project Created by S. M. Hasib (18-36939-1)

#include <iostream>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>
#include<string.h>
using namespace std;
int flag=1;


void init(void)
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0; i<=360; i++)
    {
        rad = i*(3.1416/180);
        glVertex2f(x+rx*cos(rad),y+ry*sin(rad));

    }
    glEnd();


}

void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
    glVertex2d(x,y);
    glVertex2d(x,y1);
    glVertex2d(x1,y1);
    glVertex2d(x1,y);


    glEnd();
}
void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
    glVertex2d(x1,y1);
    glVertex2d(x3,y3);
    glVertex2d(x4,y4);
    glVertex2d(x2,y2);
    glEnd();
}

void triangle(int x, int y, int x1, int x2,int y1)
{
    glBegin(GL_POLYGON);
    glVertex2d(x,y);
    glVertex2d(x1,y);

    glVertex2d(x1,y);
    glVertex2d(x2,y1);

    glVertex2d(x2,y1);
    glVertex2d(x,y);
    glEnd();
}

void axis()
{
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-500,0.001);
    glVertex2f(-500, -0.001);
    glVertex2f(500, -0.001);
    glVertex2f(500, 0.001);


    glBegin(GL_QUADS);
    glVertex2f(0.001,500);
    glVertex2f(-0.001,500);
    glVertex2f(-0.001,-500);
    glVertex2f(0.001,-500);
    glEnd();
}




void gradientGL()
{
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    // glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    glBegin(GL_QUADS);
    //yellow color
    glColor3ub(22, 97, 201);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0,1.0);
    //orange color
    glColor3ub(191,217,234);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0, 0.0);
    glEnd();
}




/*void LinesBelowRoof()
{
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
}*/



void Body(float x,float width,float height)
{



    glColor3ub(218, 218, 218);
    glBegin(GL_QUADS);
    glVertex2f((x-width),height);
    glVertex2f((x-width),0);
    glVertex2f(x, 0);
    glVertex2f(x, height);
    glEnd();
}

void Windows(float x, float width, float height)
{
    glColor3ub(163, 167, 168);
    glBegin(GL_QUADS);

    x=x-0.015;
    //float y=0;


    for( float y=0 ; y<height-0.04; y+=0.02)
    {
        y+=0.02;
        glVertex2f(x,y);
        glVertex2f(x,y+0.02);
        glVertex2f(x-width,y+0.02);
        glVertex2f(x-width,y);


    }



    glEnd();



}

void Door()
{


    glColor3ub(147, 133, 124);
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.6);
    glVertex2f(0.2, -0.6);
    glVertex2f(0.2, -0.9);
    glVertex2f(-0.2, -0.9);
    glEnd();
}

void BottomLine()
{
    glColor3ub(56, 58, 73);
    glBegin(GL_QUADS);
    glVertex2f(-0.924, -0.95);
    glVertex2f(0.906, -0.95);
    glVertex2f(0.906, -0.9);
    glVertex2f(-0.924, -0.9);
    glEnd();
}


void Circle(float cx, float cy, float r, int num_segments)
{

    const float PI = 3.14159;


    glBegin(GL_TRIANGLE_FAN);


    for (int i = 0; i < num_segments; i++)
    {
        float theta = i * (2.0f * PI / num_segments);
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}




void hill(float x)
{
    glColor3ub(176, 209, 125);
    Circle(x, 0.0, 0.2, 100);


}
void DoorKnob()
{
    glColor3ub(255, 242, 0);
    Circle(0.15, -0.75, 0.02, 30);
}

void Circle_Line(GLfloat x, GLfloat y, GLfloat radius)
{
    glColor3ub(0,0,0);
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
void Circle_Filled(GLfloat x1, GLfloat y1, GLfloat radius1)
{
    int j;

    //GLfloat x1=-0.4f; GLfloat y1=.4f; GLfloat radius1 =.2f;
    int triangleAmount1 = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi1 = 2.0f * 3.14159265358979323846;
    glColor3ub(255, 204, 102);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(j = 0; j <= triangleAmount1; j++)
    {
        glVertex2f(
            x1 + (radius1 * cos(j *  twicePi1 / triangleAmount1)),
            y1 + (radius1 * sin(j * twicePi1 / triangleAmount1))
        );
    }
    glEnd();

}



void render()
{
    for(unsigned int i = 0; i < 5; i++)
    {
        //DoSomePreparations(); // bind VAO, bind textures, set uniforms etc.
        glDrawArrays(GL_TRIANGLES, 0, 4);
    }


}

void Building(float x,float width,float height)
{



    Body(x,width,height);
    Windows(x,width-0.03, height);
    //BottomLine();
    //Door();

}

void Road()
{

    glBegin(GL_QUADS);

    glColor3ub(90,90,90);

    glVertex2f(1, 0);
    glVertex2f(-1,0);

    glColor3ub(120, 120, 120);

    glVertex2f(-1, -1);
    glVertex2f(1, -1);

    glEnd();
}

void RoadStrip(float x,float y, float width, float height, int m, int n, int o)
{
    float  y1=y, y2=y+height;

    glBegin(GL_QUADS);


    for( float x1=x ; x1<0.8; x1+=(width*2))
    {
        //y+=0.02;
        glColor3ub(255,255,255);
        glVertex2f(x1,y1);
        glVertex2f(x1+width,y1);
        glVertex2f(x1+width,y2);
        glVertex2f(x1,y2);

        glColor3ub(m,n,o);

        glVertex2f(x1+width,y1);
        glVertex2f(x1+width+width,y1);
        glVertex2f(x1+width+width,y2);
        glVertex2f(x1+width,y2);

    }

    //glTranslatef(0.0,0.05,0);
    glEnd();


}

void makeprivatecar()
{
    glColor3f(1.0, 0.0, 0.0);
    circle(5,15,0,0);
    rectangle(0,-15,60,15);

    glColor3f(0.2, 0.47, 1.0);
    triangle(5,15,20,20,45);
    triangle(40,15,60,40,45);

    glColor3f(0, 0, 0);
    rectangle(20,15,40,45);

    glColor3f(1.0, 0.0, 0.0);
    circle(5,10,80,-5);

    glColor3f(1.0, 0.0, 0.0);
    rectangle1(60,-15,80,-15,60,15,80,5);


    glColor3f(0, 0, 0);
    circle(7,14,10,-15);
    circle(7,14,60,-15);

    glColor3f(1.0, 1.0, 1.0);
    circle(6,12,10,-15);
    circle(6,12,60,-15);

}
void star()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);

    glVertex2f(-0.60, 0.77); // <--- -0.60 instead of -0.68
    glVertex2f(-0.68, 0.77); // <--- -0.68 instead of -0.60
    glVertex2f(-0.7, 0.68);
    glVertex2f(-0.64, 0.63);
    glVertex2f(-0.58, 0.68);


    glEnd();

   // glTranslatef(0.4,0,0);


}

void rain()
{

   //glTranslatef(0.04,0,0);
    glScaled(-0.98,0.1,0);
    glColor3ub(255, 255, 255);

    glBegin(GL_LINES);
    glVertex2f(-1,0);
    glVertex2f(-0.98,0.05);

    //glLoadIdentity();

    glEnd();

}

/*................tree.............*/

void Root()
{
    glColor3ub(113,27,42);
    //glColor3ub(1,1,1);
    glBegin(GL_QUADS);



    glVertex2f(0.0064, -0.15);
    glVertex2f(-0.0064,-0.15);

    glVertex2f(-0.0064, -0.3);
    glVertex2f(0.0064, -0.3);

    glEnd();
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, -1.0, 20.0, -15.0, 15.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
void canopy(float height,float Base)
{
    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    //glColor3f(0.64f, 0.16f, 0.16f);
    glColor3ub(113,27,42);
    glPushMatrix();
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    gluCylinder(qobj, Base, Base - (0.2 * Base), height, 20, 20);
    glPopMatrix();
}
void maketree(float height,float Base)
{

    glPushMatrix();



    float angle;
    canopy(height, Base);
    glTranslatef(0.0f, height,0.0f);
    height -=height*0.2f;
    Base -=Base*0.3f;
    for(float a=0; a<3.5; a++)
    {


        angle = 20+((rand()%50));
        if(angle >48)
            angle = -(20+((rand()%50)));
        if (height > 1)
        {
            glPushMatrix();
            if (flag)
                glRotatef(angle, 1.0f, 0.0f, 1.0f);
            else
                glRotatef(angle, 0.0f, 1.0f, 1.0f);
            flag = !flag;
            maketree(height, Base); //recursive call
            glPopMatrix();

        }
        else
        {
            //glColor3f(0.0f, 1.0f / a, 0.0f);
            glColor3ub(18,179,18);
            glutSolidSphere(0.1f, 10, 10);// for fruits.

        }
    }
    //Glut.glutSwapBuffers();
    glPopMatrix();
    glutSwapBuffers();



}




void display(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



   gradientGL();

  hill(-0.8);
   hill(-0.4);
hill(-0.0);
    hill(0.4);
    hill(0.8);
    //DoorKnob();
    glColor3ub(255, 204, 102);
    Circle(0.5, 0.7, 0.1, 100);

    //Circle_Line(.4f,.4f,.2f);
    //Circle_Filled(0.5,0.7,.1f);

    // render();
   Building(0.1,0.2,0.5);

    Building(-.75,0.2,0.6);
    Building(-0.3,0.16,0.75);
    Building(-0.48,0.2,0.5);
    Building(0.6,0.4,0.4);
    Building(0.9,0.2,0.6);
   Road();
    RoadStrip(-1.0,-0.04, 0.2,0.04,216,167,6);

   RoadStrip(-1.0,-0.55, 0.2,0.03,1,1,1);
    glTranslatef(0,-0.2,0);
     //makeprivatecar();


   // star();


    glTranslatef(-0.69f,0.3,0);
    glScalef(0.05,0.05,0);


   maketree(3.8f,0.08f);





   glLoadIdentity();
    //rain();
   glTranslatef(-0.69,0.26,0);
   // glScalef(0.0,0.0,0);

    Root();


    glLoadIdentity();


    // axis();






    glFlush();
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Created by S. M. Hasib (18-36939-1)");
    //glutFullScreen();
    init();

    glutDisplayFunc(display);
    //glEnable(GL_DEPTH_TEST);
   // glutReshapeFunc(resize);

    glutMainLoop();
    return 0;
}


