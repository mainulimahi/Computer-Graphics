#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>
void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}
void reshaped(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,(double)w/(double)h,1,200);
}
void keyPressed(int k,int x,int y)
{
            if(k==GLUT_KEY_LEFT)
            {
            }
}
float x=0.0,y=0.0,x1=5.0;
void update()
{
    x+=0.002;
    x1-=0.001;
    if(x>6)
        {
            x=-50;
            x1=50;
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(x1,y,-5.0);
    glBegin(GL_POLYGON);

        glColor3f(1.0,1.0,1.0);

        glVertex3f(-1.0,1.0,-5.0);
        glVertex3f(0.0,2.0,-5.0);
        glVertex3f(-2.0,2.0,-5.0);
        glVertex3f(1.0,1.0,-5.0);

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(x,y,-5.0);
    glBegin(GL_POLYGON);

        glColor3f(1.0,1.0,1.0);

        glVertex3f(1.0,0.7,-5.0);
        glVertex3f(1.5,1.0,-5.0);
        glVertex3f(0.7,1.5,-5.0);
        glVertex3f(0.0,2.0,-5.0);
        glVertex3f(-0.7,1.5,-5.0);
        glVertex3f(-1.4,1.6,-5.0);
        glVertex3f(-1.7,1.0,-5.0);
        glVertex3f(-1.5,0.7,-5.0);
        glVertex3f(-1.0,0.5,-5.0);

    glEnd();
    glPopMatrix();
    glBegin(GL_POLYGON);

        glColor3f(0.0,1.0,0.);

        glVertex3f(-2.0,-2.0,-5.0);
        glVertex3f(-1.0,-1.5,-5.0);

        glVertex3f(2.0,-2.0,-5.0);
        glVertex3f(1.2,-1.5,-5.0);

    glEnd();
    update();

    glutSwapBuffers();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(400,400);

    glutCreateWindow("Simple Cloud");

    initRendering();

    glutDisplayFunc(display);

    glutIdleFunc(display);

    glutReshapeFunc(reshaped);

    glutSpecialFunc(keyPressed);

    glutMainLoop();
return(0);
}
