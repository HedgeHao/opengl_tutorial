# Example 3:
## Draw from vertex array (with buffer)

* glew.h must include before glut.h
* openGL buffer:
> Store vertex data in OpenGL Buffered to avoid reading array every time (every frame)<br>
> Generate buffer -> Bind buffer with type -> Put data into buffer
> glEnableVertexAttribArray() will use data in gl buffer if it's set