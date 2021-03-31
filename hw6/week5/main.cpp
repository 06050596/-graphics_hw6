#include <GL/glut.h>
#include<math.h>
#include<stdio.h>
float ang=0;
int n=0,vx[9999],vy[9999];
void hand(){
glPushMatrix();
        glScalef(0.5,0.1,0.1);
        glColor3f(1,0,0);
        glutSolidCube(1);
glPopMatrix();
}
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidCube(0.5);
    glPushMatrix();
        glTranslatef(0.25,0.25,0);
        glRotatef(ang,0,0,1);
        glTranslatef(0.25,0,0);
        hand();
        glPushMatrix();
            glTranslatef(0.25,0,0);
            glRotatef(ang,0,0,1);
            glTranslatef(0.25,0,0);
            hand();
        glPopMatrix();

    glPopMatrix();
        glPushMatrix();
        glTranslatef(-0.25,0.25,0);
        glRotatef(-ang,0,0,1);
        glTranslatef(-0.25,0,0);
        hand();
        glPushMatrix();
            glTranslatef(-0.25,0,0);
            glRotatef(-ang,0,0,1);
            glTranslatef(-0.25,0,0);
            hand();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ang++;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
