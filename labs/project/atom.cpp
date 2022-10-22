#define GL_SILENCE_DEPRECATION
#include <stdlib.h>
#include <math.h>
/* MAC ONLY */
#include <GLUT/glut.h> // MAC ONLY
#include <iostream>    // MAC ONLY
/* LINUX ONLY */
// #include <GL/gl.h> // LINUX ONLY
// #include <GL/glu.h> // LINUX ONLY
// #include <GL/glut.h> // LINUX ONLY

/* ASCII code for the escape key. */
#define ESCAPE 27

static int year = 0, day = 0;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f); // Red
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glutSolidSphere(0.7, 20, 16); // nuclear
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
    glTranslatef(-0.5, 0.2, 0.0);
    glutSolidSphere(0.7, 20, 16); // nuclear

    glRotatef((GLfloat)year, 0.0, 0.0, 1.0); // eletron rotation around the nuclear
    glTranslatef(3.5, 0.0, 0.0);             // eletron location

    glPushMatrix(); // push eletron system

    glPushMatrix();

    glRotatef((GLfloat)day, 0.0, 1.0, 0.0); // eletron spinn
    glRotatef(90 - 23.4, 1.0, 0.0, 0.0);    // eletron axis
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);      // light blue
    glutSolidSphere(0.1, 10, 8);            // eletron
    glPopMatrix();

    glPushMatrix();
    glPopMatrix();

    glPopMatrix(); // pop eletron system

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        day = (day + 10) % 360;
        glutPostRedisplay();
        break;
    case 'D':
        day = (day - 10) % 360;
        glutPostRedisplay();
        break;
    case 'y':
        year = (year + 5) % 360;
        glutPostRedisplay();
        break;
    case 'Y':
        year = (year - 5) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}