## [Example0: C++ basic]
(https://github.com/HedgeHao/opengl_tutorial/tree/master/example0)

## [Example1: CMake basic](https://github.com/HedgeHao/opengl_tutorial/tree/master/example1)
## [Example2: Red Sphere](https://github.com/HedgeHao/opengl_tutorial/tree/master/example2)
## [Example3: Draw from vertex array (with buffer)](https://github.com/HedgeHao/opengl_tutorial/tree/master/example3)

## Note

* [Projection, MatrixMode (glOrtho(), glFrustum(), gluPerspective())](https://www.itread01.com/content/1549668422.html)
> OpenGL中，如果想對模型進行操作，就要對這個模型的狀態(當前的矩陣)乘上這個操作對應的一個矩陣.
如果乘以變換矩陣(平移, 縮放, 旋轉), 那相乘之後, 模型的位置被變換;
如果乘以投影矩陣(將3D物體投影到2D平面), 相乘後, 模型的投影方式被設定;
如果乘以紋理矩陣(), 模型的紋理方式被設定.