cmake_minimum_required(VERSION 3.9)

project( OpenGL_Triangle CXX )

add_executable( ${PROJECT_NAME} "" )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
    OUTPUT_NAME "opengl_triangle")

set ( source_code
"main.cpp"
)
target_sources( ${PROJECT_NAME} PRIVATE ${source_code})
find_package( OpenGL REQUIRED )
target_link_libraries( ${PROJECT_NAME} PRIVATE OpenGL::GL )

find_package(GLEW REQUIRED)
target_link_libraries( ${PROJECT_NAME} PRIVATE GLEW::GLEW )

find_package(glfw3 3.3 REQUIRED)
target_link_libraries( ${PROJECT_NAME} PRIVATE glfw )
