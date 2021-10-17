all:
	gcc -g -fPIC -c -C person.cpp flutter_wrapper.cpp
	gcc -shared person.o flutter_wrapper.o -o libperson.so
