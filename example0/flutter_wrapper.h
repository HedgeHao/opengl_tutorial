#include <iostream>

using namespace std;

extern "C"
{
  void *person_new(int age, char *name);
  void person_destroy(void *ptr);
  char *person_whoami(void *ptr);
}