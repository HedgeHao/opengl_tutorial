#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glutSolidSphere(1.0, 50, 6); // (radius, slice, stack) => (radius, longitude, latitude)
  glFlush();
}

int main(int argc, char **argv)
{
  cout << "Example 2\n";

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // GLUT single buffered
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(2000, 100);
  glutCreateWindow("GLUT Window");
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}