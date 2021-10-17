#include <iostream>
#include "person.h"
#include "flutter_wrapper.h"

using namespace std;

int main(int args, char **argv)
{
  Person p_default;
  Person p{17, "Josh"};
  char name[] = "Kimberley";
  Person p2{13, name};

  void *p3 = person_new(11, "Flutter");

  cout << "Default:" << p_default.whoami() << endl;
  cout << "Person:" << p.whoami() << endl;
  cout << "Person2:" << p2.whoami() << endl;
  cout << "Person3:" << person_whoami(p3) << endl;
  printf("%s\n", person_whoami(p3));
  return 0;
}