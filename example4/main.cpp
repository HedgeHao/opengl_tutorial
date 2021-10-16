#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

float angle = 0;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 0, 0);

  glLoadIdentity();
  glutWireTorus(0.3, 0.7, 30, 30);

  glColor3f(0, 0, 1);
  // glTranslatef(-0.2, 0.2, 0.1);
  glRotatef(angle, 1, 1, 0);
  glutWireTeapot(0.2);

  glFlush();
  angle += 0.05;
}

int main(int argc, char **argv)
{
  cout << "Example 4\n";

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // GLUT single buffered
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(2000, 100);
  glutCreateWindow("GLUT Window");
  glClearColor(1, 1, 1, 0.0);

  glutDisplayFunc(display);
  glutIdleFunc(display);

  glutMainLoop();

  return 0;
}