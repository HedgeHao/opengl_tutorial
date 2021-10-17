#include <iostream>

class Person
{
public:
  Person();
  Person(int age, std::string name) : age(age), name(name) {}
  Person(int age, char *name) : age(age)
  {
    this->name = std::string(name);
  }

  int age;
  std::string name;
  std::string whoami();

private:
  char *privacy;
};