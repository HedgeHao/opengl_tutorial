cmake_minimum_required(VERSION 3.9)

project( OpenGL_Example_4 CXX )

add_executable( ${PROJECT_NAME} "" )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
    OUTPUT_NAME "example4")

set ( source_code
"main.cpp"
)
target_sources( ${PROJECT_NAME} PRIVATE ${source_code})
find_package( OpenGL REQUIRED )
target_link_libraries( ${PROJECT_NAME} PRIVATE OpenGL::GL )

find_package( GLUT REQUIRED )
target_link_libraries( ${PROJECT_NAME} PRIVATE GLUT::GLUT )
