#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

GLfloat vertex[] = {0, 0, 0, 0, 0.3, 0, 0.8, 0, 0};
GLfloat vertex2[] = {0, 0, 0, 0, -0.7, 0, 0.5, 0, 0};

GLuint VBO;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 0, 0);
  glEnableVertexAttribArray(0); // Enable drawing array of vertex

  /**
   * (index, dimension, type, normalized, stride, vertex array)
   * dimension: 2 / 3 / 4
   * stride：number of bytes between two vertex in array
   * e.g. vertex = {x1, y1, z1, r1, g1, b1, x2, y2, z2, r2, g2, b2} => stripe = sizeof(x1) * 6
  */
  // Without buffer
  // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertex2);
  // With Buffer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

  /**
   * (mode, index, count)
   * mode: GL_POINTS / GL_TRIANGLES
   * index: which vertex in array should be the first one to draw
   * count: how many vertexes to draw
  */
  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(0);
  glFlush();
}

int main(int argc, char **argv)
{
  cout << "Example 3\n";

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // GLUT single buffered
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(2000, 100);
  glutCreateWindow("GLUT Window");
  glClearColor(1, 1, 1, 0.0);

  // Init GLEW
  GLuint result = glewInit();
  if (result != GLEW_OK)
  {
    fprintf(stderr, "Error: '%s' \n", glewGetErrorString(result));
    return -1;
  }

  // OpenGL Buffer
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

  glutDisplayFunc(display);

  glutMainLoop();

  glDeleteBuffers(1, &VBO);

  return 0;
}