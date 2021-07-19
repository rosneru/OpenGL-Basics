#include <windows.h>
#include <math.h>
#include <GL/glut.h>

#include "2dScenery.h"

GLint Tisch, Tasse, Uhr, Kanne, Bild, Lampe;

GLint width, high;

void init2dScenery(void)
{

  int i;
  /* Initializations */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(1.0, 1.0, 1.0, 1.0);

  /* Displayliste: Tisch */
  Tisch = glGenLists(1);
  glNewList(Tisch, GL_COMPILE);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(40.0, 0.0);
  glVertex2f(45.0, 0.0);
  glVertex2f(45.0, 75.0);
  glVertex2f(40.0, 75.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex2f(130.0, 0.0);
  glVertex2f(135.0, 0.0);
  glVertex2f(135.0, 75.0);
  glVertex2f(130.0, 75.0);
  glEnd();
  glBegin(GL_LINE_LOOP);
  glVertex2f(25.0, 75.0);
  glVertex2f(150.0, 75.0);
  glVertex2f(150.0, 80.0);
  glVertex2f(25.0, 80.0);
  glEnd();
  glEndList();

  /* Displayliste: Tasse (mit Untertasse) */
  Tasse = glGenLists(1);
  glNewList(Tasse, GL_COMPILE);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(0.0, 0.0);
  glVertex2f(10.0, 0.0);
  glVertex2f(15.0, 2.0);
  glVertex2f(15.0, 4.0);
  glVertex2f(10.0, 2.0);
  glVertex2f(0.0, 2.0);
  glVertex2f(-5.0, 4.0);
  glVertex2f(-5.0, 2.0);
  glEnd();
  glBegin(GL_QUADS);
  glVertex2f(0.0, 2.0);
  glVertex2f(10.0, 2.0);
  glVertex2f(10.0, 12.0);
  glVertex2f(0.0, 12.0);
  glEnd();
  glBegin(GL_LINE_STRIP);
  glVertex2f(10.0, 10.0);
  glVertex2f(11.0, 12.0);
  glVertex2f(14.0, 12.0);
  glVertex2f(15.0, 10.0);
  glVertex2f(15.0, 8.0);
  glVertex2f(10.0, 4.0);
  glEnd();
  glEndList();

  /* Displayliste: Uhr */
  /* Blockklammern nicht vergessen */
  Uhr = glGenLists(1);
  {
    int i, k;
    float delta, dDelta;
    float Pi = 3.141593;
    delta = 0.0;
    dDelta = Pi / 6;
    glNewList(Uhr, GL_COMPILE);
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 24; i++, delta += dDelta * 0.5)
      glVertex2f(15 * cos(delta), 15 * sin(delta));
    glEnd();
    glBegin(GL_LINES);
    for (i = 0; i < 12; i++, delta += dDelta)
    {
      if (i % 3)
        k = 10;
      else
        k = 8;
      glVertex2f(k * cos(delta), k * sin(delta));
      glVertex2f(13 * cos(delta), 13 * sin(delta));
    }
    glEnd();
    glColor3f(0.5, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(14 * cos(80 * Pi / 180), 14 * sin(80 * Pi / 180));
    glVertex2f(0.0, 0.0);
    glVertex2f(9 * cos(-5 * Pi / 180), 9 * sin(-5 * Pi / 180));
    glEnd();
    glEndList();
  }

  /* die Teekanne */
  Kanne = glGenLists(1);
  glNewList(Kanne, GL_COMPILE);
  glColor3f(0.0, 1.0, 0.0);
  glutWireTeapot(15);
  glEndList();

  /* Das Bild */
  Bild = glGenLists(1);
  glNewList(Bild, GL_COMPILE);
  /* Rahmen */
  glColor3f(0.2, 0.2, 0.2);
  glBegin(GL_QUADS);
  glVertex2f(0.0, 0.0); glVertex2f(30.0, 0.0); glVertex2f(30.0, 3.0); glVertex2f(0.0, 3.0);
  glVertex2f(0.0, 40.0); glVertex2f(30.0, 40.0); glVertex2f(30.0, 43.0); glVertex2f(0.0, 43.0);
  glVertex2f(0.0, 0.0); glVertex2f(0.0, 43.0); glVertex2f(3.0, 43.0); glVertex2f(3.0, 0.0);
  glVertex2f(30.0, 0.0); glVertex2f(30.0, 43.0); glVertex2f(33.0, 43.0); glVertex2f(33.0, 0.0);
  glEnd();
  /* Berge */
  glColor3f(0.9, 0.5, 0.2);
  glBegin(GL_TRIANGLES);
  glVertex2f(3.0, 23.0);
  glVertex2f(13.0, 37.0);
  glVertex2f(23.0, 23.0);
  glVertex2f(19.0, 23.0);
  glVertex2f(27.0, 33.0);
  glVertex2f(30.0, 20.0);

  glEnd();
  /* See */
  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(3.0, 3.0);
  glVertex2f(30.0, 3.0);
  glVertex2f(30.0, 22.0);
  glVertex2f(20.0, 23.0);
  glVertex2f(22.0, 24.0);
  glVertex2f(12.0, 24.0);
  glVertex2f(14.0, 25.0);
  glVertex2f(3.0, 23.0);

  glEnd();
  /* Wiese */
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(3.0, 3.0);
  glVertex2f(30.0, 3.0);
  glVertex2f(30.0, 15.0);
  glVertex2f(22.0, 10.0);
  glVertex2f(17.0, 14.0);
  glVertex2f(9.0, 11.0);
  glVertex2f(3.0, 16.0);
  glEnd();
  glEndList();

  /* Die Lampe */
  Lampe = glGenLists(1);
  glNewList(Lampe, GL_COMPILE);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2f(0.0, 4.0);
  glVertex2f(-20.0, 0.0);
  glVertex2f(0.0, 4.0);
  glVertex2f(20.0, 0.0);
  glVertex2f(0.0, 4.0);
  glVertex2f(0.0, 40.0);
  glEnd();
  /* Gluehbirne */
  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
  for (i = 0; i < 12; i++) {
    glVertex2f(4 * cos(i * 30 / (2 * 3.14)), 4 * sin(i * 30 / (2 * 3.14)));
    glVertex2f(4 * cos((i + 1) * 30 / (2 * 3.14)), 4 * sin((i + 1) * 30 / (2 * 3.14)));

  }
  glEnd();
  glEndList();

}

void display2dScenery(void)
{
  /* Creating the Scene */
  glClear(GL_COLOR_BUFFER_BIT);
  glViewport(0, 0, width, high);

  glViewport(0, 0, width, high);
  glCallList(Tisch);
  glPushMatrix();
  glTranslatef(130, 80, 0);
  glCallList(Tasse);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(180, 200, 0);
  glCallList(Uhr);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(60, 92, 0);
  glCallList(Kanne);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(25, 150, 0);
  glRotatef(5, 0, 0, 1);
  glCallList(Bild);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(90, 210, 0);
  glCallList(Lampe);
  glPopMatrix();

  glFlush();
}

void reshape2dScenery(int w, int h)
{
  /* Callback function to handle window dimensions and size changes */
  width = w;
  high = h;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-30, 240, -10, 250);
}

void processKeys2dScenery(unsigned char theKey, int mouseX, int mouseY)
{
  switch (theKey)
  {
  case 27:
    exit(-1);
  }
}


void run2dScenery(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(480, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("2D scenery (16.12.2004)");

  glutDisplayFunc(display2dScenery);
  glutReshapeFunc(reshape2dScenery);

  glutKeyboardFunc(processKeys2dScenery);

  init2dScenery();
  glutMainLoop();
}
