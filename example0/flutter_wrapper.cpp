#include "flutter_wrapper.h"
#include "person.h"

void *person_new(int age, char *name)
{
  return new Person(age, name);
}

void person_destroy(void *ptr)
{
  Person *typed_ptr = static_cast<Person *>(ptr);
  delete typed_ptr;
}

char *person_whoami(void *ptr)
{
  Person *typed_ptr = static_cast<Person *>(ptr);
  string s = typed_ptr->whoami();
  char *r = new char[s.length() + 1];
  sprintf(r, "%s", s.c_str());
  return r;
}