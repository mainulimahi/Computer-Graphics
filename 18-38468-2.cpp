#include<windows.h>
#include<iostream>
#include<math.h>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;

int X1, Y1, X2, Y2;

void Bresenham(void){
    int x,y,p;
    float m;

    double dx=abs(X2-X1), dy=abs(Y2-Y1), dz;
    m = dy/dx;
    printf("%f\n",m);

    x=X1;
    y=Y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2d(x,y);

    if(m>1){
        p=2*dx-dy;
        while(y <=Y2)
        {
            printf("%d, %d \n", x, y);
            if(p<0)
            {

                y=y+1;
                p=p+2*dx;
                glVertex2d(round(x), round(y));
            }
            else
            {
                x=x+1;
                y=y+1;
                p=p+2*dx-2*dy;
                glVertex2d(round(x), round(y));
            }
        }
    }
    else if(m<1){
        p=2*dy-dx;
        while(x<=X2)
        {
            printf("%d, %d \n", x, y);
            if(p>=0)
            {
                y=y+1;
                p=p+2*dy-2*dx;
                glVertex2d(round(x), round(y));
            }
            else
            {
                x=x+1;
                p=p+2*dy;
                glVertex2d(round(x), round(y));
            }

        }
    }
    else {
        printf("slop can't be 1");
    }
    glEnd();

    glFlush();
}
void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0, 640.0,-100.0, 480.0);
//    gluOrtho2D(0.0, 640.0,0.0, 480.0);
}




int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("DDA Algorithm");

    cout<<"Enter an initial points: ";
    cin>>X1;
    cin>>Y1;
    cout<<"Enter the final points: ";
    cin>>X2;
    cin>>Y2;
    glutDisplayFunc(Bresenham);
    myInit ();
    glutMainLoop();

}
