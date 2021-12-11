cmake_minimum_required(VERSION 3.9)

project( hello-triangle CXX )

add_executable( ${PROJECT_NAME} "" )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
    OUTPUT_NAME ${PROJECT_NAME})

set ( source_code
"main.cpp"
)
target_sources( ${PROJECT_NAME} PRIVATE ${source_code})
find_package( OpenGL REQUIRED )
target_link_libraries( ${PROJECT_NAME} PRIVATE OpenGL::GL OpenGL::GLU)

find_package(GLEW REQUIRED)
target_link_libraries( ${PROJECT_NAME} PRIVATE GLUT::GLUT GLEW)


find_package( GLUT REQUIRED )
target_link_libraries( ${PROJECT_NAME} PRIVATE GLUT::GLUT )
