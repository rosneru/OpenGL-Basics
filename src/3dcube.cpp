#include <windows.h>
#include <math.h>
#include <GL/glut.h>

#include "3dcube.h"



#define DELTA 0.1

int Maustaste;

GLint Mx, My;	// speichert Mauskoord beim Beginn des Drueckens auf linke Taste

GLint wuerfel;

GLuint width, high;

GLfloat viewpoint[3];
GLfloat alpha = 0.2, beta = 0.8, distance = 5;

GLfloat Flaeche[24][3] = {
  {0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0},	// Flaeche 1
  {1, 0, 0}, {1, 1, 0}, {1, 1, 1}, {1, 0, 1},	// Flaeche 2
  {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1},	// Flaeche 3
  {0, 0, 0}, {0, 0, 1}, {0, 1, 1}, {0, 1, 0},	// Flaeche 4
  {0, 1, 1}, {1, 1, 1}, {1, 1, 0}, {0, 1, 0},	// Flaeche 5
  {0, 0, 1}, {1, 0, 1}, {1, 0, 0}, {0, 0, 0}	// Flaeche 6
};




static void init3dCube(void)
{
  /* Initializations */
  int punkt;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClearColor(0.0, 0.0, 0.0, 1.0);
  wuerfel = 1;

  glNewList(wuerfel, GL_COMPILE);
  glBegin(GL_QUADS);
  for (punkt = 0; punkt < 24; punkt++)
  {
    glColor3fv(Flaeche[punkt]);
    glVertex3fv(Flaeche[punkt]);

  }
  glEnd();

  glEndList();
}

static void display3dCube(void)
{
  /* Creating the Scene */

  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  viewpoint[0] = distance * sin(beta) * sin(alpha) + 0.5;
  viewpoint[1] = distance * cos(beta) + 0.5;
  viewpoint[2] = distance * sin(beta) * cos(alpha) + 0.5;

  gluPerspective(30.0, (float)width / high, 0.1, 20.0);	// The width/high part constantly holds the outline of the cube
  gluLookAt(viewpoint[0], viewpoint[1], viewpoint[2], 0.5, 0.5, 0.5, 0.0, cos(beta - 3.141593 * 0.5), 0.0);

  glClear(GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);

  glCallList(wuerfel);
  glFlush();
  glutSwapBuffers();
}

static void reshape3dCube(int w, int h)
{
  /* Callback function to handle window dimensions and size changes */
  width = w;
  high = h;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

}

void processKeys3dCube(unsigned char theKey, int mouseX, int mouseY)
{
  GLint x = mouseX;				// hier nicht benoetigt
  GLint y = high - mouseY;			// hier nicht benoetigt
  switch (theKey)
  {
  case '+':
    distance -= DELTA;
    display3dCube();
    break;
  case '-':
    distance += DELTA;
    display3dCube();
    break;
  case 27:
    exit(-1);
  }
}

void doSpecials3dCube(int specKey, int mouseX, int mouseY)
{
  GLint x = mouseX;				// hier nicht benoetigt
  GLint y = high - mouseY;		// hier nicht benoetigt
  switch (specKey)
  {
  case GLUT_KEY_LEFT:
    alpha -= DELTA;
    display3dCube();
    break;
  case GLUT_KEY_RIGHT:
    alpha += DELTA;
    display3dCube();
    break;
  case GLUT_KEY_UP:
    beta -= DELTA;
    display3dCube();
    break;
  case GLUT_KEY_DOWN:
    display3dCube();
    beta += DELTA;
    break;
  }
}


void processMouse3dCube(int button, int state, int x, int y)
{
  Maustaste = button;
  if (button == GLUT_LEFT_BUTTON && (state == GLUT_UP || state == GLUT_DOWN)) {
    Mx = x;
    My = y;
  }
  //myDisplay();

}

void processMotion3dCube(int x, int y)
{
  if (Maustaste == GLUT_LEFT_BUTTON) {
    if (Mx < x) alpha -= DELTA;
    if (Mx > x) alpha += DELTA;
    if (My < y) beta -= DELTA;
    if (My > y) beta += DELTA;

    display3dCube();
  }

}



/*  Main Loop */
void run3dCube(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(480, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("3D cube (31.01.2005)");

  glutDisplayFunc(display3dCube);
  glutReshapeFunc(reshape3dCube);
  init3dCube();

  glutKeyboardFunc(processKeys3dCube);
  glutSpecialFunc(doSpecials3dCube);

  glutMouseFunc(processMouse3dCube);
  glutMotionFunc(processMotion3dCube);

  glutMainLoop();
}
