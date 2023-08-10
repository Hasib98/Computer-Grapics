#include<windows.h>
#include<math.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
int flag=1;
GLfloat i = 0.0f;

GLfloat position = 0.0f;
GLfloat speed = 0.1f;


GLfloat position3 = 0.0f;
GLfloat speed3 =- 0.5f;





void init(void)
{

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

void Idle()
{
    glutPostRedisplay();
}

void update(int value)
{

    if(position <-1.0)
        position = 1.0f;

    position -= 0.3*speed; //position=position-speed;1-.1=.9

    glutPostRedisplay();


    glutTimerFunc(100, update, 0);
}


void axis()
{
    glColor3ub(255,0,0);


    glBegin(GL_LINES);//.....X axis
    glVertex2f(-1,0);
    glVertex2f(1,0);


    glColor3ub(0,0,0);

    glBegin(GL_LINES);
    glVertex2f(-1,0.1);
    glVertex2f(1,0.1);

    glBegin(GL_LINES);
    glVertex2f(-1,0.2);
    glVertex2f(1,0.2);

    glBegin(GL_LINES);
    glVertex2f(-1,0.3);
    glVertex2f(1,0.3);

    glBegin(GL_LINES);
    glVertex2f(-1,0.4);
    glVertex2f(1,0.4);

    glBegin(GL_LINES);
    glVertex2f(-1,0.5);
    glVertex2f(1,0.5);

    glBegin(GL_LINES);
    glVertex2f(-1,0.6);
    glVertex2f(1,0.6);

    glBegin(GL_LINES);
    glVertex2f(-1,0.7);
    glVertex2f(1,0.7);

    //.................

    glBegin(GL_LINES);
    glVertex2f(-1,-0.1);
    glVertex2f(1,-0.1);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.3);
    glVertex2f(1,-0.3);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.4);
    glVertex2f(1,-0.4);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.4);
    glVertex2f(1,-0.4);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.5);
    glVertex2f(1,-0.5);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.6);
    glVertex2f(1,-0.6);

    glBegin(GL_LINES);
    glVertex2f(-1,-0.7);
    glVertex2f(1,-0.7);



    glColor3ub(255,0,0);
    glBegin(GL_LINES); //.....Y axis
    glVertex2f(0,1);
    glVertex2f(0,-1);


    glColor3ub(0,0,0);

    glBegin(GL_LINES);
    glVertex2f(0.1,-1);
    glVertex2f(0.1,1);

    glBegin(GL_LINES);
    glVertex2f(0.2,-1);
    glVertex2f(0.2,1);

    glBegin(GL_LINES);
    glVertex2f(0.3,-1);
    glVertex2f(0.3,1);

    glBegin(GL_LINES);
    glVertex2f(0.4,-1);
    glVertex2f(0.4,1);

    glBegin(GL_LINES);
    glVertex2f(0.5,-1);
    glVertex2f(0.5,1);

    glBegin(GL_LINES);
    glVertex2f(0.6,-1);
    glVertex2f(0.6,1);

    glBegin(GL_LINES);
    glVertex2f(0.7,-1);
    glVertex2f(0.7,1);

    //.................

    glBegin(GL_LINES);
    glVertex2f(-0.1,-1);
    glVertex2f(-0.1,1);

    glBegin(GL_LINES);
    glVertex2f(-0.2,-1);
    glVertex2f(-0.2,1);

    glBegin(GL_LINES);
    glVertex2f(-0.3,-1);
    glVertex2f(-0.3,1);

    glBegin(GL_LINES);
    glVertex2f(-0.4,-1);
    glVertex2f(-0.4,1);

    glBegin(GL_LINES);
    glVertex2f(-0.5,-1);
    glVertex2f(-0.5,1);

    glBegin(GL_LINES);
    glVertex2f(-0.6,-1);
    glVertex2f(-0.6,1);

    glBegin(GL_LINES);
    glVertex2f(-0.7,-1);
    glVertex2f(-0.7,1);


    glEnd();
}

void gradientGL()
{

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
void gradientGL2()
{

    glBegin(GL_QUADS);
    //yellow color
    glColor3ub(0,0,0);
    glVertex2f(1.0, 1.0);
    glVertex2f(-1.0,1.0);
    //orange color
    glColor3ub(58,58,58);
    glVertex2f(-1.0,0.0);
    glVertex2f(1.0, 0.0);
    glEnd();
}

void Circle_Filled(float cx, float cy, float r, int num_segments,int rr, int g, int b)
{

    const float PI = 3.14159;

    glColor3ub(rr,g,b);


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

void Sun()
{
    glPushMatrix();
    glTranslatef(0*position,position,0);
    //glColor3ub(255, 204, 102);

    Circle_Filled(0.5, 0.7, 0.1, 100,255, 204, 102);


    glLoadIdentity();

    glPopMatrix();

}


void moon()
{
    glPushMatrix();
    glTranslatef(0*position,position,0);
    //glColor3ub(255, 204, 102);

    Circle_Filled(0.5, 0.7, 0.1, 100,233,245,243);
    glLoadIdentity();

    glPopMatrix();

}

void cloud( int m, int n, int o)
{
    glPushMatrix();
    glTranslatef(position,0*position,0);
    glColor3ub(184,214,247);

    Circle_Filled(-0.75, 0.7, 0.08, 100,m,n,o);
    Circle_Filled(-0.67, 0.7, 0.095, 100,m,n,o);
    Circle_Filled(-0.57, 0.7, 0.08, 100,m,n,o);


    glLoadIdentity();



    glTranslatef(position,0*position,0);

    glTranslatef(0.6,0,0);
    glColor3ub(184,214,247);

    Circle_Filled(-0.75, 0.7, 0.08, 100,m,n,o);
    Circle_Filled(-0.67, 0.7, 0.095, 100,m,n,o);
    Circle_Filled(-0.57, 0.7, 0.08, 100,m,n,o);


    glLoadIdentity();



    glTranslatef(position,0*position,0);

    glTranslatef(1.2,0,0);
    glColor3ub(184,214,247);

    Circle_Filled(-0.75, 0.7, 0.08, 100,m,n,o);
    Circle_Filled(-0.67, 0.7, 0.095, 100,m,n,o);
    Circle_Filled(-0.57, 0.7, 0.08, 100,m,n,o);


    glLoadIdentity();

    glPopMatrix();
}
void field()
{
    glBegin(GL_QUADS);
    glColor3ub(204,102,0);

    glVertex2f(1, -0.55);
    glVertex2f(-1,-0.55);

    glColor3ub(102,51,0);

    glVertex2f(-1,-1);
    glVertex2f(1,-1);


    glEnd();
}
void Road()
{

    glBegin(GL_QUADS);

    glColor3ub(90,90,90);

    glVertex2f(1, 0);
    glVertex2f(-1,0);

    glColor3ub(120, 120, 120);

    glVertex2f(-1,-0.55);
    glVertex2f(1, -0.55);

    glEnd();
}

void RoadStrip(float x,float y, float width, float height, int m, int n, int o)
{
    float  y1=y, y2=y+height;

    glBegin(GL_QUADS);


    for( float x1=x ; x1<0.8; x1+=(width*2))
    {
        //y+=0.02;
        glColor3ub(0,0,0);
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
void bench()
{
    //left side bar
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,-0.1);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.6,0.55);
    glVertex2f(-0.7,0.55);
    glEnd();
    Circle_Filled(-0.65,0.55,0.05,100,0,0,0);

//right side bar

    glBegin(GL_QUADS);
    glVertex2f(0.6,-0.1);
    glVertex2f(0.7,-0.1);
    glVertex2f(0.7,0.55);
    glVertex2f(0.6,0.55);
    glEnd();
    Circle_Filled(0.65,0.55,0.05,100,0,0,0);


    glColor3ub(66,33,11);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0);
    glVertex2f(0.7,0);
    glVertex2f(0.7,0.1);
    glVertex2f(-0.7,0.1);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.2);
    glVertex2f(0.7,0.2);
    glVertex2f(0.7,0.3);
    glVertex2f(-0.7,0.3);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.4);
    glVertex2f(0.7,0.4);
    glVertex2f(0.7,0.5);
    glVertex2f(-0.7,0.5);
    glEnd();



//seat
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.2);
    glVertex2f(0.8,-0.2);
    glVertex2f(0.7,-0.1);
    glVertex2f(-0.7,-0.1);
    glEnd();

//border under seat
    glColor3ub(54,27,9);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.2);
    glVertex2f(0.8,-0.2);
    glVertex2f(0.8,-0.25);
    glVertex2f(-0.8,-0.25);
    glEnd();

//leg left side
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.75,-0.25);
    glVertex2f(-0.75,-0.4);
    glVertex2f(-0.65,-0.4);
    glVertex2f(-0.65,-0.25);
    glEnd();
//leg right side


    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(0.65,-0.25);
    glVertex2f(0.65,-0.4);
    glVertex2f(0.75,-0.4);
    glVertex2f(0.75,-0.25);
    glEnd();
}
void group_bench()
{


    glTranslatef(0,0.04,0);
    glScalef(0.1,0.1,0);
    bench();
    glLoadIdentity();

    glTranslatef(0.6,0.04,0);
    glScalef(0.1,0.1,0);
    bench();
    glLoadIdentity();

}
void Body(float x,float width,float height,int m, int n, int o)
{



    glColor3ub(m, n, o);
    glBegin(GL_QUADS);
    glVertex2f((x-width),height);
    glVertex2f((x-width),0);
    glVertex2f(x, 0);
    glVertex2f(x, height);
    glEnd();
}

void Windows(float x, float width, float height)
{
    glColor3ub(232, 232, 232);
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
void Building(float x,float width,float height,int m, int n, int o)
{



    Body(x,width,height,m,n,o);
    Windows(x,width-0.03, height);

}
void group_building()
{
    Building(0.1,0.2,0.5,223,206,195);
    Building(-.75,0.2,0.6,223,206,195);
    Building(-0.3,0.16,0.75,223,206,195);
    Building(-0.48,0.2,0.5,223,206,195);
    Building(0.6,0.4,0.4,223,206,195);
    Building(0.9,0.2,0.6,223,206,195);
}

void group_building2()
{
    Building(0.1,0.2,0.5,201,197,198);
    Building(-.75,0.2,0.6,201,197,198);
    Building(-0.3,0.16,0.75,201,197,198);
    Building(-0.48,0.2,0.5,201,197,198);
    Building(0.6,0.4,0.4,201,197,198);
    Building(0.9,0.2,0.6,201,197,198);
}

void group_megaBuilding()
{
    glTranslatef(0.5,0,0);
    glScalef(0.5,0.5,0);
    group_building();
    glLoadIdentity();

    glTranslatef(-0.5,0,0);
    glScalef(0.5,0.5,0);
    group_building();
    glLoadIdentity();

    glScalef(-0.3,0.5,0);
    group_building2();
    glLoadIdentity();

    glTranslatef(0.5,0,0);
    glScalef(-0.3,0.5,0);
    group_building2();
    glLoadIdentity();

    glTranslatef(0.8,0,0);
    glScalef(-0.3,0.5,0);
    group_building2();
    glLoadIdentity();

    glTranslatef(-0.5,0,0);
    glScalef(-0.3,0.5,0);
    group_building2();
    glLoadIdentity();

    glTranslatef(-0.7,0,0);
    glScalef(-0.3,0.5,0);
    group_building2();
    glLoadIdentity();
}

void drawlinewidth(float x, float y,float x1, float y1, int width)
{
    glPushAttrib(GL_LINE_BIT);
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex2f(x,y);
    glVertex2f(x1,y1);
    glEnd();
    glPopAttrib();

}
void drawline(float x, float y,float x1, float y1, int width)
{
    drawlinewidth(x,y,x1,y1,width);
    drawlinewidth(-x,y,-x1,y1,width);

}
void Eiffel_tower()
{
    //glColor3ub(0,0,0);
    glColor3ub(255,128,0);
//foot
    drawline(-0.4,0,-0.2,0,7);
    drawline(-0.2,0,-0.15,0.02,7);
    drawline(-0.4,0.02,-0.2,0.02,7);
    drawline(-0.2,0.02,-0.15,0.04,7);
    drawline(-0.4,0.04,-0.2,0.04,7);
    drawline(-0.2,0.04,-0.15,0.06,7);

    drawline(-0.15,0.06,-0.04,0.6,3);
//first floor
    drawline(-0.3,0.3,0,0.3,8);
    drawline(-0.33,0.4,0,0.4,9);
    drawline(-0.3,0.3,-0.3,0.4,3);
    drawline(-0.25,0.3,-0.25,0.4,3);
    drawline(-0.2,0.3,-0.2,0.4,3);
    drawline(-0.15,0.3,-0.15,0.4,3);
    drawline(-0.1,0.3,-0.1,0.4,3);
    drawline(-0.05,0.3,-0.05,0.4,3);
    drawline(0.0,0.3,0.0,0.4,3);


//second floor
    drawline(-0.1,0.7,0,0.7,8);
    drawline(-0.13,0.8,0,0.8,8);
    drawline(-0.12,0.83,0,0.83,8);
    drawline(-0.13,0.8,-0.12,0.83,3);
    drawline(-0.1,0.7,-0.13,0.8,3);

    drawline(-0.1,0.7,-0.12,0.83,3);
    drawline(-0.08,0.7,-0.10,0.83,3);
    drawline(-0.06,0.7,-0.08,0.83,3);
    drawline(-0.04,0.7,-0.06,0.83,3);
    drawline(-0.02,0.7,-0.04,0.83,3);
    drawline(-0,0.7,-0.01,0.83,3);



//left bottom arm

    drawline(-0.38,0.04,-0.28,0.3,3);
    drawline(-0.2,0.04,-0.15,0.3,3);
    //mesh
    drawline(-0.34,0.15,-0.18,0.15,3);
    drawline(-0.18,0.15,-0.3,0.3,3);
    drawline(-0.34,0.15,-0.15,0.3,3);
    drawline(-0.34,0.15,-0.2,0.04,3);
    drawline(-0.4,0.04,-0.18,0.15,3);

//third floor;
    glBegin(GL_POLYGON);
    glVertex2f(0,1.4);
    glVertex2f(-0.04,1.4);
    glVertex2f(-0.05,1.44);
    glVertex2f(0,1.44);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,1.4);
    glVertex2f(0.04,1.4);
    glVertex2f(0.05,1.44);
    glVertex2f(0,1.44);
    glEnd();

//peak
    glBegin(GL_POLYGON);
    glVertex2f(0,1.7);
    glVertex2f(0.02,1.44);
    glVertex2f(-0.02,1.44);
    glEnd();
//left top arm
    drawline(-0.09,0.83,-0.04,1.4,3);
    drawline(-0.01,0.83,0,1.4,3);

    drawline(-0.04,1.4,0,1.3,3);
    drawline(0,1.4,-0.05,1.3,3);

    drawline(-0.05,1.3,0,1.3,3);

    drawline(-0.062,1.2,0,1.3,3);

    drawline(-0.05,1.3,0,1.2,3);

    drawline(-0.062,1.2,0,1.2,3);

    drawline(-0.062,1.2,0,1.1,3);
    drawline(-0.065,1.1,0,1.2,3);

    drawline(-0.065,1.1,0,1.1,3);

    drawline(-0.065,1.1,0,1.0,3);
    drawline(-0.075,1.0,0,1.1,3);

    drawline(-0.075,1.0,0,1.0,3);

    drawline(-0.075,1.0,0,0.9,3);
    drawline(-0.085,0.9,0,1.0,3);

    drawline(-0.085,0.9,0,0.9,3);

    drawline(-0.085,0.9,0,0.8,3);
    drawline(-0.095,0.8,0,0.9,3);

    drawline(-0.095,0.8,0,0.8,3);


//left middle arm
    drawline(-0.25,0.4,-0.1,0.7,3);
    drawline(-0.13,0.4,-0.05,0.7,3);
    drawline(-0.08,0.6,0,0.6,3);

    drawline(-0.08,0.6,-0.15,0.6,3);

    drawline(-0.1,0.5,-0.15,0.6,3);
    drawline(-0.2,0.5,-0.08,0.6,3);


    drawline(-0.1,0.5,-0.26,0.4,3);
    drawline(-0.2,0.5,-0.12,0.4,3);

    drawline(-0.15,0.6,-0.05,0.7,3);
    drawline(-0.1,0.7,-0.08,0.6,3);

}

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

void treegroup()
{
    glTranslatef(-0.78f,0.13,0);
    glScalef(0.03,0.03,0);
    maketree(3.8f,0.08f);

    glLoadIdentity();


    glTranslatef(-0.2f,0.1,0);
    glScalef(0.03,0.03,0);
    maketree(3.8f,0.08f);
    glLoadIdentity();



    glTranslatef(0.69f,0.1,0);
    glScalef(0.03,0.03,0);
    maketree(3.8f,0.08f);
    glLoadIdentity();




    glTranslatef(-0.78f,0.29,0);
    glScalef(0.5,0.97,0);
    Root();
    glLoadIdentity();

    glTranslatef(-0.2f,0.29,0);
    glScalef(0.5,0.97,0);
    Root();
    glLoadIdentity();

    glTranslatef(0.69f,0.29,0);
    glScalef(0.5,0.97,0);
    Root();
    glLoadIdentity();

//////////////



}
void treegroup2()
{
    glTranslatef(-0.78f,-0.45,0);
    glScalef(0.03,0.03,0);
    maketree(3.8f,0.08f);

    glLoadIdentity();


    glTranslatef(-0.0f,-0.48,0);
    glScalef(0.03,0.03,0);
    maketree(3.8f,0.08f);
    glLoadIdentity();



    glTranslatef(0.69f,-0.48,0);
    glScalef(0.03,0.03,0);
    maketree(3.8f,0.08f);
    glLoadIdentity();




    glTranslatef(-0.78f,-0.25,0);
    glScalef(0.5,0.97,0);
    Root();
    glLoadIdentity();

    glTranslatef(-0.0f,-0.25,0);
    glScalef(0.5,0.97,0);
    Root();
    glLoadIdentity();

    glTranslatef(0.69f,-0.25,0);
    glScalef(0.5,0.97,0);
    Root();
    glLoadIdentity();



}

void amazingcar()
{
    // glTranslatef(.0,0.8,0.0);
    glEnable(GL_BLEND);	//TRANCPARENCY1
    glBlendFunc(GL_ONE, GL_ZERO);//TRANCPARENCY2 glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(.81,-0.48,0.7);//f

    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'

    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,0.7);//0
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();
    glBegin(GL_POLYGON); // top filling
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.1,0.6,0.7);//o
    glVertex3f(-0.1,0.6,-0.7);//o'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(.52,0.56,0.7);//n
    glEnd();
    glBegin(GL_POLYGON); //back filling
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.14,0.22,-0.7);//l'

    glVertex3f(1.52,.14,-0.7);//k'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.76,.22,0.7);//m
    glVertex3f(0.76,.22,-0.7);//m'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.14,0.22,0.7);//l
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.2,-.28,0.7);//r
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(0.0,-0.2,0.7);//oo
    glEnd();
    glBegin(GL_POLYGON);

    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.2,-.28,-0.7);//r'
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);

    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,0.7);//q
    glVertex3f(-1.08,0.22,0.7);//dd
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-1.02,0.6,0.7);//p
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,0.7);//p
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(-0.1,0.6,0.7);//0
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(-0.5,0.5,0.7);//ee
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,0.7);//ff
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.12,0.5,0.7);//ii
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,0.7);//n
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.76,.22,0.7);//m
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,0.7);//l
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,-.44,0.7);//j
    glVertex3f(1.38,-.48,0.7);//i

    glVertex3f(1.24,-.2,0.7);//h
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,0.22,-0.7);//q'
    glVertex3f(-1.08,0.22,-0.7);//dd'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(-1.02,0.6,-0.7);//p'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.02,0.6,-0.7);//p'
    glVertex3f(-0.98,0.5,-0.7);//aa'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(-0.1,0.6,-0.7);//0'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.64,0.5,-0.7);//bb'
    glVertex3f(-0.64,0.22,-0.7);//cc'
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(-0.5,0.5,-0.7);//ee'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(0.0,0.5,-0.7);//ff'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.12,0.5,-0.7);//ii'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.52,0.56,-0.7);//n'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.76,.22,-0.7);//m'
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(1.14,0.22,-0.7);//l'
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.24,-.2,-0.7);//h'
    glEnd();

    glBegin(GL_POLYGON);	// door1 body- rear, near
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_POLYGON);	// door body- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);	// door2	body- near,driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glBegin(GL_POLYGON);	// door2	body- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_POLYGON);//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glTranslatef(-.58,-.52,0.7);		//translate to 1st tyre
    glColor3f(0.09,0.09,0.09);	// tyre color********
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(1.68,0.0,0.0);	//translate to 2nd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(0.0,0.0,-1.4); //translate to 3rd tyre
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(-1.68,0.0,0.0); //translate to 4th tyre which is behind 1st tyre rearback
    glutSolidTorus(0.12f, .14f, 10, 25);
    glTranslatef(.58,.52,0.7); //translate to origin
    glRotatef(90.0,0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-1.40);
    glutSolidTorus(0.2f, .2f, 10, 25);
    glTranslatef(0.0,0.0,1.40);
    glRotatef(270.0,0.0,1.0,0.0);
    glBegin(GL_POLYGON);	//bottom filling

    glColor3f(0.25,0.25,0.25);
    glVertex3f(-0.3,-.48,0.7);//e
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.81,-0.48,0.7);//f
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.42,-.2,0.7);//d
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-0.3,-.48,-0.7);//e'
    glVertex3f(-0.3,-.48,0.7);//e
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.2,-.28,0.7);//r
    glVertex3f(-1.2,-.28,-0.7);//r'
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-1.12,-.48,0.7);//a
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-1.12,-.48,0.7);//a
    glVertex3f(-1.12,-.48,-0.7);//a'
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-0.86,-.48,0.7);//b
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-0.86,-.48,0.7);//b
    glVertex3f(-0.86,-.48,-0.7);//b'
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.74,-0.2,0.7);//c
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-.74,-0.2,0.7);//c
    glVertex3f(-.74,-0.2,-0.7);//c'
    glVertex3f(-.42,-.2,-0.7);//d'
    glVertex3f(-.42,-.2,0.7);//d
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.81,-0.48,0.7);//f
    glVertex3f(.81,-0.48,-0.7);//f'
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(.94,-0.2,0.7);//g
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(.94,-0.2,0.7);//g
    glVertex3f(.94,-0.2,-0.7);//g'
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.24,-.2,0.7);//h

    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.24,-.2,0.7);//h
    glVertex3f(1.24,-.2,-0.7);//h'
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.38,-.48,0.7);//i
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.38,-.48,0.7);//i
    glVertex3f(1.38,-.48,-0.7);//i'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();
    glBegin(GL_LINE_LOOP); // door outline- rear, front
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.5,0.22,0.7);//hh
    glVertex3f(0.0,0.22,0.7);//gg
    glVertex3f(0.0,-0.2,0.7);//oo
    glVertex3f(-0.5,-0.2,0.7);//pp
    glEnd();
    glBegin(GL_LINE_LOOP);	// door2 outline- near, driver
    glVertex3f(0.12,0.22,0.7);//ll
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.62,-0.2,0.7);//mm
    glVertex3f(0.12,-0.2,0.7);//nn
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);	// door2	outline- far, driver
    glVertex3f(0.12,0.22,-0.7);//ll'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.62,-0.2,-0.7);//mm'
    glVertex3f(0.12,-0.2,-0.7);//nn'
    glEnd();
    glBegin(GL_LINE_LOOP);	// door outline- rear, far
    glVertex3f(-0.5,0.22,-0.7);//hh'
    glVertex3f(0.0,0.22,-0.7);//gg'
    glVertex3f(0.0,-0.2,-0.7);//oo'
    glVertex3f(-0.5,-0.2,-0.7);//pp'
    glEnd();
    glBegin(GL_POLYGON);	//front**
    glVertex3f(1.52,.14,0.7);//k
    glVertex3f(1.52,.14,-0.7);//k'
    glVertex3f(1.52,-.44,-0.7);//j'
    glVertex3f(1.52,-.44,0.7);//j
    glEnd();

    glColor3f(0.0,0.0,1.0);
// transparent objects are placed next ..
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //TRANCPARENCY3
//windscreen
    glBegin(GL_POLYGON);
    glColor4f(0.0,0.0,0.0,0.7);	//COLOR =WHITE TRANSPARENT
    glVertex3f(0.562,.5,.6);//AAA
    glVertex3f(.562,.5,-.6);//AAA'
    glVertex3f(.76,.22,-.6);//MMM'
    glVertex3f(.76,.22,.6);//MMM
    glEnd();
    glBegin(GL_POLYGON);	//rear window
//COLOR =WHITE TRANSPARENT
    glVertex3f(-1.068,0.5,0.6);//pp
    glVertex3f(-1.068,0.5,-0.6);//pp'
    glVertex3f(-1.2,0.22,-0.6);//qq'
    glVertex3f(-1.2,0.22,0.6);//qq
    glEnd();
    glBegin(GL_POLYGON);	//leftmost window front
    glVertex3f(-0.98,0.5,0.7);//aa
    glVertex3f(-0.64,0.5,0.7);//bb
    glVertex3f(-0.64,0.22,0.7);//cc
    glVertex3f(-1.08,0.22,0.7);//dd
    glEnd();
    glBegin(GL_POLYGON);	//leftmost window back
    glVertex3f(-0.98,0.5,-0.7);//aa
    glVertex3f(-0.64,0.5,-0.7);//bb
    glVertex3f(-0.64,0.22,-0.7);//cc
    glVertex3f(-1.08,0.22,-0.7);//dd
    glEnd();
    glBegin(GL_POLYGON);	//middle window front
    glVertex3f(-0.5,0.5,0.7);
    glVertex3f(0.0,0.5,0.7);
    glVertex3f(0.0,0.22,0.7);
    glVertex3f(-0.5,0.22,0.7);
    glEnd();
    glBegin(GL_POLYGON);	//middle window back
    glVertex3f(-0.5,0.5,-0.7);
    glVertex3f(0.0,0.5,-0.7);
    glVertex3f(0.0,0.22,-0.7);
    glVertex3f(-0.5,0.22,-0.7);
    glEnd();
    glBegin(GL_POLYGON);	//rightmost window front
    glVertex3f(0.12,0.5,0.7);//ii
    glVertex3f(0.44,0.5,0.7);//jj
    glVertex3f(0.62,0.22,0.7);//kk
    glVertex3f(0.12,0.22,0.7);//ll

    glEnd();
    glBegin(GL_POLYGON);	//rightmost window back
    glVertex3f(0.12,0.5,-0.7);//ii'
    glVertex3f(0.44,0.5,-0.7);//jj'
    glVertex3f(0.62,0.22,-0.7);//kk'
    glVertex3f(0.12,0.22,-0.7);//ll'
    glEnd();
    glColor3f(0.0,0.0,1.0);
}

void privatecar()
{

    glPushMatrix();
    glTranslatef(-position,0*position,0);
    glScalef(0.4,0.4,0);


    //car1

    //glColor3ub(115,0,171);
    glColor3ub(255,102,102);

    amazingcar();






    glLoadIdentity();



    //glTranslatef(-position,0*position,0);


//car2


    glPopMatrix();



    //glutTimerFunc(100, update, 0);
}
//................rain..............
static float r1= 0;
static float r2= 10;
static float r3= 20;
static float r4= 30;
static float r5= 40;
static float r6= 50;
static float r7= 60;
static float r8= 70;
static float r9= 80;
static float r10= 90;
static float r11= 100;
static float r12= 110;

void rainfall()
{
    r1 -= 1;
    if(r1 < -100)
        r1 = 0;
    glutPostRedisplay();

    r2 -= 1;
    if(r2 < -100)
        r2 = 0;
    glutPostRedisplay();

    r3 -= 1;
    if(r3 < -100)
        r3 = 0;
    glutPostRedisplay();

    r4 -= 1;
    if(r4 < -100)
        r4 = 0;
    glutPostRedisplay();

    r5 -= 1;
    if(r5 < -100)
        r5 = 0;
    glutPostRedisplay();

    r6 -= 1;
    if(r6 < -100)
        r6 = 0;
    glutPostRedisplay();

    r7 -= 1;
    if(r7 < -100)
        r7 = 0;
    glutPostRedisplay();

    r8 -= 1;
    if(r8 < -100)
        r8 = 0;
    glutPostRedisplay();

    r9 -= 1;
    if(r9 < -100)
        r9 = 0;
    glutPostRedisplay();

    r10 -= 1;
    if(r10 < -100)
        r10 = 0;
    glutPostRedisplay();
    r11 -= 1;
    if(r11 < -100)
        r11 = 0;
    glutPostRedisplay();

    r12 -= 1;
    if(r12 < -100)
        r12 = 0;
    glutPostRedisplay();
}

void Rain()
{
    rainfall();
    glColor3f(1,1,1);
    float y = 0.5;
    for(float i = -1.0;i<100.0;i= i+0.05){
        glBegin(GL_LINES);
        glLineWidth(0.05);
        glVertex2d(i,y);
        glVertex2d(i-0.01,y-0.02);
    glEnd();

    }
}

void rainFall()
{
    glPushMatrix();
        glTranslated(0,r1,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r2,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r3,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r4,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r5,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r6,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r7,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r8,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r9,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r10,0);
        Rain();
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,r11,0);
        Rain();
    glPopMatrix();

}



void Night(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    gradientGL2();

    moon();

    cloud(137,137,137);

    group_megaBuilding();
    group_bench();

    glTranslatef(-0.5,0,0);
    glScalef(0.5,0.5,0);
    Eiffel_tower();
    glLoadIdentity();
    treegroup();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);
    Road();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);


    glTranslatef(0,-0.2,0);
    glScalef(0.4,0.4,0);
    privatecar();
    glLoadIdentity();
    RoadStrip(-1.0,-0.55, 0.2,0.03,246,108,16);



    treegroup2();

    field();
    //axis();

    glFlush();
}

void Nightrain(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    gradientGL2();

    moon();

    cloud(137,137,137);

    group_megaBuilding();
    group_bench();

    glTranslatef(-0.5,0,0);
    glScalef(0.5,0.5,0);
    Eiffel_tower();
    glLoadIdentity();
    treegroup();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);
    Road();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);


    glTranslatef(0,-0.2,0);
    glScalef(0.4,0.4,0);
    privatecar();
    glLoadIdentity();
    RoadStrip(-1.0,-0.55, 0.2,0.03,246,108,16);



    treegroup2();

    field();
    //axis();

    for(float i= -0.1; i<1.0; i+=0.009)
    {
        glTranslated(0,i,0);
        rainFall();
        glLoadIdentity();
    }


    glFlush();
}


void Day(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    gradientGL();

    Sun();

    cloud(238,238,238);

    group_megaBuilding();
    group_bench();

    glTranslatef(-0.5,0,0);
    glScalef(0.5,0.5,0);
    Eiffel_tower();
    glLoadIdentity();
    treegroup();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);
    Road();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);


    glTranslatef(0,-0.2,0);
    glScalef(0.4,0.4,0);
    privatecar();
    glLoadIdentity();
    RoadStrip(-1.0,-0.55, 0.2,0.03,246,108,16);



    treegroup2();

    field();
    //axis();

    glFlush();
}

void Dayrain(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    gradientGL();

    Sun();

    cloud(238,238,238);

    group_megaBuilding();
    group_bench();

    glTranslatef(-0.5,0,0);
    glScalef(0.5,0.5,0);

    Eiffel_tower();
    glLoadIdentity();
    treegroup();

    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);
    Road();
    RoadStrip(-1.0,-0.02, 0.2,0.02,246,108,16);


    glTranslatef(0,-0.2,0);
    glScalef(0.4,0.4,0);
    privatecar();
    glLoadIdentity();
    RoadStrip(-1.0,-0.55, 0.2,0.03,246,108,16);



    treegroup2();

    field();

    for(float i= -0.1; i<1.0; i+=0.009)
    {
        glTranslated(0,i,0);
        rainFall();
        glLoadIdentity();
    }

    //axis();

    glFlush();
}


void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
       // speed += 0.1f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        //speed -= 0.1f;
    }
    glutPostRedisplay();
}







void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    /*case '':
        i = 0.0f;
        break;
    case '':
        i = 0.1f;
        break;
*/

    case 'n':
        glutDisplayFunc(Night);
        break;

    case 'd':
        glutDisplayFunc(Day);
        break;

    case 'r':
        glutDisplayFunc(Dayrain);
        break;


    case 't':
        glutDisplayFunc(Nightrain);
        break;



        glutPostRedisplay();

    }
}

void SpecialInput(int key, int x, int y)
{
   /* switch(key)
    {
    case GLUT_KEY_UP:
        speed=.1;
        break;
    case GLUT_KEY_DOWN:
        speed=-.1;
        break;
    case GLUT_KEY_LEFT:

        break;
    case GLUT_KEY_RIGHT:
        break;
    }*/
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Eiffel Tower  project");
    glutDisplayFunc(Day);

    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    glutMouseFunc(handleMouse);

    init();
    glutTimerFunc(100, update, 0);
     glutIdleFunc(Idle);
    //glutDisplayFunc(Day);
    //glutDisplayFunc(Night);


    glutMainLoop();
    return 0;
}
