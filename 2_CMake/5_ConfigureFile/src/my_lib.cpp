#include <iostream>
#include "my_lib.hpp"
#include "config.hpp"

using namespace std;
void Print_HelloWorld()
{
    cout << project_name << "\n";
    cout << project_version << "\n";
    cout << "Hello World" << endl;
}
