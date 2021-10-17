#include <iostream>
#include "person.h"

using namespace std;

Person::Person()
{
  age = 0;
  name = "anonymous";
}

string Person::whoami()
{
  return "age=" + to_string(age) + ", name=" + name;
}