cmake_minimum_required(VERSION 3.9)

project( OpenGL_Example_0 CXX )

add_executable( ${PROJECT_NAME} "" )
set_target_properties( ${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_EXTENSIONS OFF
    OUTPUT_NAME "example0")

set ( source_code
"main.cpp"
"person.cpp"
"flutter_wrapper.cpp"
)
target_sources( ${PROJECT_NAME} PRIVATE ${source_code})