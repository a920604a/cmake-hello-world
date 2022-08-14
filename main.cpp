#include <iostream>
#include "Tim.h"
#include "a.cpp"
#include "b.cpp"
#include "c.cpp"
int main()
{
    std::cout << "Hello World\n";
    Tim().boo();
    a();
    b();
    c();
    return 0;
}
