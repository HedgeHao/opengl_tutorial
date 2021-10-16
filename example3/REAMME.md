# Example 3:
## A red sphere in a basic GLUT windows with black background

* glew.h must include before glut.h
* openGL buffer:
> Store vertex data in OpenGL Buffered to avoid reading array every time (every frame)<br>
> Generate buffer -> Bind buffer with type -> Put data into buffer
> glEnableVertexAttribArray() will use data in gl buffer if it's set