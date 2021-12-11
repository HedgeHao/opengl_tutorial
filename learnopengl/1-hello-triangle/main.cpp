#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

#define usedVertices verticesCube //方便用來切換不同的vertices

const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n";

const char *fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main(){\n"
    "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";

// 四邊形
float verticesBasic[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f,
    0.8f, 0.8f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f};

float verticesCube[] = {
    0.2, 0.2, 0,
    -0.2, 0.2, 0,
    -0.2, -0.2, 0,

    -0.2, -0.2, 0,
    0.2, -0.2, 0,
    0.2, 0.2, 0,

    0.2, 0.2, 0,
    0.4, 0.4, 0.2,
    -0.4, 0.4, 0.2,

    -0.4, 0.4, 0.2,
    -0.2, 0.2, 0,
    0.2, 0.2, 0};

unsigned int VAO;
unsigned int shaderProgram;
float *vertices;

void keyboardFunc(unsigned char c, int x, int y)
{
  if (c == 27)
  {
    glutDestroyWindow(glutGetWindow());
  }
}

void display()
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT); // Must use with glClearColor

  glBindVertexArray(VAO);
  glUseProgram(shaderProgram);
  // 從第0個頂點開始畫
  // verticeBasic:總共六個頂點(兩個三角形);
  // glDrawArrays(GL_TRIANGLES, 0, 6);

  // verticeCube: 總共12個頂點
  glDrawArrays(GL_TRIANGLES, 0, 12);

  glutSwapBuffers();
}

void initShader()
{
  unsigned int vertextShader;
  vertextShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertextShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertextShader);

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertextShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertextShader);
  glDeleteShader(fragmentShader);
}

void initTriangle()
{

  glGenVertexArrays(1, &VAO);
  // 綁上VAO, 開始使用VAO
  glBindVertexArray(VAO);

  unsigned int VBO;
  glGenBuffers(1, &VBO);
  // 把VBO綁到VAO的Array Buffer
  glBindBuffer(GL_ARRAY_BUFFER, VAO);

  // 把資料傳進Array Buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(usedVertices), usedVertices, GL_STATIC_DRAW);

  // 把資料塞到0號attribute (0號attribue, 每3個當一筆資料, type, Normalized, 下一筆資料間隔多少, 第一筆資料偏移多少)
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  //開啟0號attribute, 對應到shader的location = 0
  glEnableVertexAttribArray(0);
}

int main(int argc, char **argv)
{
  cout << "Example 4\n";

  glutInit(&argc, argv);
  glutInitWindowSize(600, 600);
  glutCreateWindow("GLUT Window");
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // GLUT single buffered

  /**
   * 要在視窗之後
   */
  if (glewInit() != GLEW_OK)
  {
    printf("failed:\n");
    return -1;
  }

  initShader();
  initTriangle();

  glViewport(0.0, 0.0, 600, 600);
  glutKeyboardFunc(keyboardFunc);

  // glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  // glutIdleFunc(display);

  glutMainLoop();

  return 0;
}